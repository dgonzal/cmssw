#include "FastSimulation/HadShower/interface/HistogramFactory.h"
#include "FastSimulation/HadShower/interface/Step.h"
#include "TH1F.h"

using namespace hadshower;

TH1F * HistogramFactory::createLongitudinalHist(const char * name,const char * title,const std::vector<Step> & steps){
    float * stepBoundaries = new float[steps.size()+1];
    for(unsigned stepIndex = 0;stepIndex < steps.size();stepIndex++){
	stepBoundaries[stepIndex] = steps[stepIndex].depth;
    }
    stepBoundaries[steps.size()] = steps.back().depth + steps.back().size;
    TH1F * hist = new TH1F(name,title,steps.size(),stepBoundaries);
    return hist;
}

TH1F * HistogramFactory::createTransverseHist(const char * name,const char * title,const std::vector<Step> & steps){
    double maxR50 = 0;
    for(const auto & step : steps){
	if(step.R50 > maxR50)
	    maxR50 = step.R50;
    }
    TH1F * hist = new TH1F(name,title,25,0,maxR50);
    return hist;
}

