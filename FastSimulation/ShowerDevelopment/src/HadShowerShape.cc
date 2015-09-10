#include "FastSimulation/ShowerDevelopment/interface/HadShowerShape.h"

HadShowerShape::HadShowerShape(const HadShowerShapeParameters & parameters,std::vector<HadShowerStep> & steps) :
    , parameters_(&parameters)
    , steps_(&steps)
    , tgamma_alphaHad(std::tgamma(parameters.alphaHad))
    , tgamma_alphaEM(std::tgamma(parameters.alphaEM))
{
    // calculate relative energy per step
    for(auto & step : steps){
	setRelativeEnergy_(step);
	setR50_(step);
    }
    correctECALFraction_();
    normaliseRelativeEnergy_();
}

// longitudinal energy density
// eq. 9 NIM A290 (1990) 469-488
void HadShowerShape::setRelativeEnergy_(HadShowerStep & step){
    // EM component of longitudinal energy density
    double x = parameters_.betaEM*step.depth_radLen;
    double relEnergyDensityEM
	= parameters_.pi0fraction_ 
	* pow(x,parameters_.alphaEM_) * exp(-x) / tgamma_alphaEM_
	* parameters_.betaEM * step.radLenPerIntLen;
    // Had component of longitudinal energy density
    double y = parameters_.alphaHad*step.depth_intLen;
    double relEnergyDensityHad = 
	= (1. - parameters_.pi0fraction_)
	* pow(y,parameters_.alphaHad_) * exp(-y) / tgamma_alphaHad
	* parameters_.betaHad;
    // total energy density
    step.relativeEnergy = (relEnergyDensityEM + relEnergyDensityHad)*step.size_intLen;
}

// parameter for transverse energy density
// eq. 7 NIM A290 (1990) 469-488
// R2prime stands for R2+R3*logE
// TODO: check: implemented differently (wrong?) in CMSSW original
void HadShowerShape::setR50_(HadShowerStep & step){
    step.R50_ = parameters_.R1 + parameters_.R2prime * step.depth_intLen;
}

void HadShowerShape::setDepth(double depth_intLen,double depth_radLen,double radLenPerIntLen){

    // longitudinal energy density
    // eq. 9 NIM A290 (1990) 469-488
    // EM component of longitudinal energy density
    double x = parameters_.betaEM*depth_radLen;
    double relEnergyEM
	= parameters_.pi0fraction_ 
	* pow(x,parameters_.alphaEM_) * exp(-x) / tgamma_alphaEM_
	* parameters_.betaEM * radLenPerIntLen;
    // Had component of longitudinal energy density
    double y = parameters_.alphaHad*depth_intLen;
    double relEnergyHad = 
	= (1. - parameters_.pi0fraction_)
	* pow(y,parameters_.alphaHad_) * exp(-y) / tgamma_alphaHad
	* parameters_.betaHad;
    // total energy density
    longitudinalRelativeEnergyDensity_ = relEnergyEM + relEnergyHad;

    // parameter for transverse energy density
    // eq. 7 NIM A290 (1990) 469-488
    // R2prime stands for R2+R3*logE
    // TODO: check: implemented differently (wrong?) in CMSSW original
    R50_ = parameters_.R1 + parameters_.R2prime*depth_intLen;
    // CMS way to introduce fluctuations
    // TODO: improve, check http://arxiv.org/pdf/hep-ex/0001020
    R50square = R50_*R50_;
}
