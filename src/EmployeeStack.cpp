/*
 * EmployeeStack.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Isabelle
 */

#include "EmployeeStack.hpp"

EmployeeStack::EmployeeStack(){
}

EmployeeStack::~EmployeeStack() {
	cout << "You are destroying a Stack of Employees." << endl;
}

// Adds a new Employee to the stack.
bool EmployeeStack::push(Employee* newEmployee){

	bool returnvalue = false;

	// If the stack is empty
	if ( this->isEmpty() ){
		// Creates a new node.
		ListNode *newNode = new ListNode;
		newNode->data = newEmployee;
		newNode->previous = nullptr;
		newNode->next = nullptr;

		// Adds it to the stack
		this->head = newNode;

		// Indicates success
		returnvalue = true;
	}

	// If the stack is not full
	else if ( !(this->isFull()) ){
		// Creates a new node.
		ListNode *newNode = new ListNode;
		newNode->data = newEmployee;
		newNode->previous = nullptr;
		newNode->next = head;

		// Adds it to the top of the stack.
		this->head->previous = newNode;
		// Updates the head.
		this->head = newNode;

		// Indicates success
		returnvalue = true;
	}

	// Exists the method
	// Returns true if the node was inserted at the end of the stack
	// Returns false if the node could not be added to the stack;
	return returnvalue;
}

// Retrieves an Employee from the stack.
// Returns nullptr is there was no employee to pop.
// the pointer is send to the user who is responsible for deleting it.
Employee * EmployeeStack::pop(){
	Employee * EmployeePoped = nullptr;

	// Check if there is more than one Employee in the stack.
	if ( !(this->isEmpty()) && this->head->next != nullptr ){
		// Saves the pointer to the Employee to return
		EmployeePoped = this->head->data;

		// Points the head to the last Employee
		this->head = this->head->next;

		// Deletes the old node (but does not delete the Employee)
		delete this->head->previous;
		this->head->previous = nullptr;
	}

	// Check if there is only one Employee in the stack
	else if ( (this->getSize()) == 1 ){
		cout << "only 1 to pop." << endl;

		// Saves the pointer to the Employee to return
		EmployeePoped = this->head->data;
		// Deletes the node
		delete this->head;

		// Points  head to nullptr (indicates that the stack is now empty).
		this->head = nullptr;

	}

	// Returns the pointer to the Employee
	// Returns nullptr if there was no Employee to pop
	return EmployeePoped;
}// end of pop

// returns true if the stack is empty
bool const EmployeeStack::isEmpty(){
	bool returnvalue = false;

	// If the stack is empty
	if ( this->head == nullptr ){
		returnvalue = true;
	}

	return returnvalue;
}

// Returns true if the stack is full
bool const EmployeeStack::isFull()
{
	// For now, the stack is never full
	return false;
}


