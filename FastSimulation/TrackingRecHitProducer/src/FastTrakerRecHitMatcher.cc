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

    //loop over rechits in track
    unsigned recHitIndex = 0;
    for (auto rit = recHits.begin();
	 rit!=recHits.end();
	 ++rit,recHitIndex++){

	DetId detid = rit->geographicalId();
	unsigned int subdet = detid.subdetId();

	// for pixel hits
	if(subdet <= 2){ 
	    matchedRecHits.push_back( rit->clone() );
	}
	else{

	    StripSubdetector specDetId=StripSubdetector(detid);
	    // for regular strip hits
	    if(!specDetId.glued()){ 
		matchedRecHits.push_back( rit->clone() );
	    }
	    // for strip hits on glued layers
	    else{ 
	    
		// get the track direction from the simhit
		LocalVector simtrackdir = simHits[rit->simHitId()].localDirection();	    

		const GluedGeomDet* gluedDet = (const GluedGeomDet*)geometry.idToDet(DetId(specDetId.glued()));
		const StripGeomDetUnit* stripdet =(StripGeomDetUnit*) gluedDet->stereoDet();
	  
		// global direction of track
		GlobalVector globaldir= stripdet->surface().toGlobal(simtrackdir);
		LocalVector gluedsimtrackdir=gluedDet->surface().toLocal(globaldir);

		// check whether next hit is list is partner
		FastSingleTrackerRecHitCombination::const_iterator partner = rit;
		partner++;
		if( partner != recHits.end() && StripSubdetector( partner->geographicalId() ).partnerDetId() == detid.rawId() )	{
		    // in case stereo hit comes before mono hit
		    // (by convention, mono hit is the most inner one)
		    if(   specDetId.stereo()  ) {
			FastMatchedTrackerRecHit theMatchedHit = match( &(*partner),  &(*rit),  gluedDet  , gluedsimtrackdir );
			theMatchedHit.setStereoLayerFirst();
		    }
		    // in case mono hit comes before stereo hit
		    else{
			FastMatchedTrackerRecHit theMatchedHit = match( &(*rit),  &(*partner),  gluedDet  , gluedsimtrackdir );
		    }
		    // skip the partner in the loop over recHits
		    ++rit,recHitIndex++;
		}
		else{
		    // in case no partner is found, project
		    FastProjectedTrackerRecHit theProjectedHit = projectOnly( &(*rit), geometry.idToDet(detid),gluedDet, gluedsimtrackdir  );
		    matchedRecHits.push_back( theProjectedHit );
		}
	    }
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

