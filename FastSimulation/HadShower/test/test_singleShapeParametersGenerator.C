#include "FastSimulation/HadShower/interface/Parameters.h"
#include "FastSimulation/HadShower/interface/SingleShapeParametersGenerator.h"
#include "FastSimulation/HadShower/interface/SingleShapeParameters.h"

#include "TFile.h"
#include "TH1D.h"
#include "CLHEP/Random/JamesRandom.h"

using namespace hadshower;

int main(){
    
    std::cout << "initializing..." << std::endl;

    double energy = 10;
    CLHEP::HepJamesRandom random;
    Parameters parameters;
    SingleShapeParametersGenerator singleShapeParametersGenerator(parameters);
    
    TFile * oFile = TFile::Open("test_singleShapeParameters.root","RECREATE");
    oFile->cd();
    TH1D * h_alphaEM = new TH1D("alphaEM","alphaEM",100,0,3);
    TH1D * h_betaEM = new TH1D("betaEM","betaEM",100,0,3);

    std::cout << "generating..." << std::endl;

    unsigned nShowers = 100;
    for(unsigned i = 0;i<nShowers;i++){
	auto singleShapeParameters = singleShapeParametersGenerator.generate(energy,random);
	h_alphaEM->Fill(singleShapeParameters->alphaEM);
	h_betaEM->Fill(singleShapeParameters->betaEM);
    }

    std::cout << "finalizing..." << std::endl;

    oFile->Write();
    oFile->Close();
    delete oFile;

}
