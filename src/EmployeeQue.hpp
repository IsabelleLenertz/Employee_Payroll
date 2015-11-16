/*
 * EmployeeQue.hpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Isabelle
 */

#ifndef EMPLOYEEQUE_HPP_
#define EMPLOYEEQUE_HPP_

#include "EmployeeList.hpp"

class EmployeeQue: public EmployeeList {
private:
	ListNode * rear;

public:
	EmployeeQue();
	virtual ~EmployeeQue();

	// Adds a new Employee to the stack.
	bool enque(Employee* newEmployee);

	// Retrieves an Employee from the stack.
	// the pointer is send to the user who is responsible for deleting it.
	Employee * deque();

	// returns true if the stack is empty
	bool const isEmpty();

	// Returns true if the stack is full
	bool const isFull();

	// Do not do anything. forces the user to use the pop and push methods
	void appendNode(Employee* NewEmployeePtr){};
	bool insertAfterNode(Employee* NewEmployee, int position){return false;};
	bool insertBeforeNode(Employee* NewEmployee, int position){return false;};
	void reverseList(){};
	bool deleteNode(int position){return false;};

};

#endif /* EMPLOYEEQUE_HPP_ */
