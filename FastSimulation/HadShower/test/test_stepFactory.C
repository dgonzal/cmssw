#include "TFile.h"
#include "TF1.h"
#include "TH1F.h"

#include "CLHEP/Random/JamesRandom.h"

#include "FastSimulation/HadShower/interface/Material.h"
#include "FastSimulation/HadShower/interface/StartGenerator.h"
#include "FastSimulation/HadShower/interface/StepFactory.h"
#include "FastSimulation/HadShower/interface/Step.h"

int main(){

    std::cout << "initializing..." << std::endl;

    unsigned nShowers = 20;

    int nHcalSteps = 20;
    int nSpots = 100;
    double hcalStepSize = 0.1;

    CLHEP::HepJamesRandom random;

    TFile * ofile = TFile::Open("test_hadShowerSteps.root","RECREATE");
    ofile->cd();

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

    // generators and factories
    hadshower::StartGenerator showerStartGenerator;
    hadshower::StepFactory stepFactory;
    
    std::cout << "generating..." << std::endl;

    // model showers with a gamma function 
    TF1 * shower = new TF1("shower","TMath::Power(x,[0]-1)*TMath::Exp(-x/[1])/TMath::Power([1],[0])",0,20);
    shower->SetParameters(2,1);
    

    for(unsigned showerIndex = 0;showerIndex < nShowers;showerIndex++){

	// generate a shower start
	double showerStart_z = showerStartGenerator.generate(random);

	// create the steps
	std::unique_ptr<std::vector<hadshower::Step> > steps = stepFactory.create(showerStart_z,
										  nHcalSteps,
										  hcalStepSize,
										  ecal,gap,hcal);
	// create a histogram to store a dummy shower
	float * stepBoundaries = new float[steps->size()+1];
	for(unsigned stepIndex = 0;stepIndex < steps->size();stepIndex++){
	    stepBoundaries[stepIndex] = (*steps)[stepIndex].depth;
	}
	stepBoundaries[steps->size()] = steps->back().depth + steps->back().size;
	char name[200];
	char title[200];
	sprintf(name,"shower%d",showerIndex);
	sprintf(title,"start %f",showerStart_z);
	TH1F * hist = new TH1F(name,title,steps->size(),stepBoundaries);
	delete [] stepBoundaries;

	// generate spots from the shower and fill in histogram
	for(unsigned spotIndex = 0;spotIndex < nSpots;spotIndex++)
	    hist->Fill(shower->GetRandom());
	
	hist->Write();
	
	
    }
    
    std::cout << "finalizing..." << std::endl;

    ofile->Close();
    delete ofile;

}
