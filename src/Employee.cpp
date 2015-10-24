//*****************

//Project Name: Project #3: Chapter 15 Employees

//Project Description: Employee, Production Worker, Shift Supervisor, Team leader classed.
// Create a virtual pay function
// Store Employees in a array
// Catch exception from the pay function

//Project Author: Lenertz Isabelle

//Is this an extra credit Project:  No

//Date completed: 10/21/2015

//Operating system used: Windows 10

//IDE Used:  Eclipse

//*****************

#include "Employee.hpp"


/**
* Default constructor
* Sets the attributes to 0 to signify that they were not initiated.
 */
Employee::Employee() {
	this->name =  " ";
	this->id = 0;
}

/**
 * Default destructor
 * Print a deleting message.
 */
Employee::~Employee(){
	cout << "You are destroying an Employee." << endl;
}

/**
 * The Employee's Id has to be greater than 0.
 * Returns true if the id was changed
 * returns false to indicate failure.
 */
bool Employee::setId(int newId) {

	// If the new id is valid
	if(newId > 0){
		// Changes the id.
		this->id = newId;
		// Returns true to indicate success
		return true;
	}
	// If the new id is not valid
	else{
		//Returns false to indicate faillure.
		return false;
	}
}

/**
 * Return this->id
 */
const int Employee::getId() {
    return this->id;
}

/**
 * Changes the name if it does not start with a space and if greater than 1 character
 * Returns true to indicate success
 * Returns false to indicate failure
 */
bool Employee::setName(string newName) {
	// If the new name is not valid (ie 1 char or starting with " "
	if ( (newName[0] == ' ') || (newName.length() <= 1) ){
		// Does not change this->name and returns false to indicate failure
		return false;
	}
	// If the new name was  valid
	else{
		// Changes this->name
		this->name = newName;
		// Returns true to indicate success
		return true;

	}
}

/**
 * Returns the name.
 */
const string Employee::getName() {
    return this->name;
}

/**
 *	Sets up this->hireDate using the Date's setDate function.
 *	Returns true to indicate success, false to indicate failure.
 */
bool Employee::setDate(string newDate) {
    // Calls the hireDate setup function
	// Tries to change the date
	if ( this->hireDate.setDate(newDate) == true ){
		// return true to indicate success;
		return true;
    }
	// If newDate was invalid
	else {
		// Returns false to indicate failure
		return false;
	}
}

/**
 * return the date as a usable string.
 */
const string Employee::getDate() {
    return this->hireDate.getDate();
}





