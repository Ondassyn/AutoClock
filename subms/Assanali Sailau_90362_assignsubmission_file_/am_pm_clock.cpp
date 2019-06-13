#include <iostream>
#include "am_pm_clock.h"

using namespace std;

// Assignment №1. Assanali Sailau
	/*
	 * Default constructor - initial time should be midnight
	 */
	am_pm_clock::am_pm_clock():
		hours(0),
		minutes(0),
		seconds(0),
		am(true) 
		{
			cout << "Default constructor\n";
		}

	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val):
		hours(hrs),
		minutes(mins),
		seconds(secs),
		am(am_val)
		{
			cout << "Constructor\n";
		}

	/*
	 * Copy constructor
	 */
	am_pm_clock::am_pm_clock(const am_pm_clock &clock):
		hours(clock.hours),
		minutes(clock.minutes),
		seconds(clock.seconds),
		am(clock.am) {
			cout << "Copy constructor\n";
		}
	

	/*
	 * Assignment operator
	 */
	am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
		this->hours = clock.hours;
		this->minutes = clock.minutes;
		this->seconds = clock.seconds;
		this->am = clock.am; 
			cout << "Assignment operator\n";
		return *this;
		
		}
	

	/*
	 * Toggles the am/pm value for the clock
	 */
	void am_pm_clock::toggle_am_pm(){
		this->am = !this->am;
	}

	/*
	 * Resets the time to midnight
	 */
	void am_pm_clock::reset(){
		this -> hours = 0;
		this -> minutes = 0;
		this -> seconds = 0;
		this -> am = true;
	}

	/*
	 * Advances the time of the clock by one second
	 */
	void am_pm_clock::advance_one_sec(){
		if (seconds == 59) {
			seconds = 0;
			if (minutes == 59) {
				minutes = 0;
				if (hours == 12) {
					hours = 1;
				}
				else if (hours == 11 && am == true) {
					hours = 12;
					am = false;
				}
				else if (hours == 11 && am == false) {
					hours = 12;
					am = true;
				} else {
					hours += 1;
				}
			} else {
				minutes += 1;
			}			
		} else {
			seconds += 1;
		}
	}

	/*
	 * Advances the time of the clock by n seconds
	 */
	void am_pm_clock::advance_n_secs(unsigned int n) {
		if (n < 0)
			throw invalid_argument("Illegal value for seconds!");
		int newsec = seconds + n;
		if (newsec < 60) {
			seconds = newsec;
		} 
		if (newsec == 60) {
			seconds = 0;
			if (minutes == 59) {
				minutes = 0;
				if (hours == 12) {
					hours = 1;
				}
				else if (hours == 11 && am == true) {
					hours = 12;
					am = false;
				}
				else if (hours == 11 && am == false) {
					hours = 12;
					am = true;
				} else {
					hours += 1;
				}
			} else {
				minutes += 1;
			}

		} else {
			seconds = newsec % 60;
			int newmin = minutes + (newsec / 60);
			if (newmin < 60) {
				minutes = newmin;
			}
			if (newmin == 60) {
				minutes = 0;
				if (hours == 12) {
					hours = 1;
				}
				else if (hours == 11 && am == true) {
					hours = 12;
					am = false;
				}
				else if (hours == 11 && am == false) {
					hours = 12;
					am = true;
				} else {
					hours += 1;
				}
			} else {
				minutes = newmin % 60;
				int newhrs = hours + (newmin / 60);
				if (newhrs < 12) {
					hours = newhrs;
				}
				if (newhrs == 12) {
					am = !am;
				} else {
					hours = newhrs % 12;
					int d = newhrs / 12;
					if (d > 1 && d % 2 == 1) {
						am = !am;
					}
				}
			}
		}


	}

	/*
	 * Getter for hours field
	 */
	unsigned int am_pm_clock::get_hours() const{
		return this->hours;
	}

	/*
	 * Setter for hours field; throws an invalid_argument exception
	 * if hrs is not a legal hours value
	 */
	void am_pm_clock::set_hours(unsigned int hrs){
		if (hrs < 0 || hrs > 12)
			throw invalid_argument("Illegal value for hours!");
		this->hours = hrs;
	}

	/*
	 * Getter for minutes field
	 */
	unsigned int am_pm_clock::get_minutes() const{
		return this->minutes;
	}

	/*
	 * Setter for minutes field; throws an invalid_argument exception
	 * if mins is not a legal minutes value
	 */
	void am_pm_clock::set_minutes(unsigned int mins){
		if (mins < 0 || mins > 59)
			throw invalid_argument("Illegal value for minutes!");
		this->minutes = mins;
	}

	/*
	 * Getter for seconds field
	 */
	unsigned int am_pm_clock::get_seconds() const{
		return this->seconds;
	}

	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
	void am_pm_clock::set_seconds(unsigned int secs){
		if (secs < 0 || secs > 59)
			throw invalid_argument("Illegal value for seconds!");
		this->seconds = secs;
	}


	/*
	 * Getter for am field
	 */
	bool am_pm_clock::is_am() const{
		return this->am;
	}

	/*
	 * Setter for am field
	 */
	void am_pm_clock::set_am(bool am_val){
		this->am = am_val;
	}

	/*
	 * Destructor
	 */
	am_pm_clock::~am_pm_clock(){
		cout << "It is destructor\n";
	}


