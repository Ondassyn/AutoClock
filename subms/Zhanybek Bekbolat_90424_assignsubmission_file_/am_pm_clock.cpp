#include "am_pm_clock.h"
#include <iostream>
#include <ostream>
//#include <stdexcept>
using namespace std;

//Default constructor
am_pm_clock::am_pm_clock() :
    hours(12), minutes(0), seconds(0),
    am(true)
{}

//Constructor
am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val)
{
    if(hrs == 0 || hrs > 12 || mins >= 60 || secs >= 60)
    {
        throw invalid_argument ("That's not how time works here!");
    } else {
        hours = hrs;
        minutes = mins;
        seconds = secs;
        am = am_val;
    }
}

//Copy constructor
am_pm_clock::am_pm_clock(const am_pm_clock &clock) :
    hours(clock.hours), minutes(clock.minutes), seconds(clock.seconds),
    am(clock.am)
{}

//Assignment operator
am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock)
{
    this->hours = clock.hours;
    this->minutes = clock.minutes;
    this->seconds = clock.seconds;
    this->am = clock.am;
    return *this;
}

//Toggle am/pm
void am_pm_clock::toggle_am_pm()
{
    if (am == true)
    {
        am = false;
    } else {
        am = true;
    }
}

//Reset to midnight
void am_pm_clock::reset()
{
    hours = 12;
    minutes = 0;
    seconds = 0;
    am = true;
}

void am_pm_clock::advance_one_sec()
{
    seconds++;
    if (seconds >= 60)
    {
        minutes++;
        seconds = 0;

        if (minutes >= 60)
        {
            hours++;
            minutes = 0;

            if (hours == 12)
            {
                toggle_am_pm();
            }
            if (hours > 12)
            {
                hours = 1;
            }
        }
    }
}

void am_pm_clock::advance_n_secs(unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        advance_one_sec();
    }
}

//Returns hours
unsigned int am_pm_clock::get_hours() const
{
    return hours;
}

//Sets hours
void am_pm_clock::set_hours(unsigned int hrs)
{
    if (hrs == 0 || hrs > 12)
    {
        throw invalid_argument ("Invalid value for hours");
    } else {
        hours = hrs;
    }
}

//Returns minutes
unsigned int am_pm_clock::get_minutes() const
{
    return minutes;
}

//Sets minutes
void am_pm_clock::set_minutes(unsigned int mins)
{
    if (mins >= 60)
    {
        throw invalid_argument ("Invalid value for minutes");
    } else {
        minutes = mins;
    }
}

//Returns seconds
unsigned int am_pm_clock::get_seconds() const
{
    return seconds;
}

//Sets seconds
void am_pm_clock::set_seconds(unsigned int secs)
{
    if (secs >= 60)
    {
        throw invalid_argument ("Invalid value for seconds");
    } else {
        seconds = secs;
    }
}

//Returns am/pm
bool am_pm_clock::is_am() const
{
    return am;
}

//Sets am/pm
void am_pm_clock::set_am(bool am_val)
{
    am = am_val;
}

//The sad, useless destructor
am_pm_clock::~am_pm_clock()
{}
