#ifndef STATEEXCEPTION_HH
#define STATEEXCEPTION_HH

#include "gameexception.hh"

#ifdef English_dox
/**
  * @file
  * @brief Exception class for illegal states.
  */
#endif

namespace Common
{
#ifdef English_dox
/**
 * @brief An exception of this type is thrown, when trying to use an object in illegal state.
 */
#endif
class StateException : public GameException
{
public:
#ifdef English_dox
    /**
     * @brief Constructor.
     * @param msg Message declaring the reason of the exception.
     * @pre -
     * @post Creates a StateException, including message declaring the reason of the exception.
     */
#endif
    explicit StateException(const std::string& msg = "");
#ifdef English_dox
    /**
     * @brief Destructor.
     */
#endif
    virtual ~StateException() = default;
};

}//Common

#endif // STATEEXCEPTION_HH
