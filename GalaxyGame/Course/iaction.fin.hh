#ifdef Finnish_dox
/**
 * @file iaction.hh
 * @brief Toiminnon rajapintaluokka.
 */


/**
 * @class Common::IAction
 * @brief Rajapintaluokka, josta kaikki toiminnot on periytettävä.
 *
 * Toiminnot jakautuvat kolmeen osaan: Periytetyn luokan rakentaja saa parametreina
 * muuttujat, joita toiminto tarvitsee. Metodi canDo() tarkistaa, voiko annetuilla
 * parametreilla suorittaa toimintoa. Metodi execute() suorittaa toiminnon, mutta
 * voi silti vielä epäonnistua. Jotkin toiminnot saatetaan suorittaa askelina,
 * jolloin metodi execute() ei suorita toimintoa kerralla loppuun.
 */
/**
 * @fn Common::IAction::IAction() = default;
 * @brief Virtuaalirakentaja. Ei tee mitään, koska kyseessä on rajapintaluokka.
 */


/**
 * @fn virtual Common::IAction::~IAction() = default;
 * @brief Virtuaalipurkaja. Ei tee mitään, koska kyseessä on rajapintaluokka.
 */


/**
 * @fn virtual bool Common::IAction::canDo() const = 0;
 * @brief Katsoo, voiko toiminnon suorittamisen aloittaa.
 *        Ei siis ota kantaa siihen, voiko jo aloitettua toimintoa jatkaa.
 * @pre Toiminnolle on assosioitu toimintoa suorittava alus.
 * @post Poikkeustakuu: nothrow
 * @return Tosi, jos toiminnon suorituksen voi aloittaa, muutoin epätosi.
 */


/**
 * @fn virtual bool Common::IAction::execute() = 0;
 * @brief Yrittää suorittaa toiminnon, tai ainakin etenee suorituksessa.
 * @pre Toiminnolle on assosioitu toimintoa suorittava alus.
 * @exception GameException Jos toiminnon tarvitsemat asiat ovat sellaisessa tilassa,
 *         ettei toimintoa voida enää suorittaa.
 * @return Tosi, jos toiminto suoritettiin loppuun. Epätosi, jos toiminto jäi kesken.
 * @post Poikkeustakuu: perus
 */

#endif
