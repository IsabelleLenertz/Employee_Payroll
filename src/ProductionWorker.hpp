/*
 * ProductionWorker.hpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Isabelle
 */

#ifndef PRODUCTIONWORKER_HPP_
#define PRODUCTIONWORKER_HPP_

#include "Employee.hpp"
#include <iostream>

using namespace std;

class ProductionWorker: public Employee {
public:

    ProductionWorker();

    /**
     * @param int
     */
    bool setShift( int);

    bool getShift();

    /**
     * @param double
     */
    bool setPayRate( double);

    double getPayRate();

    /**
     * @param double
     */
    bool setHoursWorked( double);

    double getHoursWorked();

    double pay();

    bool consoleSetUpAll();

private:
    int shift;
    double payRate;
    double hoursWorked;
};

#endif //_PRODUCTIONWORKER_H
