#include "CLHEP/Random/JamesRandom.h"
#include "FastSimulation/HadShower/interface/Shape.h"
#include "FastSimulation/HadShower/interface/ShapeParametersGenerator.h"
#include "FastSimulation/HadShower/interface/ShapeParameters.h"
#include "FastSimulation/HadShower/interface/Parameters.h"
#include "FastSimulation/HadShower/interface/Material.h"
#include "FastSimulation/HadShower/interface/StartGenerator.h"
#include "FastSimulation/HadShower/interface/Step.h"
#include "FastSimulation/HadShower/interface/HistogramFactory.h"

#include "TFile.h"
#include "TH1D.h"

int main(){
    
    std::cout << "initializing..." << std::endl;

    // particle energy
    double energy = 10.;

    CLHEP::HepJamesRandom random;

    hadshower::Parameters parameters;
    hadshower::StartGenerator startGenerator;
    hadshower::ShapeParametersGenerator shapeParametersGenerator(parameters);
    hadshower::HistogramFactory histogramFactory;

    int nHcalSteps = 25;
    double spotEnergy = 0.2;
    double hcalStepSize = 0.2;

    // material definition
    // arguments: 
    //   - material type,
    //   - thickness (interaction lenghts), 
    //   - cm per interaction lenght, 
    //   - radiation lenghts per interaction lenght
    // the values for thickness and radiation lenghts per interaction lenght are given for the barrel and for a particle that hits perpundicularly
    // the values for cm per interaction length are dymmy placeholders. They have no impact on the modeling.
    hadshower::Material ecal(hadshower::Material::ECAL,1.246,1.,25.895/1.246);
    hadshower::Material gap(hadshower::Material::GAP,0.180,1.,1.133/0.180);
    hadshower::Material hcal(hadshower::Material::HCAL,8.930,1.,8.930/93.984);
    
    // store some histograms
    TFile * oFile = TFile::Open("shape.root","RECREATE");
    oFile->cd();

    std::cout << "generating..." <<std::endl;

    unsigned nShowers = 100;
    for(unsigned showerIndex = 0;showerIndex<nShowers;showerIndex++){

	// where the shower starts
	double showerStart_z = startGenerator.generate(random);

	// the shower shape parameters
	auto shapeParameters = shapeParametersGenerator.generate(energy,random);
	std::cout << shapeParameters->alphaEM << " " << shapeParameters->alphaHad << std::endl;

	// the shower shape
	hadshower::Shape shape(*shapeParameters,
			       showerStart_z,
			       nHcalSteps,
			       hcalStepSize,
			       ecal,gap,hcal);
		    
	// plot the shower longitudinal shape
	char name[200];
	sprintf(name,"shower%d_longShape",showerIndex);
	TH1F * hist_longShape = histogramFactory.createLongitudinalHist(name,name,shape.getSteps());
	for(unsigned stepIndex = 0;stepIndex < shape.getNSteps();++stepIndex){
	    hist_longShape->SetBinContent(stepIndex+1,shape.getEnergyFraction(stepIndex));
	}

	// draw spots and fill longitudinal and transverse profile
	sprintf(name,"shower%d_longProfile",showerIndex);
	TH1F * hist_longProfile = histogramFactory.createLongitudinalHist(name,name,shape.getSteps());
	sprintf(name,"shower%d_transProfile",showerIndex);
	TH1F * hist_transProfile = histogramFactory.createTransverseHist(name,name,shape.getSteps());
	double phi,radius;
	for(unsigned stepIndex = 0;stepIndex < shape.getNSteps();++stepIndex){
	    double _stepEnergy = energy*shape.getEnergyFraction(stepIndex);
	    int _nSpots = _stepEnergy/spotEnergy + 1;
	    double _spotEnergy = _stepEnergy/_nSpots;
	    for(unsigned spotIndex = 0;spotIndex<_nSpots;spotIndex++){
		shape.generateSpot(stepIndex,random,radius,phi);
		hist_longProfile->Fill(shape.getStep(stepIndex).depth+shape.getStep(stepIndex).size/2,_spotEnergy);
		hist_transProfile->Fill(radius,_spotEnergy);
	    }
	}
    }

    std::cout << "finalizing..." << std::endl;
    oFile->Write();
    oFile->Close();
    delete oFile;
}
