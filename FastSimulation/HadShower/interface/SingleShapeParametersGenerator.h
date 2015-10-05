#ifndef HADSHOWERSINGLESHAPEPARAMETERSGENERATOR
#define HADSHOWERSINGLESHAPEPARAMETERSGENERATOR

#include <memory>

namespace CLHEP {
    class HepRandomEngine;
}

namespace hadshower {
    class SingleShapeParameters;
    class Parameters;
    class SingleShapeParametersGenerator {
	public:
	SingleShapeParametersGenerator(const Parameters & parameters);
	std::unique_ptr<SingleShapeParameters> generate(double energy,CLHEP::HepRandomEngine & random) const;
	private:
	const Parameters * parameters;
    };
}

#endif
