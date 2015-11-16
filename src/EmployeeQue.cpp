/*
 * EmployeeQue.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: Isabelle
 */

#include "EmployeeQue.hpp"

EmployeeQue::EmployeeQue() {
	// TODO Auto-generated constructor stub

}

EmployeeQue::~EmployeeQue() {
	// TODO Auto-generated destructor stub
}

// Adds a new Employee to the stack.
bool EmployeeQue::enque(Employee* newEmployee){
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

		// Adds it to the rear of the queue.
		this->rear->next = newNode;
		// Updates the rear.
		this->rear = newNode;

		// Indicates success
		returnvalue = true;
	}// else

	return returnvalue;
}// enque

// Retrieves an Employee from the front of the queue.
// the pointer is send to the user who is responsible for deleting it.
Employee * EmployeeQue::deque(){
	Employee * EmployeeDequed = nullptr;

	// Check if there is more than one Employee in the stack.
	if ( this->rear != this->head ){
		// Saves the pointer to the Employee to return
		EmployeeDequed = this->head->data;

		// Points the rear to the last Employee
		this->head = this->head->next;

		// Deletes the old node (but does not delete the Employee)
		delete this->head->previous;
		this->head->previous = nullptr;
	}

	// Check if there is only one Employee in the stack
	else if ( (this->rear == this->head) && (this->head != nullptr)){
		// Saves the pointer to the Employee to return
		EmployeeDequed = this->rear->data;

		// Deletes the node
		delete this->rear;

		// Points rear and head to nullptr (indicates that the stack is now empty.
		this->rear = nullptr;
		this->head = nullptr;

	}

	// Returns the pointer to the Employee
	// Returns nullptr if there was no Employee to deque
	return EmployeeDequed;

}

// returns true if the stack is empty
// returns true if the stack is empty
bool const EmployeeQue::isEmpty(){
	bool returnvalue = false;

	// If the stack is empty
	if ( (this->head == nullptr) && (this->rear == nullptr) ){
		returnvalue = true;
	}

	return returnvalue;
}
// Returns true if the stack is full

bool const EmployeeQue::isFull(){
	// For now, the queue is considered to be unlimited in size.
	return false;
}
