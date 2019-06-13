#include <stdio.h>
#include "am_pm_clock.h"
am_pm_clock::am_pm_clock(){
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
	this->am = true;
}
am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
	unsigned int secs, bool am_val){
	this->hours = hrs;	
	this->minutes = mins;
	this->seconds = secs;
	this->am = am_val;	
}
am_pm_clock::am_pm_clock(const am_pm_clock & clock){
	this->hours = clock.get_hours();
	this->minutes = clock.get_minutes();
	this->seconds = clock.get_seconds();
	this->am = clock.is_am();
}
am_pm_clock& am_pm_clock::operator=(const am_pm_clock & clock){
	this->hours = clock.get_hours();
	this->minutes = clock.get_minutes();
	this->seconds = clock.get_seconds();
	this->am = clock.is_am();
	return *this;
}
void am_pm_clock::toggle_am_pm(){
	if (this->am)this->am = false;
	else this->am = true;
}
void am_pm_clock::reset(){
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
	this->am = true;
}
void am_pm_clock::advance_one_sec(){
	this->seconds++;
	if(this->seconds == 60){
		this->minutes++;
		this->seconds = 0;
	}
	if(this->minutes == 60){
		this->hours++;
		this->minutes = 0;
	}
	this->hours = this->hours%24;
	if(this->hours == 12 and this->minutes == 0 and this->seconds == 0){
		this->toggle_am_pm();
	}
}

void am_pm_clock::advance_n_secs(unsigned int n){
	for(int i = 0;i < n; i++){
		this->advance_one_sec();
	}	
}
unsigned int am_pm_clock::get_hours()const{
	return this->hours;
}
void am_pm_clock::set_hours(unsigned int hrs){
	if(hrs > 23)throw std::invalid_argument("invalid value for hours");
	else this->hours = hrs;
}
unsigned int am_pm_clock::get_minutes()const{
	return this->minutes;
}
void am_pm_clock::set_minutes(unsigned int mins){
	if(mins > 59)throw std::invalid_argument("invalid value for minutes");
	else this->minutes = mins;
}
unsigned int am_pm_clock::get_seconds()const{
	return this->seconds;
}
void am_pm_clock::set_seconds(unsigned int secs){
	if(secs > 59)throw std::invalid_argument("invalid value for seconds");
	else this->seconds = secs;
}
bool am_pm_clock::is_am()const{
	return this->am;
}
void am_pm_clock::set_am(bool am_val){
	this->am = am_val;
}
am_pm_clock::~am_pm_clock(){

}

