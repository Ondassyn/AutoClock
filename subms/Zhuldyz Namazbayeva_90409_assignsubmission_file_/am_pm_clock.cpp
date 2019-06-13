//============================================================================
// Name        : tiime.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "am_pm_clock.h"


	/*
	 * Default constructor - initial time should be midnight
	 */
	am_pm_clock::am_pm_clock()
	{
		hours = 12;
		minutes = 00;
		seconds = 00;
		am = true;
		}

	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val) {
		hours = hrs;
		minutes = mins;
		seconds = secs;
		am = am_val;
	}

	/*
	 * Copy constructor
	 */

	am_pm_clock::am_pm_clock(const am_pm_clock &clock)
	{
		hours = clock.hours;
		minutes = clock.minutes;
		seconds = clock.seconds;
		am = clock.am;
	}

	/*
	 * Assignment operator
	 */
	am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock) {

		this->hours = clock.hours;
		this->seconds = clock.seconds;
		this->minutes = clock.minutes;
		this->am = clock.am;
		return *this;
	}

	/*
	 * Toggles the am/pm value for the clock
	 */
	void am_pm_clock::toggle_am_pm()
	{
		if (!am) {
			am = true;
		}
		if (am) {
			am = false;
		}
	}

	/*
	 * Resets the time to midnight
	 */
	void am_pm_clock::reset() {
		hours = 12;
		minutes = 00;
		seconds = 00;
		am = true;
	}

	/*
	 * Advances the time of the clock by one second
	 */
	void am_pm_clock::advance_one_sec() {

		if (seconds == 59 && minutes != 59 && hours != 11) {
			seconds = 00;
			minutes = minutes + 1;
		}
		if (seconds == 59 && minutes == 59 &&hours != 11) {
			seconds = 00;
			minutes = 00;
			hours = hours + 1;
		}
		if (seconds == 59 && minutes == 59 && hours == 11) {
			am_pm_clock::toggle_am_pm();
			seconds = 00;
			minutes = 00;
			hours = 12;

		}
		if (hours>12)
		{
			hours=hours-12;
		}
		seconds++;
	}

	/*
	 * Advances the time of the clock by n seconds
	 */
	void am_pm_clock::advance_n_secs(unsigned int n) {
		int sum = n + seconds;
		while ( sum >= 60)
		{
			sum -= 60;
			minutes += 1;
		}
		while (minutes >= 60)
		{
			minutes -= 60;
			hours += 1;
			if (hours == 12)
			{
				am_pm_clock::toggle_am_pm();
			}
			if (hours > 12) {
				hours = 1;
			}
		}

	}

	/*
	 * Getter for hours field
	 */
	unsigned int am_pm_clock::get_hours() const{

		return hours;
	}

	/*
	 * Setter for hours field; throws an invalid_argument exception
	 * if hrs is not a legal hours value
	 */
	void am_pm_clock::set_hours(unsigned int hrs)
	{
		if (hrs > 12)
		{
			throw std::invalid_argument("INVALID VALUE!");
		}
		if (hrs < 12)
		{
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
	void am_pm_clock::set_minutes(unsigned int mins)
	{
		if (mins > 60)
		{
			throw std::invalid_argument("INVALID VALUE!");
		}
		if (mins < 60)
		{
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
	void am_pm_clock::set_seconds(unsigned int secs)
	{
		if (secs > 60)
		{
			throw std::invalid_argument("INVALID VALUE!");
		}
		if (secs < 60)
		{
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
	void am_pm_clock::set_am(bool am_val)
	{
		am=am_val;
	}

	/*
	 * Destructor
	 */
	am_pm_clock::~am_pm_clock() {};

