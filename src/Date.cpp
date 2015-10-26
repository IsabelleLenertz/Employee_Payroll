//*****************

//Project Name: Project #4: using main parameters

//Project Description: change array to vector and allow user to uses main parameter to launch the program

//Project Author: Lenertz Isabelle

//Is this an extra credit Project:  No

//Date completed: 10/24/2015

//Operating system used: Windows 10

//IDE Used:  Eclipse

//*****************

#include "Date.hpp"

// Default constructor
Date::Date()
{
	// The date was setup with no initial value, set this->valid to false.
	this->setDate("01-01-1900");
	this->valide = false;
}

// Constructor setting the day, month and year.
Date::Date(string newDate)
{
	// send the string entered by the user to the setDate function.
	// If the date was setup correctly, set this->valide to true.
	if (setDate(newDate) == true)
	{
		this->valide = true;
	}
	// If the date setup failed, set this->valide to false.
	else
	{
		valide = false;
	}
}

// Default Destructor
Date::~Date()
{
	cout << "You are destructing a Date." << endl;
}

// Assensor and Mutator for this->day
int const Date::getDay()
{
	return this->day;
}
bool Date::setDay(int newDay)
{
	// If the user entered a valid number of days.
	if ( (newDay > 0) and (newDay <= daysInMonth()) )
	{
		// change the day
		this->day = newDay;
		// exits indicating success
		return true;
	}
	// If the users entered a non-valid number of days
	else
	{
		// Exists indicating failure, does not change the day.
		return false;
	}
}

// Assensor and Mutator for this->month
int const Date::getMonth()
{
	// Returns the month.
	return this->month;
}
bool Date::setMonth(int newMonth)
{
	// If the user tries to enter a month that is not between January(1) and December(12).
	if (newMonth < 1 || newMonth > 12)
	{
		// Does not change the month and returns false to indicate an error.
		return false;
	}
	else
	{
		//Changes the month and returns true to indicate success.
		this->month = newMonth;
		return true;
	}
}

// Assensor and Mutator for this->year
int const Date::getYear()
{
	// Return the year.
	return this->year;
}
bool Date::setYear(int newYear)
{
	// if the user tries tries to enter a day prior to year 1900 or after 2400.
	if (newYear < 1900 || newYear > 2400 )
	{
		// Does not change the year, and returns false to indicate an error.
		return false;
	}
	else
	{
		// Changes the year and returns true to indicate success.
		this->year = newYear;
		return true;
	}
}

// Returns the Date in a string : dd/mm/yyyy
string const Date::getDate()
{
	if (this->valide == true)
	{
		ostringstream convertYear, convertMonth, convertDay;
		string yearString, monthString, dayString;

		// Converts the year into a string.
		convertYear << getYear();
		yearString = convertYear.str();

		// Converts the month into a string.
		convertMonth << getMonth();
		monthString = convertMonth.str();
		if (this->month < 10){
		monthString = "0" + monthString;
		}

		// Converts the day into a string.
		convertDay << getDay();
		dayString = convertDay.str();
		if (this->day < 10) {
			dayString = "0" + dayString;
		}

		//return yearString+ "/" + monthString;
		// Returns the date in an appropriate format.
		return (monthString + "/" + dayString + "/" + yearString) ;

	}
	else
	{
		return "The date was not initiated properly.";
	}



	return "Date";
}

// Returns true if the year is a leap year.
// Procedure to obtain by https://support.microsoft.com/en-us/kb/214019
// 1) If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
// 2) If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
// 3) If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
// 4) The year is a leap year (it has 366 days).
// 5) The year is not a leap year (it has 365 days).
bool const Date::isLeapYear()
{
	// If the year is divisible by 4.
	if ( (this->year)%4 == 0)
	{
		// If the year is divisible by 4 and by 100.
		if ( (this->year)%100 == 0)
		{
			// If the year is divisible by 4, 100, and 400.
			if ( (this->year)%400 == 0 )
			{
				// The year is a leap year.
				return true;
			}
			// The year is divisible by 4 and 100, but not by 400.
			else
			{
				// The year is not a leap year.
				return false;
			}
		}
		// The year is divisible by 4 but not by 100.
		else
		{
			// The year is a leap year.
			return true;
		}
	}
	// The year is not divisible by 4.
	else
	{
		// The year is not a leap year.
		return false;
	}
}

// Returns the number of days allowed in the current month.
int const Date::daysInMonth()
{

	switch(this->month)
	{
	case 1:
		// Returns 31 days for January.
		return 31;
		break;
	case 2:
		if ( isLeapYear() )
		{
			// Returns 29 days for Feruary if the year is a leap year.
			return 29;
		}
		else
		{
			// Returns 28 days for Feruary if the year is not a leap year.
			return 28;
		}
		break;
	case 3:
		// Returns 31 for March.
		return 31;
		break;
	case 4:
		// Returns 30 for April.
		return 30;
		break;
	case 5:
		// Returns 31 for May.
		return 31;
		break;
	case 6:
		// Returns 30 for June.
		return 30;
		break;
	case 7:
		// Returns 31 for Jully.
		return 31;
		break;
	case 8:
		// Returns 31 for August.
		return 31;
		break;
	case 9:
		// Returns 30 for September.
		return 30;
		break;
	case 10:
		// Returns 31 for October.
		return 31;
		break;
	case 11:
		// Returns 30 for November.
		return 30;
		break;
	case 12:
		// Returns 31 for December.
		return 31;
		break;

	}

	return 0;

}

// Sets the date.
// Takes a string (mm-dd-yyyy) and sets this->day, this->month, and this->year
// returns true to indicates success. Changes valide to true.
bool Date::setDate(string newDate)
{
	string newMonth = newDate.substr(0, 2);
	string newDay = newDate.substr(3, 2);
	string newYear = newDate.substr(6, 4);

	if ( setYear( atoi( newYear.c_str() ) ) == true)
	{
		if ( setMonth( atoi( newMonth.c_str() ) ) == true)
		{
			if ( setDay( atoi( newDay.c_str() ) ) == true)
			{
				this->valide = true;
				return true;
			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool const Date::getValidity()
{
	return this->valide;
}

