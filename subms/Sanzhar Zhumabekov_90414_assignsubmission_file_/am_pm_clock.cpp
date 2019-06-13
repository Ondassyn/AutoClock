#include "am_pm_clock.h"
#include <iostream> 

am_pm_clock::am_pm_clock() :
		hours(12),
		minutes(00),
		seconds(00),
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

	
am_pm_clock::am_pm_clock(const am_pm_clock& clock)
	:hours{ clock.hours },
		minutes{ clock.minutes },
		seconds{ clock.seconds },
		am{ clock.am }
	{}


	am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock)
	{
		hours = clock.hours;
		minutes = clock.minutes;
		seconds = clock.seconds;
		am = clock.am;
		return *this;
	}

	void am_pm_clock::toggle_am_pm() {
		if (am == true) {
			am = false;
		}
		else {
			am = true;
		}
	}

	void am_pm_clock::reset() {
		hours = 12;
		minutes = 0;
		seconds = 0;
		am = true;
	}

	
	void am_pm_clock::advance_one_sec() {
		minutes += (++seconds) / 60;
		hours += minutes / 60;
		seconds %= 60;
		minutes %= 60;
		if (hours == 12)
			am ^= 1;
		else if (hours > 12)
			hours = 1;
	}

	
	void am_pm_clock::advance_n_secs(unsigned int n) {
		int h = n / 3600, m = (n % 3600) / 60, s = (n % 3600) % 60;
		if (seconds + s >= 60) {
			seconds += (s - 60);
			minutes++;
		}
		else {
			seconds += s;
		}
		if (minutes + m >= 60) {
			minutes += (m - 60);
			hours++;
		}
		else {
			minutes += m;
		}
		if (hours + h > 12) {
			hours += (h - 12);
		}
		else {
			hours += h;
		}

		if ((h / 12) % 2 == 1)
			am ^= 1;


	}

	unsigned int am_pm_clock::get_hours() const {
		return hours;
	}

	
	void am_pm_clock::set_hours(unsigned int hrs) {
		if (hrs > 12 || hrs < 0) {
			throw std::invalid_argument("Invalid hours value");
		}
		else {
			hours = hrs;
		}
	}


	unsigned int am_pm_clock::get_minutes() const {
		return minutes;
	}

	
	void am_pm_clock::set_minutes(unsigned int mins) {
		if (mins > 59 || mins < 0) {
			throw std::invalid_argument("Invalid minutes value");
		}
		else {
			minutes = mins;
		}
	}


	unsigned int am_pm_clock::get_seconds() const {
		return seconds;
	}

	void am_pm_clock::set_seconds(unsigned int secs) {
		if (secs > 59 || secs < 0) {
			throw std::invalid_argument("Invalid seconds value");
		}
		else {
			seconds = secs;
		}
	}

	bool am_pm_clock::is_am() const {
		return am;
	}

	void am_pm_clock::set_am(bool am_val) {
		am = am_val;
	}
	am_pm_clock::~am_pm_clock() {}