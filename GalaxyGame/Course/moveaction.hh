#ifndef MOVEACTION_HH
#define MOVEACTION_HH

#include "iaction.hh"
#include "starsystem.hh"
#include "ship.hh"

#ifdef English_dox
/**
 * @file
 * @brief Move action.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Ships use move action to travel from a star system to another.
 *
 * Move action depends heavely on the engine of the executing ship.
 * The engine determines if it is possible for the ship to move to the given destination
 * and how fast travelling can be.
 */
#endif
class MoveAction : public IAction
{
public:
#ifdef English_dox
    /**
     * @brief Constructor.
     * @post Action is associated with the ship executing the action.
     * @param executor Ship executing the action.
     * @param destination Destination of the trip.
     * @param events The events of the ship are spawned with this. Possibly nullptr.
     */
#endif
    MoveAction(std::shared_ptr<Ship> executor, std::shared_ptr<StarSystem> destination,
               std::shared_ptr<IEventHandler> events);
#ifdef English_dox
    /**
     * @copydoc IAction::canDo()
     * @note MoveAction requires also that the executor has a location and an intact engine,
     *       and that the destination exists and is reachable by the engine.
     */
#endif
    virtual bool canDo() const;
#ifdef English_dox
    /**
     * @copydoc IAction::execute()
     * @post The trip has proceeded, if the action execution is not finished.
     * @post If the action is completed, the executor has a destination.
     */
#endif
    virtual bool execute();

private:
#ifdef English_dox
    /**
     * Performs the things to be done at the start of the trip.
     * @pre Trip has not started.
     */
#endif
    void startTrip();
#ifdef English_dox
    /**
     * Checks if the trip is concluded, if yes, does the necessary things.
     * @returns True, if the trip is concluded. Otherwise false.
     */
#endif
    bool concludeTrip();
#ifdef English_dox
    //! Ship executing the action.
#endif
    std::shared_ptr<Ship> executor_;
#ifdef English_dox
    //! Destination of the trip.
#endif
    std::shared_ptr<StarSystem> destination_;
#ifdef English_dox
    //! This is used to spawn events.
#endif
    std::shared_ptr<IEventHandler> events_;
#ifdef English_dox
    //! True, if travelling has been started.
#endif
    bool travelling_;
#ifdef English_dox
    //! How many turns the trip has proceeded.
#endif
    int turns_;
    int requiredTurns_;
#ifdef English_dox
    // The coordinates of the location of the ship during travelling.
#endif
    double x_pos_;
    double y_pos_;
#ifdef English_dox
    // The displacement of the ship at each turn.
#endif
    double x_diff_;
    double y_diff_;
};

}

#endif // MOVEACTION_HH
