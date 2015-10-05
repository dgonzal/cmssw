#include "FastSimulation/HadShower/interface/SingleShapeParametersGenerator.h"
#include "FastSimulation/HadShower/interface/SingleShapeParameters.h"
#include "FastSimulation/HadShower/interface/Parameters.h"
#include "CLHEP/Random/RandomEngine.h"

#include "cmath"

using namespace hadshower;

SingleShapeParametersGenerator::SingleShapeParametersGenerator(const Parameters & parameters) 
    : parameters(&parameters)
{}

std::unique_ptr<SingleShapeParameters> SingleShapeParametersGenerator::generate(double energy,CLHEP::HepRandomEngine & random) const{

    // the product
    std::unique_ptr<SingleShapeParameters> singleShapeParameters(new SingleShapeParameters);    

    // take care of the energy range used for tuning
    double limitedEnergy = energy;
    if(energy < parameters->emin())
        limitedEnergy = parameters->emin();
    else if(energy > parameters->emax())
        limitedEnergy = parameters->emax();
    
    // most parameters are assumed to be linear functions of the following energy-dependent variable
    double logLimitedEnergy = std::log(limitedEnergy);
    double energyScale = std::log( ( parameters->e1() + logLimitedEnergy * parameters->e2() ) * limitedEnergy );
    
    // set the shower shape parameters
    singleShapeParameters->alphaEM = parameters->alphaEM1() + energyScale * parameters->alphaEM2();
    singleShapeParameters->betaEM = parameters->betaEM1() + energyScale * parameters->betaEM2();
    singleShapeParameters->alphaHad = parameters->alphaEM1() + energyScale * parameters->alphaEM2();
    singleShapeParameters->betaHad = parameters->betaHad1() + energyScale * parameters->betaHad2();
    singleShapeParameters->pi0fraction = parameters->pi0fraction1() + energyScale * parameters->pi0fraction2();
    if(singleShapeParameters->pi0fraction > 1.)
        singleShapeParameters->pi0fraction = 1.;
    singleShapeParameters->R1 = parameters->r1();
    singleShapeParameters->R2prime = parameters->r2() + parameters->r3()*logLimitedEnergy;

    // transverse shape fluctuations
    double transverseShapeFluctuationFactor = 1. + random.flat()/3.;
    singleShapeParameters->R1 *= transverseShapeFluctuationFactor;
    singleShapeParameters->R2prime *= transverseShapeFluctuationFactor;
 
    // longitudinal shape fluctuations
    double longitudinalShapeFluctuationFactor = 1. + 0.05 * (2.* random.flat() - 1.);
    singleShapeParameters->alphaEM *= longitudinalShapeFluctuationFactor;
    singleShapeParameters->alphaHad *= longitudinalShapeFluctuationFactor;

    return singleShapeParameters;

}
