#include <iostream>
#include <stdexcept>
#include "am_pm_clock.h"

	/*
	 * Default constructor - initial time should be midnight
	 */
	am_pm_clock::am_pm_clock():
		hours(12),minutes(0),seconds(0),am(true){}

	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val):
			    	hours(hrs),minutes(mins),seconds(secs),am(am_val){}

	/*
	 * Copy constructor
	 */
	am_pm_clock::am_pm_clock(const am_pm_clock &clock){
		hours=clock.hours;
		minutes=clock.minutes;
		seconds=clock.seconds;
		am=clock.am;
	}

	/*
	 * Assignment operator
	 */
	am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
		if(this!=&clock){
			hours=clock.hours;
			minutes=clock.minutes;
			seconds=clock.seconds;
			am=clock.am;
		}return *this;
	}

	/*
	 * Toggles the am/pm value for the clock
	 */
	void am_pm_clock::toggle_am_pm(){
		if(am)
			am=false;
		else
			am=true;
	}

	/*
	 * Resets the time to midnight
	 */
	void am_pm_clock::reset(){
		am=true;hours=12;minutes=0;seconds=0;
	}

	/*
	 * Advances the time of the clock by one second
	 */
	void am_pm_clock::advance_one_sec(){
		if(seconds<59){
			seconds++;
		}else if(seconds==59){
			if(minutes<59){
				seconds=0;
				minutes++;
			}else if(minutes==59){
				minutes=0;
				seconds=0;
				if(hours==11){
					toggle_am_pm();
					hours++;
				}else if(hours==12){
					hours=1;
				}else{
					hours++;
				}
			}

		}
	}

	/*
	 * Advances the time of the clock by n seconds
	 */
	void am_pm_clock::advance_n_secs(unsigned int n){
		for(unsigned int i=0;i<n;i++){
			advance_one_sec();
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
		if(1<=hrs && hrs<=12){
			hours=hrs;
		}else{
			throw std::invalid_argument("not a legal hours value");
		}
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
		if(0<=mins && mins<=59){
			minutes=mins;
		}else{
			throw std::invalid_argument("not a legal minutes value");
		}
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
		if(0<=secs && secs<=59){
			seconds=secs;
		}else{
			throw std::invalid_argument("not a legal seconds value");
		}
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
		am=am_val;
	}

	/*
	 * Print function - helper for output operator
	 */

	/*void print(std::ostream& out) const {      ----i put it in the comments----
			char buff[11];
			std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
					( am ? 'a' : 'p' ));
			out << buff;
		}
	 */

	/*this function works if it's in the main cpp file, to display time
	 *
	 * void display(const am_pm_clock& mine){
		std::cout<<mine.get_hours()<<":"<<mine.get_minutes()<<":"<<mine.get_seconds()<<" "<<
					(mine.is_am() ? "am" : "pm")<<"\n";
	}
	 */

	/*
	 * Destructor
	 */
	am_pm_clock::~am_pm_clock(){}

