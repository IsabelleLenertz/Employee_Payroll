//*****************

//Project Name: Project #4: using main parameters

//Project Description: change array to vector and allow user to uses main parameter to launch the program

//Project Author: Lenertz Isabelle

//Is this an extra credit Project:  No

//Date completed: 10/24/2015

//Operating system used: Windows 10

//IDE Used:  Eclipse

//*****************
#ifndef PRODUCTIONWORKER_HPP_
#define PRODUCTIONWORKER_HPP_

#include "Employee.hpp"
#include "Utilities.hpp"
#include <iostream>

using namespace std;

// Enum Datatype use to define the working shift of the production worker.
enum Shift { INVALID, DAY, NIGHT };

class ProductionWorker: public Employee {
public:
	/**
	 * Exception classes.
	 */
	class InvalidShift{
	};
	class InvalidPayRate{
	};
	class InvalidHoursWorked {
	};

	/**
	 * Default constructor
	 * Sets the attributes to 0 to signify that they were not initiated.
	 */
    ProductionWorker();

    /**
     * Default destructor
     * Print a deleting message.
     */
    virtual ~ProductionWorker();

    /**
     * Changes the shift of the Employee
     * Returns true to indicate success, false to indicate failure.
     */
    bool setShift(string newShift);

    /**
     * Returns the shift the production worker is working, using the Shift enum datatype
     */
    const Shift getShift();

    /**
     * Sets the hourly pay rate of the Production Worker.
     * has to be >=0
     * return true to indicate success, false to indicate failure.
     */
    bool setPayRate( double);
    /**
     * Returns the Production Worker's pay rate.
     */
    const double getPayRate();

    /**
     * Changes the Production Worker hours worked
     * Has to be >=0
     * returns true to indicate success, false to indicate failure.
     */
    bool setHoursWorked( double);
    /**
     * Returns the hours worked by the Production Worker
     */
    const double getHoursWorked();

    /**
     * Pays the Production worker hoursWorked * payRate.
     * Pays night worker 50% bonus
     * throws the exceptions : InvalidHoursWorked, InvalidPayRate, InvalidShift if the attributes were not setup properly
     */
    const double pay();
    const double getBonus();

    /**
     * Returns "Production Worker"
     */
    const string whatAmI();

private:
    Shift shift;
    double payRate;
    double hoursWorked;
};

#endif //_PRODUCTIONWORKER_H
