#include "igalaxy.hh"
#include "galaxy.hh"
#include "ship.hh"
#include "cargoship.hh"
#include "warpdrive.hh"
#include "stateexception.hh"
#include "objectnotfoundexception.hh"
#include <QString>
#include <QtTest>

#include <vector>
#include <memory>
using namespace Common;
using namespace Student;

class GalaxyTest : public QObject
{
    Q_OBJECT

public:
    GalaxyTest();

private Q_SLOTS:
    void init();
    void testConstructor();

    void testAddSingleStarSystem();
    void testAddDuplicateStarSystem();

    void testGetRandomSystemWithOneSystem();
    void testGetRandomSystemMultiple();
    void testGetStarSystemByName();
    void testGetStarSystemById();
    void testGetSystemsInRange();

    void testAddSingleShip();
    void testAddingDuplicateShip();

    void testSingleShipInSystem();
    void testShipsInMultipleSystems();
    void testRemovingShip();

private:
    std::shared_ptr<IGalaxy> galaxy_;
};

GalaxyTest::GalaxyTest()
{
    utilityInit(123);
}

// Resetoidaan galaksi(poistetaan vanha ja luodaan uusi) aina ennen uutta testicasea.
// Resetting galaxy before running each test case (removing the old object and creating a new one)
void GalaxyTest::init()
{
    galaxy_.reset();
    galaxy_ = std::make_shared<Galaxy>();
}

void GalaxyTest::testConstructor()
{
    QVERIFY2(galaxy_->getShips()->size() == 0, "No ships should be in a Galaxy when it is created");
    QVERIFY_EXCEPTION_THROWN(galaxy_->getRandomSystem(), ObjectNotFoundException);
}

void GalaxyTest::testAddSingleStarSystem()
{    
    auto starSystem = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    galaxy_->addStarSystem(starSystem);
    QCOMPARE(starSystem, galaxy_->getStarSystemByName(starSystem->getName()));
}

void GalaxyTest::testAddDuplicateStarSystem()
{
    auto starSystem = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    galaxy_->addStarSystem(starSystem);
    QCOMPARE(starSystem, galaxy_->getStarSystemByName(starSystem->getName()));

    //Try adding a star system with same name 'Sol'
    auto dupStarSystem = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Refinery, 2, 10000, Point(15,6));
    QVERIFY_EXCEPTION_THROWN(galaxy_->addStarSystem(dupStarSystem), StateException);

    //Try adding a star system with same id '1'
    auto dupStarSystem1 = std::make_shared<StarSystem>("Sol1", StarSystem::ECONOMY_TYPE::Refinery, 1, 10000, Point(15,6));
    QVERIFY_EXCEPTION_THROWN(galaxy_->addStarSystem(dupStarSystem1), StateException);

    //Try adding a star system with same location '13, 6'
    auto dupStarSystem2 = std::make_shared<StarSystem>("Sol1", StarSystem::ECONOMY_TYPE::Refinery, 2, 10000, Point(13,6));
    QVERIFY_EXCEPTION_THROWN(galaxy_->addStarSystem(dupStarSystem2), StateException);
}

void GalaxyTest::testGetRandomSystemWithOneSystem()
{
    auto starSystem = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    galaxy_->addStarSystem(starSystem);
    QCOMPARE(starSystem, galaxy_->getRandomSystem());
}

void GalaxyTest::testGetRandomSystemMultiple()
{
    auto starSystem1 = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    auto starSystem2 = std::make_shared<StarSystem>("Sirius", StarSystem::ECONOMY_TYPE::Agriculture, 2, 10000, Point(15,6));
    auto starSystem3 = std::make_shared<StarSystem>("Polar", StarSystem::ECONOMY_TYPE::HiTech, 3, 5000, Point(20,12));
    auto starSystem4 = std::make_shared<StarSystem>("Mira", StarSystem::ECONOMY_TYPE::Tourism, 4, 15000, Point(10,8));
    auto starSystem5 = std::make_shared<StarSystem>("Alpha Centauri", StarSystem::ECONOMY_TYPE::Refinery, 5, 15000, Point(1,1));
    galaxy_->addStarSystem(starSystem1);
    galaxy_->addStarSystem(starSystem2);
    galaxy_->addStarSystem(starSystem3);
    galaxy_->addStarSystem(starSystem4);
    galaxy_->addStarSystem(starSystem5);

    auto rSystem1Name = galaxy_->getRandomSystem()->getName();
    auto rSystem2Name = galaxy_->getRandomSystem()->getName();
    auto rSystem3Name = galaxy_->getRandomSystem()->getName();

    auto areRandomAllSame = (rSystem1Name == rSystem2Name) && (rSystem1Name == rSystem3Name);
    QVERIFY2(!areRandomAllSame, "GetRamdomSystem returned same system for 3 times!!");
}

