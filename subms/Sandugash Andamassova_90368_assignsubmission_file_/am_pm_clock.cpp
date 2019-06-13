#include "am_pm_clock.h"

// Default constructor: sets time 12.00.00 am

am_pm_clock::am_pm_clock() :

hours(12),
minutes(0),
seconds(0),
am(1)
{}

// Constructor: sets time to the assigned values
// throws exception, if the values are unacceptable: hrs>12, mins<0, & etc.

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
            unsigned int secs, bool am_val) :

hours(hrs),
minutes(mins),
seconds(secs),
am(am_val)

{
    if ((hrs > 12) || (hrs < 1))
        throw std::invalid_argument(" Invalid argument of hours. \n");
    
    if ((mins > 59) || (mins < 0))
        throw std::invalid_argument(" Invalid argument of mins. \n");
    
    if ((secs > 59) || (secs < 0))
        throw std::invalid_argument(" Invalid argument of secs. \n");
}

// Copy constructor: copies the values of another object

am_pm_clock::am_pm_clock(const am_pm_clock &clock) :

hours(clock.hours),
minutes(clock.minutes),
seconds(clock.seconds),
am(clock.am)
{}

// Assignment operator:

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock)
{
    am = clock.am;
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    
    return *this;
    
}

// Toggles the am/pm value for the clock:

void am_pm_clock::toggle_am_pm()
{
    if(am == 1)
        am = 0;
    
    else am = 1;
}

// Resets the time to midnight (12.0.0am):

void am_pm_clock::reset()
{
    hours = 12;
    minutes = 0;
    seconds = 0;
    am = 1;
}

// Advances the time of the clock by one second:

void am_pm_clock::advance_one_sec()
{
    // if the time is hrs.mins.59; mins will increment by 1, and seconds will be 0
    if( seconds != 59 )
        seconds++;
    
    else {
        seconds = 0;
        
        if( minutes != 59)
            minutes++;
        
        // if the time is hrs.59.59; hours will increment by 1, and seconds will be 0
        else {
            minutes = 0;
            hours++;
            
            // in case the hours became 13
            // it will be changed by 1
            if( hours == 13)
                hours = 1;
            
            // if the hours is 12
            //the clock will toggle am/pm value
            else if( hours == 12)
                toggle_am_pm();
        }}}

// Advances the time of the clock by n seconds:

void am_pm_clock::advance_n_secs(unsigned int n)
{
    int repeat = 0;
    while( repeat < n)
    {
        advance_one_sec();
        repeat++;
    }
}

// Getter for hours field:

unsigned int am_pm_clock::get_hours() const
{
return hours;
}

 // Setter for hours field; throws an invalid_argument exception
 // if hrs is not a legal hours value

void am_pm_clock::set_hours(unsigned int hrs)
{
    if ((hrs > 12) || (hrs < 1))
        throw std::invalid_argument(" Invalid argument of hours. \n");
    else
        hours = hrs;
}

// Getter for minutes field

unsigned int am_pm_clock::get_minutes() const
{
    return minutes;
}

// Setter for minutes field; throws an invalid_argument exception
// if mins is not a legal minutes value

void am_pm_clock::set_minutes(unsigned int mins)
{
    if ((mins > 59) || (mins < 0))
        throw std::invalid_argument(" Invalid argument of minutes. \n");
    else
        minutes = mins;
}


// Getter for seconds field

unsigned int am_pm_clock::get_seconds() const
{
    return seconds;
}

// Setter for seconds field; throws an invalid_argument exception
// if secs is not a legal seconds value

void am_pm_clock::set_seconds(unsigned int secs)
{
    if ((secs > 59) || (secs < 0))
        throw std::invalid_argument(" Invalid argument of seconds. \n");
    else
        seconds = secs;
}

//Getter for am field

bool am_pm_clock::is_am() const
{
    return am;
}

//Setter for am field

void am_pm_clock::set_am(bool am_val)
{
         am = am_val;
}



// Destructor
am_pm_clock::~am_pm_clock() {}
