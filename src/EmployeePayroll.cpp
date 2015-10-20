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
void setUpEmployee(Employee *pEmployee);
void setUpProductionWorker(ProductionWorker *pProdWorker);
void setUpShiftSupervisor();
void setUpTeamLeader();

int main() {
	const int MAX_EMPLOYEE = 100;
	int employeeCounter = 0; // number of employee entered by the user.
	int userChoice = 0; //use to store user's input.
	Employee *pListOfEmployee[MAX_EMPLOYEE]; // stores pointer to the new Employees.

	// Offers the user the opportunity to enter new employees as long as (s)he does not reach MAX_EMPLOYEE.
	while (employeeCounter < MAX_EMPLOYEE){
		// Displays the menu and asks for input.
		userChoice = getUserChoice();
		switch (userChoice){

		// If the user choses to add production workers
		case 1:
			// Asks for the number of production worker he wants to add
			// does not allow to go over MAX_EMPLOYEE
			int numberProdWorker = Utilities::inputInt("How many Production Workers do you want to add? ", 1, (MAX_EMPLOYEE-employeeCounter), 0) ;

			if (numberProdWorker == 0){
				// Exits the switch if the user enters 0.
				break;
			}

			else{
				// Asks for the desired number of production workers
				for (int i = 0; i < numberProdWorker; i++){
					// Dynamically allocates a new production worker.
					ProductionWorker *pTempProdWorker = new ProductionWorker;
					// Asks the user for all the information about the production worker.
					setUpProductionWorker(pTempProdWorker);
					// Updates the list of Employee.
					pListOfEmployee[employeeCounter+i] = pTempProdWorker;
				}
				// Updates the counter of employee entered by the user.
				employeeCounter += numberProdWorker;
			}
			// Exists the switch
			break;

	}

}

	return 0;
}

int getUserChoice(){
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

void setUpEmployee(Employee *pEmployee){
	while ( (pEmployee->setName( Utilities::inputString("Enter the name: ", 0, 15)))  == false  ){
			cout << "A name cannot have less than one character and cannot start with a space." << endl;
	}
	while ( (pEmployee->setId( Utilities::inputInt("Enter the Id number: ", 0, 100000, 10001)))  == false ){
	}
	while ( (pEmployee->setDate( Utilities::inputString("Enter the hiring date: ", 10, 10)))  == false ){
	}
}
void setUpProductionWorker(ProductionWorker *pProdWorker){
	setUpEmployee(pProdWorker);
	while ( (pProdWorker->setShift( Utilities::inputString("Is (s)he working day or night shifts? (night or day) ", 3, 5)))  == false ){
	}
	while ( (pProdWorker->setPayRate( Utilities::inputDouble("Hourly pay rate: ", 0, 100, 101)))  == false ){
	}
	while ( (pProdWorker->setHoursWorked( Utilities::inputDouble("Hours worked this month: ", 0, 740, 741)))  == false ){
	}

}
void setUpShiftSupervisor(){

}
void setUpTeamLeader(){

}
