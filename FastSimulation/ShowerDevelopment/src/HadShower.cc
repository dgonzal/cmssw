
HadShower::HadShower(const RandomEngineAndDistribution* randomEngine,
			       HDShowerParametrization* parameters, 
			       EcalHitMaker* ecalHitMaker,
			       HcalHitMaker* hcalHitmaker,
			       double energy,
			       double probShowerStartsInHcal) 
    : randomEngine_(engine)
    , parameters_(parameters)
    , ecalHitMaker_(ecalHitMaker)
    , hcalHitMaker_(hcalHitMaker)
    , energy_(energy)
    , probShowerStartsInHcal_(probShowerStartsInHcal)
{

    // there are 2 sets of parameters for 2 energy ranges:
    if(energy_ < parameters_->emid())
	parameters_->setCase(1);
    else
	parameters_->setCase(2);

    // step size in hcal
    hcalStepSize_intLen_ = parameters_->hsParameters()->getHDdepthStep();
    if(energy_ > parameters_->emax())
	hcalStepSize_intLen_ *= 2;
       
    // prepare to generate a shower
    calculateEnergyScale_();
    drawShowerStart_();
    initialiseSteps_();
    drawShowerShape_();
    fluctuateEcalEnergy_();
    applyLongitudinalShapeFluctuations_()
    calculateIdealEnergySpotSize_();

    // if the only step is in ECAL, increase the transverse spread
    if(steps_.size() == 1 and steps_[0].detector == ecal) steps.R50 *= 2.;

    
}

void HadShower::calculateEnergyScale(){
    
    limitedEnergy_ = energy_;
    if(limitedEnergy < parameters_->emin())
	limitedEnergy = paramers_->emin();
    else if(limitedEnergy > parameters->emax())
	limitedEnergy = parameters_->emax();
    logLimitedEnergy_ = std::log(limitedEnergy_);
    // most parameters are assumed to be linear functions of the following energy-dependent variable
    energyScale_ = std::log((parameters_->e1() + std::logLimitedEnergy_*parameters)*limitedEnergy_);

}

double HadShower::drawShowerStart(){
    
    // exponential distribution, reduces with 1/e per unit length (=nominal interaction lenght)
    showerStart_z = std::log(1./random->flatShoot());
    
    // if the fraction of showers that start in HCAL is 1, let the shower start at the HCAL entrance
    // TODO: it probably doesn't make sense to let these showers start at the hcal entrance
    //       these are particles with a long interaction length, so probably they start showering late in HCAL
    if (fractionShowerStartsInHCAL==1) {
	showerStart_z = ecal_dz + gap_dz;
    }
    // else, enforce the right fraction of showers starting in HCAL by changing the slope of the exponential
    // TODO: why the 0.9? consider applying these factors right away when showerStart_z is initialised
    else{
	showerStart_z=showerStart_z*0.9*ecal_dz/std::log(1./probShowerStartsInHCAL);
    }

    // let the shower start at the calorimeter entrance if the energy is outside the energy range of the parameterisation
    // TODO: perhaps better to leave the showerStart_z unchanged (in fact, low energy hadrons are much more likely to start showering late
    if(energy < emin) {
	showerStart_z = 0.;
    }

    // if the shower starts to deep, take a different starting point, uniformely distributed in the allowed range
    // TODO: uniform distribution makes no sense, perhaps better to make no shower at all in this case
    double max_z = ecal_dz_intLen + gap_dz_intLen + hcal_dz_intLen - 1.1 * hcalStepSize_intLen;
    if(showerStart_z > max_z) {
	showerStart_z = max_z *  random->flatShoot();
    }

    // if particle energy < 10 GeV and shower starts in first 80% of ECAL,
    // move to random place in firts half of ECAL
    // TODO: why is this? smells like a mistake
    if(onECAL && energy < emid) { // emid = 10 GeV see HDShowerParametrization.h
	if(ecal_dz > hcalStepSize_intLen && (ecal_dz - showerStart_z)/ecal_dz > 0.2) {
	    showerStart_z = 0.5 * ecal_dz * random->flatShoot();
	}
    }
    
    // TODO: when is this ever true? and why is the start set to 0?
    if(depthHCAL < step_dz){ 
	showerStart_z = 0;
    }

    if(showerStart_z < ecal_dz){
	// If shower starts in last 10% of ECAL, 
	// or if ECAL is very thin postonpone to HCAL entrance
	if(ecal_dz > depthStep || showerStart_z/ecal_dz > 0.9){
	    showerStart_z = ecal_dz + gap_dz;
	}
    }
    // If shower starts in gap between ecal and hcal, postpone to HCAL entrance
    else if(showerStart_z < ecal_dz + gap_dz){
	showerStart_z = ecal_dz + gap_dz;
    }

    if(ecal_dz_intLen < hcalStepSize_intLen && hcal_dz_intLen < hcalStepSize_intLen){
	showerStart_z_intLen = ecal_dz_intLen + gap_dz_intLen + hcal_dz_intLen;
	return;
    }
}

