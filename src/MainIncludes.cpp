/*
 * MainIncludes.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Isabelle
 */
#include "MainIncludes.hpp"

using namespace std;




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
	cout << "6. Stack Menu" << endl;
	cout << "8. Goto Menu" << endl;
	cout << "9. Exit Program" << endl;

	//Asks the used for input and returns it
	return Utilities::inputInt("Please enter a menu option :", 1, 9, 9);
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

void displayEmployee(Employee * pEmployee){
	cout << left << setw(7) << "ID" << " " <<  setw(30) << "Full Name" << " " << setw(22) << "Type" << " " << setw(10) << "Hire Date" << endl;
	cout << "------- ------------------------------ ---------------------- ----------" << endl;
	cout << left << setw(7) << pEmployee->getId() << " ";
	cout << left << setw(30) << pEmployee->getName() << " ";
	cout << left << setw(22) << pEmployee->whatAmI() << " ";
	cout << left << setw(10) << pEmployee->getDate() << " " << endl;

}

