#include "FastSimulation/HadShower/interface/StartGenerator.h"
#include "CLHEP/Random/RandomEngine.h"
#include <cmath>

using namespace hadshower;

// TODO: introduce energy dependence using the mip-fraction approach,
//       or using geant4
double StartGenerator::generate(CLHEP::HepRandomEngine & random){
  return std::log(1./random.flat());
}
