/*
 * QueueMenu.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Isabelle
 */

#include "QueueMenu.hpp"

int printQueueMenu(){
	// Prints the header
	string welcome = "Welcome to the Queue Menu";
	cout << welcome << endl;
	for (int i=0; i< (int)welcome.size(); i++){
		cout << "=";
	}
	cout << endl;

	// Prints the menu
	cout << "1. Enque Que" << endl;
	cout << "2. Deque Que" << endl;
	cout << "3. List Que" << endl;
	cout << "4. Destroy Que" << endl;
	cout << "5. Return to Main Menu" << endl;

	//Asks the used for input and returns it
	return Utilities::inputInt("Please enter a menu option :", 1, 5, 5);
}// printQueueMenu

// Switch statement managing the user answer from queue Menu
void queueManagement(EmployeeQue & queue){
	int userchoice = 0;
	while (userchoice != 5 ){
		userchoice = printQueueMenu();
		switch(userchoice){
		case 1:{
			enqueProductionWorker(queue);
			break;
		}// case 1
		case 2:{
			dequeProductionWorker(queue);
			break;
		}// case 2
		case 3:{
			printReport(queue);
			break;
		}
		case 4:{
			destroyQue(queue);
			break;
		}
		}// switch
	}
}

// Adds a production worker to the stack
void enqueProductionWorker(EmployeeQue & queue){
	// Creates a new production worker
	ProductionWorker * pNewProdWorker = new ProductionWorker;
	setUpProductionWorker(pNewProdWorker);

	// Adds the production worker to the queue
	if (queue.enque(pNewProdWorker)){
		// Returns true if the production worker was successfully added
		cout << "Your production worker was successfully added." << endl;
	}
}

void dequeProductionWorker(EmployeeQue & queue){
	// Creates a pointer to the employee to pop
	Employee * pDequedProdWorker = nullptr;

	// Pops the production worker out of the stack.
	pDequedProdWorker = queue.deque();

	// If a Employee was removed from the queue
	if (pDequedProdWorker != nullptr){
		// Displays its Id, name, and pay
		displayEmployee(pDequedProdWorker);
	}
	else{
		cout << "There is no employee in your queue." << endl;
	}

	// Deletes the employee
	delete pDequedProdWorker;

}

void destroyQue(EmployeeQue & queue){
	if (queue.getSize() == 0){
		cout << "Your queue is already empty" << endl;
	}
	else{
		queue.destroyList();
		cout << "You deleted all the employees in your queue." << endl;
	}
}
