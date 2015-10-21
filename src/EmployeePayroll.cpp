//============================================================================
// Name        : EmployeePayroll.cpp
// Author      : Isabelle Delmas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include "Utilities.hpp"
#include "Employee.hpp"
#include "ProductionWorker.hpp"
#include "ShiftSupervisor.hpp"
#include "TeamLeader.hpp"

using namespace std;

/**
 * Prints the menu and ask for the user choice
 */
int getUserChoice();

/**
 * Calls all the appropriate mutators for an Employee type.
 * Sets all the attributes.
 */
void setUpEmployee(Employee *pEmployee);
void setUpProductionWorker(ProductionWorker *pProdWorker);
void setUpShiftSupervisor(ShiftSupervisor *pShiftSuper);
void setUpTeamLeader(TeamLeader *pLeader);

/**
 * Goes through an array of employee and pays everyone.
 */
void payEveryone(Employee* employees[], int arraySize);

/**
 * Goes trough an array of dynamically allocated objects/variables and deletes them.
 */
template <typename T>
void cleanUp(T *pArray[], int arraySize);


int main() {
	const int MAX_EMPLOYEE = 10;
	int employeeCounter = 0; // number of employee entered by the user.
	int userChoice = 0; //use to store user's input.
	Employee *pListOfEmployee[MAX_EMPLOYEE]; // stores pointer to the new Employees.

	// Offers the user the opportunity to enter new employees as long as (s)he does not reach MAX_EMPLOYEE.
	while (employeeCounter < MAX_EMPLOYEE){
		// Displays the menu and asks for input.
		userChoice = getUserChoice();
		switch (userChoice){

		// If the user chooses to add production workers
		case 1:{
			// Asks for the number of production worker he wants to add
			// does not allow to go over MAX_EMPLOYEE
			int numberProdWorker = Utilities::inputInt("How many Production Workers do you want to add? ", 1, (MAX_EMPLOYEE-employeeCounter), 0) ;

			if (numberProdWorker == 0){
				// Exits the switch if the user enters 0.
				break;
			}

			// If the user confirms (s)he wants to enter Production Workers
			else{
				// Asks for the desired number of production workers
				for (int i = 0; i < numberProdWorker; i++){
					cout << "Production Worker #" << i+1 << ": " << endl;
					// Dynamically allocates a new production worker.
					ProductionWorker *pTempProdWorker = new ProductionWorker;
					// Asks the user for all the information about the production worker.
					setUpProductionWorker(pTempProdWorker);
					// Updates the list of Employees.
					pListOfEmployee[employeeCounter+i] = pTempProdWorker;
				}
				// Updates the counter of employee entered by the user.
				employeeCounter += numberProdWorker;
			}
			// Exists the switch
			break;
		}
		// If the user chooses to add shift supervisors
		case 2:{
			// Asks for the number of shift supervisors he wants to add
			// does not allow to go over MAX_EMPLOYEE
			int numberShiftSupervisors = Utilities::inputInt("How many Shift Supervisors do you want to add? ", 1, (MAX_EMPLOYEE-employeeCounter), 0) ;

			if (numberShiftSupervisors == 0){
				// Exits the switch if the user enters 0.
				break;
			}

			// If the user confirms (s)he wants to enter Production Workers
			else{
				// Asks for the desired number of production workers
				for (int i = 0; i < numberShiftSupervisors; i++){
					cout << "Shift Supervisor #" << i+1 << ": " << endl;
					// Dynamically allocates a new production worker.
					ShiftSupervisor *pTempShiftSuper = new ShiftSupervisor;
					// Asks the user for all the information about the production worker.
					setUpShiftSupervisor(pTempShiftSuper);
					// Updates the list of Employees.
					pListOfEmployee[employeeCounter+i] = pTempShiftSuper;
				}
				// Updates the counter of employee entered by the user.
				employeeCounter += numberShiftSupervisors;
			}
			// Exists the switch
			break;
		}
		case 3: {
			// Asks for the number of production worker he wants to add
			// does not allow to go over MAX_EMPLOYEE
			int numberTeamLeader = Utilities::inputInt("How many Team Leaders do you want to add? ", 1, (MAX_EMPLOYEE-employeeCounter), 0) ;

			// If the user wants to add 0 Team Leader.
			if (numberTeamLeader == 0){
				// Exits the switch if the user enters 0.
				break;
			}

			// If the user confirms (s)he wants to enter team leaders
			else{
				// Asks for the desired number of team leaders
				for (int i = 0; i < numberTeamLeader; i++){
					cout << "Team Leader #" << i+1 << ": " << endl;
					// Dynamically allocates a new team leader.
					TeamLeader *pTempLeader = new TeamLeader;
					// Asks the user for all the information about the team leader.
					setUpTeamLeader(pTempLeader);
					// Updates the list of Employees.
					pListOfEmployee[employeeCounter+i] = pTempLeader;
				}
				// Updates the counter of employee entered by the user.
				employeeCounter += numberTeamLeader;
			}
			// Exists the switch
			break;
		}
		case 4:{
			if (employeeCounter == 0){
				cout << "You don't have anyone to pay." << endl;
			}
			else{
				payEveryone(pListOfEmployee, employeeCounter);
			}
			break;
		}

		case 9: {
			// Make sure the user wants to exist the program
			cout << "Are you sure you want to exit the program? " << endl;
			cout << "This sofware does not save any data to the disk, the information about " << employeeCounter << " employees will be lost." << endl;
			string userChoice = Utilities::inputString("answer(yes/no): ", 2, 3);
			userChoice = Utilities::makeLowerCase(userChoice);

			// if the user answers yes
			if (userChoice == "yes"){
				cout << "Thank you for using our product." << endl;
				cout << "Have nice day." <<endl;
				// Exists the program
				cleanUp(pListOfEmployee, employeeCounter);
				return 0;
			}
			else if(userChoice == "no") {
				cout << "That's a reasonable choice! "<< endl;
				// Exists the switch, goes back to the bening of the while loop
				break;
			}

		}// case 9
		}// switch

	}// while

	// Indicates that the maximum number of employee has been reached.
	if (employeeCounter == 0){
		cout << "You don't have anyone to pay." << endl;
	}
	else{
		cout << "You have reached the maximum number of employees." << endl;
		cout << "This month's payroll: " << endl;
		payEveryone(pListOfEmployee, employeeCounter);
	}

	// Deletes all the dynamically allocated employees before exiting.
	cleanUp(pListOfEmployee, employeeCounter);

	return 0;
}// main

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
			cout << "A name needs more than one character and cannot start with a space." << endl;
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
void setUpShiftSupervisor(ShiftSupervisor *pShiftSuper){
	string userInput = "";

	setUpEmployee(pShiftSuper);
	// Asks the user for the annual salary
	while ( (pShiftSuper->setAnnualSalary( Utilities::inputInt("Annual Salary: ", 0, 200000, 200001)))  == false ){
	}
	// Asks the user for annual production bonus
	while ( (pShiftSuper->setAnnualProductionBonus( Utilities::inputInt("Annual Production Bonus: ", 0, 200000, 200001)))  == false ){
	}
	// Asks the user if the production goal where meet
	while ( userInput != "yes" && userInput != "no") {
		// Inputs a string, and converts it to lower cases
		userInput = Utilities::inputString("Did (s)he meet their production goals (yes/no)? ", 2, 3);
		userInput = Utilities::makeLowerCase(userInput);
		// Changes the goalMeet attribute according to the user response.
		if (userInput == "yes")
		{
			pShiftSuper->setGoalMeet(true);
		}
		else if(userInput == "no") {
			pShiftSuper->setGoalMeet(false);
		}
	}
}
void setUpTeamLeader(TeamLeader *pLeader){
	setUpProductionWorker(pLeader);
	// Asks the user for the monthly bonus
	while ( (pLeader->setMonthlyBonus( Utilities::inputInt("Monthly Bonus: ", 0, 20000, 20001)))  == false ){
	}
	// Asks the user for the number of hours of formation required
	while ( (pLeader->setFormationRqm( Utilities::inputInt("Minimum hours of formation required: ", 0, 744, 745)))  == false ){
	}
	// Asks the user for the number of hours of formation attended this month
	while ( (pLeader->setFormationAttended( Utilities::inputInt("Hours of formation attended this month: ", 0, 744, 745)))  == false ){
	}

}
void payEveryone(Employee* employees[], int arraySize){

	// Prints a header
	cout << setw(15) << left << "ID Number";
	cout << setw(15) << left << "Name";
	cout << setw(30) << left << "Category";
	cout << setw(15) << left << "Pay ($)";
	cout << endl;

	// Prints a separation line
	for (int i=0; i<75; i++){
		cout << "-";
	}
	cout << endl;

	// Goes trough the array of Employee and prints the info
	for (int i = 0; i < arraySize; i++) {
		// Prints the ID
		cout << setw(15) << employees[i]->getId();
		// Prints the name
		cout << setw(15) << employees[i]->getName();
		// Prints the category
		cout << setw(30) << employees[i]->whatAmI();
		// Prints the monthly salary
		try{
			double pay = employees[i]->pay();
			cout << setw(15) << fixed << setprecision(2) << pay;
			cout << endl;
		}
		catch (ProductionWorker::InvalidShift &e){
			cout << "Could not be paid. Shift not set."<< endl;
		}
		catch (ProductionWorker::InvalidPayRate &e){
			cout << "Could not be paid. Invalid pay rate."<< endl;
		}
		catch (ProductionWorker::InvalidHoursWorked &e){
			cout << "Could not be paid. Invalid number of hours." << endl;
		}
		catch (ShiftSupervisor::InvalidBonus &e){
			cout << "Could not be paid. Bonus not valid." << endl;
		}
		catch (ShiftSupervisor::InvalidPay &e){
			cout << "Could not be paid. Pay not valid." << endl;
		}
		catch (TeamLeader::InvalidFormationRqm &e){
			cout << "Could not be paid. Invalid formation requirement." << endl;
		}
		catch (TeamLeader::InvalidMonthlyBonus &e){
			cout << "Could not be paid. Invalid monthly bonus." << endl;
		}
	}// end of for

	cout << endl << endl << endl;

}// end pay()

template <typename T>
void cleanUp(T *pArray[], int arraySize)
{
	// Goes trough an array
	for(int i = 0; i<arraySize; i++){
		// Deletes every dynamicaly allocated objects
		delete pArray[i];
	}
}



