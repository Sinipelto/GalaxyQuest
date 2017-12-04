#ifdef Finnish_dox

/**
 * @file shipfactory.hh
 * @brief Avaruusaluksen abstrakti kantaluokka.
 */

/**
  @namespace Course
*/

/**
 * @class Course::ShipFactory
 * @brief Singleton-luokka aluksien luomiseen.
 *
 * Tehtaalle voi rekisteröidä uusia aluksia käyttäen funktiota addBuildableShip.
 * Esimerkkejä löytyy moodulin Initialize funktiosta getGameRunner.
 */

/**
 * @brief BuildFunction tyyppimäärittely aluksen rakennusfunktiolle.
 *
 * @typedef typedef std::function<std::shared_ptr<Common::Ship>(std::shared_ptr<Common::StarSystem>,
 *                                                  std::shared_ptr<Common::IEventHandler>)> BuildFunction;
*/

/**
 * @fn static ShipFactory& Course::ShipFactory::getInstance();
 * @post Exception guarantee: nothrow
 * @return Viite tehtaaseen.
 */

/**
 * @fn void Course::ShipFactory::addBuildableShip(const std::string typeName, BuildFunction buildFunction);
 * @brief Rekisteröi uuden alustyypin rakennettavaksi.
 * @param typeName Rakennettavan alustyypin tunniste.
 * @param buildFunction Rakennettavan aluksen rakennusfunktio.
 * @post Poikkeustakuu: perus
 */

/**
 * @fn std::vector<std::string> Course::ShipFactory::getBuildableShips() const;
 * @post Poikkeustakuu: nothrow
 * @return Rakennettavissa olevien alusten tyyppinimet.
 */

/**
 * @fn std::shared_ptr<Common::Ship> Course::ShipFactory::createRandomShip();
 * @brief Rakentaa satunnaisen aluksen rekisteröityjen alustyyppien joukosta.
 * @param initialLocation Tähtijärjestelmä, johon alus rakennetaan.
 * @param handler Alus assosioidaan tämän tapahtumanvälittäjän kanssa.
 * @post Luo eventin aluksen rakentamisesta, käyttäen parametria handler.
 * @post Poikkeustakuu: nothrow
 * @return Rakennettu alus. Nullptr, mikäli yhtään alusta ei ole rekisteröity.
 */
                                               
/**
 * @fn std::shared_ptr<Common::Ship> Course::ShipFactory::createShip(
        std::string typeName,
        std::shared_ptr<Common::StarSystem> initialLocation,
        std::shared_ptr<Common::IEventHandler> handler);
 * @brief createShip luo aluksen tyyppinimen mukaan.
 * @param typeName Rakennettavan alustyypin tunniste.
 * @param initialLocation Tähtijärjestelmä, johon alus rakennetaan.
 * @param handler Alus assosioidaan tämän tapahtumanvälittäjän kanssa.
 * @post Luo eventin aluksen rakentamisesta, käyttäen parametria handler.
 * @post Poikkeustakuu: nothrow
 * @return Rakennettu alus. Nullptr, mikäli yhtään alusta ei ole rekisteröity parametrillä typename.
 */
 
// EOF: shipfactory.fin.hh
#endif
