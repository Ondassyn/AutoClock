#include "am_pm_clock.h"
#include <stdexcept>
#include <iostream>

using namespace std;
/*
	 * Default constructor - initial time should be midnight
	 */	
	am_pm_clock::am_pm_clock()
	{
		hours = 12;
		minutes = 0;
		seconds = 0;
		am = 1;
	}
	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
		unsigned int secs, bool am_val)
	{
		if((hrs > 12) || (hrs < 1))
			throw std::invalid_argument("Not valid values for time\n");
		if((mins > 59) || (mins < 0))
			throw std::invalid_argument("Not valid values for time\n");
		if((secs > 59) || (secs < 0))
			throw std::invalid_argument("Not valid values for time\n");
		hours = hrs;
		minutes = mins;
		seconds = secs;
		am = am_val;
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
		hours = clock.hours;
		minutes = clock.minutes;
		seconds = clock.seconds;
		am = clock.am;
		return *this;
	}
	/*
	 * Toggles the am/pm value for the clock
	 */
	void am_pm_clock::toggle_am_pm()
	{
		if(am == 0)
			am = 1;
		else
			am = 0;
	}

	/*
	 * Resets the time to midnight
	 */
	void am_pm_clock::reset()
	{
		hours = 12;
		minutes = 0;
		seconds = 0;
		am = 1;
	}
	/*
	 * Advances the time of the clock by one second
	 */
	void am_pm_clock::advance_one_sec()
	{
		if(seconds == 59)
		{
			seconds = 0;
			if(minutes == 59)
			{
				minutes = 0;
				if(hours == 12)
				{
					hours = 1;
				}
				else if(hours == 11)
				{
					toggle_am_pm();
					hours++;
				}
				else hours++;
			}
			else minutes++;
		}
			else
			seconds++;
	}
	/*
	 * Advances the time of the clock by n seconds
	 */
	void am_pm_clock::advance_n_secs(unsigned int n)
	{
		for(int i = 0; i<n; i++)
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
	 * Setter for hours field; throws an invalid_argument exception
	 * if hrs is not a legal hours value
	 */
	void am_pm_clock::set_hours(unsigned int hrs)
	{
		if(hrs > 12 || hrs < 1)
			throw std::invalid_argument("Not valid values for hours\n");
		else
			hours = hrs;
	}

	/*
	 * Getter for minutes field
	 */
	unsigned int am_pm_clock::get_minutes() const
	{
		return minutes;
	}

	/*
	 * Setter for minutes field; throws an invalid_argument exception
	 * if mins is not a legal minutes value
	 */
	void am_pm_clock::set_minutes(unsigned int mins)
	{
		if(mins > 59 || mins < 1)
			throw std::invalid_argument("Not valid values for minutes\n");
		else
			minutes = mins;
	}

	/*
	 * Getter for seconds field
	 */
	unsigned int am_pm_clock::get_seconds() const
	{
		return seconds;
	}
	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
	void am_pm_clock::set_seconds(unsigned int secs)
	{
		if(secs > 59 || secs < 1)
			throw std::invalid_argument("Not valid values for seconds\n");
		else
			seconds = secs;	
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
	 * Print function - helper for output operator
	 */

	/*
	 * Destructor
	 */
	am_pm_clock::~am_pm_clock() {}
