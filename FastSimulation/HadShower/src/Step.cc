#include "FastSimulation/HadShower/interface/Step.h"
#include "FastSimulation/HadShower/interface/Material.h"

using namespace hadshower;

Step::Step(const Material & material,double size)
    : material(&material)
    , depth(0.)
    , depthInRadLen(0.)
    , depthInCm(0.)
    , size(size)
    , sizeInRadLen(size * material.radLenPerIntLen)
    , sizeInCm(size * material.cmPerIntLen)
{}

Step::Step(const Material & material,const Step & previousStep,double size)
    : material(&material)
    , depth(previousStep.depth + previousStep.size)
    , depthInRadLen(previousStep.depthInRadLen + previousStep.sizeInRadLen)
    , depthInCm(previousStep.depthInCm + previousStep.sizeInCm)
    , size(size)
    , sizeInRadLen(size * material.radLenPerIntLen)
    , sizeInCm(size * material.cmPerIntLen)
{}
