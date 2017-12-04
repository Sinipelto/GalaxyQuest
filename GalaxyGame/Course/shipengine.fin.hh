#ifdef Finnish_dox

/**
 * @file ship.hh
 * @brief Aluksen moottorin abstrakti kantaluokka.
 */

/**
  @namespace Common
*/

/**
 * @brief Tietotyyppi, jolla havainnollistetaan moottorin kuntoa ja siihen tulevia muutoksia.
 *
 * @typedef int Common::ShipEngine::Health;
 */

/**
 * @class Common::ShipEngine
 * @brief Aluksen moottori asettaa rajoituksia aluksen liikkumiselle tähtijärjestelmästä toiseen.
 *
 * Kukin periytetty luokka tietää, minkä tähtijärjestelmien välillä voi liikkua, ja miten kauan
 * siinä kestää. Lisäksi kantaluokka toteuttaa moottorin kuntoa muuttavat funktiot.
 */

/**
 * @fn Common::ShipEngine::ShipEngine(int maxHealth);
 * @brief Rakentaja.
 * @param maxHealth Moottorin paras mahdollinen kunto.
 */

/**
 * @fn virtual Common::ShipEngine::~ShipEngine() = default;
 * @brief Purkaja.
 */

/**
 * @fn virtual bool Common::ShipEngine::canStart() const;
 * @brief Tarkistaa voiko moottorin startata.
 * @post Poikkeustakuu: nothrow
 * @return Tosi, jos moottorin voi starta. Muuten epätosi.
 */

/**
 * @fn virtual void Common::ShipEngine::onStart() =  0;
 * @brief Suorittaa startin yhteydessä tapahtuvat asiat.
 * @post Poikkeustakuu: perus
 */

/**
 * @fn virtual StarSystem::Vector Common::ShipEngine::getValidDestinations(std::shared_ptr<StarSystem> source) const = 0;
 * @brief Hakee tähtijärjestelmät, joihin moottorilla pääsee.
 * @pre Parametri source ei saa olla nullptr.
 * @post Poikkeustakuu: nothrow
 * @param source Mahdollisen matkan lähtöpaikka.
 * @return Mahdolliset matkan määränpäät. Ei saa sisältää parametria source.
 */

/**
 * @fn virtual bool Common::ShipEngine::isValidTrip(std::shared_ptr<StarSystem> source,
                            std::shared_ptr<StarSystem> destination) const =  0;
 * @brief Tarkistaa, voiko kahden tähtijärjestelmän välillä matkustaa suoraan.
 *        Tyypillisesti määränpää ei voi olla sama kuin lähtöpaikka.
 * @pre Parametri source ei saa olla nullptr.
 * @pre Parametri destination ei saa olla nullptr.
 * @post Poikkeustakuu: nothrow
 * @param currentLocation Tarkistettavan matkan lähtöpaikka.
 * @param destination Tarkistettavan matkan määränpää.
 * @return Tosi, jos matka on mahdollinen. Epätosi, jos ei ole.
 */

/**
 * @fn virtual int Common::ShipEngine::requiredTurns(std::shared_ptr<StarSystem> source,
 *                       std::shared_ptr<StarSystem> destination) const =  0;
 * @brief Laskee montako vuoroa tarvitaan kahden tähtijärjestelmän väliseen matkaan.
 * @pre Parametri source ei saa olla nullptr.
 * @pre Parametri destination ei saa olla nullptr.
 * @post Poikkeustakuu: nothrow
 * @param source Mahdollisen matkan lähtöpaikka.
 * @return Montako vuoroa tarvitaan.
 */

/**
 * @fn void Common::ShipEngine::decreaseHealth(EngineHealth amountDecreased);
 * @brief Huonontaa moottorin kuntoa.
 * @post Jos moottori hajosi, spawnaa eventin.
 * @post Poikkeustakuu: nothrow
 * @param amountDecreased Paljonko kuntoa vähennetään.
 */

/**
 * @fn void Common::ShipEngine::repair(EngineHealth amountRepaired);
 * @brief Kasvattaa moottorin kuntoa.
 * @post Poikkeustakuu: nothrow
 * @param amountRepaired Paljonko kuntoa kasvatetaan.
 */

/**
 * @fn EngineHealth Common::ShipEngine::getHealth() const;
 * @brief Katsoo moottorin nykyisen kunnon.
 * @post Poikkeustakuu: nothrow
 * @return Moottorin kuntolukema.
 */

/**
 * @fn EngineHealth Common::ShipEngine::getMaxHealth() const;
 * @brief Katsoo kuinka hyvässä kunnossa moottori voi parhaimmillaan olla.
 * @post Poikkeustakuu: nothrow
 * @return Moottorin maksimikuntolukema.
 */

/**
 * @fn bool Common::ShipEngine::isBroken() const;
 * @brief Katsoo onko moottori hajonnut.
 * @post Poikkeustakuu: nothrow
 * @return Tosi, jos moottori on hajonnut, muuten epätosi.
 */

/**
  * @private
*/
//! Moottorin paras mahdollinen kunto.
//! @variable EngineHealth maxHealth_;
//! Moottorin tämänhetkinen kunto.
//! @variable EngineHealth health_;

// EOF: shipengine.fin.hh
#endif
