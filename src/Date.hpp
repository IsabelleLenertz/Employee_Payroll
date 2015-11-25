


#ifndef DATE_HPP_
#define DATE_HPP_

#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;

class Date
{
private:
	// Store the day of the date
	int day;
	// Store the month of the date
	int month;
	// Store the year of the date
	int year;
	// stores true if the date is setup correctly.
	bool valide;

	// Mutators for this->day, this->month, and this->year
	bool setDay(int newDay);
	bool setMonth(int newMonth);
	bool setYear(int newYear);

	// Returns the number of days allowed in the current month.
	int const daysInMonth();





public:
	// Default constructor
	Date();
	// Constructor setting the day, month and year
	Date(string newDate);

	// Default Destructor
	~Date();

	// Assensor for this->day, this->month, this->year, and this->valide
	int const getDay();
	int const getMonth();
	int const getYear();
	bool const getValidity();

	// Sets the date.
	// Takes a string (dd-mm-yyy) and sets this->day, this->month, and this->year
	// returns true to indicates success. Changes valide to true.
	bool setDate(string newDate);

	// Return the Date in a string : dd/mm/yyyy
	string const getDate();

	// Returns true if the year is a leap year.
	bool const isLeapYear();




};


#endif /* DATE_HPP_ */
