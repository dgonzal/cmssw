#include "FastSimulation/HadShower/interface/Shape.h"
#include "FastSimulation/HadShower/interface/StepFactory.h"
#include "FastSimulation/HadShower/interface/ShapeParameters.h"
#include "FastSimulation/HadShower/interface/Material.h"

using namespace hadshower;

const StepFactory Shape::stepFactory = StepFactory();

Shape::Shape(const ShapeParameters & shapeParameters,
	     double showerStart_z,
	     unsigned nHcalSteps,
	     double hcalStepSize,
	     const Material & ecal,
	     const Material & gap,
	     const Material & hcal)
    : shapeParameters(&shapeParameters)
    , tgamma_alphaHad(std::tgamma(shapeParameters.alphaHad))
    , tgamma_alphaEM(std::tgamma(shapeParameters.alphaEM))
    , steps(stepFactory.create(showerStart_z,nHcalSteps,hcalStepSize,ecal,gap,hcal))
    , nSteps(steps ? steps->size() : 0)
{    
    for(auto & step : (*steps)){
	step.energyFraction = calculateEnergyFraction(step);
	step.R50 = calculateR50(step);
    }
    normaliseEnergyFractions(*steps);
    applyEcalEnergyFactor(*steps);
}


// longitudinal energy density
// eq. 9 NIM A290 (1990) 469-488
double Shape::calculateEnergyFraction(const Step & step) const{
    // EM component of longitudinal energy density
    double x = shapeParameters->betaEM*step.depthInRadLen;
    double relEnergyDensityEM
	= shapeParameters->pi0fraction
	* pow(x,shapeParameters->alphaEM) * exp(-x) / tgamma_alphaEM
	* shapeParameters->betaEM * step.sizeInRadLen / step.size;
    // Had component of longitudinal energy density
    double y = shapeParameters->alphaHad*step.depth;
    double relEnergyDensityHad
	= (1. - shapeParameters->pi0fraction)
	* pow(y,shapeParameters->alphaHad) * exp(-y) / tgamma_alphaHad
	* shapeParameters->betaHad;
    // total energy density
    return (relEnergyDensityEM + relEnergyDensityHad)*step.size;
}

// parameter for transverse energy density
// eq. 7 NIM A290 (1990) 469-488
// R2prime stands for R2+R3*logE
// TODO: check: implemented differently (wrong?) in CMSSW original
double Shape::calculateR50(const Step & step) const{
    return shapeParameters->R1 + shapeParameters->R2prime * step.depth;
}

void Shape::normaliseEnergyFractions(std::vector<Step> & steps){
    double sum = 0;
    for(auto & step : steps)
	sum += step.energyFraction;
    if(sum != 0){
	for(auto & step : steps){
	    step.energyFraction /= sum;
	}
    }
    else{
	double energyFraction = 1./steps.size();
	for(auto & step : steps){
	    step.energyFraction = energyFraction;
	}
    }
}

// note: this is not exactly what happens in the original HDShower
//       (it would be hard to fully reproduce the same behavior without making this code really ugly)
void Shape::applyEcalEnergyFactor(std::vector<Step> & steps){
    
    // correct ecal
    double oldEcalEnergyFraction = 0;
    for(auto & step : steps){
	if(step.material->type == Material::ECAL){
	    oldEcalEnergyFraction += step.energyFraction;
	    step.energyFraction *= shapeParameters->ecalEnergyFactor;
	}
    }
    
    // correct hcal
    double newEcalEnergyFraction = oldEcalEnergyFraction * shapeParameters->ecalEnergyFactor;
    double hcalEnergyFactor = (1. - newEcalEnergyFraction) / (1. - oldEcalEnergyFraction);
    for(auto & step : steps){
	if(step.material->type == Material::HCAL){
	    step.energyFraction *= hcalEnergyFactor;
	}
    }
}

