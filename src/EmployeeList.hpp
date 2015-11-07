/*
 * EmployeeList.hpp
 *
 *  Created on: Nov 6, 2015
 *      Author: Isabelle
 */

#ifndef EMPLOYEELIST_HPP_
#define EMPLOYEELIST_HPP_

#include "Employee.cpp"

//
// Linked list Node
struct ListNode {
	Employee *data;
	struct ListNode *next;
}; // ListNode

class EmployeeList {
private:
	ListNode *head;
	ListNode *currentPtr;

public:
	EmployeeList();
	virtual ~EmployeeList();

	// Function Prototypes
	/**
	 * Adds a new employee to the end of the list.
	 **/
	void appendNode(Employee* NewEmployeePtr);

	/**
	 * Returns the list node pointed by the currentPtr
	 */
	ListNode const getCurrentPtr(void);

	/**
	void destroyList(ListNode *&aNode);
	void traverseList(ListNode *aNode);
	// Returns true if the node was inserted properly
	// Returns false if the position did not exists.
	bool insertNode(ListNode *&, Employee*, int);
	// Returns the size of the list.
	int getSize(ListNode *aNode);
	// Returns the position of a node
	int findNode(ListNode *aNode, double searchWeight);
	// Reverse the list
	void  reverseList(ListNode * &headPtr);
	// Deletes a node at a specific position (position >1)
	// returns true to signify success
	// returns false to signify the node was not find.
	bool deleteNode(ListNode *&aNode, int position);
	*/
};

#endif /* EMPLOYEELIST_HPP_ */
