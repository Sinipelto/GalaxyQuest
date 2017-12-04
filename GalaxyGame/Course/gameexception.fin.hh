

/**
 * @file gameexception.hh
 * @brief Määrittelee poikkeusluokan pelissä tapahtuvia virheitä varten.
 */

/**
  @namespace Common
*/

/**
 * @class Common::GameException
 * @brief Kantaluokka pelissä käytettäville poikkeuksille.
 */

/**
 * @fn explicit Common::GameException::GameException(const std::string& msg = "");
 * @brief Rakentaja.
 * @param msg Poikkeuksen syytä selventävä viesti.
 * @pre -
 * @post Luo pelivirheen, joka sisältää poikkeuksen syytä selventävän viestin.
 */

/**
 * @fn virtual Common::GameException::~GameException() = default;
 * @brief Purkaja.
 */

/**
 * @fn virtual std::string Common::GameException::msg() const;
 * @brief msg antaa poikkeuksen syytä selventävän viestin.
 * @pre -
 * @post Poikkeustakuu: nothrow.
 * @return Rakentajassa annettu viesti tai tyhjä merkkijono.
 */

/**
  * @private
*/

/**
 * @variable const std::string msg_;
 */

// EOF: gameexception.fin.hh
