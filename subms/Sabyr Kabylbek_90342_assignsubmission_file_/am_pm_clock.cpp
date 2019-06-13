#include "am_pm_clock.h"
#include<stdexcept>

am_pm_clock::am_pm_clock() :
	hours(12),
	minutes(0),
	seconds(0),
	am(true)
{

}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
	unsigned int secs, bool am_val) :
	hours(hrs),
	minutes(mins),
	seconds(secs),
	am(am_val)

{

}

am_pm_clock::am_pm_clock(const am_pm_clock& clock) :
	hours(clock.hours),
	minutes(clock.minutes),
	seconds(clock.seconds),
	am(clock.am)
{

}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock)
{
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
	return *this;

}

void am_pm_clock::toggle_am_pm()
{
	if (am) am = false;
	else am = true;
}

void am_pm_clock::reset()
{
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = true;
}

void am_pm_clock::advance_one_sec()
{
	++seconds;
	if (seconds == 60)
	{
		seconds = 0;
		++minutes;
		if (minutes == 60)
		{
			minutes = 0;
			++hours;
			if (hours == 12)
			{
				toggle_am_pm();
				if (hours == 13) hours = 1;
			}

		}
	}
}


void am_pm_clock::advance_n_secs(unsigned int n)
{
	seconds = seconds + n;
	do {
		if (seconds >= 60)
		{
			seconds = seconds - 60;
			++minutes;
			if (minutes == 60)
			{
				minutes = 0;
				++hours;
				if (hours >= 12)
				{
					toggle_am_pm();
					if (hours == 13) hours = 1;
				}

			}
		}
		n = n - 60;
	} while (n >= 60);
}

unsigned int am_pm_clock::get_hours() const
{
	return hours;
}

void am_pm_clock::set_hours(unsigned int hrs)
{
	if (hrs == 0 || hrs > 12)
		throw std::invalid_argument("You cannot set a number greater than 12");
	else hours = hrs;

}

unsigned int am_pm_clock::get_minutes() const
{
	return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins)
{
	if (mins > 59)
		throw std::invalid_argument("You cannot set a number greater than 59");
	else
	{
		minutes = mins;
	}
}

unsigned int am_pm_clock::get_seconds() const
{
	return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs)
{
	if (secs > 59)
		throw std::invalid_argument("You cannot set a number greater than 59");
	else
	{
		seconds = secs;
	}
}

bool am_pm_clock::is_am() const
{
	if (am) return true;
	else return false;
}

void am_pm_clock::set_am(bool am_val)
{
	am = am_val;
}

am_pm_clock::~am_pm_clock() {}


