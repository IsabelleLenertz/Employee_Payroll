/*
 * EmployeeStack.hpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Isabelle
 */

#ifndef EMPLOYEESTACK_HPP_
#define EMPLOYEESTACK_HPP_

#include "EmployeeList.hpp"

class EmployeeStack: public EmployeeList {
private:
	ListNode * rear;

public:
	EmployeeStack();
	virtual ~EmployeeStack();

	// Adds a new Employee to the stack.
	bool push(Employee* newEmployee);

	// Retrieves an Employee from the stack.
	// the pointer is send to the user who is responsible for deleting it.
	Employee * pop();

	// returns true if the stack is empty
	bool const isEmpty();

	// Returns true if the stack is full
	bool const isFull();

	// Do not do anything. forces the user to use the pop and push methods
	void appendNode(Employee* NewEmployeePtr){};
	bool insertAfterNode(Employee* NewEmployee, int position){return false;};
	bool insertBeforeNode(Employee* NewEmployee, int position){return false;};


};

#endif /* EMPLOYEESTACK_HPP_ */
