#ifdef Finnish_dox

/**
 * @file ship.hh
 * @brief Avaruusaluksen abstrakti kantaluokka.
 */

/**
  @namespace Common
*/

/**
 * @class Common::Ship
 * @brief Abstrakti kantaluokka, josta kaikki alustyypit on periytettävä.
 *
 * Aluksen keskeisimmät ominaisuudet ovat toiminnon suorittaminen sekä
 * seuraavan toiminnon päättäminen. Toiminnon päättäminen on toteutettava
 * periytetyssä luokassa.
 */

/**
 * @fn Common::Ship::Ship(std::shared_ptr<ShipEngine> engine,
         std::shared_ptr<StarSystem> initialLocation,
         std::shared_ptr<IEventHandler> events);
 * @brief Rakentaja.
 * @param engine Moottori, jota aluksen halutaan käytettävän.
 * @param initialLocation Sijainti, jonne alus syntyy.
 * @param events Tätä kautta spawnataan aluksen eventit. Voi olla myös nullptr.
 */

/**
 * @fn virtual Common::Ship::~Ship() = default;
 * @brief Purkaja.
 */

/**
 * @fn virtual std::shared_ptr<ShipEngine> Common::Ship::getEngine();
 * @post Poikkeustakuu: nothrow
 * @return Aluksen käyttämä moottori.
 */

/**
 * @fn virtual std::shared_ptr<StarSystem> Common::Ship::getLocation();
 * @post Poikkeustakuu: nothrow
 * @return Aluksen tämänhetkinen sijainti. Nullptr, jos alus on matkalla tähtijärjestelmien välillä.
 */

/**
 * @fn virtual std::string Common::Ship::getName() const;
 * @post Poikkeustakuu: nothrow
 * @return Aluksen nimi.
 */

/**
 * @fn virtual void Common::Ship::setName(std::string name_);
 * @brief Asettaa alukselle nimen.
 * @post Alukselle on asetettu nimi.
 * @post Poikkeustakuu: vahva
 * @param name Aluksen uusi nimi.
 */

/**
 * @fn virtual void Common::Ship::setLocation(std::shared_ptr<StarSystem> newLocation);
 * @brief Asettaa alukselle uuden sijainnin.
 * @post Aluksen sijainti on muuttunut ja aiheesta on synnytetty tapahtuma.
 * @post Poikkeustakuu: perus
 * @param newLocation Aluksen uusi sijainti. Voi olla muyös nullptr.
 */

/**
 * @fn virtual void Common::Ship::executeAction();
 * @brief Suorittaa alukselle asetetun toiminnon, tai etenee siinä.
 *        Mutta vain, jos alukselle on asetettu jokin toiminto.
 * @post Jos toiminto suoritettiin loppuun, aluksella ei ole toimintoa.
 * @post Poikkeustakuu: nothrow
 */

/**
 * @fn virtual void Common::Ship::abandonShip();
 * @brief Merkkaa aluksen hylätyksi.
 * @post Poikkeustakuu: perus
 * @post Alus on hylätty. Hylätyt alukset eivät valitse toimintoa, eikä niitä voi korjata.
 */

/**
 * @fn virtual bool Common::Ship::isAbandoned();
 * @brief Kertoo onko alus hylätty.
 * @post Poikkeustakuu: perus
 * @return Tosi, jos alus on hylätty, muutoin epätosi.
 */

/**
 * @fn virtual bool Common::Ship::decideAction() = 0;
 * @brief Alusta kehoitetaan luomaan uusi toiminto.
 * Mutta vain, jos aluksella ei ole jo toimintoa.
 * @post Aluksella on uusi toiminto, jos sellainen pystyttiin tekemään.
 * @post Poikkeustakuu: nothrow
 * @return Tosi, jos toiminto luotiin, muuten epätosi.
 */

/**
  * @protected
*/

/**
 * @var std::shared_ptr<ShipEngine> Ship::engine_;
 * @brief Aluksen moottori.
 */

/**
 * @var std::shared_ptr<StarSystem> Ship::location_;
 * @brief Aluksen nykyinen sijainti.
 */

/**
 * @var std::shared_ptr<IEventHandler> Ship::events_;
 * @brief Tätä kautta spawnataan eventit.
 */

/**
 * @var std::shared_ptr<IAction> Ship::currentAction_;
 * @brief Aluksen meneillään oleva toiminto.
 */

/**
 * @var std::string Ship::name_;
 * @brief Aluksen nimi.
 */

/**
 * @var bool Ship::abandoned_;
 * @brief Tosi, jos alus on hylätty, muutoin epätosi.
 */

// EOF: ship.fin.hh
#endif
