#ifndef HADSHOWERSHAPEPARAMETERSGENERATOR
#define HADSHOWERSHAPEPARAMETERSGENERATOR

#include <memory>

namespace CLHEP {
    class HepRandomEngine;
}

namespace hadshower {
    class ShapeParameters;
    class Parameters;
    class ShapeParametersGenerator {
	public:
	ShapeParametersGenerator(const Parameters & parameters);
	std::unique_ptr<ShapeParameters> generate(double energy,CLHEP::HepRandomEngine & random) const;
	private:
	const Parameters * parameters;
    };
}

#endif
