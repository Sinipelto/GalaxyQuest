

/**
 * @file formatexception.hh
 * @brief Määrittelee poikkeusluokan datan rakenteessa tapahtuvia virheitä varten.
 */

/**
  @namespace Common
*/

/**
 * @class Common::FormatException : public GameException
 * @brief Poikkeusluokka virheelliselle datan rakenteelle.
 */

/**
 * @fn explicit Common::FormatException::FormatException(const std::string& msg = "");
 * @brief Rakentaja.
 * @param msg Poikkeuksen syytä selventävä viesti.
 * @pre -
 * @post Luo rakennevirheen FormatException, joka sisältää poikkeuksen syytä selventävän viestin.
 */

/**
 * @fn virtual Common::FormatException::~FormatException() = default;
 * @brief Purkaja.
 */


// EOF: formatexception.fin.hh
