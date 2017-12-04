

/**
 * @file stateexception.hh
 * @brief Laittoman tilan poikkeusluokka.
 */

/**
  @namespace Common
*/

/**
 * @class Common::StateException : public GameException
 * @brief Tämän tyyppinen poikkeus heitetään, kun yritetään käyttää oliota laittomassa tilassa.
 */

/**
 * @fn explicit Common::StateException::StateException(const std::string& msg = "");
 * @brief Rakentaja.
 * @param msg Poikkeuksen syytä selventävä viesti.
 * @post Luo poikkeuksen StateException, joka sisältää poikkeuksen syytä selventävän viestin.
 */

/**
 * @fn virtual Common::StateException::~StateException() = default;
 * @brief Purkaja.
 */

// EOF: stateexception.fin.hh
