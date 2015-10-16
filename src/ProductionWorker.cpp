/*
 * ProductionWorker.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Isabelle
 */

#include "ProductionWorker.hpp"

/**
 * Default constructor
 * Sets the attributes to 0 to signify that they were not initiated.
 */
ProductionWorker::ProductionWorker() {
	this->hoursWorked = 0.0;
	this->payRate = 0;
	this->shift = INVALID;
}

/**
 * Default destructor
 * Print a deleting message.
 */
ProductionWorker::~ProductionWorker(){
	cout << "You are destroying a ProductionWorker." << endl;
}

/**
 * Changes the shift of the Employee
 * Returns true to indicate success, false to indicate failure.
 */
bool ProductionWorker::setShift(string newShift) {

	// Converts the new shift to uppercases
	newShift = Utilities::makeUpperCase(newShift);

	if (newShift == "DAY"){
		// change this->shift to DAY.
		this->shift = DAY;
		// Returns true to indicate success.
		return true;
	}
	else if (newShift == "NIGHT"){
		// Changes this->shift to NIGHT
		this->shift = NIGHT;
		// Returns true to indicate success.
		return true;
	}
	else{
		// if the new shift was invalid.
		// returns false to indicate failure.
		return false;
	}
}

/**
 * Returns the shift the production worker is working, using the Shift enum datatype
 */
Shift ProductionWorker::getShift() {
    return this->shift;
}

/**
 * Sets the hourly pay rate of the Production Worker.
 * has to be >0
 * return true to indicate success, false to indicate failure.
 */
bool ProductionWorker::setPayRate(double newPayrate) {
	// If the pay rate was valid
	if (newPayrate > 0){
		// Changes this->payRate
		this->payRate = newPayrate;
		// Returns true to indicate success
		return true;
	}
	// if the new pay rate was invalid
	else{
		// Does not change the pay rate and returns false to indicate failure
		return false;
	}
}

/**
 * Returns the Production Worker's pay rate.
 */
double ProductionWorker::getPayRate() {
    return this->payRate;
}

/**
 * Changes the Production Worker hours worked
 * Has to be >0
 * returns true to indicate success, false to indicate failure.
 */
bool ProductionWorker::setHoursWorked(double newHours) {
    // If the new hours are valid.
	if (newHours > 0){
    	// changes the hours worked
    	this->hoursWorked = newHours;
    	// return true to indicate success
    	return true;
    }
	// If the new hours are not valid.
    else{
    	// Does not change the hours, returns false to indicate failure
    	return false;
    }
}

/**
 * Returns the hours worked by the Production Worker
 */
double ProductionWorker::getHoursWorked() {
    return this->hoursWorked;
}

/**
 * @return double
 */
double ProductionWorker::pay() {
    return 0.0;
}

/**
 * @return bool
 */
bool ProductionWorker::consoleSetUpAll() {
    return false;
}
