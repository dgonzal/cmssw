#include "FastSimulation/TrackingRecHitProducer/interface/FastTrackerRecHitMatcher.h"

#include "DataFormats/DetId/interface/DetId.h"
#include "Geometry/CommonDetUnit/interface/GeomDetUnit.h"
#include "Geometry/CommonTopologies/interface/StripTopology.h"
#include "Geometry/TrackerGeometryBuilder/interface/GluedGeomDet.h"
#include "DataFormats/TrackerRecHit2D/interface/FastMatchedTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/FastProjectedTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/FastSingleTrackerRecHit.h"
#include "DataFormats/SiStripDetId/interface/StripSubdetector.h"
#include "Geometry/TrackerGeometryBuilder/interface/StripGeomDetUnit.h"
#include <cfloat>


void FastTrackerRecHitMatcher::match(  const FastSingleTrackerRecHitCombination & recHits, 
				       const edm::PSimHitContainer & simHits,
				       const TrackerGeometry & geometry,
				       FastTrackerRecHitCombination & matchedRecHits){

    FastSingleTrackerRecHitCombination::const_iterator rit = recHits.begin();
    FastSingleTrackerRecHitCombination::const_iterator firstRecHit = recHits.begin();
    FastSingleTrackerRecHitCombination::const_iterator lastRecHit = recHits.end();
    
    //loop over rechits in track
    for (unsigned recHitIndex = 0;recHitIndex < recHits.size();++recHitIndex){

	const FastSingleTrackerRecHit & recHit = recHits[recHitIndex];

	DetId detid = rit->geographicalId();
	unsigned int subdet = detid.subdetId();

	if(subdet>2){

	    StripSubdetector specDetId=StripSubdetector(detid);

	    // if this is on a glued, then place only one hit in vector
	    if(specDetId.glued()){

		// get the track direction from the simhit
		LocalVector simtrackdir = simHits[recHit.simHitId()].localDirection();	    

		const GluedGeomDet* gluedDet = (const GluedGeomDet*)geometry.idToDet(DetId(specDetId.glued()));
		const StripGeomDetUnit* stripdet =(StripGeomDetUnit*) gluedDet->stereoDet();
	  
		// global direction of track
		GlobalVector globaldir= stripdet->surface().toGlobal(simtrackdir);
		LocalVector gluedsimtrackdir=gluedDet->surface().toLocal(globaldir);

		// get partner layer, it is the next one or previous one in the vector
		FastSingleTrackerRecHitCombination::const_iterator partner = rit;
		FastSingleTrackerRecHitCombination::const_iterator partnerNext = rit;
		FastSingleTrackerRecHitCombination::const_iterator partnerPrev = rit;
		partnerNext++; partnerPrev--;
	  
	  
		// check if this hit is on a stereo layer (== the second layer of a double sided module)
		if(   specDetId.stereo()  ) {
	
		    int partnersFound = 0;
		    // check next one in vector
		    // safety check first
		    if(partnerNext != recHits.end() ) 
			if( StripSubdetector( partnerNext->geographicalId() ).partnerDetId() == detid.rawId() )	{
			    partner= partnerNext;
			    partnersFound++;
			}
		    // check prevoius one in vector     
		    if( rit !=  recHits.begin()) 
			if(  StripSubdetector( partnerPrev->geographicalId() ).partnerDetId() == detid.rawId() ) {
			    partnersFound++;
			    partner= partnerPrev;
			}
	    
	    
		    // in case partner has not been found this way, need to loop over all rechits in track to be sure
		    // (rare cases fortunately)
		    if(partnersFound==0){
			for(FastSingleTrackerRecHitCombination::const_iterator iter = firstRecHit; iter != lastRecHit; ++iter  ){
			    if( StripSubdetector( iter->geographicalId() ).partnerDetId() == detid.rawId()){
				partnersFound++;
				partner = iter;
			    }
			}
		    }

		    if(partnersFound == 1) {
			FastMatchedTrackerRecHit theMatchedHit = match( &(*partner),  &(*rit),  gluedDet  , gluedsimtrackdir );
			if(partner == partnerNext)
			    theMatchedHit.setStereoLayerFirst();
			matchedRecHits.push_back( theMatchedHit );
		    } 
		    else{
			// no partner to match, place projected one in map
			FastProjectedTrackerRecHit theProjectedHit = projectOnly( &(*rit), geometry.idToDet(detid),gluedDet, gluedsimtrackdir  );
			matchedRecHits.push_back( theProjectedHit );
			//there is no partner here
		    }
		} // end if stereo
		else {   // we are on a mono layer
		    // usually this hit is already matched, but not if stereo hit is missing (rare cases)
		    // check if stereo hit is missing
		    int partnersFound = 0;
		    // check next one in vector
		    // safety check first
		    if(partnerNext != recHits.end() ) 
			if( StripSubdetector( partnerNext->geographicalId() ).partnerDetId() == detid.rawId() )	{
			    partnersFound++;
			}
		    // check prevoius one in vector     
		    if( rit !=  recHits.begin()) 
			if(  StripSubdetector( partnerPrev->geographicalId() ).partnerDetId() == detid.rawId() ) {
			    partnersFound++;
			}

		    if(partnersFound==0){ // no partner hit found this way, need to iterate over all hits to be sure (rare cases)
			for(FastSingleTrackerRecHitCombination::const_iterator iter = firstRecHit; iter != lastRecHit; ++iter  ){
			    if( StripSubdetector( iter->geographicalId() ).partnerDetId() == detid.rawId()){
				partnersFound++;
			    }
			}
		    }	    
	    
	    
		    if(partnersFound==0){ // no partner hit found 
			// no partner to match, place projected one one in map
			FastProjectedTrackerRecHit theProjectedHit = 
			    projectOnly( &(*rit), geometry.idToDet(detid),gluedDet, gluedsimtrackdir  );
			matchedRecHits.push_back( theProjectedHit );
		    }	    
		} // end we are on a a mono layer
	    } // end if glued 
	    else{ 
		matchedRecHits.push_back( *rit ); // if not glued place the original one in vector 
	    }
	
	}// end if strip
	else {

	    matchedRecHits.push_back( *rit );  // if not strip place the original one in vector
	}
      
    } // end loop over rechits
    
}





