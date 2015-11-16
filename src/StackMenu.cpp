/*
 * StackMenu.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: Isabelle
 */
#include "StackMenu.hpp"

//Prints the stack menu and ask for the user choice
int stackMenu(){
	// Prints the header
	string welcome = "Welcome to the Stack Menu";
	cout << welcome << endl;
	for (int i=0; i< (int)welcome.size(); i++){
		cout << "=";
	}
	cout << endl;

	// Prints the menu
	cout << "1. Push a Production Worker" << endl;
	cout << "2. Pop a Production Worker" << endl;
	cout << "3. Display the stack" << endl;
	cout << "4. Destroy the stack" << endl;
	cout << "5. Return to main menu" << endl;

	//Asks the used for input and returns it
	return Utilities::inputInt("Please enter a menu option :", 1, 4, 5);

}

// Switch statement managing the user answer from stackMenu
void stackManagement(EmployeeStack & stack){
	int userchoice = 0;
	while (userchoice != 5 ){
		userchoice = stackMenu();
		switch(userchoice){
		case 1:{
			pushProductionWorker(stack);
			break;
		}// case 1
		case 2:{
			popProductionWorker(stack);
			break;
		}// case 2
		case 3:{
			printReport(stack);
			break;
		}
		case 4:{
			stack.destroyList();
			cout << "You deleted all the employees in your stack" << endl;
			break;
		}


		}// switch
	}

}

// Adds a production worker to the stack
// Returns true to indicate success, false to indicate failure.
void pushProductionWorker(EmployeeStack & stack){
	// Creates a new production worker
	ProductionWorker * pNewProdWorker = new ProductionWorker;
	setUpProductionWorker(pNewProdWorker);

	// Adds the production worker to the stack
	if (stack.push(pNewProdWorker)){
		// Returns true if the production worker was successfully added
		cout << "Your production worker was successfully added." << endl;
	}
}

void popProductionWorker(EmployeeStack & stack){
	// Creates a pointer to the employee to pop
	Employee * pPopedProdWorker = nullptr;

	// Pops the production worker out of the stack.
	pPopedProdWorker = stack.pop();

	// Displays its Id, name, and pay
	cout << left << setw(7) << "ID" << " " <<  setw(30) << "Full Name" << " " << setw(22) << "Type" << " " << setw(10) << "Hire Date" << endl;
	cout << "------- ------------------------------ ---------------------- ----------" << endl;
	cout << left << setw(7) << pPopedProdWorker->getId() << " ";
	cout << left << setw(30) << pPopedProdWorker->getName() << " ";
	cout << left << setw(22) << pPopedProdWorker->whatAmI() << " ";
	cout << left << setw(10) << pPopedProdWorker->getDate() << " " << endl;

	// Deletes the employee
	delete pPopedProdWorker;

}
