/*
 * TeamLeader.hpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Isabelle
 */

#ifndef TEAMLEADER_HPP_
#define TEAMLEADER_HPP_

#include "Employee.hpp"
#include "ProductionWorker.hpp"
#include <iostream>

using namespace std;

class TeamLeader: public ProductionWorker {
	private:
		int monthlyBonus;
		int formationRqm;
		int formationAttended;

	public:
		/*
		 * Exception classes
		 */
		class InvalidFormationRqm{
		};
		class IvalidFormationAttended{
		};
		class InvalidMonthlyBonus{
		};

		/*
		 * Defaults constructor
		 * Sets the attributes to zero to signify that they were not initiated
		 */
		TeamLeader();
		/*
		 * Default destructor
		 */
		virtual ~TeamLeader();
		/**
		 * Changes the Monthly Bonus.
		 * The new bonus cannot be a negative number
		 * Returns true to indicate success, false to indicate failure.
		 */
		bool setMonthlyBonus( int);
		/**
		 * Returns the monthly bonus
		 */
		const int getMonthlyBonus();

		/**
		 * Changes the Formation Requirement (number of hours).
		 * The requirement cannot be a negative number
		 * Returns true to indicate success, false to indicate failure.
		 */
		bool setFormationRqm( int);
		/**
		 * Returns the formation requirement
		 */
		const int getFormationRqm();

		/**
		 * Changes the Formation attended (number of hours).
		 * The formation attended cannot be a negative number
		 * Returns true to indicate success, false to indicate failure.
		 */
		bool setFormationAttended( int);
		/**
		 * Returns the number of formation hours attended
		 */
		const int getFormationAttended();

		/**
		 * Returns true if the Team Leader meets the formation requirement
		 * Returns false if the Team Leader does not meet the formation requirement
		 */
		const bool formationRqmMeet();

		/**
		 * Check if the Team Leader was properly initiated before calculating his pay.
		 * Adds his monthly bonus to his hourly pay if the Team Leader meets the formation requirement.
		 * Returns his total pay.
		 */
		const double pay();

		/**
		 * Returns "Team Leader"
		 */
		const string whatAmI();


};

#endif //_TEAMLEADER_H
