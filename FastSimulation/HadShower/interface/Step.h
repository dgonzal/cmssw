#ifndef HADSHOWERSTEP_H
#define HADSHOWERSTEP_H

namespace hadshower {

    class Material;
    class Step;

    class Step{
	
	public:
	
	Step(const Material & material,double size);                     // create a step at depth 0
	Step(const Material & material,const Step & previousStep,double size); // create a step after previousStep
	    
	const Material * material;
	const double depth;
	const double depthInRadLen;
	const double depthInCm;
	const double size;
	const double sizeInRadLen;
	const double sizeInCm;
	double R50;
	double energyFraction;
    };

}

#endif
