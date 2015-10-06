#include "FastSimulation/HadShower/interface/StepFactory.h"
#include "FastSimulation/HadShower/interface/Step.h"
#include "FastSimulation/HadShower/interface/Material.h"

using namespace hadshower;

std::unique_ptr<std::vector<Step> > StepFactory::create(double showerStart_z,
							unsigned nHcalSteps,
							double hcalStepSize,
							const Material & ecal,
							const Material & gap,
							const Material & hcal) const{
    
    // the product
    std::unique_ptr<std::vector<Step> > steps(new std::vector<Step>);

    // shower starts in ecal:
    if(showerStart_z < ecal.dz) {
	//   one big step in ECAL
	steps->push_back(Step(ecal,ecal.dz - showerStart_z));
	//   and a next one in the gap
	steps->push_back(Step(gap,steps->back(),gap.dz));
    }
    // shower starts in gap:
    else if(showerStart_z < ecal.dz + gap.dz) {
	//   one big step in the gap
	steps->push_back(Step(gap,ecal.dz + gap.dz - showerStart_z));
    }
    
    // the hcal steps
    unsigned hcalStepIndex = 0;        // count the number of hcal steps
    double hcal_dz_leftOver = hcal.dz; // keep track of how many interaction lenght hcal has left
    // loop until the end of hcal is reached, or the max number of steps
    while(hcalStepIndex < nHcalSteps && hcal_dz_leftOver > 0.){
	double _stepSize = hcalStepSize < hcal_dz_leftOver ? hcalStepSize : hcal_dz_leftOver;
	// treate the very first step different from the other ones
	if(steps->size()==0)
	    steps->push_back(Step(hcal,_stepSize));
	else
	    steps->push_back(Step(hcal,steps->back(),_stepSize));
	hcal_dz_leftOver -= _stepSize;
	hcalStepIndex++;
    }
    
    return steps;
}
