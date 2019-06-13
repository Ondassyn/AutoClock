//
//  AM_PM_CLOCK.cpp
//  Akadil
//
//  Created by Akadil Kalimoldayev on 6/7/19.
//  Copyright © 2019 Akadil Kalimoldayev. All rights reserved.
//

#include <stdio.h>

#include "AM_PM_CLOCK.h"

/*
 * Toggles the am/pm value for the clock
 */
void am_pm_clock:: toggle_am_pm(){
    if(am==1){
        am=2;
    }else{
        am=1;
    }
}

/*
 * Resets the time to midnight
 */
void am_pm_clock:: reset(){
    hours=12;
    minutes=0;
    seconds=0;
    am=1;
}

/*
 * Advances the time of the clock by one second
 */
void am_pm_clock:: advance_one_sec(){
    seconds++;
}

/*
 * Advances the time of the clock by n seconds
 */
void am_pm_clock:: advance_n_secs(unsigned int n){
    seconds=seconds+n;
}

/*
 * Getter for hours field
 */
unsigned int am_pm_clock:: get_hours() const{
    return hours;
};

/*
 * Setter for hours field; throws an invalid_argument exception
 * if hrs is not a legal hours value
 */
void am_pm_clock:: set_hours(unsigned int hrs){
    if(hrs>12 && hrs<1){
        throw std::invalid_argument("this number is not a legal hours value");
    }else{
        hours=hrs;
    }
}


/*
 * Getter for minutes field
 */
unsigned int am_pm_clock:: get_minutes() const{
    return minutes;
};

/*
 * Setter for minutes field; throws an invalid_argument exception
 * if mins is not a legal minutes value
 */
void am_pm_clock:: set_minutes(unsigned int mins){
    if(mins>59 && mins<0){
        throw std::invalid_argument("this number is not a legal minutes value");
    }else{
        minutes=mins;
    }
}

/*
 * Getter for seconds field
 */
unsigned int am_pm_clock:: get_seconds() const{
    return seconds;
};

/*
 * Setter for seconds field; throws an invalid_argument exception
 * if secs is not a legal seconds value
 */
void am_pm_clock:: set_seconds(unsigned int secs){
    if(secs>59 && secs<0){
        throw std::invalid_argument("this number is not a legal seconds value");
    }else{
        seconds=secs;
    }
}

/*
 * Getter for am field
 */
bool am_pm_clock:: is_am() const{
    return am;
};

/*
 * Setter for am field
 */
void am_pm_clock:: set_am(bool am_val){
    if(am_val!=1 || am_val!=0){
        throw std::invalid_argument("this number is not legal am/pm value");
    }else{
        am=am_val;
    }
}

/*
 * Print function - helper for output operator
 */

