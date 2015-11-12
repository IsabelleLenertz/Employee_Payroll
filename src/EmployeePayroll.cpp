//*****************

//Project Name: Project #5: Employee Linked List

//Project Description: Optimize employee list using a linked list instead of a vector.

//Project Author: Lenertz Isabelle

//Is this an extra credit Project:  No

//Date completed: 11/11/2015

//Operating system used: Windows 10

//IDE Used:  Eclipse

//*****************

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
void payEveryone(EmployeeList & employees);

/**
 * Print a list of all the employees
 */
void printReport(EmployeeList & listOfEmployee);

/**
 * Goes trough an array of dynamically allocated objects/variables and deletes them.
 */
template <typename T>
void cleanUp(vector<T *> pArray);

/**
 * Prints an error message explaining what parameter the user should enter.
 */
void printError();


int main(int argc, char* argv[]) {

	int numberOfEmployees = 0; // number of employees entered using the command line, will be equal to argv[2]
	int numberShiftSupervisors = 0;
	int numberTeamLeader = 0;
	int numberProdWorker = 0;
	int userChoice = 0; //use to store user's input.
	bool continueWhileLoop = true; // will be changed to false if the user entered command line parameters
	EmployeeList pListOfEmployee;
	//vector<Employee *> pListOfEmployee; // stores pointer to the new Employees.

	 // Check for the number of parameters
	if (argc > 3){
		// Prints an error message explaining what parameters the user should enter.
		printError();
		return 0;
	}
	// If the user entered 3 parameters
	else if (argc == 3){
		// Converts the third parameter to an integer
		numberOfEmployees = atoi(argv[2]); // 0 if the third parameter was not an number, truncated is not an integer or if something else follows an integer
		cout << numberOfEmployees << endl;

		// Check if the second parameter is valid
		if ( (*argv[1] != 'P') && (*argv[1] != 'T') && (*argv[1] != 'S') && (*argv[1] != 'p') && (*argv[1] != 't') && (*argv[1] != 's') ) {
				printError();
				return 0;
		}
		// Check if the third parameter is valid
		else if ( (numberOfEmployees < 1) || (numberOfEmployees > 100) ){
				printError();
				return 0;
		}
	}
	// Offers the user the opportunity to enter new employees as long as (s)he does not reach MAX_EMPLOYEE.
	while (continueWhileLoop == true){
		// Displays the menu and asks for input.
		if (argc == 1){
			userChoice = getUserChoice();
		}
		// If the user choose to enter production workers
		else if( (*argv[1] == 'P') || (*argv[1] == 'p') ){
			// Will exit the program after one while loop
			continueWhileLoop = false;
			// send the user to the section of the switch asking for the input of production workers
			userChoice = 1;
			// The program will not ask for a number of production worker to add, but will use the third parameter.
			numberProdWorker = numberOfEmployees;
		}
		// If the user choose to enter shift supervisors
		else if( (*argv[1] == 'S') || (*argv[1] == 's') ){
			// Will exit the program after one while loop
			continueWhileLoop = false;
			// send the user to the section of the switch asking for the input of shift supervisors
			userChoice = 2;
			// The program will not ask for a number of production worker to add, but will use the third parameter.
			numberShiftSupervisors = numberOfEmployees;
		}
		// If the user choose to enter team leaders
		else if( (*argv[1] == 'T') || (*argv[1] == 't')){
			// Will exit the program after one while loop
			continueWhileLoop = false;
			// send the user to the section of the switch asking for the input of team leaders
			userChoice = 3;
			// The program will not ask for a number of production worker to add, but will use the third parameter.
			numberTeamLeader = numberOfEmployees;
		}
		switch (userChoice){
		// If the user chooses to add production workers
		case 1:{
			// If the user did not enter any parameter using command line.
			if (argc == 1){
				// Asks for the number of production worker he wants to add
				numberProdWorker = Utilities::inputInt("How many Production Workers do you want to add? ", 1, 10, 0) ;
			}
			// If the user indicated he wants to enter 0 employees
			if (numberProdWorker == 0){
				// Exits the switch if the user enters 0.
				break;
			}

			// If the user wants to enter more than 0 employees
			else{
				// Asks for the desired number of production workers
				for (int i = 0; i < numberProdWorker; i++){
					cout << "Production Worker #" << i+1 << ": " << endl;
					// Dynamically allocates a new production worker.
					ProductionWorker *pTempProdWorker = new ProductionWorker;
					// Asks the user for all the information about the production worker.
					setUpProductionWorker(pTempProdWorker);
					// Updates the list of Employees.
					pListOfEmployee.appendNode(pTempProdWorker);
					//pListOfEmployee.push_back(pTempProdWorker);
				}

			}
			// Exists the switch
			break;
		}// end of case 1

		// If the user chooses to add shift supervisors
		case 2:{
			// If the user did not enter any parameter using command line.
			if (argc == 1)
			{
				// Asks for the number of shift supervisors he wants to add
				numberShiftSupervisors = Utilities::inputInt("How many Shift Supervisors do you want to add? ", 1, 10, 0) ;
			}
			// If the user indicated he wants to enter 0 employees
			if (numberShiftSupervisors == 0){
				// Exits the switch if the user enters 0.
				break;
			}

			// If the user wants to enter more than 0 employees
			else{
				// Asks for the desired number of production workers
				for (int i = 0; i < numberShiftSupervisors; i++){
					cout << "Shift Supervisor #" << i+1 << ": " << endl;
					// Dynamically allocates a new production worker.
					ShiftSupervisor *pTempShiftSuper = new ShiftSupervisor;
					// Asks the user for all the information about the production worker.
					setUpShiftSupervisor(pTempShiftSuper);
					// Updates the list of Employees.
					pListOfEmployee.appendNode(pTempShiftSuper);
					//pListOfEmployee.push_back(pTempShiftSuper);
				}
			}
			// Exists the switch
			break;
		}// end of case 2

		// If the user chooses to enter Team Leaders
		case 3: {
			// If the user did not enter any parameter using command line.
			if (argc == 1){
				// Asks for the number of production worker he wants to add
				numberTeamLeader = Utilities::inputInt("How many Team Leaders do you want to add? ", 1, 10, 0) ;
			}
			// If the user wants to add 0 Team Leader.
			if (numberTeamLeader == 0){
				// Exits the switch if the user enters 0.
				break;
			}
			// If the user wants to enter more than 0 employees
			else{
				// Asks for the desired number of team leaders
				for (int i = 0; i < numberTeamLeader; i++){
					cout << "Team Leader #" << i+1 << ": " << endl;
					// Dynamically allocates a new team leader.
					TeamLeader *pTempLeader = new TeamLeader;
					// Asks the user for all the information about the team leader.
					setUpTeamLeader(pTempLeader);
					// Updates the list of Employees.
					pListOfEmployee.appendNode(pTempLeader);
					//pListOfEmployee.push_back(pTempLeader);
				}// end of for
			}// end of else
			// Exists the switch
			break;
		}// end of case 3

		// If the user chooses to pay everyone
		case 4:{
			// Pays all the employees and exists the switch
			payEveryone(pListOfEmployee);
			break;
		} // end of case 4

		// If the user chooses to print a report
		case 5:{
			// Prints a report
			printReport(pListOfEmployee);
			break;
		}
		//If the user chooses to exit the program
		case 9: {
			// Make sure the user wants to exist the program
			cout << "Are you sure you want to exit the program? " << endl;
			cout << "This software does not save any data to the disk, the information about " << pListOfEmployee.getSize() << " employees will be lost." << endl;
			string userChoice = Utilities::inputString("answer(yes/no): ", 2, 3);
			userChoice = Utilities::makeLowerCase(userChoice);

			// if the user answers yes
			if (userChoice == "yes"){
				cout << "Thank you for using our product." << endl;
				cout << "Have nice day." <<endl;
				// Exists the program
				pListOfEmployee.destroyList();
				return 0;
			}
			else if(userChoice == "no") {
				cout << "That's a reasonable choice! "<< endl;
				// Exists the switch, goes back to the beginning of the while loop
				break;
			}

		}// end of case 9
		}// end of switch

	}// end of while

	// If the user entered command line parameters
	if(argc == 3){
		// Pays all the employees before exiting
		payEveryone(pListOfEmployee);
	}
	// Deletes all the dynamically allocated employees before exiting.
	pListOfEmployee.destroyList();

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
	cout << "5. Print Report" << endl;
	cout << "9. Exit Program" << endl;

	//Asks the used for input and returns it
	return Utilities::inputInt("Please enter a menu option :", 1, 5, 9);
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
void payEveryone(EmployeeList& employees){

	Employee * currentEmployee = nullptr;
	int sizeOfList = employees.getSize();

	if (employees.getSize() == 0){
		cout << "You don't have anyone to pay." << endl;
	}// end of if
	else {
		// Prints a header
		cout << endl <<"This Month Pay Roll" << endl << endl;
		cout << setw(15) << left << "ID Number";
		cout << setw(15) << left << "Name";
		cout << setw(30) << left << "Category";
		cout << setw(15) << left << "Total Pay ($)";
		cout << setw(15) << left << "Bonus ($)";
		cout << setw(30) << left << "Comments";
		cout << endl;

		// Prints a separation line
		for (int i=0; i<120; i++){
			cout << "-";
		}
		cout << endl;

		// Goes trough the liked list of Employee and prints the info
		for (int i = 1; i <= sizeOfList; i++) {
			//sets the current point
			if (employees.positionTo(i) == true ){
				currentEmployee = employees.getCurrentPtr();
				// Prints the ID
				cout << setw(15) << currentEmployee->getId();
				// Prints the name
				cout << setw(15) << currentEmployee->getName();
				// Prints the category
				cout << setw(30) << currentEmployee->whatAmI();
				// Prints the monthly salary
				try{
					double pay = currentEmployee->pay();
					cout << setw(15) << fixed << setprecision(2) << pay;
				}
				catch (ProductionWorker::InvalidShift &e){
					cout << "Could not be paid. Shift not set.";
				}
				catch (ProductionWorker::InvalidPayRate &e){
					cout << "Could not be paid. Invalid pay rate.";
				}
				catch (ProductionWorker::InvalidHoursWorked &e){
					cout << "Could not be paid. Invalid number of hours.";
				}
				catch (ShiftSupervisor::InvalidBonus &e){
					cout << "Could not be paid. Bonus not valid.";
				}
				catch (ShiftSupervisor::InvalidPay &e){
					cout << "Could not be paid. Pay not valid.";
				}
				catch (TeamLeader::InvalidFormationRqm &e){
					cout << "Could not be paid. Invalid formation requirement.";
				}
				catch (TeamLeader::InvalidMonthlyBonus &e){
					cout << "Could not be paid. Invalid monthly bonus.";
				}
				try{
					double bonus = currentEmployee->getBonus();
					cout << setw(15) << fixed << setprecision(2) << bonus;
				}
				catch (ProductionWorker::InvalidShift &e){
					cout << "Could not be paid. Shift not set.";
				}
				catch (ProductionWorker::InvalidPayRate &e){
					cout << "Could not be paid. Invalid pay rate.";
				}
				catch (ProductionWorker::InvalidHoursWorked &e){
					cout << "Could not be paid. Invalid number of hours.";
				}
				catch (ShiftSupervisor::InvalidBonus &e){
					cout << "Could not be paid. Bonus not valid.";
				}
				catch (ShiftSupervisor::InvalidPay &e){
					cout << "Could not be paid. Pay not valid.";
				}
				catch (TeamLeader::InvalidFormationRqm &e){
					cout << "Could not be paid. Invalid formation requirement.";
				}
				catch (TeamLeader::InvalidMonthlyBonus &e){
					cout << "Could not be paid. Invalid monthly bonus.";
				}
				cout << setw(30) << currentEmployee->getComment() << endl;
			}

		}// end of for

		cout << endl << endl << endl;
	}// end of else


}// end pay()

template <typename T>
void cleanUp(vector<T *> pArray)
{
	// Goes trough an array
	for(int i = 0; i < pArray.size(); i++){
		// Deletes every dynamically allocated objects
		delete pArray[i];
	}
	pArray.erase(pArray.begin(),pArray.end());
}

/**
 * Prints an error message explaining what parameter the user should enter.
 */
void printError()
{
	string error = "**Error** ";
	cout << error << "Invalid number of arguments." << endl;
	cout << error << "Format of command is: program_name employee-Type number-of-Employees"<< endl;
	cout << error << "Employee type is a <P>roduction Worker, <T>eam Leader, <S>hift Supervisor" << endl;
	cout << error << "Number of Employees is 1 - 100" << endl;
	cout << error << "Example: EmployeePayroll P 10 // Will create 10 production workers" << endl;
}

/**
 * Print a list of all the employees
 */
void printReport(EmployeeList &listOfEmployee){
	string header = "Employee Listing";
	int listSize = listOfEmployee.getSize();
	Employee * ptempEmployee = nullptr;
	if (listSize != 0){
		// Prints a header
			cout << header << endl;
			for (int i = 0; (unsigned int)i<header.size(); i++){
				cout << "=";
			}
			cout << endl;

			cout << left << setw(7) << "ID" << " " <<  setw(30) << "Full Name" << " " << setw(22) << "Type" << " " << setw(10) << "Hire Date" << endl;
			cout << "------- ------------------------------ ---------------------- ----------" << endl;

			// goes through the list
			for (int i = 0; i < listSize; i++){
				if ( listOfEmployee.positionTo(i+1) == true ){
					ptempEmployee = listOfEmployee.getCurrentPtr();
					cout << left << setw(7) << ptempEmployee->getId() << " ";
					cout << left << setw(30) << ptempEmployee->getName() << " ";
					cout << left << setw(22) << ptempEmployee->whatAmI() << " ";
					cout << left << setw(10) << ptempEmployee->getDate() << " " << endl;
				}
				else{
					cout << "Something went wrong i = " << i << endl;
				}

			}
	}// end of if
	else{
		cout << "You don't have any employees saved. No reports to print." << endl;
	}

}

