//
// Created by s.amangeldi on 07.06.2019.
//

#include "am_pm_clock.h"

am_pm_clock::am_pm_clock()
{
    hours = 12;
    minutes = 00;
    seconds = 00;
    am = true;
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,unsigned int secs, bool am_val)
{
    seconds = secs;
    minutes = mins;
    hours = hrs;
    am = am_val;
}

am_pm_clock:: am_pm_clock(const am_pm_clock &clock)
{
    seconds = clock.seconds;
    minutes = clock.minutes;
    hours = clock.hours;
    am = clock.am;
}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock &clock)
{
    seconds = clock.seconds;
    minutes = clock.minutes;
    hours = clock.hours;
    am = clock.am;
    return const_cast<am_pm_clock &>(clock);
}

void am_pm_clock::toggle_am_pm(){am = !am;}

void am_pm_clock::reset()
{
    set_hours(12);
    set_minutes(0);
    set_seconds(0);
    set_am(true);
}

void am_pm_clock::advance_one_sec()
{
    seconds++;
    if(seconds > 59){
        minutes++;
        seconds -= 60;
    }
    if(minutes > 59) {
        hours++;
        minutes -= 60;
    }
    if(hours > 12) {
        am = !am;
        hours -= 12;
    }
}

void am_pm_clock::advance_n_secs(unsigned int n)
{
    hours += (n / 3600);
    n %= 3600;
    minutes += (n / 60);
    n %= 60;
    seconds += n;
    if(seconds > 59){
        minutes++;
        seconds -= 60;
    }
    if(minutes > 59) {
        hours++;
        minutes -= 60;
    }
    if(hours > 12) {
        am = !am;
        hours -= 12;
    }
}

unsigned int am_pm_clock::get_hours() const{return hours;}

void am_pm_clock::set_hours(unsigned int hrs) {
    if(hrs < 0 )
        throw std::out_of_range("invalid_argument exception");
    if(hrs > 12)
        throw std::out_of_range("invalid_argument exception");
    hours = hrs;
}

unsigned int am_pm_clock::get_minutes() const{return minutes;}

void am_pm_clock::set_minutes(unsigned int mins)
{
    if(mins < 0 )
        throw std::out_of_range("invalid_argument exception");
    if(mins > 59)
        throw std::out_of_range("invalid_argument exception");
    minutes = mins;
}

unsigned int am_pm_clock::get_seconds() const{return seconds;}

void am_pm_clock::set_seconds(unsigned int secs)
{
    if(secs < 0 )
        throw std::out_of_range("invalid_argument exception");
    if(secs > 59)
        throw std::out_of_range("invalid_argument exception");
    seconds = secs;
}

bool am_pm_clock::is_am() const{return am;}

void am_pm_clock::set_am(bool am_val){am = am_val;}

am_pm_clock::~am_pm_clock() {}