FastMatchedTrackerRecHit FastTrackerRecHitMatcher::match(const FastSingleTrackerRecHit *monoRH,
							 const FastSingleTrackerRecHit *stereoRH,
							 const GluedGeomDet* gluedDet,
							 LocalVector& trackdirection) const
{


    // stripdet = mono
    // partnerstripdet = stereo
    const GeomDetUnit* stripdet = gluedDet->monoDet();
    const GeomDetUnit* partnerstripdet = gluedDet->stereoDet();
    const StripTopology& topol=(const StripTopology&)stripdet->topology();

    LocalPoint position;    

    // position of the initial and final point of the strip (RPHI cluster) in local strip coordinates
    MeasurementPoint RPHIpoint=topol.measurementPosition(monoRH->localPosition());
    MeasurementPoint RPHIpointini=MeasurementPoint(RPHIpoint.x(),-0.5);
    MeasurementPoint RPHIpointend=MeasurementPoint(RPHIpoint.x(),0.5);
  
    // position of the initial and final point of the strip in local coordinates (mono det)
    StripPosition stripmono=StripPosition(topol.localPosition(RPHIpointini),topol.localPosition(RPHIpointend));

    if(trackdirection.mag2()<FLT_MIN){// in case of no track hypothesis assume a track from the origin through the center of the strip
	LocalPoint lcenterofstrip=monoRH->localPosition();
	GlobalPoint gcenterofstrip=(stripdet->surface()).toGlobal(lcenterofstrip);
	GlobalVector gtrackdirection=gcenterofstrip-GlobalPoint(0,0,0);
	trackdirection=(gluedDet->surface()).toLocal(gtrackdirection);
    }
 
    //project mono hit on glued det
    StripPosition projectedstripmono=project(stripdet,gluedDet,stripmono,trackdirection);
    const StripTopology& partnertopol=(const StripTopology&)partnerstripdet->topology();

    //error calculation (the part that depends on mono RH only)
    LocalVector  RPHIpositiononGluedendvector=projectedstripmono.second-projectedstripmono.first;
    double c1=sin(RPHIpositiononGluedendvector.phi()); 
    double s1=-cos(RPHIpositiononGluedendvector.phi());
    MeasurementError errormonoRH=topol.measurementError(monoRH->localPosition(),monoRH->localPositionError());
    double pitch=topol.localPitch(monoRH->localPosition());
    double sigmap12=errormonoRH.uu()*pitch*pitch;

    // position of the initial and final point of the strip (STEREO cluster)
    MeasurementPoint STEREOpoint=partnertopol.measurementPosition(stereoRH->localPosition());

    MeasurementPoint STEREOpointini=MeasurementPoint(STEREOpoint.x(),-0.5);
    MeasurementPoint STEREOpointend=MeasurementPoint(STEREOpoint.x(),0.5);

    // position of the initial and final point of the strip in local coordinates (stereo det)
    StripPosition stripstereo(partnertopol.localPosition(STEREOpointini),partnertopol.localPosition(STEREOpointend));

    //project stereo hit on glued det
    StripPosition projectedstripstereo=project(partnerstripdet,gluedDet,stripstereo,trackdirection);

    //perform the matching
    //(x2-x1)(y-y1)=(y2-y1)(x-x1)
    AlgebraicMatrix22 m; AlgebraicVector2 c, solution;
    m(0,0)=-(projectedstripmono.second.y()-projectedstripmono.first.y()); m(0,1)=(projectedstripmono.second.x()-projectedstripmono.first.x());
    m(1,0)=-(projectedstripstereo.second.y()-projectedstripstereo.first.y()); m(1,1)=(projectedstripstereo.second.x()-projectedstripstereo.first.x());
    c(0)=m(0,1)*projectedstripmono.first.y()+m(0,0)*projectedstripmono.first.x();
    c(1)=m(1,1)*projectedstripstereo.first.y()+m(1,0)*projectedstripstereo.first.x();
    m.Invert(); solution = m * c;
    position=LocalPoint(solution(0),solution(1));


    //
    // temporary fix by tommaso
    //


    LocalError tempError (100,0,100);

    // calculate the error
    LocalVector  stereopositiononGluedendvector=projectedstripstereo.second-projectedstripstereo.first;
    double c2=sin(stereopositiononGluedendvector.phi()); double s2=-cos(stereopositiononGluedendvector.phi());
    MeasurementError errorstereoRH=partnertopol.measurementError(stereoRH->localPosition(), stereoRH->localPositionError());
    pitch=partnertopol.localPitch(stereoRH->localPosition());
    double sigmap22=errorstereoRH.uu()*pitch*pitch;
    double diff=(c1*s2-c2*s1);
    double invdet2=1/(diff*diff);
    float xx=invdet2*(sigmap12*s2*s2+sigmap22*s1*s1);
    float xy=-invdet2*(sigmap12*c2*s2+sigmap22*c1*s1);
    float yy=invdet2*(sigmap12*c2*c2+sigmap22*c1*c1);
    LocalError error=LocalError(xx,xy,yy);

    //Added by DAO to make sure y positions are zero.
    DetId det(monoRH->geographicalId());
    if(det.subdetId() > 2) {
    
	FastMatchedTrackerRecHit rV(position, error, *gluedDet, *monoRH, *stereoRH);
	return rV;
    }
  
    else {
	throw cms::Exception("FastTrackerRecHitMatcher") << "Matched Pixel!?";
    }
}


