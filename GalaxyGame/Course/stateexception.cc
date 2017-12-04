#include "stateexception.hh"

namespace Common
{

StateException::StateException(const std::string &msg):
    GameException(msg)
{
}

}//Common
