#ifdef Finnish_dox

/**
 * @file starsystemfactory.hh
 * @brief Tähtijärjestelmiä luova singleton-tehdas.
 */

/**
  @namespace Course
*/

/**
 * @class Course::StarSystemFactory
 * @brief Singleton-luokka tähtijärjestelmien luomiseen.
 *
 * Tehdasta kehoitetaan lukemaan JSON tiedosto, jonka jälkeen siltä pyydetään
 * tietorakenne, joka sisältää luetut tähtijärjestelmät.
 */

/**
 * @fn static StarSystemFactory& Course::StarSystemFactory::getInstance();
 * @post Exception guarantee: nothrow
 * @return Viite tehtaaseen.
 */

/**
 * @fn void Course::StarSystemFactory::readJSON(std::string filename);
 * @brief Lukee tähtijärjestelmät JSON-tiedostosta.
 * @post Tähtijärjestelmät sisältävä JSON-tiedosto on luettu.
 * @post Poikkeustakuu: perus
 * @param filename Kansiossa GalaxyGame/Assets sijaitsevan tiedoston nimi.
 * @exception IOException Tiedostoa ei voitu avata luettavaksi.
 * @exception FormatException JSON-tiedoston muoto on virheellinen.
 */

/**
 * @fn Common::StarSystem::Vector Course::StarSystemFactory::getAllStarSystems();
 * @post Exception guarantee: nothrow
 * @return Palauttaa JSON-tiedostosta luetut järjestelmät. Jos järjestelmiä ei ole luettu
 * tai niitä ei ollut, palauttaa tyhjän vektorin.
 */

/**
 * @fn bool Course::StarSystemFactory::isJSONread() const;
 * @post Exception guarantee: nothrow
 * @return True, jos JSON-tiedosto on onnistuneesti luettu, muuten false.
 */
 
// EOF: starsystemfactory.fin.hh
#endif
