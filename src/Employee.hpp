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

    Employee();

    /**
     * @param int
     */
    bool setId( int);

    int getId();

    /**
     * @param string
     */
    bool setName( string);

    string getName();

    /**
     * @param string
     */
    bool setDate( string);

    string getDate();

    virtual double pay() = 0;

    virtual bool consoleSetUpAll() = 0;

private:
    int id;
    string name;
    Date hireDate;
};

#endif
