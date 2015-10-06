#include "CLHEP/Random/JamesRandom.h"
#include "FastSimulation/HadShower/interface/Shape.h"
#include "FastSimulation/HadShower/interface/SingleShapeParametersGenerator.h"
#include "FastSimulation/HadShower/interface/SingleShapeParameters.h"
#include "FastSimulation/HadShower/interface/Parameters.h"
#include "FastSimulation/HadShower/interface/Material.h"
#include "FastSimulation/HadShower/interface/StartGenerator.h"
#include "FastSimulation/HadShower/interface/StepFactory.h"
#include "FastSimulation/HadShower/interface/Step.h"

#include "TFile.h"
#include "TH1D.h"

using namespace hadshower;

int main(){
    
    std::cout << "initializing..." << std::endl;

    CLHEP::HepJamesRandom random;
    Parameters parameters;
    StartGenerator startGenerator;
    StepFactory stepFactory;
    SingleShapeParametersGenerator singleShapeParametersGenerator(parameters);

    int nHcalSteps = 25;
    double spotEnergy = 0.2;
    double hcalStepSize = 0.2;
    double energy = 10.;

    // some bogus material definition
    // arguments: 
    //   - material type,
    //   - thickness (interaction lenghts), 
    //   - cm per interaction lenght, 
    //   - radiation lenghts per interaction lenght
    Material ecal(Material::ECAL,0,12,10);
    Material gap(Material::GAP,0,12,10);
    Material hcal(Material::HCAL,5,0.5,10);
    
    TFile * oFile = TFile::Open("test_showerShape.root","RECREATE");
    oFile->cd();

    std::cout << "generating..." <<std::endl;

    unsigned nShowers = 100;
    for(unsigned showerIndex = 0;showerIndex<nShowers;showerIndex++){

	// where the shower starts
	double showerStart_z = startGenerator.generate(random);

	// the shower steps
	auto steps = stepFactory.create(showerStart_z,
					nHcalSteps,
					hcalStepSize,
					ecal,gap,hcal);

	// the shower shape
	auto singleShapeParameters = singleShapeParametersGenerator.generate(energy,random);
	Shape shape(*singleShapeParameters,*steps);
	
	// draw the shower longitudinal shape
	float * stepBoundaries = new float[steps->size()+1];
	for(unsigned stepIndex = 0;stepIndex < steps->size();stepIndex++){
	    stepBoundaries[stepIndex] = (*steps)[stepIndex].depth;
	}
	stepBoundaries[steps->size()] = steps->back().depth + steps->back().size;
	char name[200];
	sprintf(name,"shower%d_longShape",showerIndex);
	TH1F * hist_longShape = new TH1F(name,name,steps->size(),stepBoundaries);
	std::cout << steps->size() << std::endl;
	for(unsigned stepIndex = 0;stepIndex < steps->size();++stepIndex){
	    hist_longShape->SetBinContent(stepIndex+1,shape.getEnergyFraction(stepIndex));
	}

	// draw spots and fill longitudinal and transverse profile
	sprintf(name,"shower%d_longProfile",showerIndex);
	TH1F * hist_longProfile = new TH1F(name,name,steps->size(),stepBoundaries);
	sprintf(name,"shower%d_transProfile",showerIndex);
	TH1F * hist_transProfile = new TH1F(name,name,steps->size(),stepBoundaries);
	double phi,radius;
	for(unsigned stepIndex = 0;stepIndex < steps->size();++stepIndex){
	    double _stepEnergy = energy*shape.getEnergyFraction(stepIndex);
	    int _nSpots = _stepEnergy/spotEnergy + 1;
	    double _spotEnergy = _stepEnergy/_nSpots;
	    for(unsigned spotIndex = 0;spotIndex<_nSpots;spotIndex++){
		shape.generateSpot(stepIndex,random,radius,phi);
		hist_longProfile->Fill((*steps)[stepIndex].depth+(*steps)[stepIndex].size/2,_spotEnergy);
		hist_transProfile->Fill(radius,_spotEnergy);
	    }
	}
    }

    std::cout << "finalizing..." << std::endl;
    oFile->Write();
    oFile->Close();
    delete oFile;
}
