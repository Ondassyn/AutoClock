#include <iostream>
#include <ostream>
#include "am_pm_clock.h"

// Default constructor - initial time should be midnight
am_pm_clock::am_pm_clock() :
    hours(12), minutes(0), seconds(0), am(true)
{
}

// Constructor - sets fields to the given argument values
am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs,
                         bool am_val)
{
    if (hrs == 0 || hrs > 12 || mins > 59 || secs > 59)
    {
        throw std::invalid_argument("This value is invalid!");
    }
    else
    {
        hours = hrs;
        minutes = mins;
        seconds = secs;
        am = am_val;
    }
}

//Copy constructor
am_pm_clock::am_pm_clock(const am_pm_clock &clock)
{
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
}

// Assignment operator
am_pm_clock& am_pm_clock::operator=(const am_pm_clock&clock)
{
    if (this == &clock)
    {
        return *this;
    }
    else
    {
        hours = clock.hours;
        minutes = clock.minutes;
        seconds = clock.seconds;
        am = clock.am;
        return *this;
    }
}

//Toggles the am/pm value for the clock
void am_pm_clock::toggle_am_pm()
{
    if (am == true)
    {
        am = false;
    }
    else
    {
        am = true;
    }
}

//Resets the time to midnight
void am_pm_clock::reset()
{
    hours = 12;
    minutes = 0;
    seconds = 0;
    am = true;
}

// Advances the time of the clock by one second
void am_pm_clock::advance_one_sec()
{
    if (seconds + 1 >= 60)
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
    else
    {
        seconds++;
    }
}

void am_pm_clock::advance_n_secs(unsigned int n)
{
    unsigned int var;
    for (var = 0; var < n; var++)
    {
        advance_one_sec();
    }
}
//void am_pm_clock::advance_n_secs(unsigned int n)
//{
// if (seconds+n >= 60)
// {
// minutes += n/60;
// seconds += n - minutes*60;
// {
// if(seconds >= 60)
// {
// minutes++;
// }
// }
// if(minutes >= 60)
// {
// hours += n/60;
// minutes += n - hours*60;
// {
// if(minutes >= 60)
// {
// hours++;
// }
// }
// if(hours == 12)
// {
// toggle_am_pm();
// }
// if(hours > 12)
// {
// hours = 1;
// }
// }
// }else
// {
// seconds++;
// }
//}

// Getter for hours field
unsigned int am_pm_clock::get_hours() const
{
    return hours;
}

/* Setter for hours field; throws an invalid_argument exception
* if hrs is not a legal hours value
*/
void am_pm_clock::set_hours(unsigned int hrs)
{
    if (hours >= 1 && hours <= 12)
    {
        hours = hrs;
    }
    else
    {
        throw std::invalid_argument("This value is invalid!");
    }
}

// Getter for minutes field
unsigned int am_pm_clock::get_minutes() const
{
    return minutes;
}

/* Setter for minutes field; throws an invalid_argument exception
* if mins is not a legal minutes value
*/
void am_pm_clock::set_minutes(unsigned int mins)
{
    if (minutes >= 0 && minutes <= 59)
    {
        minutes = mins;
    }
    else
    {
        throw std::invalid_argument("This value is invalid!");
    }
}

// Getter for seconds field
unsigned int am_pm_clock::get_seconds() const
{
    return seconds;
}

/* Setter for seconds field; throws an invalid_argument exception
* if secs is not a legal seconds value
*/
void am_pm_clock::set_seconds(unsigned int secs)
{
    if (seconds >= 0 && seconds <= 59)
    {
        seconds = secs;
    }
    else
    {
        throw std::invalid_argument("This value is invalid!");
    }
}

// Getter for am field
bool am_pm_clock::is_am() const
{
    return am;
}
am_pm_clock::~am_pm_clock()
{
}
