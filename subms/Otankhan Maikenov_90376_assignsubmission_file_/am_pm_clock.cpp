#include <iostream>
#include "am_pm_clock.h"

am_pm_clock::am_pm_clock() :
	hours(12), 
	minutes(0), 
	seconds(0), 
	am(1)
{
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val) :
	hours(hrs),
	minutes(mins),
	seconds(secs),
	am(am_val)
{
}

am_pm_clock::am_pm_clock(const am_pm_clock &clock) :
	hours(clock.hours),
	minutes(clock.minutes),
	seconds(clock.seconds),
	am(clock.am)
{
}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock)
{
	this->hours = clock.hours;
	this->minutes = clock.minutes;
	this->seconds = clock.seconds;
	this->am = clock.am;
	return *this;
}

void am_pm_clock::toggle_am_pm()
{
	if (am == 1)
		am = 0;
	else
		am = 1;
}

void am_pm_clock::reset()
{
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = 1;
}

void am_pm_clock::advance_one_sec()
{
	if (seconds == 59)
	{
		seconds = 0;
		if (minutes == 59)
		{
			minutes = 0;
			if (hours == 12)
				hours = 1;
			else
			{
				hours++;
				if (hours == 12)
					toggle_am_pm();
			}
		}
		else
			minutes++;
	}
	else
		seconds++;
}

void am_pm_clock::advance_n_secs(unsigned int n)
{
	for (size_t i = 1; i <= n; i++)
		advance_one_sec();
}

unsigned int am_pm_clock::get_hours() const
{
	return hours;
}

void am_pm_clock::set_hours(unsigned int hrs)
{
	if (hrs < 1 || hrs > 12)
		throw std::invalid_argument("Invalid argument for hours.\n");
	hours = hrs;
}

unsigned int am_pm_clock::get_minutes() const
{
	return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins)
{
	if (mins < 0 || mins > 59)
		throw std::invalid_argument("Invalid argument for minutes.\n");
	minutes = mins;
}

unsigned int am_pm_clock::get_seconds() const
{
	return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs)
{
	if (secs < 0 || secs > 59)
		throw std::invalid_argument("Invalid argument for seconds.\n");
	seconds = secs;
}

bool am_pm_clock::is_am() const
{
	return am;
}

void am_pm_clock::set_am(bool am_val)
{
 	am = am_val;
}

am_pm_clock::~am_pm_clock()
{
}