#include "am_pm_clock.h"
#include <iostream>

am_pm_clock::am_pm_clock() {
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = 1;
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val){
					hours = hrs;
					minutes = mins;
					seconds = secs;
					am = am_val;
				}

am_pm_clock::am_pm_clock(const am_pm_clock &clock) {
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
	return *this;
}

void am_pm_clock::toggle_am_pm(){
		am = !am;
	};

void am_pm_clock::reset(){
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = 1;
};

void am_pm_clock::advance_one_sec(){
	seconds += 1;
	if (seconds == 60){
		seconds = 0;
		minutes += 1;
		if (minutes == 60){
			minutes = 0;
			hours += 1;
			if (hours == 12){
				am = !am;
			} else if(hours == 13){
				hours = 1;
			}
		}
	}
};

void am_pm_clock::advance_n_secs(unsigned int n){
	int i = 0;
	for(i = 0; i < n; i++){
		this->advance_one_sec();
	}
};

unsigned int am_pm_clock::get_hours() const{
	return hours;
};

void am_pm_clock::set_hours(unsigned int hrs){
	if (hrs < 0 || hrs > 13){
		throw std::invalid_argument("hours should be less than 13 and not negative");
	} else {
		hours = hrs;
	}
};

unsigned int am_pm_clock::get_minutes() const{
	return minutes;
};

void am_pm_clock::set_minutes(unsigned int mins){
	if (mins < 0 || mins >59){
		throw std::invalid_argument("minutes should be less than 60 and not negative");
	} else {
		minutes = mins;
	}
};

unsigned int am_pm_clock::get_seconds() const{
	return seconds;
};

void am_pm_clock::set_seconds(unsigned int secs){
	if (secs < 0 || secs > 59){
		throw std::invalid_argument("seconds should be less than 60 and not negative");
	} else {
		seconds = secs;
	}
};

bool am_pm_clock::is_am() const{
	return am;
};

void am_pm_clock::set_am(bool am_val){
	am = am_val;
};

am_pm_clock::~am_pm_clock() {};