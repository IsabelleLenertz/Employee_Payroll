/*
 * ShiftSupervisor.hpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Isabelle
 */

#ifndef SHIFTSUPERVISOR_HPP_
#define SHIFTSUPERVISOR_HPP_

#include <iostream>
#include "Employee.hpp"
using namespace std;



class ShiftSupervisor: public Employee {

public:
    ShiftSupervisor();

    /**
     * @param int
     */
    bool setAnnualSalary( int);

    int getAnnualSalary();

    /**
     * @param int
     */
    bool setAnnualProductionBonus( int);

    int getAnnualProductionBonus();

    /**
     * @param bool
     */
    bool setGoalMeet( bool);

    bool getGoalMeet();

    virtual double pay() = 0;

    virtual bool consoleSetUpAll() = 0;

private:
    int annualSalary;
    int annualProductionBonus;
    bool goalsMeet;
};

#endif //_SHIFTSUPERVISOR_H
