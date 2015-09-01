// -*- C++ -*-
//
// Package:    FedericoTest/ReadPFFlowCollection
// Class:      ReadPFFlowCollection
// 
/**\class ReadPFFlowCollection ReadPFFlowCollection.cc FedericoTest/ReadPFFlowCollection/plugins/ReadPFFlowCollection.cc

   Description: [one line class summary]

   Implementation:
   [Notes on implementation]
*/
//
// Original Author:  Lukas Vanelderen
//         Created:  Tue, 01 Sep 2015 08:54:44 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class ReadPFFlowCollection : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
    public:
    explicit ReadPFFlowCollection(const edm::ParameterSet&);
    ~ReadPFFlowCollection();

    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


    private:
    virtual void beginJob() override;
    virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
    virtual void endJob() override;

    // !! a typedef to make life easy
    typedef std::vector<edm::FwdPtr<reco::PFCandidate> > PFCollection;
    // !! create a token for the particle flow candidates
    edm::EDGetTokenT<PFCollection> pfCollectionToken;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
ReadPFFlowCollection::ReadPFFlowCollection(const edm::ParameterSet& iConfig) 
    // !! initialise the token
    : pfCollectionToken(consumes<PFCollection>(edm::InputTag("particleFlowPtrs")))    
{
    //now do what ever initialization is needed
    
}


ReadPFFlowCollection::~ReadPFFlowCollection()
{
 
    // do anything here that needs to be done at desctruction time
    // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
    ReadPFFlowCollection::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;

    // !! retrieve the collection
    edm::Handle<PFCollection> pfCollection;
    iEvent.getByToken(pfCollectionToken,pfCollection);

    // !! loop over the collection, and count the number of charged and neutral hadrons
    unsigned int nChargedHadrons = 0;
    unsigned int nNeutralHadrons = 0;
    for(const auto & pfPart : *pfCollection){
	// http://cmslxr.fnal.gov/lxr/source/DataFormats/ParticleFlowCandidate/interface/PFCandidate.h?v=CMSSW_7_6_X_2015-08-30-2300#0044
	if(pfPart->particleId() == reco::PFCandidate::h)
	    nChargedHadrons += 1;
	else if(pfPart->particleId() == reco::PFCandidate::h0)
	    nNeutralHadrons += 1;
    }
    std::cout << "counted: " << nChargedHadrons << " " << nNeutralHadrons << std::endl;

}


// ------------ method called once each job just before starting event loop  ------------
void 
    ReadPFFlowCollection::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
    ReadPFFlowCollection::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
    ReadPFFlowCollection::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
    //The following says we do not know what parameters are allowed so do no validation
    // Please change this to state exactly what you do use, even if it is no parameters
    edm::ParameterSetDescription desc;
    desc.setUnknown();
    descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ReadPFFlowCollection);
