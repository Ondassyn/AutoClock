//
//  am_pm_clock.cpp
//  adil
//
//  Created by Adil Kenzhigaliyev on 6/7/19.
//  Copyright © 2019 Adil Kenzhigaliyev. All rights reserved.
//

//#include "am_pm_clock.hpp"

#ifndef AM_PM_CLOCK_H_
#define AM_PM_CLOCK_H_

#include <ostream>

class am_pm_clock {
    
    unsigned int hours, minutes, seconds;
    bool   am;
    
public:
    
    /*
     * Default constructor - initial time should be midnight
     */
    am_pm_clock() {
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
        this->am = true;
    }
    
    /*
     * Constructor - sets fields to the given argument values
     */
    am_pm_clock(unsigned int hrs, unsigned int mins,
                unsigned int secs, bool am_val) {
        this->hours = hrs;
        this->minutes = mins;
        this->seconds = secs;
        this->am = am_val;
    }
    
    /*
     * Copy constructor
     */
    am_pm_clock(const am_pm_clock &clock) {
        this->hours = clock.hours;
        this->minutes = clock.minutes;
        this->seconds = clock.seconds;
        this->am = clock.am;
    }
    
    /*
     * Assignment operator
     */
    am_pm_clock& operator=(const am_pm_clock& clock) {
        am_pm_clock *th = new am_pm_clock();
        th->hours = clock.hours;
        th->minutes = clock.minutes;
        th->seconds = clock.seconds;
        th->am = clock.am;
        return *th;
    }
    
    /*
     * Toggles the am/pm value for the clock
     */
    void toggle_am_pm() {
        this->am = !(this->am);
    }
    
    /*
     * Resets the time to midnight
     */
    void reset() {
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
        this->am = true;
    }
    
    /*
     * Advances the time of the clock by one second
     */
    void advance_one_sec() {
        if (seconds < 59) {
            seconds++;
        } else if (minutes < 59) {
            minutes++;
            seconds = 0;
        } else if (hours < 11) {
            hours++;
            minutes = 0;
            seconds = 0;
        } else {
            hours = 0;
            minutes = 0;
            seconds = 0;
            am = !am;
        }
    }
    
    /*
     * Advances the time of the clock by n seconds
     */
    void advance_n_secs(unsigned int n) {
        unsigned int n_secs = n%60;
        unsigned int n_hours = ((n - n_secs)/3600);
        unsigned int n_mins = (n - n_secs - n_hours*3600)/60;
        
        if (seconds + n_secs < 60) {
            seconds = seconds + n;
        } else {
            seconds = seconds + n_secs - 60;
            n_mins++;
        }
        
        if (n_mins > 59) {
            n_hours++;
            n_mins = n_mins%60;
        }
        
        if (n_hours > 11) {
            n_hours = n_hours%12;
            am = !am;
        }
        
        if (minutes + n_mins < 60) {
            minutes = minutes + n_mins;
        } else {
            minutes = minutes + n_mins - 60;
            n_hours++;
        }
        
        if (n_hours > 11) {
            n_hours = n_hours%12;
            am = !am;
        }
        
        if (hours + n_hours < 12) {
            hours = hours + n_hours;
        } else {
            hours = hours + n_hours - 12;
            am = !am;
        }
    }
    
    /*
     * Getter for hours field
     */
    unsigned int get_hours() const {
        return hours;
    }
    
    /*
     * Setter for hours field; throws an invalid_argument exception
     * if hrs is not a legal hours value
     */
    void set_hours(unsigned int hrs) {
        hours = hrs;
    }
    
    /*
     * Getter for minutes field
     */
    unsigned int get_minutes() const {
        return minutes;
    }
    
    /*
     * Setter for minutes field; throws an invalid_argument exception
     * if mins is not a legal minutes value
     */
    void set_minutes(unsigned int mins) {
        minutes = mins;
    }
    
    /*
     * Getter for seconds field
     */
    unsigned int get_seconds() const {
        return seconds;
    }
    
    /*
     * Setter for seconds field; throws an invalid_argument exception
     * if secs is not a legal seconds value
     */
    void set_seconds(unsigned int secs) {
        seconds = seconds;
    }
    
    /*
     * Getter for am field
     */
    bool is_am() const {
        return am;
    }
    
    /*
     * Setter for am field
     */
    void set_am(bool am_val) {
        am = am_val;
    }
    
    /*
     * Print function - helper for output operator
     */
    void print(std::ostream& out) const {
        char buff[11];
        std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
                     ( am ? 'a' : 'p' ));
        out << buff;
    }
    
    /*
     * Destructor
     */
    ~am_pm_clock() {
        delete this;
    }
};

inline std::ostream& operator << (std::ostream& out, const am_pm_clock& clock) {
    clock.print(out);
    return out;
}

#endif /* AM_PM_CLOCK_H_ */