void GalaxyTest::testGetStarSystemByName()
{
    auto starSystem1 = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    auto starSystem2 = std::make_shared<StarSystem>("Sirius", StarSystem::ECONOMY_TYPE::Agriculture, 2, 10000, Point(15,6));
    auto starSystem3 = std::make_shared<StarSystem>("Polar", StarSystem::ECONOMY_TYPE::HiTech, 3, 5000, Point(20,12));
    galaxy_->addStarSystem(starSystem1);
    galaxy_->addStarSystem(starSystem2);
    galaxy_->addStarSystem(starSystem3);
    QCOMPARE(galaxy_->getStarSystemByName("Sirius"), starSystem2);
    QVERIFY_EXCEPTION_THROWN(galaxy_->getStarSystemByName("Mira"), ObjectNotFoundException);
}

void GalaxyTest::testGetStarSystemById()
{
    auto starSystem1 = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    auto starSystem2 = std::make_shared<StarSystem>("Sirius", StarSystem::ECONOMY_TYPE::Agriculture, 2, 10000, Point(15,6));
    auto starSystem3 = std::make_shared<StarSystem>("Polar", StarSystem::ECONOMY_TYPE::HiTech, 3, 5000, Point(20,12));
    galaxy_->addStarSystem(starSystem1);
    galaxy_->addStarSystem(starSystem2);
    galaxy_->addStarSystem(starSystem3);
    QCOMPARE(galaxy_->getStarSystemById(2), starSystem2);
    QVERIFY_EXCEPTION_THROWN(galaxy_->getStarSystemById(5), ObjectNotFoundException);
}

//Tämä testi ei ole vielä millään tapaa täydellinen, varsinkin kun starsystems.json:n
//sisällöstä ja filtteröinnistä ei ole vielä varmuutta.
void GalaxyTest::testGetSystemsInRange()
{
    auto starSystem1 = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    auto starSystem2 = std::make_shared<StarSystem>("Sirius", StarSystem::ECONOMY_TYPE::Agriculture, 2, 10000, Point(15,20));
    auto starSystem3 = std::make_shared<StarSystem>("Polar", StarSystem::ECONOMY_TYPE::HiTech, 3, 5000, Point(10,8));
    galaxy_->addStarSystem(starSystem1);
    galaxy_->addStarSystem(starSystem2);
    galaxy_->addStarSystem(starSystem3);

    auto neighbours = galaxy_->getSystemsInRange(starSystem1, 5);
    QVERIFY2(neighbours.size() == 1, "Wrong number of neighbors");
    QCOMPARE(neighbours.front(), starSystem3);

    auto newStarSystem = std::make_shared<StarSystem>("Discovery", StarSystem::ECONOMY_TYPE::Agriculture, 4, 10000, Point(6,6));
    QVERIFY_EXCEPTION_THROWN(galaxy_->getSystemsInRange(newStarSystem, 5), ObjectNotFoundException);
}


void GalaxyTest::testAddSingleShip()
{
    auto starSystem1 = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    galaxy_->addStarSystem(starSystem1);

    auto ship1 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sol"));
    galaxy_->addShip(ship1);
    QVERIFY(galaxy_->getShips()->size() == 1);
}

void GalaxyTest::testAddingDuplicateShip()
{
    auto starSystem1 = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    galaxy_->addStarSystem(starSystem1);

    auto ship1 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sol"));
    galaxy_->addShip(ship1);

    // Adding the same ship object should throw an exception
    QVERIFY_EXCEPTION_THROWN(galaxy_->addShip(ship1), StateException);

    // Adding a new ship object with same properties should not
    ship1 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sol"));
    galaxy_->addShip(ship1);
    QVERIFY(galaxy_->getShips()->size() == 2);
}

