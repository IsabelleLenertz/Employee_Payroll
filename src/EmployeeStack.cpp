/*
 * EmployeeStack.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Isabelle
 */

#include "EmployeeStack.hpp"

EmployeeStack::EmployeeStack(){
	this->rear = nullptr;
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
		this->rear = newNode;

		// Indicates success
		returnvalue = true;
	}

	// If the stack is not full
	else if ( !(this->isFull()) ){
		// Creates a new node.
		ListNode *newNode = new ListNode;
		newNode->data = newEmployee;
		newNode->previous = this->rear;
		newNode->next = nullptr;

		// Adds it to the top of the stack.
		this->rear->next = newNode;
		// Updates the head.
		this->rear = newNode;

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
	if ( this->rear != this->head ){
		// Saves the pointer to the Employee to return
		EmployeePoped = this->rear->data;

		// Points the rear to the last Employee
		this->rear = this->rear->previous;

		// Deletes the old node (but does not delete the Employee)
		delete this->rear->next;
		this->rear->next = nullptr;
	}

	// Check if there is only one Employee in the stack
	else if ( (this->rear == this->head) && (this->head != nullptr)){
		// Saves the pointer to the Employee to return
		EmployeePoped = this->rear->data;

		// Deletes the node
		delete this->rear;

		// Points rear and head to nullptr (indicates that the stack is now empty.
		this->rear = nullptr;
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
	if ( (this->head == nullptr) && (this->rear == nullptr) ){
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


