#ifdef Finnish_dox
/**
* @file igalaxy.hh
* @brief Määrittelee galaksin rajapintaluokan.
*/

/**
 * @brief Sisältää valmiina annettuja rajapintoja ja muita luokkia, joihin voi viitata opiskelijoiden tekemässä koodissa.
 * @namespace Common
 */

/**
* @class Common::IGalaxy
* @brief Määrittää rajapinnan galaksille
*
*  @invariant Tähtijärjestelmän nimi, tunniste ja sijainti on ainutlaatuinen. Samaa alusolioita on galaksissa maksimissaan yksi kappale.
*/

/**
 * @brief Vektorityyppi, joka pitää sisällään osoittimia aluksiin.
 *
 * @typedef std::vector<std::shared_ptr<Common::Ship> > Common::IGalaxy::ShipVector;
 */


/**
* @fn Common::IGalaxy::IGalaxy() = default;
* @brief Rajapintaluokan oletusrakentaja (olemassa dokumentaatiota varten)
* @post Galaksi on alustettu ja tyhjä, ja aluksia ja tähtijärjestelmiä voidaan lisätä
*
*/


/**
* @fn virtual Common::IGalaxy::~IGalaxy() = default;
* @brief Rajapintaluokassa on oletusarvoinen virtuaalipurkaja (olemassa, koska kantaluokalla tulee olla virtuaalipurkaja).
*/


/**
* @fn virtual void Common::IGalaxy::addShip(std::shared_ptr<Ship> ship) = 0;
* @brief addShip Lisää uuden aluksen galaksiin.
* @param ship Galaksiin lisättävä alus.
* @post Alus lisätty galaksiin.
* @exception StateException Jos sama alusolio löytyy jo galaksista.
* @post Poikkeustakuu: vahva
*/


/**
* @fn    virtual void Common::IGalaxy::removeShip(std::shared_ptr<Ship> ship) = 0;
* @brief removeShip poistaa aluksen galaksista.
* @param ship Galaksista poistettava alus
* @post Alus on poistettu galaksista
* @exception ObjectNotFoundException, jos alus ei ole olemassa
* @post Poikkeustakuu: vahva
*/


/**
* @fn virtual void Common::IGalaxy::addStarSystem(std::shared_ptr<StarSystem> system) = 0;
* @brief addStarSystem lisää uuden tähtijärjestelmän galaksiin
* @param system Galaksiin lisättävä tähtijärjestelmä
* @post Tähtijärjestelmä on lisätty galaksiin
* @exception StateException, jos galaksissa on ennestään tähtijärjestelmä, jolla on sama nimi tai tunniste tai sijainti
* @post Poikkeustakuu: vahva
*/


/**
*@fn virtual std::shared_ptr<ShipVector> Common::IGalaxy::getShips() = 0;
* @brief getShips
* @return Jaettu osoitin vektoriin, joka sisältää galaksissa olevat alukset. Tyhjä vektori, jos ei ole mitään aluksia.
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual StarSystem::Vector Common::IGalaxy::getSystemsInRange(std::shared_ptr<StarSystem> origin, int range) = 0;
* @brief getSystemsInRange
* @param origin Tarkastelun kohteena oleva tähtijärjestelmä
* @param range Etäisyys valovuosina
* @exception Heittää poikkeuksen ObjectNotFoundException, jos järjestelmää ei ole galaksissa
* @return Tähtijärjestelmät, jotka ovat annetun etäisyyden päässä tarkasteltavasta tähtijärjestelmästä. Tyhjä vektori, jos tällaisia tähtijärjestelmiä ei ole.
* @post Poikkeustakuu: vahva
*/


/**
* @fn virtual std::shared_ptr<StarSystem> Common::IGalaxy::getRandomSystem() = 0;
* @brief getRandomSystem palauttaa satunnaisen tähtijärjestelmän
* @return Satunnainen tähtijärjestelmä galaksiin lisättyjen järjestelmien joukosta.
* @exception ObjectNotFoundException, jos galaksissa ei ole yhtään tähtijärjestelmää
* @post Poikkeustakuu: vahva
*/


/**
* @fn virtual ShipVector Common::IGalaxy::getShipsInStarSystem(std::string name) = 0;
* @brief getShipsInStarSystem
* @param name Tähtijärjestelmän nimi
* @return Vektori, joka sisältää annetun tähtijärjestelmän alukset. Tyhjä vektori, jos tähtijärjestelmässä ei ole yhtään alusta.
* @exception ObjectNotFoundException, jos annettua tähtijärjestelmää ei ole olemassa
* @post Poikkeustakuu: vahva
*/


/**
* @fn virtual std::shared_ptr<Common::StarSystem> Common::IGalaxy::getStarSystemByName(std::string name) = 0 ;
* @brief getStarSystemByName antaa tähtijärjestelmän nimen perusteella
* @param name Tähtijärjestelmän nimi
* @return Jaettu osoitin tähtijärjestelmäolioon
* @exception ObjectNotFoundException, jos parametrina annettua tähtijärjestelmää ei ole olemassa
* @post Poikkeustakuu: vahva
*/


/**
* @fn virtual std::shared_ptr<Common::StarSystem> Common::IGalaxy::getStarSystemById(unsigned id) = 0;
* @brief getStarSystemById antaa tähtijärjestelmän tunnisteen perusteella
* @param id Tähtijärjestelmän tunniste
* @return Jaettu osoitin tähtijärjestelmäolioon
* @exception ObjectNotFoundException, jos parametrina annettua tähtijärjestelmää ei ole olemassa
* @post Poikkeustakuu: vahva
*/

#endif

//EOF: igalaxy.fin.hh
