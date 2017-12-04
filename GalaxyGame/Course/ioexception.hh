#ifndef IOEXCEPTION_HH
#define IOEXCEPTION_HH

#include "gameexception.hh"

#ifdef English_dox
/**
  * @file
  * @brief Defines an exception class for errors that happen when handling files
  */
#endif

namespace Common
{

#ifdef English_dox
/**
 * @brief Exception class for file handling errors
 */
#endif
class IoException : public GameException
{
public:
#ifdef English_dox
    /**
     * @brief Constructor.
     * @param msg Message containing the reason for the error
     * @pre -
     * @post Instance of IOException created including a message of the reason for the error
     */
#endif
    explicit IoException(const std::string& msg = "");

#ifdef English_dox
    /**
     * @brief Destructor.
     */
#endif
    virtual ~IoException() = default;
};

} // Common

#endif // IOEXCEPTION_HH
