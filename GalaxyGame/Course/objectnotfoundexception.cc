#include "objectnotfoundexception.hh"

namespace Common
{

ObjectNotFoundException::ObjectNotFoundException(const std::string &msg):
    GameException(msg)
{
}

} // Common