void HadShower::drawShowerShape(){

    // set the shower shape parameters
    showerShapeParameters_.alphaEM = parameters_->alpe1() + energyScale_ * parameters->alpe2();
    showerShapeParameters_.betaEM = parameters_->bete1() + energyScale_ * parameters->bete2();
    showerShapeParameters_.alphaHad = parameters_->alph1() + energyScale_ * parameters->alph2();
    showerShapeParameters_.betaHad = parameters_->beth1() + energyScale_ * parameters->beth2();
    showerShapeParameters_.pi0fraction = parameters_->part1() + energyScale_ * parameters->part2();
    if(showerShapeParameters_.pi0fraction > 1.)
	showerShapeParameters_.pi0fraction = 1.;
    showerShapeParameters_.R1 = parameters_->part2();
    showerShapeParameters_.R2prime = theParam->r2() + theParam->r3()*logLimitedEnergy_;

    // TODO: improve model for transverse and longitudinal shape fluctuations
    double transShapeFluctuationFactor_ = myParam->hsParameters()->getHDtransParam()*(1. + random->floatShoot());

    // apply transverse shape fluctuations
    showerShapeParameters_.R1 *= transShapeFluctuationFactor_;
    showerShapeParameters_.R2prime *= transShapeFluctuationFactor_;

    // and initialise the shower shape
    showerShape_.reset(new HadShowerShape(showerShapeParameters_,steps_));
    
    // TODO : original HD shower has a line that excludes steps with too little energy
    //        if(nPest <= 1 && count !=0 ) break;
    //        I don't get the logic, so I skip it
    //        might be worth investigating

}

void HadShower::fluctuateEcalEnergy(){

    double stepEnergySum = 0;
    double oldEcalEnergy = 0;
    double ecalEnergy = 0;
    
    // fluctuate ecal energy
    double ecalEnergyFactor = 2. * parameters->hsParameters()->getHDbalanceEH() * randomEngine->flatShoot();
    for(auto & step : steps_){
	stepEnergySum += step.energy;
	if(step.detector == ecal){
	    oldEcalEnergy += step.energy;
	    step.energy *= ecalEnergyFactor;
	    newEcalEnergy += step.energy;
	}
    }

    // rebalance energy
    double hcalEnergyFactor = (stepEnergySum - newEcalEnergy) / (stepEnergySum - oldEcalEnergy);
    for(auto & step : steps_){
	if(step.detector == hcal)
	    step.energy *= hcalEnergyFactor;
    }

}


void HadShower::normaliseEnergy(){

    double stepEnergySum = 0;
    for(auto & step : steps_){
	stepEnergySum += step.energy;
    }
    double normFactor = 1. / stepEnergySum;
    for(auto & step : steps_){
	step.energy *= normFactor;
    }
}


void HadShower::initialiseSteps(){

    // TODO: not sure if I need step depth and size in cm

    // ECAL is one step
    if(showerStart_z_ < ecal_dz){

	double hcalIntLen_cm = theParam->ecalProperties()->interactionLength();
	double hcalRadLen_cm = theParam->ecalProperties()->radLenInCm();

	steps_.push_back(HadShowerStep());
	HadShowerStep & step = steps.back();

	step.detector = ecal;
	step.size_intLen = ecal_dz - showerStart_z;
	step.size_cm = step.size_intLen*EcalIntLen_cm;
	step.size_radLen = step.size_cm/EcalRadLen_cm;
	step.depth_intLen = step.size_intLen * 0.5;
	step.depth_cm = step.size_cm * 0.5;
	step.depth_radLen = step.size_radLen * 0.5;
    }

    // n steps in hcal
    unsigned nHcalSteps = myParam->hsParameters()->getHDnDepthSteps();
    if(hcal_dz < hcalStepSize)
	nHcalSteps = 0;
    else if(energy_ < myParam->hsParameters()->getHDcriticalEnergy())
	nHcalSteps = 1;


    // number of steps in hcal
    int nHcalSteps = hdParam->hsParameters()->getHDnDepthSteps();
    if(energy < hdParam->hsParameters()->getHDcriticalEnergy()){
	nHcalSteps = 1;
    }
    // if hcal is too thin, skip it
    if(hcal_dz < step_dz){
	nHcalSteps = 0;
    }
    
    // create hcal steps
    double hcalIntLen_cm = theParam->hcalProperties()->interactionLength();
    double hcalRadLen_cm = theParam->hcalProperties()->radLenInCm();
    for (int i = 0; i < nHcalSteps ; i++) {

	steps_.push_back(HaDShowerStep());
	HaDShowerStep &step = steps.back();

	step.detector = hcal;
	step.caloProperties = hdShowerParam->hcalProperTies();
	step.size_intLen = hcalStepSize;
	step.size_cm = step.size_intLen*hcalIntLen_cm;
	step.size_radLen = step.size_cm/hcalRadLen_cm;
	if(steps_.size() > 1 ){   // if this is the first step
	    step.depth_intLen = step.size_intLen * 0.5;
	    step.depth_cm = step.size_cm * 0.5;
	    step.depth_radLen = step.size_radLen * 0.5;
	}
	else {                    
	    HDShowerStep & previousStep = steps_[steps_.size()-2];
	    if(previousStep.detector = ecal){ // if the previous step was in ecal
		step.depth_intLen = ecal_dz_intLen + gap_dz_intLen + step.size_intLen * 0.5;
		step.depth_cm = ecal_dz_cm + gap_dz_cm + step.size_cm * 0.5;
		step.depth_cm = ecal_dz_radLen + gap_dz_radLen + step.size_radLen * 0.5;
	    }
	    else{ // 'normal' hcal stpes
		step.depth_intLen = previousStep.depth_intLen + (previousStep.size_intLen + step.size_intLen) * 0.5;
		step.depth_cm = previousStep.depth_cm + (previousStep.size_cm + step.size_cm) * 0.5;
		step.depth_radLen = previousStep.depth_radLen + (previousStep.size_radLen + step.size_radLen) * 0.5;
	    }
	}
	// outer edge of the step is required to be inside the calorimeter volume
	if(showerStart_z_intLen_ + step.depth_intLen + step.size_intLen * 0.5 > total_dz_intLen_){
	    steps_.pop_back();
	    break;
	}
    }
}

