//============================================================================
// Name        : assignment1.cpp
// Author      : Dana 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "am_pm_clock.h"
using namespace std;

 /*
  * Default constructor - initial time should be midnight
  */
 am_pm_clock:: am_pm_clock(){
	 hours=12;
	 minutes=0;
	 seconds=0;
	 am=true;
 }

 /*
  * Constructor - sets fields to the given argument values
 */
 am_pm_clock:: am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val){
 	hours=hrs;
	minutes=mins;
	seconds=secs;
	am=am_val;
 }

 /*
 * Copy constructor
 */
 am_pm_clock::am_pm_clock (const am_pm_clock &clock){
	hours=clock.get_hours();
	minutes=clock.get_minutes();
	seconds=clock.get_seconds();
	am=clock.is_am();
	}

 /*
 * Assignment operator
 */
 am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
	hours=clock.get_hours();
	minutes=clock.get_minutes();
	seconds=clock.get_seconds();
	am=clock.is_am();
	return *this;
		}

 /*
 * Toggles the am/pm value for the clock
 */
 void am_pm_clock:: toggle_am_pm(){
	if(am==true){
	 	am=false;
	}else if(am==false){
		am=true;
	}
 }

 /*
  * Resets the time to midnight
  */
 void am_pm_clock:: reset(){
	hours=12;
	minutes=0;
	seconds=0;
	am=true;
 }

 /*
 * Advances the time of the clock by one second
 */
 void am_pm_clock:: advance_one_sec(){
	if(seconds==59 && minutes==59){
		seconds=0;
		minutes=0;
		if(hours==11){
			hours++;
			toggle_am_pm();
		}else if(hours==12){
			hours=1;
		}else{
			hours++;				}
	}else{	
		seconds++;
	}
 }


 /*
 * Advances the time of the clock by n seconds
 */
 void am_pm_clock:: advance_n_secs(unsigned int n){
	seconds+=n; //seconds=6001
	if(seconds>59){
		unsigned int m=(seconds/60); //m=100
		minutes+=m; //0+100=100
		seconds=seconds-(60*m);//6001-6000=1
		if(minutes>59){
			unsigned int l=(minutes/60);// 100/60=1
			minutes=minutes-(60*l); //40
			hours+=l; //12+1
			if(hours>12){ // 13pm
				hours=hours-12;//13-12=1pm
			}
		}
	}
 }
	// 25/7=3 and if 25%7=4


 /*
 * Getter for hours field
 */
 unsigned int am_pm_clock:: get_hours() const{
	return hours;
 }

 /*
 * Setter for hours field; throws an invalid_argument exception
 * if hrs is not a legal hours value
 */
 void am_pm_clock:: set_hours(unsigned int hrs){
	hours=hrs;
	if(hours>12 || hours<1){
		throw std::invalid_argument("Hours are not in a legal value!!!");
	}
 }

 /*
 * Getter for minutes field
 */
 unsigned int am_pm_clock::  get_minutes() const{
	return minutes;
 }

 /*
 *
 * Setter for minutes field; throws an invalid_argument exception
 * if mins is not a legal minutes value
 */
 void am_pm_clock::  set_minutes(unsigned int mins){
	minutes=mins;
	if(minutes>59 || minutes<0){
		throw std::invalid_argument("Minutes are not in a legal value!!!");
	}
 }

 /*
 * Getter for seconds field
 */
 unsigned int am_pm_clock::  get_seconds() const{
	return seconds;
 }

 /*
 * Setter for seconds field; throws an invalid_argument exception
 * if secs is not a legal seconds value
 */
 void am_pm_clock:: set_seconds(unsigned int secs){
	seconds=secs;
	if(secs>59 || seconds<0){
	throw std::invalid_argument("Seconds are not in a legal value!!!");
	}
 }

 /*
  * Getter for am field
  */
 bool am_pm_clock:: is_am() const{
	 return am;
 }

 /*
 * Setter for am field
 */
 void am_pm_clock:: set_am(bool am_val){
 	am=am_val;
 }

 /*
 * Print function - helper for output operator
 *
 void am_pm_clock:: print(std::ostream& out) const {
		char buff[11];
		std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
				( am ? 'a' : 'p' ));
	 	out << buff;
 }
*/
	
 /*
 * Destructor
 */
 am_pm_clock::~am_pm_clock(){
 }



