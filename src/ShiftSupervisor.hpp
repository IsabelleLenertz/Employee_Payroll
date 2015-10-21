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
    virtual ~ShiftSupervisor();
    /**
     * Exception class
     */
    class InvalidBonus{
    };
    class InvalidPay{
    };

    /**
     * Changes the Annual Salary.
     * The new salary cannot be a negative number
     * Returns true to indicate success, false to indicate failure.
     */
    bool setAnnualSalary( int);
    /**
     * Returns the annual Salary
     */
    const int getAnnualSalary();

    /**
     * Changes the Annual Production Bonus.
     * The new bonus cannot be a negative number
     * Returns true to indicate success, false to indicate failure.
     */
    bool setAnnualProductionBonus( int);
    /**
     * Returns the annual production bonus
     */
    const int getAnnualProductionBonus();

    /**
     * Use to indicate if the shift supervisor met his rqmts
     */
    void setGoalMeet(bool);
    /**
     * Returns true if the shift supervisor met his rqmts.
     */
    const bool getGoalMeet();

    /**
     * The Shift Supervisor if paid his monthly salary + 1/12th of his production bonus if his goals were reached.
     * Throws an exception if the annual salary or the bonus were not setup properly
     */
    const double pay();

    /**
     * Returns "Production Worker"
     */
    const string whatAmI();


private:
    int annualSalary;
    int annualProductionBonus;
    bool goalsMeet;
};

#endif //_SHIFTSUPERVISOR_H
