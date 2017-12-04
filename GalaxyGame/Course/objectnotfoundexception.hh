#ifndef OBJECTNOTFOUNDEXCEPTION_HH
#define OBJECTNOTFOUNDEXCEPTION_HH

#include "gameexception.hh"
#ifdef English_dox
/**
  * @file
  * @brief Defines exception class for errors when the object requested is not found
  */
#endif

namespace Common
{
#ifdef English_dox
/**
 * @brief Exception class for erroneous object search.
 */
#endif
class ObjectNotFoundException : public GameException
{
public:
#ifdef English_dox
    /**
     * @brief Constructor.
     * @param msg Message declaring the reason of the exception.
     * @pre -
     * @post Creates ObjectNotFoundException, including the message declaring the reason of the exception.
     */
#endif
    explicit ObjectNotFoundException(const std::string& msg = "");
#ifdef English_dox
    /**
     * @brief Destructor.
     */
#endif
    virtual ~ObjectNotFoundException() = default;
};

} // Common

#endif // OBJECTNOTFOUNDEXCEPTION_HH
