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
	this->destroyList();
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

/**
 * Deletes the entire list.
 */
void EmployeeList::destroyList() {
	ListNode *tempPtr;

	while (this->head != nullptr) {
		// remembers address of the next node
		tempPtr = this->head->next;

		// Destroys the boat of the current node
		delete this->head->data;
		// Destroys the current node
		delete this->head;

		// set current pointer to the next node
		this->head = tempPtr;
	}// while

}

/**
 * Inserts an Employee in the lists at  position.
 */
bool EmployeeList::insertAfterNode(Employee* NewEmployee, int position){

	// temporary pointer to a node
	ListNode *nodePtr;
	ListNode *tempNode;

	// Check if the list is empty
	if (this->head == nullptr){
		return false;
	}
	else{
		nodePtr = this->head;
	}

	// Goes through the list and make sure the position the user wants to insert a node to exists.
	// Return false if the position does not exist.
	if (position !=0){
		for (int i=0; i < (position-1); i++ ) {
			// check if we do not reach the list
			if (nodePtr->next == nullptr){
				return false;
			}
			else{
				nodePtr = nodePtr->next;
			}
		} // end of for	}
		ListNode *newNode = new ListNode;
		tempNode = nodePtr->next;
		nodePtr->next = newNode;
		newNode->data = NewEmployee;
		newNode->next = tempNode;
	} // end of if
	else{
		ListNode *newNode = new ListNode;
		tempNode = nodePtr;
		newNode->data = NewEmployee;
		newNode->next = tempNode;
		this->head = newNode;
	}
	return true;
}// end of insertNode

/**
 * Returns the size of the list.
 */
int EmployeeList::getSize() {
	ListNode *nodePtr;
	int size = 0;

	nodePtr=this->head;
	while (nodePtr != nullptr) {
		// remembers address of the next node
		nodePtr = nodePtr->next;
		size++;

	}		// while

	return size;
}

/**
 * Returns the position of a node
 * Returns 0 if the node was not found
 */
int EmployeeList::findNode(int searchId){
	ListNode *nodePtr;
	int position = 0;

	nodePtr = this->head;
	while (nodePtr) {
		// remembers address of the next node
		if ( searchId == nodePtr->data->getId() ){
			// exists the while loop if the weight is found
			break;
		}
		else{
			// keeps track of the position
			position++;
			nodePtr = nodePtr->next;
		}// end of else
	}// while

	if (nodePtr == nullptr)	{
		return 0;
	}
	else {
		return (position+1);
	}

} // end of findNode

/**
 * Reverse the order of the list. the first Employee becomes the last one.
 */
void EmployeeList::reverseList() {
	ListNode *nodePtr;
	ListNode *tempHeadPtr, *temp;

	tempHeadPtr = this->head ;
	nodePtr = this->head->next;
	while (nodePtr != nullptr) {
		temp = nodePtr->next;
		nodePtr->next = this->head;
		this->head = nodePtr;
		nodePtr = temp;
	}		// while
	tempHeadPtr->next = nullptr;
} // end of reverseList

/**
 * Deletes a node at a specific position (position >1)
 * returns true to signify success
 * returns false to signify the node was not find
 */
bool EmployeeList::deleteNode(int position){

	// temporary pointer to a node
	ListNode *nodePtr;
	ListNode *prevNode;

	// Initializes the previous node we want to keep track of.
	prevNode = this->head;
	// Check if the list is empty
	if (this->head == nullptr){
		return false;
	}
	else{
		nodePtr = this->head;
	}

	// Goes through the list and make sure the position the user wants to delete a node that exists.
	// Return false if the position does not exist.
	if (position !=0){
		for (int i=0; i < (position-1); i++ ) {
			// check if we do not reach the end list
			if (nodePtr->next == nullptr){
				// returns false if reached the end of the list without finding the position
				return false;
			}
			else{
				// moves to the next node
				prevNode = nodePtr;
				nodePtr = nodePtr->next;
			}
		} // end of for
		// if the user wants to delete the first node
		if (position == 1) {
				// if the user wants to delete the first node and it is the only node.
				if (nodePtr->next == nullptr){
					this->head = nullptr;
				}// end of if
				// if the user wants to delete the first node and it is not the only node.
				else{
					this->head = nodePtr->next;
				}// end of else

		}// end of if
		//If the user wants to delete any other than the first one.
		else{
			// moves to the next node
			prevNode->next = nodePtr->next;
		}// end of else

		// deletes the node and reconnects the two portion of the list.
		prevNode->next = nodePtr->next;
		// deletes the dynamically allocated memory
		delete nodePtr->data;
		delete nodePtr;

	} // end of if
	else{
		// return false if the user wants to delete position 0 (does not exist, we start at 1)
		return false;
	}

	// signifies the node was properly deleted.
	return true;

}
