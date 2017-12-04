#ifndef GAMEEXCEPTION_HH
#define GAMEEXCEPTION_HH

#include <string>

#ifdef English_dox
/**
  * @file
  * @brief Defines exception class for errors occuring in the game.
  */
#endif

namespace Common
{

#ifdef English_dox
/**
 * @brief Base class for exceptions used in the game.
 */
#endif
class GameException
{
public:
#ifdef English_dox
    /**
     * @brief Constructor.
     * @param msg Message declaring the reason of the exception.
     * @pre -
     * @post Creates game error, including a message declaring the reason of the exception.
     */
#endif
    explicit GameException(const std::string& msg = "");
#ifdef English_dox
    /**
     * @brief Destructor.
     */
#endif
    virtual ~GameException() = default;
#ifdef English_dox
    /**
     * @brief msg gives message declaring the reason of the exception.
     * @pre -
     * @post Exception guarantee: nothrow.
     * @return Message given in the constructor or the empty string.
     */
#endif
    virtual std::string msg() const;

private:
    const std::string msg_;
};

} // Commmon

#endif // GAMEEXCEPTION_HH
