//============================================================================
// Name        : am_pm_clock.cpp
// Author      : Nursultan Ryspanbetov
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "am_pm_clock.h"

	/*
	 * Default constructor - initial time should be midnight
	 */
	am_pm_clock():
		hours(12),
		minutes(00),
		seconds(00),
		am(true)
	{

	}


	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val):
		hours(hrs),
		minutes(mins),
		seconds(secs),
		am(am_val)
	{

	}

	/*
	 * Copy constructor
	 */
	am_pm_clock(const am_pm_clock &clock){
		hours = clock.hours;
		minutes = clock.minutes;
		seconds = clock.seconds;
		am = clock.am;
	}
	/*
	 * Assignment operator
	 */

	am_pm_clock& operator=(const am_pm_clock& clock){
		hours = clock.hours;
		minutes = clock.minutes;
		seconds = clock.seconds;
		am = clock.am;
		return clock;
	}

	/*
	 * Toggles the am/pm value for the clock
	 */
	void toggle_am_pm(){
		am = !am;
	}
	/*
	 * Resets the time to midnight
	 */
	void reset(){
		hours = 12;
		minutes = 0;
		seconds = 0;
		am = true;
	}

	/*
	 * Advances the time of the clock by one second
	 */
	void advance_one_sec(){
		unsigned int m = minutes;
		unsigned int s = seconds;
		unsigned int h = hours;
		seconds = ( s + 1 ) % 60;
		minutes = ( m + ( s + 1 ) / 60 ) %  60;
		hours = ( h + ( s + 1 + 60 * m ) / 3600 ) % 12 + 1;
	}

	/*
	 * Advances the time of the clock by n seconds
	 */
	void advance_n_secs(unsigned int n){
		unsigned int m = minutes;
		unsigned int s = seconds;
		unsigned int h = hours;
		seconds = ( s + n ) % 60;
		minutes = ( m + ( s + n ) / 60 ) %  60;
		hours = ( h + ( s + n + 60 * m ) / 3600 ) % 12 + 1;
	}

	/*
	 * Getter for hours field
	 */
	unsigned int get_hours() const{
		return hours;
	}

	/*
	 * Setter for hours field; throws an invalid_argument exception
	 * if hrs is not a legal hours value
	 */
	void set_hours(unsigned int hrs){
		if ( hrs > 12 ) {
			throw std::invalid_argument("The clock is not 24-hour time, it cannot be more than 12 hrs!");
		}
		hours = hrs;
	}

	/*
	 * Getter for minutes field
	 */
	unsigned int get_minutes() const{
		return minutes;
	}

	/*
	 * Setter for minutes field; throws an invalid_argument exception
	 * if mins is not a legal minutes value
	 */
	void set_minutes(unsigned int mins){
		if ( mins > 59 ) {
			throw std::invalid_argument("Minutes cannot be more than 59!");
		}
		minutes = mins;
	}

	/*
	 * Getter for seconds field
	 */
	unsigned int get_seconds() const{
		return seconds;
	}

	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
	void set_seconds(unsigned int secs){
		if ( secs > 59 ) {
			throw std::invalid_argument("Seconds cannot be more than 59");
		}
		seconds = secs;
	}

	/*
	 * Getter for am field
	 */
	bool is_am() const{
		return am;
	}

	/*
	 * Setter for am field
	 */
	void set_am(bool am_val){
		am = am_val;
	}

	/*
	 * Print function - helper for output operator
	 */
	void print(std::ostream& out) const {
		char buff[11];
		std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
				( am ? 'a' : 'p' ));
		out << buff;
	}

	/*
	 * Destructor
	 */
	~am_pm_clock();
};

	inline std::ostream& operator << (std::ostream& out, const am_pm_clock& clock) {
		clock.print(out);
		return out;
}
