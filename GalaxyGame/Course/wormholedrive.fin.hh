#ifdef Finnish_dox

/**
 * @file wormholedrive.hh
 * @brief Madonreikämoottori.
 */

/**
  @namespace Common {

using Common::StarSystem;
using Common::StarSystem::Vector;
using Common::EngineHealth;
using Common::IGalaxy;
*/

/** @class Common::WormHoleDrive : public Common::ShipEngine
 *  @brief Madonreikämoottorilla kestää hetki latautua, mutta saapuu paikalle välittömästi.
 *  Moottori kuluu startin yhteydessä.
 */
//! Maksimi etäisyys lähtöpaikan ja määränpään välillä.
//! @variable static const int RANGE;
//! Moottorin kuntolukema parhaimmillaan.
//! @variable static const EngineHealth MAX_HEALTH;
//! Paljonko startti pahimmillaan heikentää moottorin kuntoa.
//! @variable static const EngineHealth MAX_DAMAGE_PER_START;
//! Kuinka vähän startti pienimmillään heikentää moottorin kuntoa.
//! @variable static const EngineHealth MIN_DAMAGE_PER_START;
//! Akun maksimi kapasiteetti.
//! @variable static const int MAX_CHARGE;

/** @fn WormHoleDrive(std::shared_ptr<IGalaxy> galaxy);
 * @param galaxy Galaksi, jossa moottoria tullaan käyttämään.
*/

/**
 * @fn virtual void Common::WormHoleDrive::canStart();
 * @brief Tarkistaa voiko moottorin käynnistää.
 * @return True, jos moottori ei ole rikki ja on täyteen ladattu.
 */

/**
 * @fn virtual void  Common::WormHoleDrive::onStart();
 * @note Moottori kuluu startattaessa.
 * @copydoc ShipEngine::onStart()
 */

/**
 * @fn virtual StarSystem::Vector getValidDestinations(std::shared_ptr<StarSystem> source) const;
 * @copydoc ShipEngine::getValidDestinations()
 */

/**
 * @fn virtual bool isValidTrip(std::shared_ptr<StarSystem> source, std::shared_ptr<StarSystem> destination) const;
 * @copydoc ShipEngine::isValidTrip()
 */

/**
   @fn virtual int requiredTurns(std::shared_ptr<StarSystem> source, std::shared_ptr<StarSystem> destination) const;
 * @note Koska madonreikämoottori mahdollistaa välittömän matkustuksen, palauttaa aina 1.
 * @copydoc ShipEngine::requiredTurns()
 */

/**
 * @fn void charge();
 * @brief Lisää akkuun virtaa yhden pykälän verran
 * @post Akkuun on lisätty latausta yhden pykälän verran.
 */

/**
 * @fn bool isCharged() const;
 * @brief isCharged kertoo onko moottori ladattu täyteen
 * @return true, jos moottori on ladattu täyteen, muuten false
 */


/**
  @private
*/
//! Galaksi, jossa moottoria käytetään.
//! @variable std::shared_ptr<IGalaxy> galaxy_;
//! Paljonko on moottorin akussa virtaa.
//! @variable int charge_;

// EOF: wormholedrive.fin.hh
#endif
