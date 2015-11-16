/*
 * QueueMenu.hpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Isabelle
 */

#ifndef QUEUEMENU_HPP_
#define QUEUEMENU_HPP_

#include "MainIncludes.hpp"

using namespace std;

int printQueueMenu();

// Switch statement managing the user answer from queue Menu
void queueManagement(EmployeeQue & queue);

// Adds a production worker to the stack
void enqueProductionWorker(EmployeeQue & queue);

// Retrieves a production worker form the que and prints the information
void dequeProductionWorker(EmployeeQue & queue);

// destroy the queue and gives appropriate feedback;
void destroyQue(EmployeeQue & queue);







#endif /* QUEUEMENU_HPP_ */
