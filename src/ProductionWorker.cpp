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
const Shift ProductionWorker::getShift() {
    return this->shift;
}

/**
 * Sets the hourly pay rate of the Production Worker.
 * has to be >=0
 * return true to indicate success, false to indicate failure.
 */
bool ProductionWorker::setPayRate(double newPayrate) {
	// If the pay rate was valid
	if (newPayrate >= 0){
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
const double ProductionWorker::getPayRate() {
    return this->payRate;
}

/**
 * Changes the Production Worker hours worked
 * Has to be >=0
 * returns true to indicate success, false to indicate failure.
 */
bool ProductionWorker::setHoursWorked(double newHours) {
    // If the new hours are valid.
	if (newHours >= 0){
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
const double ProductionWorker::getHoursWorked() {
    return this->hoursWorked;
}

/**
 * Pays the Production worker hoursWorked * payRate.
 * Pays night worker 50% bonus
 * throws the exceptions : InvalidHoursWorked, InvalidPayRate, InvalidShift if the attributes were not setup properly
 */
const double ProductionWorker::pay() {

	// Throws an exception if this->hoursWorked is not setup properly
	if (this->hoursWorked <= 0)
	{
		throw InvalidHoursWorked();
	}
	// Throws an exception if this->hourlyPayRate is not set properly.
	else if (this->payRate <=0){
		throw InvalidPayRate();
	}
	else if (this->shift == NIGHT ){
    	// A production worker working night shift is paied 50% bonus
    	return (this->payRate)*1.5*(this->hoursWorked);
    }
    else if (this->shift == DAY){
    	// Returns the normal pay
    	return (this->payRate)*(this->hoursWorked);
    }
	// Throws an exception if this->shift is not setup properly.
	else
	{
		throw InvalidShift();
	}
}

/**
 * Returns "Production Worker"
 */
const string ProductionWorker::whatAmI()
{
	return "Production Worker";
}

