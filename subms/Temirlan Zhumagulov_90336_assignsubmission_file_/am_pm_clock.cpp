#include <iostream>
#include "am_pm_clock.h"
using namespace std;

void am_pm_clock::reset() {
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = true;
}

void am_pm_clock::advance_one_sec() {
	seconds += 1;
	if (seconds > 59) {
		seconds = 0;
		minutes += 1;
	}
	if (minutes > 59) {
		minutes = 0;
		hours += 1;
	}
	if (hours > 23) {
		hours = 0;
	}
	if (hours > 11) {
		am = !am;
		hours -= 12;
	}
	if (hours == 0) {
		hours = 12;
	}
}

void am_pm_clock::advance_n_secs(unsigned int n) {
	unsigned h = n / 3600;
	n -= (h * 3600);
	unsigned m = n / 60;
	n -= (m * 60);
	hours += h;
	minutes += m;
	seconds += n;
	if (hours > 23) {
		unsigned a = hours / 24;
		hours -= (a * 24);
	}
	if (minutes > 59) {
		minutes -= 60;
	}
	if (seconds > 59) {
		seconds -= 60;
	}
	if (hours > 11) {
		am = false;
		hours -= 12;
	}
	else am = true;

	if (hours == 0) {
		hours = 12;
	}
}

unsigned int am_pm_clock::get_hours() const {
	return hours;
}

void am_pm_clock::set_hours(unsigned int hrs) {
	hours = hrs;
}

unsigned int am_pm_clock::get_minutes() const {
	return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins) {
	minutes = mins;
}

unsigned int am_pm_clock::get_seconds() const {
	return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs) {
	seconds = secs;
}

bool am_pm_clock::is_am() const {
	return am;
}

void am_pm_clock::set_am(bool am_val) {
	am = am_val;
}

