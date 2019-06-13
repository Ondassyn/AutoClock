//
//  am_pm_clock.cpp
//  S19Ass1
//
//  Created by Rollan on 6/7/19.
//  Copyright © 2019 Rollan. All rights reserved.
//

#include "am_pm_clock.h"
#include <stdexcept>

am_pm_clock::am_pm_clock(): //default constructor
    hours (12),
    minutes(00),
    seconds(00),
    am(true)

{
    
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
                         unsigned int secs, bool am_val): //constructor
    hours(hrs),
    minutes(mins),
    seconds(secs),
    am(am_val)

{
    
}

am_pm_clock::am_pm_clock(const am_pm_clock &clock): //Copy constructor
    hours(clock.hours),
    minutes(clock.minutes),
    seconds(clock.seconds),
    am(clock.am)

{
    
}

/*
 * Assignment operator
 */
am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
    this->hours = clock.hours;
    this->minutes = clock.minutes;
    this->seconds = clock.seconds;
    this->am = clock.am;
    return *this;
}

void am_pm_clock::toggle_am_pm()
{
    if (am)
        am = false;
    else
        am = true;
}

void am_pm_clock::reset() {
    seconds = 0;
    minutes = 0;
    hours = 12;
    am = true;
}

void am_pm_clock::advance_one_sec() {
    if (seconds != 59)
        seconds++;
    else {
        seconds = 0;
        if (minutes == 59) {
            minutes = 0;
            if (hours == 11) {
                toggle_am_pm();
                hours++;
            }
            if (hours == 12)
                hours = 1;
        }
    }
}

void am_pm_clock::advance_n_secs(unsigned int n){
    
    unsigned int save = seconds;
  
        for (unsigned int s = seconds; s < n; s++) {
            seconds++;
            if (s % 60 == 0) {
                minutes++;
                seconds = 0;
                if (minutes == 60) {
                    minutes = 0;
                    if (hours == 11) {
                        toggle_am_pm();
                        hours++;
                    }
                    if (hours == 12)
                        hours = 1;
                }
            }
        }
    seconds = save + seconds;
    
}

unsigned int am_pm_clock::get_hours() const
{
    return hours;
}

void am_pm_clock::set_hours(unsigned int hrs) {
    if (hrs > 12)
        throw std::invalid_argument("Hours cannot exceed 12");
    if (hrs < 1)
        throw std::invalid_argument("Hours cannot be 0");
    hours = hrs;
}

unsigned int am_pm_clock::get_minutes() const
{
    return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins) {
    if (mins > 59)
        throw std::invalid_argument("Minutes cannot exceed 59");
    minutes = mins;
}

unsigned int am_pm_clock::get_seconds() const
{
    return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs) {
    if (secs > 59)
        throw std::invalid_argument("Seconds cannot exceed 59");
    seconds = secs;
}

bool am_pm_clock::is_am() const
{
    return am;
}

void am_pm_clock::set_am(bool am_val){
    am_val = is_am();
}

am_pm_clock::~am_pm_clock() { };
