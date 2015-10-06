#include "FastSimulation/HadShower/interface/StartGenerator.h"
#include "TH1D.h"
#include "TFile.h"
#include "CLHEP/Random/JamesRandom.h"

int main(){

    std::cout << "initializing..." << std::endl;
    CLHEP::HepJamesRandom random;
    hadshower::StartGenerator showerStartGenerator;
    TFile * oFile = TFile::Open("testShowerStart.root","RECREATE");
    oFile->cd();
    TH1D * h1 = new TH1D("h1","h1",100,0,5);
    std::cout << "generatig..." << std::endl;
    for(int i =0;i<10000;i++){
	h1->Fill(showerStartGenerator.generate(random));
    }
    std::cout << "finalizing..." << std::endl;
    oFile->Write();
    oFile->Close();
    delete oFile;

}
