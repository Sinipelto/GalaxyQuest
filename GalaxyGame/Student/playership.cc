#include "playership.hh"

using namespace Common;

Student::Playership::Playership(std::shared_ptr<ShipEngine> engine,
                                std::shared_ptr<StarSystem> initialLocation,
                                std::shared_ptr<IEventHandler> events,
                                std::shared_ptr<Galaxy> galaxy)
    : Common::Ship(engine, initialLocation, events),
      engine_(engine),
      initLocation_(initialLocation),
      events_(events),
      galaxy_(galaxy),
      currentAction_(nullptr),
      name_(),
      abandoned_(false),
      rectItem_(new QGraphicsRectItem())
{
    rectItem_->setBrush(Qt::blue);
    rectItem_->setZValue(2); // Player is above everything
}

Student::Playership::~Playership()
{
    engine_ = nullptr;
    location_ = nullptr;
    events_ = nullptr;
    galaxy_ = nullptr;
    currentAction_ = nullptr;
    delete rectItem_;
}

QGraphicsRectItem* Student::Playership::getItem() const
{
    return rectItem_;
}

std::shared_ptr<Common::StarSystem> Student::Playership::getSpawnLocation() const
{
    return initLocation_;
}

bool Student::Playership::decideAction()
{
    return 0;
}

void Student::Playership::initGraphics()
{
    rectItem_->setPos(0,0);
    Point point = initLocation_->getCoordinates();
    auto x = point.x*SCALE + 3; // Scale x
    auto y = point.y*SCALE + 3; // Scale y
    rectItem_->setRect(x, y, 10, 10); // Set playership size
}

void Student::Playership::spawn()
{
    initLocation_ = galaxy_->getRandomSystem();
    initGraphics();
}
