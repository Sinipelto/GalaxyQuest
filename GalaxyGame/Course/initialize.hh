#ifndef INITIALIZE_HH
#define INITIALIZE_HH

#include "igalaxy.hh"
#include "ieventhandler.hh"
#include "igamerunner.hh"

#include <functional>
#include <memory>

#ifdef English_dox
/**
 * @file
 * @brief This module contains the functions related to the initialization of the game.
 * * This is used to integrate the code from course side with the implementation by students
 */
#endif
namespace Common {
typedef std::function<std::shared_ptr<Common::Ship>(std::shared_ptr<Common::StarSystem>,
                                                    std::shared_ptr<Common::IEventHandler>)> BuildFunction;

#ifdef English_dox
/**
 * @brief getGameRunner Creates an instance of the class that implements IGameRunner interface
 *
 * @post Created IGameRunner instance is associated with the galaxy and event handler
 * @post The galaxy passed as a parameter is populated with star systems.
 * @param galaxy Galaxy, with which the returned object should be associated.
 * @param handler Event handler, with which the returned object should be associated.
 * @exception IOException Could not open file Assets/starsystems.json for reading.
 * @exception FormatException Format of file Assets/starsystems.json is invalid.
 * @return Created instance.
 */
#endif
std::shared_ptr<IGameRunner> getGameRunner(std::shared_ptr<IGalaxy> galaxy,
                                           std::shared_ptr<IEventHandler> handler);

#ifdef English_dox
/**
 * @brief addNewShipType registers a new ship type to be used for building
 * @post  New ships of the registered type can be created
 * @param typeName Name of the new ship type
 * @param buildFunction Function that can be used to build new ship types
 * @note This function needs to be used, only in case if we want to create new types of ships and motors as an additional feature
 */
#endif
void addNewShipType(std::string typeName, BuildFunction buildFunction);

} //Common

#endif // INITIALIZE_HH
