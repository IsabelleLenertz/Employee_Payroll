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
#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_

#include <iostream>
#include "Date.hpp"

using namespace std;

class Employee {
public:



	/**
	 * Default constructor
	 * Sets the attributes to 0 to signify that they were not initiated.
	 */
    Employee();
    /**
     * Default destructor
     * Print a deleting message.
     */
    virtual ~Employee();

    /**
     * The Employee's Id has to be greater than 0.
     * Returns true if the id was changed
     * returns false to indicate failure.
     */
    bool setId( int);
    /**
     * Return this->id
     */
    const int getId();

    /**
     * Changes the name if it does not start with a space and if greater than 1 character
     * Returns true to indicate success
     * Returns false to indicate failure
     */
    bool setName( string);
    /**
     * Returns the name.
     */
    const string getName();

    /**
     *	Sets up this->hireDate using the Date's setDate function.
     *	Returns true to indicate success, false to indicate failure.
     */
    bool setDate( string);
    /**
     * return the date as a usable string.
     */
    const string getDate();

    const virtual double pay() = 0;
    const virtual double getBonus() = 0;
    /**
     * Returns the type of employee in a string
     */
    const virtual string whatAmI() = 0;

    const string getComment();

    const void setComment(string newComment);



private:
    int id;
    string name;
    Date hireDate;
    string comment;
};

#endif
