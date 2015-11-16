#ifndef STACKMENU_HPP_
#define STACKMENU_HPP_

#include "MainIncludes.hpp"
#include <iostream>
#include <stdio.h>
#include <iomanip>


using namespace std;

// Switch statement managing the user answer from stackMenu
void stackManagement(EmployeeStack & stack);


//Prints the stack menu and ask for the user choice
int stackMenu();

// Adds a production worker to the stack
void pushProductionWorker(EmployeeStack & stack);

// Pops a production worker out of the stacks and display its information.
void popProductionWorker(EmployeeStack & stack);

// Destroy the stack and gives appropriate feedback;
void destroyStack(EmployeeStack & stack);


#endif /* EMPLOYEELIST_HPP_ */
