#ifndef CARGOSHIP_HH
#define CARGOSHIP_HH

#include "ship.hh"

#ifdef English_dox
/**
 * @file
 * @brief Cargo ship.
 */
#endif
namespace Common {
#ifdef English_dox
/**
 * @brief Cargo ship carries cargo between star systems.
 *
 * Ship first tries to load and unload cargo. If these are not possible,
 * it tries to move to another, randomly selected, star system. If this is not possible either,
 * and if the engine is broken, distress call is sent.
 *
 * If there is nothing that can be done, i.e. the engine is broken, and it is not possible to
 * move between star systems, the ship just leaves the action without choosing.
 *
 * Deserted cargo ship does not choose an action.
 */
#endif
class CargoShip : public Ship
{
public:
#ifdef English_dox
    /**
     * @copydoc Ship()
     */
#endif
    CargoShip(std::shared_ptr<ShipEngine> engine,
              std::shared_ptr<StarSystem> initialLocation,
              std::shared_ptr<IEventHandler> events = nullptr);
#ifdef English_dox
    /**
     * @copydoc Ship::decideAction()
     * @note Ship prefers actions in the following order
     * UnloadCargo
     * LoadCargo
     * MoveAction
     * ChargeAction
     * RepairAction
     * DistressAction
     *
     */
#endif
    virtual bool decideAction();
#ifdef English_dox
    /**
     * @brief Returns the current cargo of the ship.
     * @post Exception guarantee: nothrow
     */
#endif
    StarSystem::ECONOMY_TYPE getCargo() const;
#ifdef English_dox
    /**
     * @brief Sets a new cargo for the ship, or removes the existing one.
     * @post Exception guarantee: nothrow
     */
#endif
    void setCargo(StarSystem::ECONOMY_TYPE cargo);
#ifdef English_dox
    /**
     * @brief Returns the current action of the ship.
     * @post Exception guarantee: nothrow
     */
#endif
    virtual std::shared_ptr<IAction> getAction() const;

private:
#ifdef English_dox
    /**
     * @brief Tests, if it is possible or reasonable to move somewhere.
     * If it is, creates a new moving action and chooses it as the next action.
     * @return True, if a new action was created. Otherwise false.
     */
#endif
    bool decideToMove();
#ifdef English_dox
    //! Current cargo, if any.
#endif
    StarSystem::ECONOMY_TYPE cargo_;
};

}

#endif // CARGOSHIP_HH
