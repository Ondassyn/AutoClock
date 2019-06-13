#include "am_pm_clock.h"
#include <iostream>

am_pm_clock::am_pm_clock()
{
    hours = 12;
    minutes = 00;
    seconds = 00;
    am = true;     
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val)
{
    hours = hrs;
    minutes = mins;
    seconds = secs;
    am = am_val;
}
			   
am_pm_clock::am_pm_clock(const am_pm_clock &clock)
{
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock)
{
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
}

void am_pm_clock::toggle_am_pm()
{
	am = (am+1)%2;
}

void am_pm_clock::reset()
{
    hours = 12;
    minutes = 00;
    seconds = 00;
    am = true;
}

void am_pm_clock::advance_one_sec()
{
	seconds++;
    if(seconds == 60){           
        seconds = 0;
        minutes++;
        
        if(minutes == 60){
            minutes = 0;
            hours++;
	
            if(hours == 12){
                am_pm_clock::toggle_am_pm();
            }
            if(hours == 13)hours = 1;
		}
	}             
}

void am_pm_clock::advance_n_secs(unsigned int n)
{
    int total = seconds + minutes*60 + hours*3600;
    total += n;
    hours = total/3600;
    minutes = (total%3600)/60;
    seconds = (total%3600%60);
	
}

unsigned int am_pm_clock::get_hours() const
{
    return hours;
}

void am_pm_clock::set_hours(unsigned int hrs)
{
    if(hrs > 0 && hrs < 12){
        hours = hrs;
    } else {
        throw std::invalid_argument( "is not legal hours value\n" );
    }
}

unsigned int am_pm_clock::get_minutes() const
{
    return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins)
{
    if(mins >= 0 && mins < 60){
        minutes = mins;
    } else if (mins < 0) {
        minutes = 0;
    } else {
        throw std::invalid_argument( "is not legal minutes value\n" );
    }
}

unsigned int am_pm_clock::get_seconds() const
{
    return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs)
{
    if(secs >= 0 && secs < 60){
        seconds = secs;
    } else if (secs < 0) {
        seconds = 0;
    } else {
        throw std::invalid_argument( "is not legal seconds value\n" );
    } 
}

bool am_pm_clock::is_am() const
{
    return am;
}

void am_pm_clock::set_am(bool am_val)
{
    if(am_val == true)
        am = 1;
    else
        am = 0;
}

am_pm_clock::~am_pm_clock() {}
