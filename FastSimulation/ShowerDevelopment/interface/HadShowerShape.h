#ifndef HADSHOWERSHAPE_H
#define HADSHOWERSHAPE_H

#include <cmath>
#include "CLHEP/Random/RandomEngine.h"


class HaDShowerStep{
    
    enum Detector {ecal = 0,hcal=1};
    
    Detector detector;
    unsigned int nspots;
    double energy;
    double depth_intLen;
    double depth_radLen;
    double depth_cm;
    double size_radLen;
    double radLenPerIntLen;
    double R50;
    
};

class HadShowerShapeParameters{

    public:

    double alphaEM;
    double betaEM;
    double alphaHAD;
    double alphaHAD;
    double pi0fraction;
    double R1;
    double R2prime;
}


class HadShowerShape {

    public:

    HadShowerShape(const HadShowerParameters & parameters,std::vector<HadShowerStep> & steps);
    ~HadShowerShape(){}

    unsigned nSteps(){return steps.size();}

    double getRelativeEnergyDensity(unsigned showerStepIndex){
	return (*steps)[stepIndex].relativeEnergy;
    }

    // TODO: make sure this is normalised
    double getRelativeEnergyDensity(unsigned showerStepIndex,double radius){
	return (*steps)[stepIndex].relativeEnergy*2*longitudinalEnergyDensity_*radius*R50square/std::pow(radius*radius+R50square,2);
    }

    // sample the radial distribution in the given step inverse transform sampling of the radial distribution
    bool generateSpot(unsigned showerStepIndex,HepRandomEngine & engine,double & radius,double & phi){
	double u = engine.flat();
	// [ int_0^r transverse distribtution ]^-1 = R50_*std::sqrt(u/(1.-u))
	radius = R50_*std::sqrt(u/(1.-u));
	// we assume symmetry w.r.t. phi
	phi = engine.flat()*2.*M_PI;
    }
};