void HadShower::applyLongitudinalShapeFluctuations(){
    double hcalDepthFactor = parameters_->hsParameters()->getHDhcalDepthFactor() +
	0.05 * (2.* random->flatShoot() - 1.);
    for(auto & step : steps){
	if(step.detector == hcal){
	    step.depth_intLen *= hcalDepthFactor;
	    step.depth_cm *= hcalDepthFactor;
	    step.depth_radLen *= hcalDepthFactor;
	}
    }
}

void HadShower::calculateIdealEnergySpotSize(){
    // note: for each step,the size of the spots is changed
    // such that an integer number of spots makes up the energy of the step
    idealEnergySpotSize_ = parameters_->hsParameters()->getHDeSpotSize();
    if(energy_ > 0.5 * parameters_->emax()){
	idealEnergySpotSize_ *= 2.5;
	if(energy_ > parameters_->emax()){
	    idealEnergySpotSize *= 4;
	}
    }
}

void HadShower::compute() const{

    for(int stepIndex = 0,nSteps = steps_size();stepIndex < nSteps;stepIndex++){
	
	const auto & step = steps_[stepIndex];

	if(step.detector == ecal){

	    // set the z coordinates of the spots
	    if(!ecalHitMaker->getPads(showerStart_z_intLen + step.depth_intLen)){
		continue;
	    }

	    // set spot energy
	    // TODO: this is different in original HDShower
	    //       I (lukas vanelderen) can't make much sense of it, so I implement it how I think it was intended to be
	    double stepEnergy = step.energyFraction * energy_;
	    unsigned nSpots = ( stepEnergy / idealSpotEnergy + 1 ) * 10;
	    double spotEnergy = stepEnergy / nSpots;
	    if(nSpots >  maxNTrials){
		nSpots  = maxNTrials;
		spotEnergy = stepEnergy / nSpots;
	    }
	    ecalHitMaker_->setSpotEnergy(espot);

	    // how many trails allowed?
	    int nTrials = maxNTrails;
	    if(myParam->hsParameters()->getHDlossesOpt()){
		nTrails = nSpots;
	    }

	    // generate radius and phi coordinates
	    double radius,phi;
	    for(unsigned spotIndex = 0,trialIndex = 0; trialIndex < nTrials && spotInex < nSpots ; trialIndex ++){
		showerShape_.generateSpot(stepIndex,randomEngine.engine(),radius,phi);
		if( ecalHitMaker->addHit(radius,phi,0) ){
		    spotIndex++;
		}
	    }
	    
	}
	else{
	    
	    // set the z coordinates of the spots
	    if(!hcalHitMaker->setDepth(step.depth_intLen)){
		if(!hcalHitMaker->setDepth(step.depth_intLen - step.size_intLen))
		    continue;
	    }

	    // set spot energy
	    double stepEnergy = step.energyFraction * energy_;
	    int nSpots = stepEnergy/idealSpotEnergy + 1;
	    if(nSpots > maxNTrails)  // this safety was not in HDShower
		nSpots = maxNTrails;
	    double spotEnergy = stepEnergy / nSpots;
	    hcalHitMaker->setSpotEnergy(spotEnergy);
	    
	    // how many trails allowed?
	    int nTrials = maxNTrails;
	    if(myParam->hsParameters()->getHDlossesOpt()){
		nTrails = nSpots;
	    }

	    // generate radius and phi coordinates
	    double radius,phi;
	    ungined spot = 0;
	    for(unsigned spotIndex = 0,trialIndex = 0; trialIndex < maxTrials && spotInex < nSpots ; trialIndex ++){
		showerShape_.generateSpot(stepIndex,randomEngine.engine(),radius,phi);
		if( hcalHitMaker->addHit(radius,phi,0) ){
		    spotIndex++;
		}
	    }
	    
	}
    }
}
