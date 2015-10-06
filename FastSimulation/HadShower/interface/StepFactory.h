#ifndef HADSHOWERSTEPFACTORY_H
#define HADSHOWERSTEPFACTORY_H

#include <vector>
#include <memory>


namespace hadshower{

    class Step;
    class Material;

    class StepFactory{

	public:
	
	StepFactory(){;}
	~StepFactory(){;}
	
	std::unique_ptr<std::vector<Step> > create(double showerStart_z,
						   unsigned nHcalSteps,
						   double hcalStepSize,
						   const Material & ecal,
						   const Material & gap,
						   const Material & hcal) const;
    };

}

#endif