void GalaxyTest::testSingleShipInSystem()
{
    auto starSystem1 = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    auto starSystem2 = std::make_shared<StarSystem>("Sirius", StarSystem::ECONOMY_TYPE::Agriculture, 2, 10000, Point(15,6));
    auto starSystem3 = std::make_shared<StarSystem>("Polar", StarSystem::ECONOMY_TYPE::HiTech, 3, 5000, Point(10,8));
    galaxy_->addStarSystem(starSystem1);
    galaxy_->addStarSystem(starSystem2);
    galaxy_->addStarSystem(starSystem3);


    auto ship1 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sirius"));
    galaxy_->addShip(ship1);
    QVERIFY(galaxy_->getShipsInStarSystem("Sol").size() == 0);
    QVERIFY(galaxy_->getShipsInStarSystem("Sirius").size() == 1);
    QVERIFY(galaxy_->getShipsInStarSystem("Polar").size() == 0);

    // This expects the implementation to store ships in same order as added!?
    //QCOMPARE(ship1, std::dynamic_pointer_cast<CargoShip>(galaxy_->getShipsInStarSystem("Sirius").at(0)));
}

void GalaxyTest::testShipsInMultipleSystems()
{
    auto starSystem1 = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    auto starSystem2 = std::make_shared<StarSystem>("Sirius", StarSystem::ECONOMY_TYPE::HiTech, 2, 5000, Point(20,12));
    auto starSystem3 = std::make_shared<StarSystem>("Polar", StarSystem::ECONOMY_TYPE::Tourism, 3, 15000, Point(10,8));
    galaxy_->addStarSystem(starSystem1);
    galaxy_->addStarSystem(starSystem2);
    galaxy_->addStarSystem(starSystem3);

    auto ship1 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sol"));
    auto ship2 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sirius"));
    auto ship3 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sirius"));

    galaxy_->addShip(ship1);
    galaxy_->addShip(ship2);
    galaxy_->addShip(ship3);
    QVERIFY(galaxy_->getShipsInStarSystem("Sol").size() == 1);
    QVERIFY(galaxy_->getShipsInStarSystem("Sirius").size() == 2);
    QVERIFY(galaxy_->getShipsInStarSystem("Polar").size() == 0);


}

void GalaxyTest::testRemovingShip()
{
    auto starSystem1 = std::make_shared<StarSystem>("Sol", StarSystem::ECONOMY_TYPE::Agriculture, 1, 10000, Point(13,6));
    auto starSystem2 = std::make_shared<StarSystem>("Sirius", StarSystem::ECONOMY_TYPE::HiTech, 2, 5000, Point(20,12));
    auto starSystem3 = std::make_shared<StarSystem>("Polar", StarSystem::ECONOMY_TYPE::Tourism, 3, 15000, Point(10,8));
    galaxy_->addStarSystem(starSystem1);
    galaxy_->addStarSystem(starSystem2);
    galaxy_->addStarSystem(starSystem3);

    auto ship1 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sol"));
    auto ship2 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sirius"));
    auto ship3 = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sirius"));

    galaxy_->addShip(ship1);
    galaxy_->addShip(ship2);
    galaxy_->addShip(ship3);

    galaxy_->removeShip(ship1);
    galaxy_->removeShip(ship3);
    QVERIFY(galaxy_->getShipsInStarSystem("Sol").size() == 0);
    QVERIFY(galaxy_->getShipsInStarSystem("Sirius").size() == 1);
    QVERIFY(galaxy_->getShipsInStarSystem("Polar").size() == 0);

    auto newShip = std::make_shared<CargoShip> (std::make_shared<WarpDrive>(galaxy_), galaxy_->getStarSystemByName("Sol"));
    QVERIFY_EXCEPTION_THROWN(galaxy_->removeShip(newShip), ObjectNotFoundException);
}


QTEST_APPLESS_MAIN(GalaxyTest)

#include "galaxytest.moc"
