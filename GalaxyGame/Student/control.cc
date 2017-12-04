#include "control.hh"
#include "gamewindow.hh"

Student::Control::Control(Student::Playership* player, GameWindow* gameWindow, std::vector<SystemComplex> &complex):
    player_(player),
    gameWindow_(gameWindow),
    complex_(complex)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setPos(0,0);
}

Student::Control::~Control()
{
    for (auto iter = complex_.begin();iter!=complex_.end();iter++) {
        delete iter->objectShape;
        iter->object = nullptr;
    }
}

void Student::Control::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_R) {
        gameWindow_->rescueShipPublic();
    }
    else if (event->key() == Qt::Key_W || event->key() == Qt::Key_A ||
           event->key() == Qt::Key_S || event->key() == Qt::Key_D ) {

        auto x = player_->getItem()->x();
        auto y = player_->getItem()->y();

        const int n = 6; // How much the ship position changes

        // setPos is faster than setRect
        switch (event->key()) {
        case Qt::Key_W:
            player_->getItem()->setPos(x, y-n);
            break;
        case Qt::Key_A:
            player_->getItem()->setPos(x-n, y);
            break;
        case Qt::Key_S:
            player_->getItem()->setPos(x, y+n);
            break;
        case Qt::Key_D:
            player_->getItem()->setPos(x+n, y);
            break;
        }
        // After moving
        gameWindow_->centerOnPlayer();
    }
}

std::shared_ptr<Common::StarSystem> Student::Control::checkCollideWithSystem()
{
    // If player collides with starsystem, return pointer to system
    // Otherwise returns nullpointer

    auto colliderList = player_->getItem()->collidingItems(); // Items player are colliding with

    for (auto item = colliderList.begin(); item != colliderList.end(); item++) {

        if (dynamic_cast<QGraphicsEllipseItem*>(*item) != nullptr) {
            // Collider is starsystem (ellipseItem)

            for (auto iter = complex_.begin(); iter!=complex_.end();iter++) {
                if (iter->objectShape == *item) {
                    return iter->object; // Return system collided
                }
            }
        }
    }
    return nullptr;
}
