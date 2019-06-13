#include <am_pm_clock.h>
#include <ostream>
/*
 * Default constructor - initial time should be midnight
 */
am_pm_clock:: am_pm_clock()
{
    hours = 12;
    minutes= 0;
    seconds = 0;
    am =1;
}

/*
 * Constructor - sets fields to the given argument values
 */
am_pm_clock:: am_pm_clock(unsigned int hrs, unsigned int mins,
                          unsigned int secs, bool am_val)
{
    hours = hrs;
    minutes = mins;
    seconds = secs;
    am = am_val;
}

/*
 * Copy constructor
 */
am_pm_clock:: am_pm_clock(const am_pm_clock &clock)
{
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
}

/*
 * Assignment operator
 */
am_pm_clock:: am_pm_clock& operator=(const am_pm_clock& clock)
{
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
    return *this;
}

/*
 * Toggles the am/pm value for the clock
 */
void am_pm_clock:: toggle_am_pm()
{
    if(am == true)
    {
        am=0;
    }
    else
    {
        am=1;
    }
}

/*
 * Resets the time to midnight
 */
void am_pm_clock:: reset()
{
    hours = 12;
    minutes= 0;
    seconds = 0;
    am =1;
}

/*
 * Advances the time of the clock by one second
 */
void am_pm_clock:: advance_one_sec()
{
    second+=1;
}

/*
 * Advances the time of the clock by n seconds
 */
void am_pm_clock:: advance_n_secs(unsigned int n)
{
    seconds+=n;
}

/*
 * Getter for hours field
 */
unsigned int am_pm_clock:: get_hours() const
{
    return hours;
}

/*
 * Setter for hours field; throws an invalid_argument exception
 * if hrs is not a legal hours value
 */
void am_pm_clock:: set_hours(unsigned int hrs)
{
    hours = hrs;
}

/*
 * Getter for minutes field
 */
unsigned int am_pm_clock:: get_minutes() const
{
    return minutes;
}

/*
 * Setter for minutes field; throws an invalid_argument exception
 * if mins is not a legal minutes value
 */
void am_pm_clock:: set_minutes(unsigned int mins)
{
    minutes=mins;
}

/*
 * Getter for seconds field
 */
unsigned int am_pm_clock:: get_seconds() const
{
    return seconds;
}

/*
 * Setter for seconds field; throws an invalid_argument exception
 * if secs is not a legal seconds value
 */
void am_pm_clock:: set_seconds(unsigned int secs)
{
    seconds=secs;
}

/*
 * Getter for am field
 */
bool am_pm_clock:: is_am() const
{
    if(am==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Setter for am field
 */
void am_pm_clock:: set_am(bool am_val)
{
    am=am_val;
}

/*
 * Print function - helper for output operator
 */
void print(std::ostream& out) const
{
    char buff[11];
    std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
                 ( am ? 'a' : 'p' ));
    out << buff;
}

/*
 * Destructor
 */
~am_pm_clock();

inline std::ostream& operator << (std::ostream& out, const am_pm_clock& clock)
{
    clock.print(out);
    return out;
}
