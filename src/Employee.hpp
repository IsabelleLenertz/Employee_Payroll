/*
 * Employee.hpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Isabelle
 */

#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_

#include <iostream>
#include "Date.hpp"

using namespace std;

class Employee {
public:

	// Default constructor and constructor
    Employee();
    ~Employee();

    /**
     * The Employee's Id has to be greater than 0.
     * Returns true if the id was changed
     * returns false to indicate failure.
     */
    bool setId( int);
    /**
     * Return this->id
     */
    int getId();

    /**
     * Changes the name if it does not start with a space and if greater than 1 character
     * Returns true to indicate success
     * Returns false to indicate failure
     */
    bool setName( string);
    /**
     * Returns the name.
     */
    string getName();

    /**
     *	Sets up this->hireDate using the Date's setDate function.
     *	Returns true to indicate success, false to indicate failure.
     */
    bool setDate( string);
    /**
     * return the date as a usable string.
     */
    string getDate();

    virtual double pay() = 0;

    virtual bool consoleSetUpAll() = 0;

private:
    int id;
    string name;
    Date hireDate;
};

#endif
