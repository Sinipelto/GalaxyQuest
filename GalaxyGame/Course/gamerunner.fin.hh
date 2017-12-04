#ifdef Finnish_dox
/**
* @file gamerunner.hh
* @brief Toteuttaa rajapinnan IGamerunner.
*/

/**
 * @brief Sisältää valmiina annettuja luokkia, joihin ei voi viitata opiskelijoiden tekemässä koodissa.
 * @namespace Course
 */

/**
* @class Course::GameRunner
* @brief Toteuttaa rajapinnan IGamerunner.
*
* Toiminnallisuus käytännössä sama, kuin on luvattu rajapinnassa IGameRunner.
* Rakentaja vaatii kuitenkin enemmän parametrejä.
*/

/**
* @fn Course::GameRunner::GameRunner(std::shared_ptr<Common::IGalaxy> galaxy,
       std::shared_ptr<Common::IEventHandler> events);
* @brief Rakentaja.
* @post Olio on assosioitu galaksin kanssa.
* @param galaxy Galaksi, jonka kanssa olio assosioidaan.
* @param events Tätä kautta spawnataan aluksen eventit. Voi olla myös nullptr.
*/


/**
* @fn virtual void Common::GameRunner::spawnShips(unsigned int count);
* @copydoc igamerunner::spawnShips()
*/


/**
* fn virtual void Common::GameRunner::createActions();
* @copydoc Common::GameRunner::igamerunner::createActions()
*/

/**
* @fn virtual void Common::GameRunner::doActions();
* @copydoc igamerunner::doActions()
*/



#endif
// EOF: gamerunner.fin.hh
