#ifndef DISTRESSACTION_HH
#define DISTRESSACTION_HH

#include "iaction.hh"
#include "ship.hh"

#ifdef English_dox
/**
 * @file
 * @brief Distress action.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Ships make distress calls with this action.
 *
 * Distress calls spawn an event, which is meant to be taken into account
 * in the user interface somehow.
 *
 * If distress call takes 20 turns, the ship will be deserted and an event is spawned about it.
 */
#endif
class DistressAction : public IAction
{
public:
#ifdef English_dox
    //! Maximum duration of a distress call in turns.
#endif
    static unsigned const MAX_DISTRESS_DURATION;
#ifdef English_dox
    /**
     * @brief Constructor.
     * @post A ship is associated to the action to execute the action.
     * @param executor Ship executing the action.
     * @param events This is used to spawn events. Possibly nullptr.
     */
#endif
    DistressAction(std::shared_ptr<Ship> executor, std::shared_ptr<IEventHandler> events);

#ifdef English_dox
    /**
     * @copydoc IAction::canDo()
     * @note DistressAction requires also that the executor has an engine, which is broken.
     */
#endif
    virtual bool canDo() const;
#ifdef English_dox
    /**
     * @copydoc IAction::execute()
     * @post Distress call event has been spawned, but only if the action was executed
     *       for the first time during the lifetime of this object.
     * @post If action has been completed, the off event of the distress call has been spawned.
     * @post If distress call takes 20 turns, the ship is deserted and the action is finished.
     * @note Action is not finished, until the engine is completely repaired.
     */
#endif
    virtual bool execute();

private:
#ifdef English_dox
    //! Ship executing the action.
#endif
    std::shared_ptr<Ship> executor_;
#ifdef English_dox
    //! This is used to spawn events.
#endif
    std::shared_ptr<IEventHandler> events_;
#ifdef English_dox
    //! True, if distress call has been spawned during execution.
#endif
    bool distressAsserted_;
    unsigned distressDuration_;
};

}

#endif // DISTRESSACTION_HH
