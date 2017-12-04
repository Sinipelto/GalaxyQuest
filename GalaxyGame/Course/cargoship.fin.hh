#ifdef Finnish_dox

/**
  * @include
#include "ship.hh"
*/

/**
 * @file cargoship.hh
 * @brief Rahtialus.
 */

/**
  @namespace Common
 */


/**
 * @class Common::CargoShip
 * @brief Rahtialus kuljettaa rahtia tähtijärjestelmien välillä.
 *
 * Alus pyrkii aina ensin lastaamaan ja purkaamaan lastia, ja jos näitä ei voi tehdä,
 * alus pyrkii siirtymään toiseen satunnaisesti valittuun tähtijärjestelmään. Jos tämäkään
 * ei onnistu, ja moottori on rikki, lähetetään hätäkutsu.
 *
 * Jos mitään ei ole tehtävissä, eli siis moottori on rikki, eikä tähtijärjestelmien välillä
 * pysty liikkumaan, alus vain jättää toiminnon valitsematta.
 *
 * Hylätty rahtialus ei valitse toimintoa.
 */

/**
 * @copydoc Ship()
 */

/**
  * @fn Common::CargoShip::CargoShip(std::shared_ptr<ShipEngine> engine,
              std::shared_ptr<StarSystem> initialLocation,
              std::shared_ptr<IEventHandler> events = nullptr);
  * @brief CargoShip
  * @param engine
  * @param initialLocation
  * @param events
  */


    /**
     * @copydoc Ship::decideAction()
     * @note Alus preferoi toimintoja seuraavassa järjestyksessä
     * UnloadCargo
     * LoadCargo
     * MoveAction
     * ChargeAction
     * RepairAction
     * DistressAction
     *
     *
     */

/**
 * @fn virtual bool Common::CargoShip::decideAction();
 * @brief decideAction
 * @return
 */

/**
  * @fn StarSystem::ECONOMY_TYPE Common::CargoShip::getCargo() const;
  * @brief Palauttaa aluksen nykyisen lastin.
  * @post Poikkeustakuu: nothrow
  */


/**
  * @fn void Common::CargoShip::setCargo(StarSystem::ECONOMY_TYPE cargo);
  * @brief Asettaa alukselle uuden lastin tai poistaa olemassa olevan.
  * @post Poikkeustakuu: nothrow
  */


/**
  * @fn virtual std::shared_ptr<IAction> Common::CargoShip::getAction() const;
  * @brief Palauttaa aluksen nykyisen toiminnon.
  * @post Poikkeustakuu: nothrow
  */

/**
  @private
*/

/**
  * @fn bool Common::CargoShip::decideToMove();
  * @brief Kokeilee, voiko tai kannattaako aluksen siirtyä mihinkään.
  * Jos voi, luo uuden liikkumistoiminnon ja valitsee sen seuraavaksi toiminnoksi.
  * @return Tosi, jos uusi toiminto luotiin. Muuten epätosi.
  */


//! Mitä aluksella on lastina tällä hetkellä, jos on.
//! @variable StarSystem::ECONOMY_TYPE cargo_;

// EOF: cargoship.fin.hh
#endif
