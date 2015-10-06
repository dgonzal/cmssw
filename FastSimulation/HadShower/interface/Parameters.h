#ifndef HADSHOWERPARAMETERS
#define HADSHOWERPARAMETERS

namespace hadshower {

    class Parameters {
	public:

	// to distinguish between low- and high-energy case
	void setCase(int choice) {
	    if(choice < 1 || choice > 2) theCase = 2;
	    else theCase = choice; 
	} 

	// Minimal energy for the parameters calculation ( e < emin)  
	double emin() const { return 2.;}                 
	// First  range for the parameters calculation   ( emin < e < mid) 
	double emid() const { return 10.; }
	// Second range for the parameters calculation   ( emid < e < emax) 
	double emax() const { return 500.; }

	double e1() const { return 0.35; }
	double e2() const { return 0.09; }
	double alphaEM1() const { if(theCase==1) return 1.08;  else return 1.30; }
	double alphaEM2() const { if(theCase==1) return 0.24;  else return 0.255; }
	double betaEM1() const { if(theCase==1) return 0.478; else return 0.289; }
	double betaEM2() const { if(theCase==1) return 0.135; else return 0.010; }
	double alphaHad1() const { if(theCase==1) return 1.17;  else return 0.38; }
	double alphaHad2() const { if(theCase==1) return 0.21;  else return 0.23; }
	double betaHad1() const { if(theCase==1) return 2.10;  else return 0.83; }
	double betaHad2() const { if(theCase==1) return 0.72;  else return 0.049; }
	double pi0fraction1() const { if(theCase==1) return 0.751; else return 0.509; }
	double pi0fraction2() const { if(theCase==1) return 0.177; else return 0.021; }
	double r1() const { return 0.0124; } 
	double r2() const { return 0.359; } 
	double r3() const { return 0.0511; } 
  
	private:
  
	int theCase;
    };

}

#endif