FastTrackerRecHitMatcher::StripPosition 
    FastTrackerRecHitMatcher::project(const GeomDetUnit *det,
				      const GluedGeomDet* glueddet,
				      const StripPosition& strip,
				      const LocalVector& trackdirection)const
{

    GlobalPoint globalpointini=(det->surface()).toGlobal(strip.first);
    GlobalPoint globalpointend=(det->surface()).toGlobal(strip.second);

    // position of the initial and final point of the strip in glued local coordinates
    LocalPoint positiononGluedini=(glueddet->surface()).toLocal(globalpointini);
    LocalPoint positiononGluedend=(glueddet->surface()).toLocal(globalpointend);

    //correct the position with the track direction

    float scale=-positiononGluedini.z()/trackdirection.z();

    LocalPoint projpositiononGluedini= positiononGluedini + scale*trackdirection;
    LocalPoint projpositiononGluedend= positiononGluedend + scale*trackdirection;

    return StripPosition(projpositiononGluedini,projpositiononGluedend);
}



FastProjectedTrackerRecHit FastTrackerRecHitMatcher::projectOnly( const FastSingleTrackerRecHit *originalRH,
								  const GeomDet * monoDet,
								  const GluedGeomDet* gluedDet,
								  LocalVector& ldir) const
{
    LocalPoint position(originalRH->localPosition().x(), 0.,0.);
    const BoundPlane& gluedPlane = gluedDet->surface();
    const BoundPlane& hitPlane = monoDet->surface();

    double delta = gluedPlane.localZ( hitPlane.position());

    LocalPoint lhitPos = gluedPlane.toLocal( monoDet->surface().toGlobal(position ) );
    LocalPoint projectedHitPos = lhitPos - ldir * delta/ldir.z();

    LocalVector hitXAxis = gluedPlane.toLocal( hitPlane.toGlobal( LocalVector(1,0,0)));
    LocalError hitErr = originalRH->localPositionError();

    if (gluedPlane.normalVector().dot( hitPlane.normalVector()) < 0) {
	// the two planes are inverted, and the correlation element must change sign
	hitErr = LocalError( hitErr.xx(), -hitErr.xy(), hitErr.yy());
    }
    LocalError rotatedError = hitErr.rotate( hitXAxis.x(), hitXAxis.y());
  
  
    const GeomDetUnit *gluedMonoDet = gluedDet->monoDet();
    const GeomDetUnit *gluedStereoDet = gluedDet->stereoDet();
    int isMono = 0;
    int isStereo = 0;
  
    if(monoDet->geographicalId()==gluedMonoDet->geographicalId()) isMono = 1;
    if(monoDet->geographicalId()==gluedStereoDet->geographicalId()) isStereo = 1;
    //Added by DAO to make sure y positions are zero and correct Mono or stereo Det is filled.
  
    if ((isMono && isStereo)||(!isMono&&!isStereo)) throw cms::Exception("FastTrackerRecHitMatcher") << "Something wrong with DetIds.";
    FastProjectedTrackerRecHit rV(projectedHitPos, rotatedError, *gluedDet, *originalRH);
    return rV;
}

