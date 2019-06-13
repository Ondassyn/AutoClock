//============================================================================
// Name        : am_pm_clock.cpp
// Author      : Alibek Bolat
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include "am_pm_clock.h"
using namespace std;

	/*
	 * Default constructor - initial time should be midnight
	 */
am_pm_clock::am_pm_clock():
		hours (12),
		minutes (0),
		seconds (0),
		am (true) {
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
		{ }

	/*
	 * Copy constructor
	 */
am_pm_clock::am_pm_clock(const am_pm_clock &clock):
		hours(clock.hours),
		minutes(clock.minutes),
		seconds(clock.seconds),
		am(clock.am)  { }

	/*
	 * Assignment operator
	 */
am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock) {
		this->hours = clock.hours;
		this->minutes = clock.minutes;
		this->seconds = clock.seconds;
		this->am = clock.am;
		return *this;
	}

	/*
	 * Toggles the am/pm value for the clock
	 */
void am_pm_clock::toggle_am_pm() {

		if (am == true) {
			am = false;
		} else {
			am = true;
		}
	}

	/*
	 * Resets the time to midnight
	 */
void am_pm_clock::reset() {
		hours = 12;
		minutes = 0;
		seconds = 0;
		am = true;
	}

	/*
	 * Advances the time of the clock by one second
	 */
void am_pm_clock::advance_one_sec() {
			if (seconds < 59) {
				seconds = seconds + 1;
			} else {
				seconds = 0;
				minutes++;
				if (minutes == 60) {
					minutes = 0;
					if (hours == 11) {
						hours = 12;
						toggle_am_pm();
					} else if (hours == 12) {
						hours = 1;
					} else {
						hours++;
					}
				}
			}
		}

	/*
	 * Advances the time of the clock by n seconds
	 */
void am_pm_clock::advance_n_secs(unsigned int n) {
		for (unsigned int i = 0; i < n; i++) {
			advance_one_sec();
		}
	}

	/*
	 * Getter for hours field
	 */
unsigned int am_pm_clock::get_hours() const {
		return hours;
	}

	/*
	 * Setter for hours field; throws an invalid_argument exception
	 * if hrs is not a legal hours value
	 */
void am_pm_clock::set_hours(unsigned int hrs) {
		if (hrs == 0 || hrs > 12) {
			throw std::invalid_argument ("not in range");
		} else {
			hours = hrs;
		}
	}

	/*
	 * Getter for minutes field
	 */
unsigned int am_pm_clock::get_minutes() const {
		return minutes;
	}

	/*
	 * Setter for minutes field; throws an invalid_argument exception
	 * if mins is not a legal minutes value
	 */
void am_pm_clock::set_minutes(unsigned int mins) {
		if (mins > 59) {
			throw std::invalid_argument("not in range");
		} else {
			minutes = mins;
		}
	}

	/*
	 * Getter for seconds field
	 */
unsigned int am_pm_clock::get_seconds() const {
		return seconds;
	}

	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
void am_pm_clock::set_seconds(unsigned int secs) {
		if (secs > 59) {
			throw std::invalid_argument("cannot have negative secs");
		} else {
			seconds = secs;
		}
	}

	/*
	 * Getter for am field
	 */
bool am_pm_clock::is_am() const {
		return am;
	}

	/*
	 * Setter for am field
	 */
void am_pm_clock::set_am(bool am_val) {
		am = am_val;
	}
