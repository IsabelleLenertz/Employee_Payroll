/*
 * TeamLeader.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Isabelle
 */

#include "TeamLeader.hpp"
/*
 * Default constructor
 * Sets the attributes to zero to signify that they were not initiated
 */
TeamLeader::TeamLeader(){
	// Sets the attributes to zero to signify that they were not initiated
	this->formationAttended = 0;
	this->formationRqm = 0;
	this->monthlyBonus = 0;
}
TeamLeader::~TeamLeader(){
	cout << "You are destroying a team leader."<< endl;
}


/**
 * Changes the Monthly Bonus.
 * The new bonus cannot be a negative number
 * Returns true to indicate success, false to indicate failure.
 */
bool TeamLeader::setMonthlyBonus(int newBonus) {
	// The monthly bonus cannot be negative
	if (newBonus >= 0){
		// Changes the bonus
		this->monthlyBonus = newBonus;
		// Returns true to indicate success
		return true;
	}
	// If the new bonus is not valid
	else{
		// Does not change the bonus and returns false to indicate failure
		return false;
	}
}

/**
 * Returns the monthly bonus
 */
const int TeamLeader::getMonthlyBonus() {
    return this->monthlyBonus;
}

/**
 * Changes the Formation Requirement (number of hours).
 * The requirement cannot be a negative number
 * Returns true to indicate success, false to indicate failure.
 */
bool TeamLeader::setFormationRqm(int newRqm) {
	// The formation requirement cannot be negative
	if (newRqm >= 0){
		// Changes the bonus
		this->formationRqm = newRqm;
		// Returns true to indicate success
		return true;
	}
	// If the formation requirement is not valid
	else{
		// Does not change the formation and returns false to indicate failure
		return false;
	}
}

/**
 * Returns number of formation hours required
 */
const int TeamLeader::getFormationRqm() {
    return this->formationRqm;
}

/**
 * Changes the Formation attended (number of hours).
 * The formation attended cannot be a negative number
 * Returns true to indicate success, false to indicate failure.
 */
bool TeamLeader::setFormationAttended(int formation) {
	// The formation attended hours cannot be negative
	if (formation >= 0){
		// Changes the formation attended
		this->formationAttended = formation;
		// Returns true to indicate success
		return true;
	}
	// If the new formation attended is not valid
	else{
		// Does not change the formation and returns false to indicate failure
		return false;
	}
}

/**
 * Returns the number of formation hours attended
 */
const int TeamLeader::getFormationAttended() {
    return this->formationAttended;
}

/**
 * Returns true if the Team Leader meets the formation requirement
 * Returns false if the Team Leader does not meet the formation requirement
 */
const bool TeamLeader::formationRqmMeet() {
    // If the Team leader did not attended the required number of formation hours
	if ( (this->formationAttended) < (this->formationRqm) ){
    	return false;
    }
	//If the Team Leader attended the required number of formation hours
    else{
    	return true;
    }
}

/**
 * Check if the Team Leader was properly initiated before calculating his pay.
 * Adds his monthly bonus to his hourly pay if the Team Leader meets the formation requirement.
 * Returns his total pay.
 *
 */
double TeamLeader::pay() {
	double totalPay = this->ProductionWorker::pay();
	// If the formation requirement was not properly initialized
	if ( (this->formationRqm) == 0){
		//throws an error class
		throw InvalidFormationRqm();
	}
	// If the formation attended was not properly initialized
	else if ( (this->formationAttended) == 0) {
		//throws an error class
		throw IvalidFormationAttended();
	}
	// If the monthly bonus was not properly initialized
	else if( (this->monthlyBonus) == 0 ){
		//throws an error class
		throw InvalidMonthlyBonus();
	}
	//If the Team Leader met the formation requirements
	else if ( (this->formationRqmMeet()) == true ){
		// Adds his bonus to his salary.
		totalPay += this->monthlyBonus;
	}

	// Returns the monthly salary.
    return totalPay;
}

/**
 * Returns "Team Leader"
 */
string TeamLeader::whatAmI()
{
	return "Team Leader";
}

/**
 * @return bool
 */
bool TeamLeader::consoleSetUpAll() {
    return false;
}
