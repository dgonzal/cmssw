#ifndef HADSHOWERSTARTGENERATOR_H
#define HADSHOWERSTARTGENERATOR_H

namespace CLHEP{
    class HepRandomEngine;
}

namespace hadshower {
    class StartGenerator {
	public:
	double generate(CLHEP::HepRandomEngine & random);
    };
}

#endif
