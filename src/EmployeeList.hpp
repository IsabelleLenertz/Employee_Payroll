//*****************

//Project Name: Project #5: Employee Linked List

//Project Description: Optimize employee list using a linked list instead of a vector.

//Project Author: Lenertz Isabelle

//Is this an extra credit Project:  No

//Date completed: 11/11/2015

//Operating system used: Windows 10

//IDE Used:  Eclipse

//*****************

#ifndef EMPLOYEELIST_HPP_
#define EMPLOYEELIST_HPP_

#include "Employee.hpp"

//
// Linked list Node
struct ListNode {
	Employee *data;
	struct ListNode *next;
	struct ListNode *previous;
}; // ListNode

class EmployeeList {
protected:
	ListNode *head;
	ListNode *currentPtr;

public:
	EmployeeList();
	virtual ~EmployeeList();

	/**
	 * Adds a new employee to the end of the list.
	 **/
	void appendNode(Employee* NewEmployeePtr);

	/**
	 * Returns the list node pointed by the currentPtr
	 */
	Employee* const getCurrentPtr(void);

	/**
	 * Deletes the entire list.
	 */
	void destroyList();

	/**
	 * Inserts an Employee in the lists before a specific position.
	 */
	bool insertAfterNode(Employee* NewEmployee, int position);

	/**
	 * Inserts an Employee in the lists before a specific position.
	 */
	bool insertBeforeNode(Employee* NewEmployee, int position);

	/**
	 * Returns the size of the list.
	 */
	int getSize();

	/**
	 * Returns the position of a node
	 * Returns 0 if the node was not found
	 */
	int findNode(int searchId);

	/**
	 * Reverse the order of the list. the first Employee becomes the last one.
	 */
	void reverseList();

	/**
	 * Deletes a node at a specific position (position >1)
	 * returns true to signify success
	 * returns false to signify the node was not find
	 */
	bool deleteNode(int position);


	// Position the currentPtr to a specific position
	// return true to indicate success
	// Return false if the position did not exist
	bool positionTo(int position);

	// Positions the current pointer
	bool goToFirst();
	bool goToNext();
	bool goToPrevious();
	bool  goToLast();


};

#endif /* EMPLOYEELIST_HPP_ */
