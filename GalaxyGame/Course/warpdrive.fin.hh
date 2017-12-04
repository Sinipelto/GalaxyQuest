#ifdef Finnish_dox

/**
 * @file warpdrive.hh
 * @brief Poimuajomoottori.
 */

/**
  @namespace Common
*/

/**
 * @class Common::WarpDrive : public ShipEngine
 * @brief Poimuajomoottori lähtee välittömästi käyntiin, mutta sillä kestää jonkin aikaa
 * saavuttaa määränpäänä oleva tähtijärjestelmä. Moottori kuluu startin yhteydessä.
 */

//! Maksimietäisyys lähtöpaikan ja määränpään välillä.
//! @variable static const int RANGE;
//! Kuinka monta pitkä matka edetään yhden vuoron aikana.
//! @variable static const int DISTANCE_PER_MOVEMENT;
//! Moottorin kuntolukema parhaimmillaan.
//! @variable static const EngineHealth MAX_HEALTH;
//! Paljonko startti pahimmillaan heikentää moottorin kuntoa.
//! @variable static const EngineHealth MAX_DAMAGE_PER_START;
//! Kuinka vähän startti pienimmillään heikentää moottorin kuntoa.
//! @variable static const EngineHealth MIN_DAMAGE_PER_START;

/**
 * @fn Common::WarpDrive::WarpDrive(std::shared_ptr<IGalaxy> galaxy);
 * @brief Suositeltu rakentaja.
 * @param galaxy Galaksi, jossa moottoria tullaan käyttämään.
 */

/**
 * @fn virtual void Common::WarpDrive::onStart();
 * @copydoc ShipEngine::onStart()
 */

/**
 * @fn virtual StarSystem::Vector Common::WarpDrive::getValidDestinations(std::shared_ptr<StarSystem> source) const;
 * @copydoc ShipEngine::getValidDestinations()
 * @note Warppimoottori kuluu startissa.
 */

/**
 * @fn virtual bool Common::WarpDrive::isValidTrip(std::shared_ptr<StarSystem> source,
                          std::shared_ptr<StarSystem> destination) const;
 * @copydoc ShipEngine::isValidTrip()
 * @note Warppimoottori katsoo kantamansa maksimietäisyyden mukaan.
 */

/**
 * @fn virtual int Common::WarpDrive::requiredTurns(std::shared_ptr<StarSystem> source,
                             std::shared_ptr<StarSystem> destination) const;
 * @copydoc ShipEngine::requiredTurns()
 * @note Warppimoottorin vaatimat vuorot kasvavat lähes lineaarisesti etäisyyden mukaan.
 */

/**
 * @private
*/
//! Galaksi, jossa moottoria käytetään.
//! @variable std::shared_ptr<IGalaxy> galaxy_;

#endif
// EOF: warpdrive.fin.hh
