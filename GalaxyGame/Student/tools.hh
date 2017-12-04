#ifndef TOOLS_HH
#define TOOLS_HH

#include "starsystem.hh"
#include <QString>

static const int SCALE = 20;

namespace Student {

// Used to convert starsystem's economy to a printable form

QString economyTypeToQstring(const Common::StarSystem::ECONOMY_TYPE& type);

}//Student

#endif // TOOLS_HH
