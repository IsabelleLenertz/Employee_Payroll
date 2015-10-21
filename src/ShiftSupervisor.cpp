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
#include "ShiftSupervisor.hpp"

ShiftSupervisor::ShiftSupervisor() {

}

ShiftSupervisor::~ShiftSupervisor(){
	cout << "You are destroying a shift supervisor."<< endl;
}

/**
 * Changes the Annual Salary.
 * The new salary cannot be a negative number
 * Returns true to indicate success, false to indicate failure.
 */
bool ShiftSupervisor::setAnnualSalary(int newSalary){
	// The annual Salary cannot be negative
	if (newSalary >= 0){
		// Changes the salary
		this->annualSalary = newSalary;
		// Returns true to indicate success
		return true;
	}
	// If the new salary is not valid
	else{
		// Does not change the salary and returns false to indicate failure
		return false;
	}
}

/**
 * Returns the annual Salary
 */
const int ShiftSupervisor::getAnnualSalary() {
    return this->annualSalary;
}

/**
 * Changes the Annual Production Bonus.
 * The new bonus cannot be a negative number
 * Returns true to indicate success, false to indicate failure.
 */
bool ShiftSupervisor::setAnnualProductionBonus(int newBonus) {
	// The annual production bonus cannot be negative
	if (newBonus >= 0){
		// Changes the production bonus
		this->annualProductionBonus = newBonus;
		// Returns true to indicate success
		return true;
	}
	// If the new bonus is not valid
	else{
		// Does not change the bonus and returns false to indicate failure
		return false;
	}
}

/**
 * Returns the annual production bonus
 */
const int ShiftSupervisor::getAnnualProductionBonus() {
    return this->annualProductionBonus;
}

/**
 * Use to indicate if the shift supervisor met his rqmts
 */
void ShiftSupervisor::setGoalMeet(bool flag) {
    this->goalsMeet = flag;
}

/**
 * Returns true if the shift supervisor met his rqmts.
 */
const bool ShiftSupervisor::getGoalMeet() {
    return this->goalsMeet;
}

/**
 * The Shift Supervisor if paid his monthly salary + 1/12th of his production bonus if his goals were reached.
 * Throws an exception if the annual salary or the bonus were not setup properly
 */
const double ShiftSupervisor::pay() {
    // If the annual salary was no set up
	if (this->annualSalary == 0){
    	// Does not allow the shift supervisor to be paid.
		throw InvalidPay();
    }
    // If the annual bonus was no set up
    else if(this->annualProductionBonus == 0){
    	// Does not allow the shift supervisor to be paid.
    	throw InvalidBonus();
    }
    else{
    	if (this->goalsMeet == true){
    		return (this->annualSalary + this->annualProductionBonus)/12.0;
    	}
    	else
    	{
    		return (this->annualSalary/12.0);
    	}
    }
}

/**
 * Returns "Shift Supervisor"
 */
const string ShiftSupervisor::whatAmI()
{
	return "Shift Supervisor";
}
