#ifndef WARPDRIVE_H
#define WARPDRIVE_H

#include "shipengine.hh"
#include "igalaxy.hh"

#ifdef English_dox
/**
 * @file warpdrive.hh
 * @brief Warp engine.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Warp engine starts immediately, but it takes some time to
 * reach the destination. This engine wears on start.
 */
#endif
class WarpDrive : public ShipEngine
{
public:
#ifdef English_dox
    //! Maximum distance between the start point and the destination.
#endif
    static const int RANGE;
#ifdef English_dox
    //! How much the trip proceeds, when calling doMovement.
#endif
    static const int DISTANCE_PER_MOVEMENT;
#ifdef English_dox
    //! Health number of the engine at best.
#endif
    static const Health MAX_HEALTH;
#ifdef English_dox
    //! How much does the start decrease the health of the engine at worst.
#endif
    static const Health MAX_DAMAGE_PER_START;
#ifdef English_dox
    //! How much does the start decrease the health of engine at least.
#endif
    static const Health MIN_DAMAGE_PER_START;
#ifdef English_dox
    /**
     * @brief Recommended constructor.
     * @param galaxy Galaxy, where the engine will be used.
     */
#endif
    WarpDrive(std::shared_ptr<IGalaxy> galaxy);
#ifdef English_dox
    /**
     * @note This engine wears on start.
     * @copydoc ShipEngine::onStart()
     */
#endif
    virtual void onStart();
#ifdef English_dox
    /**
     * @copydoc ShipEngine::getValidDestinations()
     */
#endif
    virtual StarSystem::StarSystemVector getValidDestinations(std::shared_ptr<StarSystem> source) const;
#ifdef English_dox
    /**
     * @copydoc ShipEngine::isValidTrip()
     * @note Warp engine looks its range according to the maximum distance.
     */
#endif
    virtual bool isValidTrip(std::shared_ptr<StarSystem> source,
                            std::shared_ptr<StarSystem> destination) const;
#ifdef English_dox
    /**
     * @note Turns required by the warp engine increase almost linearly in relation to the distance.
     * @copydoc ShipEngine::requiredTurns()
     */
#endif
    virtual int requiredTurns(std::shared_ptr<StarSystem> source,
                             std::shared_ptr<StarSystem> destination) const;
    
private:
#ifdef English_dox
    //! Galaxy, where the engine is used.
#endif
    std::shared_ptr<IGalaxy> galaxy_;
};

}

#endif // WARPDRIVE_H
