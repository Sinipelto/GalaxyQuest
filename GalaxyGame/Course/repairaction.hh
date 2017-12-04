#ifndef REPAIRACTION_HH
#define REPAIRACTION_HH

#include "iaction.hh"
#include "ship.hh"

#ifdef English_dox
/**
 * @file
 * @brief Repair action of the engine.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Ships repair engines with this action.
 *
 * Repairing may take several turns, and may require a certain kind of star system.
 */
#endif
class RepairAction : public IAction
{
public:
#ifdef English_dox
    //! How much repairing is done in each turn.
#endif
    static const ShipEngine::Health REPAIR_PER_INCREMENT;
#ifdef English_dox
    /**
     * @brief Constructor.
     * @post Action is associated with the ship executing the action.
     * @param executor Ship executing the action.
     * @param target Target engine of the action.
     * @param needsService Must be true, if repairing is not possible without maintenance infrastructure,
     *                     which can be found in the location of the ships.
     */
#endif
    RepairAction(std::shared_ptr<Ship> executor, std::shared_ptr<ShipEngine> target, bool needsService);
#ifdef English_dox
    /**
     * @copydoc IAction::canDo()
     * @note RepairAction requires also the action to have a target ship,
     *       and the target ship must have a broken engine.
     *       If repairing requires maintenance infrastructure, such must be found in the star system.
     */
#endif
    virtual bool canDo() const;
#ifdef English_dox
    /**
     * @copydoc IAction::execute()
     * @post If the engine is not fully repaired, the action execution is not finished.
     */
#endif
    virtual bool execute();

private:
#ifdef English_dox
    //! Ship executing the action.
#endif
    std::shared_ptr<Ship> executor_;
#ifdef English_dox
    //! Target ship of the action.
#endif
    std::shared_ptr<ShipEngine> target_;
#ifdef English_dox
    //! If true, repairing is not possible without maintenance infrastructure, which can be found in the location of the ships.
#endif
    bool needsService_;
};

}

#endif // REPAIRACTION_HH
