//*****************

//Project Name: Project #6: Queue, Stack, and recursive functions

//Project Description: 	Create a Queue and a stack class inherited from the Linked list.
//						Create two recursive function (total pay, and destroy list).
//						Create a gotTo menu

//Project Author: Lenertz Isabelle

//Is this an extra credit Project:  yes
//									Make your linked list a doubly linked list

//Date completed: 24/11/2015

//Operating system used: Windows 10

//IDE Used:  Eclipse

//*****************

#include "MainIncludes.hpp"

using namespace std;

int main(int argc, char* argv[]) {

	int numberOfEmployees = 0; // number of employees entered using the command line, will be equal to argv[2]
	int numberShiftSupervisors = 0;
	int numberTeamLeader = 0;
	int numberProdWorker = 0;
	int userChoice = 0; //use to store user's input.
	bool continueWhileLoop = true; // will be changed to false if the user entered command line parameters
	EmployeeList pListOfEmployee;
	EmployeeStack stack;
	EmployeeQue queue;

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
		}// case 5

		// If the user chooses to go to the go to menu
		case 6:{
			goToMenu(pListOfEmployee);
			break;
		}// case 6

		// If the user chooses to o into the queue menu
		case 7:{
			queueManagement(queue);
			break;
		}// case 7

		// If the user chooses to go into the stack menu
		case 8:{
			stackManagement(stack);
			break;

		} // case6





		// If the user chooses to destroy the list recursively
		case 9:{
			int numberDestroyed = pListOfEmployee.recursiveDestruction();
			cout << "You destroyed " << numberDestroyed << " Employee(s)" << endl;
			break;
		}// case 9

		// If the user chooses to get to total pay for this period
		case 10:{
			int totalPay = pListOfEmployee.recPayPeriod();
			cout << "Total pay for this period: $" << fixed << setprecision(2) << totalPay << endl;
			break;
		}// case 9

		//If the user chooses to exit the program
		case 11: {
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


