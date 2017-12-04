#ifdef Finnish_dox

/**
* @file istatistics.hh
* @brief Määrittelee luokan, joka pitää kirjaa pelin tilasta.
*/

/**
* @class Common::IStatistics
* @brief Määrittelee rajapinnan tilastoluokalle.
*
* @invariant getPoints() >= 0
* @invariant getCreditBalance() >= MAX_LOAN_ALLOWANCE
* MAX_LOAN_ALLOWANCE on raja-arvo sille, paljonko pelaajalla voi olla velkaa
* Varsinaisen arvon saa päättää luokan toteuttaja.
*/


/**
* @fn Common::IStatistics::IStatistics() = default;
* @brief Rajapintaluokan oletusrakentaja (olemassa dokumentaatiota varten).
*/


/**
* @fn virtual Common::IStatistics::~IStatistics() = default;
* @brief Rajapintaluokassa on oletusarvoinen virtuaalipurkaja (olemassa, koska kantaluokalla tulee olla virtuaalipurkaja).
*/


/**
* @fn virtual void Common::IStatistics::addSavedShip() = 0;
* @brief Lisää yhden hädästä pelastetun aluksen.
* @post Poikkeustakuu: nothrow
*
*/

/**
* @fn virtual unsigned Common::IStatistics::getSavedShips() const = 0;
* @return Pelastettujen alusten määrä.
* @post Poikkeustakuu: nothrow
*/

/**
* @fn virtual void Common::IStatistics::addLostShip() = 0;
* @brief Lisää yhden menetetyn aluksen. Tämän kautta tilastoidaan myös muut galaksista poistetut alukset.
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual unsigned Common::IStatistics::getLostShips() const = 0;
* @brief Kertoo menetettyjen alusten määrän.
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IStatistics::addPoints(unsigned amount) = 0;
* @brief Lisää pelaajalle pisteitä.
* @param amount Lisättävien pisteiden määrä.
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IStatistics::reducePoints(unsigned amount) = 0;
* @brief Vähentää pelaajan pisteitä.
* @param amount Vähennettävien pisteiden määrä.
* @exception StateException, jos pisteet menisivät alle nollan
* @post Poikkeustakuu: vahva
*/


/**
* @fn virtual unsigned Common::IStatistics::getPoints() const = 0;
* @return Pelaajan pisteet.
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IStatistics::addCredits(unsigned amount) = 0;
* @brief Lisää pelaajan "tilille" crediittejä.
* @param amount Lisättävien crediittien määrä.
* @post Poikkeustakuu: nothrow
*/


/**
* @fn virtual void Common::IStatistics::reduceCredits(unsigned amount) = 0;
* @brief Vähentää pelaajan "tililtä" crediittejä.
* @param amount Vähennettävien crediittien määrä.
* @exception StateException, jos invariantti rikkoutuu.
* @post Poikkeustakuu: vahva
*/


/**
* @fn virtual int Common::IStatistics::getCreditBalance() const = 0;
* @return Jäljellä olevien crediittien määrän.
* @post Poikkeustakuu: nothrow
*/


#endif

// EOF: istatistics.fin.hh
