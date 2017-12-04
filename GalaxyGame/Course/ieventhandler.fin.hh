#ifdef Finnish_dox
/**
* @file ieventhandler.hh
* @brief Määrittelee tapahtumankäsittelijän rajapinnan.
*/

/**
* @namespace Common
*/

/**
* @class Common::IEventHandler
* @brief Tapahtumanvälittäjä ottaa vastaan tapahtumia ja delegoi niiden käsittelyn
* tapahtumasta kiinnostuneelle oliolle. Oliot synnyttävät tapahtumia kutsumalla 
* tapahtumakäsittelijän funktioita. Tätä on havainnollistettu syvällisemmin työohjeen
* sekvenssikaavioissa.
*
* TÄMÄ TARKOITTAA ETTÄ TÄMÄN LUOKAN FUNKTIODEN SELITTEET OIKEASTI VAIN KERTOVAT MILLOIN
* FUNKTIOTA KUTSUTAAN LUOKAN ULKOPUOLELTA.
*
* Käytännössä tapahtumakäsittelijän avulla käyttöliittymälle ilmoitetaan pelitilan
* muutoksista.
*/

/**
* Tarpeellisten luokkien ennakkoesittelyt.
*/
class Ship;
class StarSystem;
struct Point;


/**
* @fn Common::IEventHandler::IEventHandler() = default;
* @brief Rajapintaluokan oletusrakentaja (olemassa dokumentaatiota varten)
*/


/**
* @fn virtual Common::IEventHandler::~IEventHandler() = default;
* @brief Rajapintaluokassa on oletusarvoinen virtuaalipurkaja (olemassa, koska kantaluokalla tulee olla virtuaalipurkaja).
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IEventHandler::shipSpawned(std::shared_ptr<Ship> ship) = 0;
* @brief Uusi alus on luotu galaksiin.
* @param ship luotu alus
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IEventHandler::shipRemoved (std::shared_ptr<Ship> ship) = 0 ;
* @brief Alus on poistettu galaksista.
* @param ship Poistettu alus
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IEventHandler::shipMoved(std::shared_ptr<Ship> ship, Point origin, Point target) = 0 ;
* @brief Alus on siirtynyt pisteestä toiseen.
* @param ship Liikkunut alus
* @param origin Piste, josta alus lähti liikkeelle
* @param target Piste, jonne alus saapui
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IEventHandler::shipRelocated(std::shared_ptr<Ship> ship, std::shared_ptr<StarSystem> starSystem) = 0;
* @brief Alus on siirtynyt tähtijärjestelmään tai tähtijärjestelmästä pois.
* @param ship Alus, joka vaihtoi sijaintia
* @param starSystem Tähtijärjestelmä, josta alus siirtyi pois. Voi olla myös nullptr.
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IEventHandler::exceptionInExecution(std::shared_ptr<Ship> ship, std::string const& msg) = 0;
* @brief Aluksen suorittama toiminto on aiheuttanut poikkeuksen, ja siksi keskeytetty.
* @param ship Poikkeuksen aiheuttanut alus
* @param msg Poikkeuksen selite
* @post Poikkeustakuu: nothrow
*/


/**
* @fn  virtual void Common::IEventHandler::distressOn(std::shared_ptr<Ship> ship) = 0 ;
* @brief Alus on tehnyt hätäkutsun.
* @param ship Hätäkutsun tehnyt alus
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IEventHandler::distressOff(std::shared_ptr<Ship> ship) = 0;
* @brief Alus on sulkenut hätäkutsun.
* @param ship Hätäkutsun sulkenut alus
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IEventHandler::shipAbandoned(std::shared_ptr<Ship> ship) = 0;
* @brief Alus on hylätty.
* @param ship Hylätty alus
* @post Poikkeustakuu: nothrow
*/

#endif // IEVENTHANDLER_HH
