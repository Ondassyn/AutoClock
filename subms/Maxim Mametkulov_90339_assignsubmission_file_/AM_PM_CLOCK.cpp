#include <iostream>
#include "AM_PM_CLOCK.h"

am_pm_clock::am_pm_clock():
	hours(12),
	minutes(0),
	seconds(0),
	am(true)
{}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val){
	hours = hrs; minutes = mins; seconds = secs;
	am = am_val;
}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
  hours = clock.get_hours();
  minutes = clock.get_minutes();
  seconds = clock.get_seconds();
  am = clock.is_am();
  return *this;
}

am_pm_clock::am_pm_clock(const am_pm_clock &clock){
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
}
//toggles am to pm 
void am_pm_clock::toggle_am_pm(){
	if (am) am = false;
	am = true;
}

void am_pm_clock::reset(){
	hours = 12; minutes = 0; seconds = 0; am = true;
}

void am_pm_clock::advance_one_sec(){
	seconds++;
	if (seconds==60){seconds=0;minutes++;
		if (minutes==60){
			minutes=0; hours++;
			if (hours==13){hours=1;}
		}}
}

void am_pm_clock::advance_n_secs(unsigned int n){
	seconds = seconds + n;
	if (seconds>=60){seconds=0;minutes++;
		if(minutes==60){minutes=0;hours++;
			if(hours==13){hours=1;}}}
}

unsigned int am_pm_clock::get_hours() const{
	return hours;
}

unsigned int am_pm_clock::get_minutes() const{
	return minutes;
}

unsigned int am_pm_clock::get_seconds() const{
	return seconds;
}

bool am_pm_clock::is_am() const{
	return am;
}

void am_pm_clock::set_am(bool am_val){
	am = am_val;
}

void am_pm_clock::set_hours(unsigned int hrs){
	if ((hrs>=24)||(hrs<0)){
		throw std::invalid_argument("hours cannot be more than 24 or less than 0");
	}
  
	hours = hrs;
}

void am_pm_clock::set_minutes(unsigned int mins){
	if ((mins>=60)||(mins<0)){
		throw std::invalid_argument("Minutes cannot be more than 60 or less than 0");
	}
	minutes = mins;
}

void am_pm_clock::set_seconds(unsigned int secs){
	if ((secs>=60)||(secs<0)){
		throw std::invalid_argument("Seconds cannot be more than 60 or less than 0");
	}
	seconds = secs;
}

am_pm_clock::~am_pm_clock(){}