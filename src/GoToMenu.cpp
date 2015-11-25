/*
 * GoToMenu.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Isabelle
 */
#include "GoToMenu.hpp"

using namespace std;

void goToMenu(EmployeeList & pList){
	int userchoice = 0;
	while (userchoice != 6 ){
		userchoice = printgoToMenu();
		switch(userchoice){
		// Goes to the first node
		case 1:{
			if ( !(pList.goToFirst()) ){
				cout << "The First node does not exist." << endl;
			}
			break;
		}// case 1

		// Goes to the next node
		case 2:{
			if ( !(pList.goToNext()) ){
				cout << "The Next node does not exist." << endl;
			}
			break;
		}// case 2

		// Goes to the previous node
		case 3:{
			if ( !(pList.goToPrevious()) ){
				cout << "The previous node does not exist." << endl;
			}
			break;
		}// case 3

		// Goes to the Last node
		case 4:{
			if ( !(pList.goToLast()) ){
				cout << "The Last node does not exist." << endl;
			}
			break;
		}// case 4





		// Prints the current employee
		case 5:{
			// If the current pointer points to an employee
			if ( pList.getCurrentPtr() != nullptr ){
				displayEmployee(pList.getCurrentPtr());
			}
			// Else displays an error message
			else{
				cout << "No Employee to display" << endl;
			}
			break;
		}// case 5
		}// switch
	}

}


int printgoToMenu(){
	// Prints the header
	string welcome = "Welcome to the GoTo Menu";
	cout << welcome << endl;
	for (int i=0; i< (int)welcome.size(); i++){
		cout << "=";
	}
	cout << endl;

	// Prints the menu
	cout << "1. Goto First" << endl;
	cout << "2. Goto Next" << endl;
	cout << "3. Goto Previous" << endl;
	cout << "4. Goto Last" << endl;
	cout << "5. Display Current" << endl;
	cout << "6. Return to Main Menu" << endl;


	//Asks the used for input and returns it
	return Utilities::inputInt("Please enter a menu option :", 1, 5, 6);
}



