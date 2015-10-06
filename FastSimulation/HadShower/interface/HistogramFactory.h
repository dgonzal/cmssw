#ifndef HADSHOWERHISTOGRAMFACTORY_H
#define HADSHOWERHISTOGRAMFACTORY_H

#include <vector>

class TH1F;

namespace hadshower {
    class Step;
    class HistogramFactory {
	public:
	TH1F * createLongitudinalHist(const char * name,const char * title,const std::vector<Step> & steps);
	TH1F * createTransverseHist(const char * name,const char * title,const std::vector<Step> & steps);
    };
}

#endif
