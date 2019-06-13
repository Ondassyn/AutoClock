#include "am_pm_clock.h"
am_pm_clock::am_pm_clock() {
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = true;
}
am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
	unsigned int secs, bool am_val) {
	hours = hrs;
	minutes = mins;
	seconds = secs;
	am = am_val;
}
am_pm_clock::am_pm_clock(const am_pm_clock &clock) {
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
}
am_pm_clock &am_pm_clock ::operator=(const am_pm_clock& clock) {
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
	return *this;
}
am_pm_clock::~am_pm_clock() {
	am = false;
	hours = 0;
	minutes = 0;
	seconds = 0;
}
/*
	 * Toggles the am/pm value for the clock
	 */
void am_pm_clock::toggle_am_pm() {
	am = !am;
}

/*
 * Resets the time to midnight
 */
void am_pm_clock::reset() {
	hours = 12;
	minutes = 0;
	seconds = 0;
	am = true;
}

/*
 * Advances the time of the clock by one second
 */
void am_pm_clock::advance_one_sec() {
	seconds++;
	minutes += seconds / 60;
	seconds %= 60;
	hours += minutes / 60;
	minutes %= 60;
	if (hours > 13) {
		toggle_am_pm();
		hours %= 12;
	}
}

/*
 * Advances the time of the clock by n seconds
 */
void am_pm_clock::advance_n_secs(unsigned int n) {
	seconds += n;
	minutes += seconds / 60;
	seconds %= 60;
	hours += minutes / 60;
	minutes %= 60;
	if (hours > 13) {
		am = !am;
		hours %= 12;
	}
}

/*
 * Getter for hours field
 */
unsigned int am_pm_clock::get_hours() const {
	return hours;
}

/*
 * Setter for hours field; throws an invalid_argument exception
 * if hrs is not a legal hours value
 */
void am_pm_clock::set_hours(unsigned int hrs) {
	if (hrs > 12 || hrs < 0) throw std::invalid_argument("Invalid syntax.");
	hours = hrs;
}

/*
 * Getter for minutes field
 */
unsigned int am_pm_clock::get_minutes() const {
	return minutes;
}

/*
 * Setter for minutes field; throws an invalid_argument exception
 * if mins is not a legal minutes value
 */
void am_pm_clock::set_minutes(unsigned int mins) {
	if (mins < 0 || mins > 59) throw std::invalid_argument("Invalid syntax.");
	minutes = mins;
}

/*
 * Getter for seconds field
 */
unsigned int am_pm_clock::get_seconds() const {
	return seconds;
}

/*
 * Setter for seconds field; throws an invalid_argument exception
 * if secs is not a legal seconds value
 */
void am_pm_clock::set_seconds(unsigned int secs) {
	if (secs > 59 || secs < 0) throw std::invalid_argument("Invalid syntax.");
	seconds = secs;
}

/*
 * Getter for am field
 */
bool am_pm_clock::is_am() const {
	return am;
}

/*
 * Setter for am field
 */
void am_pm_clock::set_am(bool am_val) {
	am = am_val;
}
