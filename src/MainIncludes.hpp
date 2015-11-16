/*
 * MainIncludes.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: Isabelle
 */
#ifndef MAININCLUDES_HPP_
#define MAININCLUDES_HPP_

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include "Utilities.hpp"
#include "Employee.hpp"
#include "ProductionWorker.hpp"
#include "ShiftSupervisor.hpp"
#include "TeamLeader.hpp"
#include "EmployeeList.hpp"
#include "EmployeeStack.hpp"
#include "StackMenu.hpp"


using namespace std;


// Prints the menu and ask for the user choice
int getUserChoice();


// Calls all the appropriate mutators for an Employee type.
// Sets all the attributes.
void setUpEmployee(Employee *pEmployee);
void setUpProductionWorker(ProductionWorker *pProdWorker);
void setUpShiftSupervisor(ShiftSupervisor *pShiftSuper);
void setUpTeamLeader(TeamLeader *pLeader);


// Goes through an array of employee and pays everyone.
void payEveryone(EmployeeList & employees);


// Print a list of all the employees
void printReport(EmployeeList & listOfEmployee);
// Displays only one Employee
void displayEmployee(Employee * pEmployee);


// Goes trough an array of dynamically allocated objects/variables and deletes them.
template <typename T>
void cleanUp(vector<T *> pArray);


//Prints an error message explaining what parameter the user should enter.
void printError();



#endif /* EMPLOYEELIST_HPP_ */




