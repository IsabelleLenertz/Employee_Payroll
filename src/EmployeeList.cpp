/*
 * EmployeeList.cpp
 *
 *  Created on: Nov 6, 2015
 *      Author: Isabelle
 */

#include "EmployeeList.hpp"

EmployeeList::EmployeeList() {
	this->head = nullptr;
	this->currentPtr = this->head;
}

EmployeeList::~EmployeeList() {
	cout << "You are destroying a List of Employees." << endl;
}


// Adds a new employee to the end of the list.
void EmployeeList::appendNode(Employee* newEmployeePtr){

	ListNode *nodePtr;

	// If the list is empty.
	if (this->head == nullptr) {
		// Dynamically allocate a new node to the head
		this->head = new ListNode;
		// Put the address of the new employee inside the data pointer.
		this->head->data = newEmployeePtr;
		this->head->next = nullptr;
	} // end of if

	// Else looks for the end of the list
	else {
		nodePtr = this->head;
		// while node ptr has something in it (it it true if it has smth other than null or zero)
		while (nodePtr->next != nullptr) {
			nodePtr = nodePtr->next;
		}	// end of while
		// Create a new node after the last of the list
		nodePtr->next = new ListNode;
		// Assigns the boat to that node
		nodePtr->next->data = newEmployeePtr;
		// Set the last pointer to nullptr
		nodePtr->next->next = nullptr;
	}// end of else
}// end of appendNode

/**
 * Returns the list node pointed by the currentPtr
 */
ListNode const EmployeeList::getCurrentPtr(void){
	return *(this->currentPtr);
}
