//============================================================================
// Name        : EmployeePayroll.cpp
// Author      : Isabelle Delmas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Utilities.hpp"
#include "Employee.hpp"
#include "ProductionWorker.hpp"
#include "ShiftSupervisor.hpp"
#include "TeamLeader.hpp"

using namespace std;

int getUserChoice();

int main() {
	int userChoice = 0; //use to stroe user's input.


	userChoice = getUserChoice();
	cout << userChoice;
	return 0;
}

int getUserChoice()
{
	// Prints the header
	string welcome = "Welcome to the Employee Pay System";
	cout << welcome << endl;
	for (int i=0; i< (int)welcome.size(); i++){
		cout << "=";
	}
	cout << endl;

	// Prints the menu
	cout << "1. Enter Production Worker Information" << endl;
	cout << "2. Enter Shift Supervisor Information" << endl;
	cout << "3. Enter Team Leader Information" << endl;
	cout << "4. Pay Everyone" << endl;
	cout << "9. Exit Program" << endl;

	//Asks the used for input and returns it
	return Utilities::inputInt("Please enter a menu option :", 1, 4, 9);

}
