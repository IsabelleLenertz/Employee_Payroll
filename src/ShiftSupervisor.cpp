/*
 * ShiftSupervisor.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Isabelle
 */

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
	if (newSalary <= 0){
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
int ShiftSupervisor::getAnnualSalary() {
    return this->annualSalary;
}

/**
 * Changes the Annual Production Bonus.
 * The new bonus cannot be a negative number
 * Returns true to indicate success, false to indicate failure.
 */
bool ShiftSupervisor::setAnnualProductionBonus(int newBonus) {
	// The annual production bonus cannot be negative
	if (newBonus <= 0){
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
int ShiftSupervisor::getAnnualProductionBonus() {
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
bool ShiftSupervisor::getGoalMeet() {
    return this->goalsMeet;
}

/**
 * The Shift Supervisor if paid his monthly salary + 1/12th of his production bonus if his goals were reached.
 * Throws an exception if the annual salary or the bonus were not setup properly
 */
double ShiftSupervisor::pay() {
    if (this->annualSalary == 0){
    	throw InvalidPay();
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
string ShiftSupervisor::whatAmI()
{
	return "Shift Supervisor";
}

/**
 * @return bool
 */
bool ShiftSupervisor::consoleSetUpAll() {
    return false;
}
