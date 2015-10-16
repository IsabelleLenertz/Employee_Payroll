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
		int monhtlyBonus;
		int formationRqm;
		int formationAttended;

	public:

		/**
		 * Accessor and mutator for this->monthlyBonus
		 */
		bool setMonthlyBonus( int);
		int getMonthlyBonus();

		/**
		 * Accessor and mutator for this->FormationRqm
		 */
		bool setFormationRqm( int);
		int getFormationRqm();

		/**
		 * Accessor and mutator for this->formationAttended
		 */
		bool setFormationAttended( int);
		int getFormationAttended();

		/**
		 * Check if the formation Rqm where meet, returns true if so
		 */
		bool formationRqmMeet();

		/**
		 * Pays the Team Leader
		 */
		double pay();

		/**
		 * Returns "Team Leader"
		 */
		string whatAmI();

		/**
		 * Prompt the user for all the Team Leader's attributes.
		 * Was created for the console programs solely.
		 * GUI can use the mutator separately to setup the Team Leader's attributes.
		 */
		bool consoleSetUpAll();

};

#endif //_TEAMLEADER_H
