#ifdef Finnish_dox

/**
 * @file starsystem.hh
 * @brief Tähtijärjestelmä, sijainnin perusyksikkö.
 */

/**
  @namespace Common
*/

/**
 * @class Common::StarSystem
 * @brief Galaksit koostuvat tähtijärjestelmistä.
 *
 * Tähtijärjestelmä on dataluokka, joka koostuu kentistä kuten koordinaatit, väkiluku ja elinkeino.
 * Moni muu asia pelilogiikassa, kuten alusten siirtyminen ja rahti, ovat tähtijärjestelmien varassa.
 */

/**
 * @brief Vektorityyppi, joka pitää sisällään osoittimia tähtijärjestelmiin.
 *
 * @typedef std::vector<std::shared_ptr<StarSystem> > Common::StarSystem::Vector;
 */

/**
 * @var static const int Common::StarSystem::POPULATION_REPAIR_TRESHOLD;
 * @brief Jos väkiluku ylittää tämän kynnysarvon, voidaan tähtijärjestelmässä korjata ilman huoltoa.
 */

/**
 * @enum Common::StarSystem::ECONOMY_TYPE
 * @brief Tietotyyppi, jolla ilmaistaan tähtijärjestelmän pääasiallinen elinkeino.
 */

/**
 * @fn Common::StarSystem::StarSystem();
 * @brief Rakentaja.
 * @param name Tähtijärjestelmän nimi.
 * @param economy Tähtijärjestelmän pääasiallinen elinkeino.
 * @param id Tähtijärjestelmän tunniste.
 * @param population Tähtijärjestelmän väkiluku.
 * @param location Tähtijärjestelmän sijainti koordinaateissa.
 */

/**
 * @fn std::string Common::StarSystem::getName() const;
 * @return Tähtijärjestelmän nimi.
 * @post Poikkeustakuu: nothrow
 */

/**
 * @fn Common::StarSystem::ECONOMY_TYPE Common::StarSystem::getEconomy() const;
 * @return Tähtijärjestelmän pääasiallinen elinkeino.
 * @post Poikkeustakuu: nothrow
 */

/**
 * @fn unsigned Common::StarSystem::getId() const;
 * @return Tähtijärjestelmän tunniste.
 * @post Poikkeustakuu: nothrow
 */

/**
 * @fn uint64_t Common::StarSystem::getPopulation() const;
 * @return Tähtijärjestelmän väkiluku.
 * @post Poikkeustakuu: nothrow
 */

/**
 * @fn Common::Point Common::StarSystem::getCoordinates() const;
 * @return Tähtijärjestelmän sijainti koordinaateissa.
 * @post Poikkeustakuu: nothrow
 */

/**
 * @fn bool Common::StarSystem::isInhabited() const;
 * @brief Tarkistaa, onko tähtijärjestelmä asutettu.
 * @return Tosi, jos on, muutoin epätosi.
 * @post Poikkeustakuu: nothrow
 */

/**
 * @fn bool Common::StarSystem::canRepair() const;
 * @brief Tarkistaa, voiko tähtijärjestelmässä suorittaa korjauksia ilman lisävarusteita.
 * @return Tosi, jos voi, muutoin epätosi.
 * @post Poikkeustakuu: nothrow
 */

/**
  * @private
*/
//! Tähtijärjestelmän nimi.
//! @variable std::string name_;
//! Tähtijärjestelmän pääasiallinen elinkeino.
//! @variable ECONOMY_TYPE economy_;
//! Tähtijärjestelmän tunniste.
//! @variable unsigned id_;
//! Tähtijärjestelmän väkiluku.
//! @variable uint64_t population_;
//! Tähtijärjestelmän sijainti koordinaateissa.
//! @variable Point coordinates_;

// EOF: starsystem.fin.hh
#endif
