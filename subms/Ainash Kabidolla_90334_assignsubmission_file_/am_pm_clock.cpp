#include "am_pm_clock.h"

	/*
	 * Default constructor - initial time should be midnight
	 */
	am_pm_clock::am_pm_clock(){	
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = true;
}
	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val){
	hours = hrs;
	minutes = mins;
	seconds = secs;
	am = am_val;
}
	/*
	 * Copy constructor
	 */
	am_pm_clock::am_pm_clock(const am_pm_clock &clock){
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
}

	am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
}

	/*
	 * Toggles the am/pm value for the clock
	 */
	void am_pm_clock::toggle_am_pm(){
	if (am == true) {
		am = false;
	} else {
		am = true;
	}
}

	/*
	 * Resets the time to midnight
	 */
	void am_pm_clock::reset(){
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = true;
}

	/*
	 * Advances the time of the clock by one second
	 */
	void am_pm_clock::advance_one_sec(){
	if (seconds + 1 < 60) {
		seconds = seconds + 1;
	} else {
		if (minutes + 1 < 60) {
			minutes = minutes + 1;
			seconds = 0;
		} else {
			if (hours == 12) {
				hours = 1;
				minutes = 0;
				seconds = 0;
			} else if (hours == 11){
				toggle_am_pm();
				hours = 12; 
				minutes = 0;
				seconds = 0;
			} else if (hours < 11) {
				hours = hours + 1;
				minutes = 0;
				seconds = 0;
			}
		}
	} 
}

	/*
	 * Advances the time of the clock by n seconds
	 */
	void am_pm_clock::advance_n_secs(unsigned int n){
	if (n < 60 && seconds + n < 60) {
		seconds = seconds + n;
	} else if (n < 60 && seconds + n > 60){
		if (minutes + 1 < 60) {
			minutes = minutes + 1;
			seconds = seconds + n - 60;
		} else {
			if (hours == 12) {
				hours = 1;
				minutes = 0;
				seconds = seconds + n - 60;
			} else if (hours == 11){
				toggle_am_pm();
				hours = 12; 
				minutes = 0;
				seconds = seconds + n - 60;
			} else if (hours < 11) {
				hours = hours + 1;
				minutes = 0;
				seconds = seconds + n - 60;
			}
		}
	} else if (n/60 < 60){
		int i = n/60;
		if (minutes + i < 60) {
			minutes = minutes + i;
			seconds = seconds + n - i*60;
		} else {
			if (hours == 12) {
				hours = 1;
				minutes = minutes + i - 60;
				seconds = seconds + n - i*60;
			} else if (hours == 11){
				toggle_am_pm();
				hours = 12; 
				minutes = minutes + i - 60;
				seconds = seconds + n - i*60;
			} else if (hours < 11) {
				hours = hours + 1;
				minutes = minutes + i - 60;
				seconds = seconds + n - i*60;
			}
		}
	} else if (n/60 >= 60){
		int i = n/60;
		int j = i/60;
		
		if (hours + j == 12) {
			hours = 1;
			minutes = minutes + i - 60;
			seconds = seconds + n - i*60;
		} else if (hours + j == 11){
			toggle_am_pm();
			hours = 12; 
			minutes = minutes + i - 60;
			seconds = seconds + n - i*60;
		} else if (hours + j < 11) {
			hours = hours + 1;
			minutes = minutes + i - 60;
			seconds = seconds + n - i*60;
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
	void am_pm_clock::set_hours(unsigned int hrs){
	if (hrs <= 12) {
		hours = hrs;
	} else {
		throw std::invalid_argument("The range should be between 1 and 12");   }
}

	/*
	 * Getter for minutes field
	 */
	unsigned int am_pm_clock::get_minutes() const{
	return minutes;
}

	/*
	 * Setter for minutes field; throws an invalid_argument exception
	 * if mins is not a legal minutes value
	 */
	void am_pm_clock::set_minutes(unsigned int mins){
	if (mins < 60) {
		minutes = mins;
	} else {
		throw std::invalid_argument("The range should be between 0 and 59");   }
}


	/*
	 * Getter for seconds field
	 */
	unsigned int am_pm_clock::get_seconds() const{
	return seconds;
}

	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
	void am_pm_clock::set_seconds(unsigned int secs){
	if (secs < 60) {
		seconds = secs;
	} else {
		throw std::invalid_argument("The range should be between 1 and 59");   }
}

	/*
	 * Getter for am field
	 */
	bool am_pm_clock::is_am() const{
	return am;
}

	/*
	 * Setter for am field
	 */
	void am_pm_clock::set_am(bool am_val){
	if (am_val == true){
		am = true;
	} else {
		am = false;
	}
}
	am_pm_clock::~am_pm_clock() {}

