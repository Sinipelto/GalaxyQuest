#ifndef WORMHOLEDRIVE_HH
#define WORMHOLEDRIVE_HH

#include "shipengine.hh"
#include "igalaxy.hh"

#ifdef English_dox
/**
 * @file wormholedrive.hh
 * @brief Wormhole engine.
 */
#endif
namespace Common {

using Common::StarSystem;
using Common::IGalaxy;
#ifdef English_dox
/**
 * @brief Wormhole engine takes some time to charge, but it will arrive
 * instantaneously. This engine wears on start.
 */
#endif
class WormHoleDrive : public Common::ShipEngine
{
public:
#ifdef English_dox
    //! Maximum distance between the start point and the destination.
#endif
    static const int RANGE;
#ifdef English_dox
    //! Health number of the engine at best.
#endif
    static const Health MAX_HEALTH;
#ifdef English_dox
    //! How much does the start decrease the health of the engine at worst.
#endif
    static const Health MAX_DAMAGE_PER_START;
#ifdef English_dox
    //! How little does the start decrease the health of engine at least.
#endif
    static const Health MIN_DAMAGE_PER_START;
#ifdef English_dox
    //! Maximum capacity of the accumulator.
#endif
    static const int MAX_CHARGE;
#ifdef English_dox
    /**
     * @param galaxy Galaxy, where the engine will be used.
     */
#endif
    WormHoleDrive(std::shared_ptr<IGalaxy> galaxy);
#ifdef English_dox
    /**
     * @brief Checks if the engine can be started.
     * @return True, if engine is not broken and fully charged.
     */
#endif
    virtual bool canStart() const;
#ifdef English_dox
    /**
     * @note Wormhole engine is discharged on start.
     * @note This engine wears on start.
     * @copydoc ShipEngine::onStart
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
     */
#endif
    virtual bool isValidTrip(std::shared_ptr<StarSystem> source,
                            std::shared_ptr<StarSystem> destination) const;
#ifdef English_dox
    /**
     * @note Since WormHoleDrive allows instantaneous travel, requiredTurns always returns 1.
     * @copydoc ShipEngine::requiredTurns()
     */
#endif
    virtual int requiredTurns(std::shared_ptr<StarSystem> source,
                             std::shared_ptr<StarSystem> destination) const;
#ifdef English_dox
    /**
     * @brief Increases the power of the accumulator with one increment.
     * @post the charge has been increased by one increment
     */
#endif
    void charge();
#ifdef English_dox
    /**
     * @brief Checks if the drive is fully charged
     * @return True, if the engine is fully charged, otherwise false.
     */
#endif
    bool isCharged() const;

private:
#ifdef English_dox
    //! The ship containing the engine is in this galaxy.
#endif
    std::shared_ptr<IGalaxy> galaxy_;
#ifdef English_dox
    //! How much power the accumulator of the engine has.
#endif
    int charge_;
};

}//Common

#endif // WORMHOLEDRIVE_HH
