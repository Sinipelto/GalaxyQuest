#ifndef FORMATEXCEPTION_HH
#define FORMATEXCEPTION_HH

#include "gameexception.hh"
#ifdef English_dox
/**
  * @file
  * @brief Defines exception class for errors occuring in data format.
  */
#endif

namespace Common
{
#ifdef English_dox
/**
 * @brief Exception class for erroneous data format.
 */
#endif
class FormatException : public GameException
{
public:
#ifdef English_dox
    /**
     * @brief Constructor.
     * @param msg Message declaring the reason of the exception.
     * @pre -
     * @post Creates FormatException, including the message declaring the reason of the exception.
     */
#endif
    explicit FormatException(const std::string& msg = "");
#ifdef English_dox
    /**
     * @brief Destructor.
     */
#endif
    virtual ~FormatException() = default;
};

} // Common

#endif // FORMATEXCEPTION_HH
