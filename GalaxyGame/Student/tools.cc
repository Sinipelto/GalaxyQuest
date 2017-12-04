#include "tools.hh"

QString Student::economyTypeToQstring(const Common::StarSystem::ECONOMY_TYPE &type)
{
    using TYPE = Common::StarSystem::ECONOMY_TYPE;
    switch (type) {
    case TYPE::Agriculture:
        return QString("Agriculture");
    case TYPE::Colony:
        return (QString("Colony"));
    case TYPE::Extraction:
        return (QString("Extraction"));
    case TYPE::HiTech:
        return (QString("HiTech"));
    case TYPE::Industrial:
        return (QString("Industrial"));
    case TYPE::Military:
        return (QString("Military"));
    case TYPE::None:
        return (QString("None"));
    case TYPE::Refinery:
        return (QString("Refinery"));
    case TYPE::Service:
        return (QString("Service"));
    case TYPE::Terraforming:
        return (QString("Terraforming"));
    case TYPE::Tourism:
        return (QString("Tourism"));
    }
    return QString("ENUMERATION ERROR");
}
