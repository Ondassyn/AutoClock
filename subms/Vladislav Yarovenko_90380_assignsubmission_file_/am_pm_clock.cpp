
#include <iostream>
#include <ostream>
#include <stdexcept> //I had to include this library because std::invalid_argument caused an error
#include <cstdio>       // I had to include this library because sprintf caused an error
#include "am_pm_clock.h"

/*
 * Default constructor
 */
am_pm_clock::am_pm_clock():

    hours(12),
    minutes(0),
    seconds(0),
    am(true)
{   }

/*
 * Constructor
 */
am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
                         unsigned int secs, bool am_val)
{
    if (hrs < 1 || hrs > 12 || mins >= 60 || secs >= 60)
    {
        throw std::invalid_argument("Wrong time\n");
    }
    else
    {
        hours = hrs;
        minutes = mins;
        seconds = secs;
        am = am_val;
    }
}

/*
 * Copy constructor
 */
am_pm_clock::am_pm_clock(const am_pm_clock &clock)
{
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
}

/*
 * Assignment operator
 */
am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock)
{
    this->hours = clock.hours;
    this->minutes = clock.minutes;
    this->seconds = clock.seconds;
    this->am = clock.am;
    return *this;
}

/*
 * Toggles the am/pm value for the clock
 */
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

/*
 * Resets the time to midnight
 */
void am_pm_clock::reset()
{

    hours = 12;
    minutes = 0;
    seconds = 0;
    am = true;
}

/*
 * Advances the time of the clock by one second
 */
void am_pm_clock::advance_one_sec()
{
    if (seconds+1 >=60)
    {
        minutes++;
        seconds = 0;
        if (minutes>=60)
        {
            hours++;
            minutes = 0;
            if (hours == 12)
            {
                toggle_am_pm();

            }
            else if (hours > 12)
            {
                hours = 1;
            }
        }
    }
    else
    {
        seconds +=1;
    }
}

/*
 * Advances the time of the clock by n seconds
 */
void am_pm_clock::advance_n_secs(unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++)
    {
        advance_one_sec();
    }
}

/*
 * Getter for hours field
 */
unsigned int am_pm_clock::get_hours() const
{
    return hours;
}

/*
 * Setter for hours field;
 */
void am_pm_clock::set_hours(unsigned int hrs)
{
    if (hrs >= 1 && hrs <= 12)
    {
        hours = hrs;
    }
    else
    {
        throw std::invalid_argument("Wrong time\n");
    }
}

/*
 * Getter for minutes field
 */
unsigned int am_pm_clock::get_minutes() const
{
    return minutes;
}

/*
 * Setter for minutes field
 */
void am_pm_clock::set_minutes(unsigned int mins)
{
    if (mins >= 0 && mins < 60)
    {
        minutes = mins;
    }
    else
    {
        throw std::invalid_argument("Wrong time\n");
    }
}

/*
 * Getter for seconds field
 */
unsigned int am_pm_clock::get_seconds() const
{
    return seconds;
}

/*
 * Setter for seconds field
 */
void am_pm_clock::set_seconds(unsigned int secs)
{
    if (secs >= 0 && secs < 60)
    {
        seconds = secs;
    }
    else
    {
        throw std::invalid_argument("Wrong time\n");
    }
}

/*
 * Getter for am field
 */
bool am_pm_clock::is_am() const
{
    return am;
}

/*
 * Setter for am field
 */
void am_pm_clock::set_am(bool am_val)
{
    am = am_val;
}



/*
 * Destructor
 */
am_pm_clock::~am_pm_clock()
{    }



