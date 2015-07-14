/**
 * base class for FastSim tracker RecHit containers
 * it inherits from BaseTrackerRecHit
 * and adds all the special FastSim features required to 
 * - perform truth matching,
 * - duplicate track removal
 * - fast tracking emulation
 */

#ifndef FastBaseTrackerRecHit_H
#define FastBaseTrackerRecHit_H

#include "BaseTrackerRecHit.h"
#include "stdint.h"

class FastBaseTrackerRecHit : public BaseTrackerRecHit 
{

    public:
    
    /// default constructor
    /// 
    FastBaseTrackerRecHit()
	: BaseTrackerRecHit()
	, id_(-1)
	, eeId_(0)
	, hitCombinationId_(-1)
	{}
    
    /// destructor
    ///
    ~FastBaseTrackerRecHit() {}
    
    /// constructor
    /// requires a position with error in local detector coordinates,
    /// the detector id, and type information (rt)
    FastBaseTrackerRecHit( const LocalPoint& p, const LocalError&e, GeomDet const & idet,trackerHitRTTI::RTTI rt) 
	: BaseTrackerRecHit(p,e,idet,rt) 
	, id_(-1)
	, eeId_(0)
	, hitCombinationId_(-1)
	{store();}

    virtual FastBaseTrackerRecHit * clone() const =0;
    
    /* getters */
  
    int32_t                      id()                     const { return id_;}                  ///< see setId(int32_t id)
    int32_t                      eeId()                   const { return eeId_;}                ///< see setEeId(int32_t eeId)
    int32_t                      hitCombinationId()       const { return hitCombinationId_;}    ///< see setHitCombinationId(int32_t hitCombinationId)
    const std::vector<int32_t> & simTrackIds()            const { return simTrackIds_;}         ///< see addSimTrackId(int32_t simTrackId)
    size_t                       nSimTrackIds()           const { return simTrackIds_.size();}  ///< see addSimTrackId(int32_t simTrackId)
    int32_t                      simTrackId(size_t i)     const { return i < simTrackIds_.size() ? simTrackIds_[i] : -1;}  ///< see addSimTrackId(int32_t simTrackId)

    /* setters */
  
    /// set the hit id number
    /// for any particular hit in any particular event,
    // the hit id number must be unique within the list of hits in the event
    void setId(int32_t id)            {id_ = id;}

    /// set the hit's event number
    /// there is in principle no reason to play with this variable outside the PU mixing modules
    /// see Adjuster::doTheOffset(int bunchSpace, int bcr, TrackingRecHitCollection & trackingrechits, unsigned int evtNr, int vertexOffset)
    void setEeId(int32_t eeId)        {eeId_ = eeId;}

    /// set the id number for the hit combination to which the hit belongs
    /// the hit combination id number is the index of the combination in the FastTrackerRecHitCombinations list
    void setHitCombinationId(int32_t hitCombinationId) {hitCombinationId_ = hitCombinationId;}

    /// add an id number to the list of id numbers of SimTracks from which the hit originates
    /// the SimTrack id numbers are the indices of the SimTracks in the SimTrack collection
    void addSimTrackId(int32_t simTrackId)  {simTrackIds_.push_back(simTrackId);}

    /// similar to addSimTrackId(int32_t simTrackId) 
    /// add a list of id numbers rather than a single one
    void addSimTrackIds(const std::vector<int32_t> & simTrackIds)  {simTrackIds_.insert(simTrackIds_.end(),simTrackIds.begin(),simTrackIds.end());}

    /// bogus function : 
    /// needs to be implemented to avoid a purely virtual function
    virtual std::vector<const TrackingRecHit*> recHits() const { return std::vector<TrackingRecHit const*>();}

    /// bogus function : 
    /// needs to be implemented to avoid a purely virtual function
    virtual std::vector<TrackingRecHit*> recHits()  { return std::vector<TrackingRecHit*>();}
 
    /// bogus function : 
    /// needs to be implemented to avoid a purely virtual function
    OmniClusterRef const & firstClusterRef() const;

    /// fastsim's way to check whether 2 single hits share sim-information or not
    /// hits are considered to share sim-information if 
    /// - they have the same hit id number
    /// - they have the same event id number
    // used by functions
    // - FastTrackerSingleRecHit::sharesInput 
    // - FastSiStripMatchedRecHit::sharesInput
    // - FastProjectedSiStripRecHit2D::sharesInput
    virtual bool hasEqualOrigin(const FastBaseTrackerRecHit & other) const {return id_ == other.id_ && eeId_ == other.eeId_;}

    // fastsim hits cannot improve with track
    //
    virtual bool canImproveWithTrack() const {return false;}

    private:

    virtual TrackingRecHit * clone(const TkCloner&, const TrajectoryStateOnSurface&) const { return clone();} ///< need this one?

    protected:

    int32_t id_;                         ///< see setId(int32_t id)
    int32_t eeId_;                       ///< see setEeId(int32_t eeid)
    int32_t hitCombinationId_;           ///< see setHitCombinationId(int32_t hitCombinationId)
    std::vector<int32_t> simTrackIds_;   ///< see addSimTrackIds(int32_t)

    LocalPoint m_myPos;                  ///< helps making the hit postion and error persistent
    LocalError m_myErr;                  ///< helps making the hit postion and error persistent

    void store() { m_myPos=pos_;  m_myErr=err_;}  ///< helps making the hit postion and error persistent
    void load()  { pos_=m_myPos; err_=m_myErr;}   ///< helps making the hit postion and error persistent
  
};

/// Comparison operator
///
inline bool operator<( const FastBaseTrackerRecHit& one, const FastBaseTrackerRecHit& other) {
    return ( one.geographicalId() < other.geographicalId() );
}

#endif
