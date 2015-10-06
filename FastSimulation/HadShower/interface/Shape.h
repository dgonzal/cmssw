#ifndef HADSHOWERSHAPE_H
#define HADSHOWERSHAPE_H

#include <cmath>
#include <memory>
#include "CLHEP/Random/RandomEngine.h"
#include "FastSimulation/HadShower/interface/Step.h"

namespace hadshower {

    class ShapeParameters;
    class StepFactory;
    class Shape {

	public:

	Shape(const ShapeParameters & shapeParameters,
	      double showerStart_z,
	      unsigned nHcalSteps,
	      double hcalStepSize,
	      const Material & ecal,
	      const Material & gap,
	      const Material & hcal);
	
	~Shape(){}
	
	unsigned getNSteps(){return nSteps;}
	
	Step & getStep(unsigned stepIndex){
	    return (*steps)[stepIndex];
	}

	std::vector<Step> & getSteps(){return *steps;}

	double getEnergyFraction(unsigned stepIndex){
	    return (*steps)[stepIndex].energyFraction;
	}

	// energy fraction in step multiplied with 
	// eq. 7 NIM A290 (1990) 469-488
	double getRelativeEnergyDensity(unsigned stepIndex,double r) const{
	    const double & R50 = (*steps)[stepIndex].R50;
	    return (*steps)[stepIndex].energyFraction * 2 * r * pow(R50,2) / pow(pow(r,2) + pow(R50,2),2);
	}

	// sample the radial distribution in the given step inverse transform sampling of the radial distribution
	bool generateSpot(unsigned stepIndex,CLHEP::HepRandomEngine & random,double & radius,double & phi) const{
	    double u = random.flat();
	    // [ int_0^r transverse distribtution ]^-1 = R50_*std::sqrt(u/(1.-u))
	    radius = (*steps)[stepIndex].R50*std::sqrt(u/(1.-u));
	    // we assume symmetry w.r.t. phi
	    phi = random.flat()*2.*M_PI;
	}

	private:
	
	// data members
	static const StepFactory stepFactory;
	const ShapeParameters * shapeParameters;
	const double tgamma_alphaHad;
	const double tgamma_alphaEM;
	std::unique_ptr<std::vector< hadshower::Step > > steps;
	const unsigned nSteps;

	// internal functions

	double calculateEnergyFraction(const Step & step) const; /// calculate and return relative energy of the given step
	double calculateR50(const Step & step) const;               /// calculate and return R50 for given step
	void normaliseEnergyFractions(std::vector<Step> & steps);   /// force the relative energies in the steps to sum up to 1
	void applyEcalEnergyFactor(std::vector<Step> & steps);
	
	
	

    };
}

#endif
