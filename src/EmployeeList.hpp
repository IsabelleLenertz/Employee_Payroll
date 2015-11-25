

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

	// Recursively destroys a part of the list
	// Returns the number of Employees destroyed
	int privateRecursiveDestruction(ListNode * nodePtr);

	// Goes through the entire list and returns the total pay
	// Adds the pay of each employee in the list
	// Recursive function
	double privateRecPayPeriod(ListNode * nodePtr);



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

	// Recursively destroys the list
	// Returns the number of Employees destroyed
	int recursiveDestruction();

	// Goes through the entire list and returns the total pay
	// Adds the pay of each employee in the list
	// Recursive function
	double recPayPeriod();


};

#endif /* EMPLOYEELIST_HPP_ */
