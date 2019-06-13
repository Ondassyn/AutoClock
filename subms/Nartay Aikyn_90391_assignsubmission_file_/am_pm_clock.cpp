
#include <iostream>
#include <ostream>
#include "am_pm_clock.h"

using namespace std;


am_pm_clock::am_pm_clock():
	hours(12),
	minutes(0),
	seconds(0),
	am(true)
{

}


am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
						unsigned int secs, bool am_val){
	if(hrs > 12 || hrs < 1 || mins > 59 || mins < 0 || secs > 59 || secs < 0 || (am_val != 1 && am_val != 0)){
		throw invalid_argument("\nIncorrect input");
	}
	hours = hrs;
	minutes = mins;
	seconds = secs;
	am = am_val;
}


am_pm_clock::am_pm_clock(const am_pm_clock &clock){
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
}


am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){

	if (this == &clock) return *this;

	this->hours = clock.hours;
	this->minutes = clock.minutes;
	this->seconds = clock.seconds;
	this->am = clock.am;

	return *this;
}


void am_pm_clock::toggle_am_pm(){
	am = am ? false : true;
}


void am_pm_clock::reset(){
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = true;
}


void am_pm_clock::advance_one_sec(){

	if(seconds != 59){
		seconds++;

	}else{
		seconds = 0;

		if(minutes != 59){
			minutes++;

		}else{
			minutes = 0;

			if(hours < 11){
				hours++;

			}else if(hours == 11){
				hours++;
				toggle_am_pm();

			}else if(hours == 12){
				hours = 1;

			}
		}
	}
}


void am_pm_clock:: advance_n_secs(unsigned int n){
	unsigned int i;
	for(i = 0; i < n; i++){
		advance_one_sec();
	}
}


unsigned int am_pm_clock:: get_hours() const{
	return hours;
}


void am_pm_clock:: set_hours(unsigned int hrs){
	if(hrs > 12 || hrs < 1){
		throw invalid_argument("\nGive me something right (1 to 12)");
	}
	hours = hrs;
}


unsigned int am_pm_clock:: get_minutes() const{
	return minutes;
}


void am_pm_clock:: set_minutes(unsigned int mins){
	if(mins > 59 || mins < 0){
		throw invalid_argument("\nGive me something right (0 to 59)");
	}
	minutes = mins;
}


unsigned int am_pm_clock:: get_seconds() const{
	return seconds;
}


void am_pm_clock:: set_seconds(unsigned int secs){
	if(secs > 59 || secs < 0){
		throw invalid_argument("\nGive me something right (0 to 59)");
	}
	seconds = secs;
}


bool am_pm_clock:: is_am() const{
	return am;
}


void am_pm_clock:: set_am(bool am_val){
	am = am_val;
}


am_pm_clock::~am_pm_clock(){ }




