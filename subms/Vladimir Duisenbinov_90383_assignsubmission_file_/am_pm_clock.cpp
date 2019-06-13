#include "am_pm_clock.h"
#include <iostream>

/*
    * Default constructor - initial time should be midnight
    */
am_pm_clock::am_pm_clock() {
    this->reset();
}

/*
    * Constructor - sets fields to the given argument values
    */
am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
            unsigned int secs, bool am_val) {
    if (hrs < 1 || hrs > 12 || mins < 0 || mins > 59 || secs < 0 || secs > 59){
        throw std::invalid_argument("invalid argument values");
    }
    
    hours = hrs;
    minutes = mins;
    seconds = secs;
    am = am_val;
}

/*
    * Copy constructor
    */
am_pm_clock::am_pm_clock(const am_pm_clock &clock) {
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
}

/*
    * Assignment operator
    */
am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock) {
    if (this != &clock) {
        hours = clock.hours;
        minutes = clock.minutes;
        seconds = clock.seconds;
        am = clock.am;
    }
    return *this;
}

/*
 destructor
*/
am_pm_clock::~am_pm_clock() {
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
    advance_n_secs(1);
}

void am_pm_clock::advance_n_secs(unsigned int n) {
    unsigned int s = seconds + minutes * 60 + hours * 3600 + n;
    if (am && hours == 12) s -= 12 * 3600;
    else if (!am && hours != 12) s += 12 * 3600;
    // std::cout << s << "\n";
    seconds = (s % 3600) % 60;
    minutes = (s % 3600) / 60;
    hours = (s / 3600) % 24;
    // std::cout << hours << "\n";
    am = false;

    if (hours > 12) {
        hours -= 12;
    }
    else if (hours != 12) {
        am = true;
        if (hours == 0) hours = 12;
    }
}

unsigned int am_pm_clock::get_hours() const {
    return hours;
}

void am_pm_clock::set_hours(unsigned int hrs) {
    if (hrs > 12 || hrs < 1)
        throw std::invalid_argument("invalid hrs");
    hours = hrs;
}

unsigned int am_pm_clock::get_minutes() const {
    return minutes;
}


void am_pm_clock::set_minutes(unsigned int mins) {
    if (mins > 59 || mins < 0)
        throw std::invalid_argument("invalid mins");
    minutes = mins;
}


unsigned int am_pm_clock::get_seconds() const {
    return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs) {
    if (secs > 59 || secs < 0)
        throw std::invalid_argument("invalid secs");
    seconds = secs;
}

bool am_pm_clock::is_am() const {
    return am;
}

void am_pm_clock::set_am(bool am_val) {
    am = am_val;
}