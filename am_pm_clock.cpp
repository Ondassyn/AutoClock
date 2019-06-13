#include "am_pm_clock.h"

am_pm_clock::am_pm_clock() :
		hours(12), minutes(0), seconds(0), am(true) {

}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs,
		bool am_val) :
		hours(hrs), minutes(mins), seconds(secs), am(am_val) {

	if (hrs > 12 || hrs == 0)
		throw std::invalid_argument("hrs must be between 1 and 12");
	if (mins > 59)
		throw std::invalid_argument("mins must be < 60");
	if (secs > 59)
		throw std::invalid_argument("secs must be < 60");
}

am_pm_clock::am_pm_clock(const am_pm_clock &clock) :
		hours(clock.hours), minutes(clock.minutes), seconds(clock.seconds), am(
				clock.am) {

}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock) {
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
	return *this;
}

void am_pm_clock::toggle_am_pm() {
	am = !am;
}

void am_pm_clock::reset() {
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = true;
}

void am_pm_clock::advance_one_sec() {
	if (seconds < 59) {
		seconds++;
		return;
	}
	seconds = 0;

	if (minutes < 59) {
		minutes++;
		return;
	}
	minutes = 0;

	if (hours < 11) {
		hours++;
		return;
	}

	if (hours == 11) {
		hours = 12;
		am = !am;
		return;
	}

	hours = 1;
}

void am_pm_clock::advance_n_secs(unsigned int n) {

	for (unsigned int i = 0; i < n; ++i) {
		advance_one_sec();
	}
}

unsigned int am_pm_clock::get_hours() const {
	return hours;
}

void am_pm_clock::set_hours(unsigned int hrs) {
	if (hrs > 12 || hrs == 0)
		throw std::invalid_argument("hrs must be between 1 and 12");
	hours = hrs;
}

unsigned int am_pm_clock::get_minutes() const {
	return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins) {
	if (mins > 59)
		throw std::invalid_argument("mins must be < 60");
	minutes = mins;
}

unsigned int am_pm_clock::get_seconds() const {
	return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs) {
	if (secs > 59)
		throw std::invalid_argument("secs must be < 60");
	seconds = secs;
}

bool am_pm_clock::is_am() const {
	return am;
}

void am_pm_clock::set_am(bool am_val) {
	am = am_val;
}

am_pm_clock::~am_pm_clock() {

}

