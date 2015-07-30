/**
 * base class for FastSim tracker RecHit containers
 * it inherits from BaseTrackerRecHit
 * and adds all the special FastSim features required to 
 * - perform truth matching,
 * - duplicate track removal
 * - fast tracking emulation
 */

#ifndef FastTrackerRecHit_H
#define FastTrackerRecHit_H

#include "DataFormats/TrackerRecHit2D/interface/BaseTrackerRecHit.h"
#include "stdint.h"

namespace fastTrackerRecHitType {
    enum HitType {
	siPixel = 0,
	siStrip1D = 1,
	siStrip2D = 2,
	siStripMatched2D = 3,
	siStripProjectedMono2D = 4,
	siStripProjectedStereo2D = 5,
    };
    inline trackerHitRTTI::RTTI rtti(HitType hitType){
	if(hitType >=0 || hitType <= 2) return trackerHitRTTI::fastSingle;
	else if(hitType == siStripMatched2D) return trackerHitRTTI::fastMatch;
	else if(hitType == siStripProjectedMono2D) return trackerHitRTTI::fastProjMono;
	else if(hitType == siStripProjectedStereo2D) return trackerHitRTTI::fastProjStereo;
    }
    inline bool is2D(HitType hitType) {return hitType != siStrip1D;}
    inline bool isPixel(HitType hitType) {return hitType == siPixel;}
}


class FastTrackerRecHit : public BaseTrackerRecHit 
{
    public:

    /// default constructor
    /// 
    FastTrackerRecHit()
	: BaseTrackerRecHit()
	, hitCombinationId_(-1)
	, isPixel_(false)
	, is2D_(true)
	{}
    
    /// destructor
    ///
    ~FastTrackerRecHit() {}
    
    /// constructor
    /// requires a position with error in local detector coordinates,
    /// the detector id, and type information (rt)
    FastTrackerRecHit( const LocalPoint& p, const LocalError&e, GeomDet const & idet,fastTrackerRecHitType::HitType hitType) 
	: BaseTrackerRecHit(p,e,idet,fastTrackerRecHitType::rtti(hitType)) 
	, hitCombinationId_(-1)
	, isPixel_(fastTrackerRecHitType::isPixel(hitType))
	, is2D_(fastTrackerRecHitType::is2D(hitType))
	{store();}

    virtual FastTrackerRecHit * clone() const {FastTrackerRecHit * p =  new FastTrackerRecHit( * this); p->load(); return p;}

    /// Steers behaviour of hit in track fit.
    /// Hit is interpreted as 1D or 2D depending on value of is2D_
    void getKfComponents( KfComponentsHolder & holder ) const GCC11_OVERRIDE { if(is2D_) getKfComponents2D(holder); else getKfComponents1D(holder);}

    /// Steers behaviour of hit in track fit.
    /// Hit is interpreted as 1D or 2D depending on value of is2D_
    int dimension() const GCC11_OVERRIDE {return is2D_ ? 2 : 1;} ///< get the dimensions right

    /// Steers behaviour of hit in track fit.
    /// FastSim hit smearing assumes
    virtual bool canImproveWithTrack() const {return false;}

    /* getters */

    virtual size_t               nIds()                        const { return 0;}
    virtual int32_t              id(size_t i = 0)              const { return -1;}
    virtual int32_t              eventId(size_t i = 0)         const { return -1;}
    
    int32_t                      hitCombinationId()            const { return hitCombinationId_;}    ///< see setHitCombinationId(int32_t hitCombinationId)
    virtual size_t               nSimTrackIds()                const { return 0;}                    ///< see FastSingleTrackerRecHit::addSimTrackId(int32_t simTrackId)
    virtual int32_t              simTrackId(size_t i)          const { return -1;}                   ///< see FastSingleTrackerRecHit::addSimTrackId(int32_t simTrackId)
    virtual int32_t              simTrackEventId(size_t i)     const { return -1;}                   ///< see FastSingleTrackerRecHit::addSimTrackId(int32_t simTrackId)
    bool isPixel() const GCC11_OVERRIDE {return isPixel_;} ///< pixel or strip?

    /* setters */

    /// set the id number for the hit combination to which the hit belongs
    /// the hit combination id number is the index of the combination in the FastTrackerRecHitCombinations list
    virtual void setHitCombinationId(int32_t hitCombinationId) {hitCombinationId_ = hitCombinationId;}

    virtual void setEventId(int32_t eventId) {};

    void set2D(bool is2D=true){is2D_ = is2D;}

    /// bogus function : 
    /// implement purely virtual function of TrackingRecHit
    virtual std::vector<const TrackingRecHit*> recHits() const { return std::vector<TrackingRecHit const*>();}

    /// bogus function : 
    /// implement purely virtual function of TrackingRecHit
    virtual std::vector<TrackingRecHit*> recHits()  { return std::vector<TrackingRecHit*>();}
 
    /// bogus function : 
    /// implement purely virutal function of BaseTrackerRecHit
    OmniClusterRef const & firstClusterRef() const;

    /// fastsim's way to check whether 2 single hits share sim-information or not
    /// hits are considered to share sim-information if 
    /// - they have the same hit id number
    /// - they have the same event id number
    // used by functions
    // - FastTrackerSingleRecHit::sharesInput 
    // - FastSiStripMatchedRecHit::sharesInput
    // - FastProjectedSiStripRecHit2D::sharesInput
    bool sameId(const FastTrackerRecHit * other,size_t i=0) const {return id(i) == other->id(i) && eventId(i) == other->eventId(i);}
    bool sharesInput(const TrackingRecHit * other,SharedInputType what) const;

    protected:

    int32_t hitCombinationId_;           ///< see setHitCombinationId(int32_t hitCombinationId)
    const bool isPixel_;                 ///< hit is either on pixel modul (isPixel_ = true) or strip module (isPixel_ = false)
    bool is2D_;                          ///< hit is either one dimensional (is2D_ = false) or two dimensions (is2D_ = true)

    LocalPoint m_myPos;                  ///< helps making the hit postion and error persistent
    LocalError m_myErr;                  ///< helps making the hit postion and error persistent

    void store() { m_myPos=pos_;  m_myErr=err_;}  ///< helps making the hit postion and error persistent
    void load()  { pos_=m_myPos; err_=m_myErr;}   ///< helps making the hit postion and error persistent
  
};

/// Comparison operator
///
inline bool operator<( const FastTrackerRecHit& one, const FastTrackerRecHit& other) {
    return ( one.geographicalId() < other.geographicalId() );
}

#endif
