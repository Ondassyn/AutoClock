/*
 * am_pm_clock.cpp
 *
 *  Created on: Jun 7, 2019
 *      Author: student
 */

#include <ostream>
#include <cstdio>

#include "am_pm_clock.h"
using namespace std;

	am_pm_clock::am_pm_clock():
			am(true),
			hours(12),
			minutes(00),
			seconds(00)
	{}

	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
		    unsigned int secs, bool am_val)
		    am(am_val),
			hours(hrs),
			minutes(mins),
			seconds(secs)
{}


am_pm_clock::am_pm_clock(const am_pm_clock &clock)

am_pm_clock::am_pm_clock& operator=(const am_pm_clock& clock){
	this->hours=clock.hours;
	this->minutes=clock.minutes;
	this->seconds=clock.seconds;
	this->am=clock.am;
	return *this;
}

	/*
	 * Toggles the am/pm value for the clock
	 */
	void am_pm_clock:: toggle_am_pm(){
	 if(is_am())
		 set_am(false);
	 else
		 set_am(true);
	}
	/*
	 * Resets the time to midnight
	 */
	 void am_pm_clock::reset(){
			 set_hours(12);
			 set_minutes(00);
			 set_seconds(00);
			 set_am(true);
		 }

	/*
	 * Advances the time of the clock by one second
	 */
	 void am_pm_clock::advance_one_sec(){
		if(get_seconds()<59)
			set_seconds(get_seconds()+1);
		else
			set_seconds(00);
			if(get_minutes()<59)
				set_minutes(get_minutes()+1);
			else
				set_minutes(00);
			    set_hours(get_hours()+1);
				if(get_hours()>11)
					toggle_am_pm();

	 }
	/*
	 * Advances the time of the clock by n seconds
	 */
void am_pm_clock::advance_n_secs(unsigned int n){
		set_seconds((get_seconds()+n)%60);
		if(get_seconds()==0){
			set_minutes((get_minutes()+1)%60);
			if(get_minutes()==0){
				set_hours((get_hours()+1)%12);
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
	 * Setter for hours field; throws an 	am_pm_clock::invalid_argument exception
	 * if hrs is not a legal|hours> hours value
	 */
	void am_pm_clock::set_hours(unsigned int hrs){
		if(hours<0||hours>12)
				throw std::invalid_argument("Cannot have negative value!");
		else
			//unsigned int new_hours=hours+hrs;
			//hours=new_hours;
			hours=hrs;
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
		if(minutes<0||minutes>59)
					throw std::invalid_argument("Cannot have negative value!");
		else
					//unsigned int new_minutes=minutes+mins;
					//minutes=new_minutes;
		minutes=mins;
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
		if(seconds<0||seconds>59)
				throw std::invalid_argument("Cannot have negative value!");
		else
				seconds=secs;
	}

	/*
	 * Getter for am field
	 */
	bool am_pm_clock::is_am() const{
		if(am==true)
			return true;
		else
			return false;
	}

	/*
	 * Setter for am field
	 */
	void am_pm_clock::set_am(bool am_val){
		if(am_val)
			am(true);
		else
			am(false);
	}

	/*
	 * Print function - helper for output operator
	 */
	void am_pm_clock::print(std::ostream& out) const {
		char buff[11];
		std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
				( am ? 'a' : 'p' ));
		out << buff;
	}

	/*
		 * Destructor
		 */
		~am_pm_clock(){
		delete[];
	}

inline std::ostream& operator << (std::ostream& out, const am_pm_clock& clock)
{
	clock.print(out);
	return out;
}




