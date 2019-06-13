//
//  am_pm_clock.cpp
//  Summer_Assignment_1
//
//  Created by карим on 6/5/19.
//  Copyright © 2019 карим. All rights reserved.
//


#include "am_pm_clock.h"
#include <iostream>

am_pm_clock::am_pm_clock() :
                hours(12),
                minutes(0),
                seconds(0),
                am(true)
{}


am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
                         unsigned int secs, bool am_val):
                hours(hrs),
                minutes(mins),
                seconds(secs),
                am(am_val)
{}


am_pm_clock::am_pm_clock(const am_pm_clock &clock):
                hours(clock.hours),
                minutes(clock.minutes),
                seconds(clock.seconds),
                am(clock.am)
{}


am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
    this->hours = clock.hours;
    this->minutes = clock.minutes;
    this->seconds = clock.seconds;
    this->am = clock.am;
    return *this;
}


void am_pm_clock::toggle_am_pm(){
    if(am == true) am = false;
    else am = true;
}


void am_pm_clock::reset(){
    hours = 12;
    minutes = 0;
    seconds = 0;
    am = true;
}


void am_pm_clock::advance_one_sec(){ //It could be done with loop, but I decided that in that way the code wil be faster
    seconds++;
    if(seconds == 60){
        seconds = 0;
        minutes++;
    }
    if(minutes == 60){
        minutes = 0;
        hours++;
    }
    if(hours == 12) toggle_am_pm();
    if(hours == 13) hours = 1;
}


void am_pm_clock::advance_n_secs(unsigned int n){ //I could use the function above, but I wanted not to use loops
    seconds+=n;
    if(seconds >= 60){
        minutes+=seconds/60;
        seconds = seconds%60;
    }
    if(minutes >= 60){
        hours+=minutes/60;
        minutes = minutes%60;
    }
    if(hours >= 12){
        if((hours/12) % 2 == 1) toggle_am_pm();
        hours = hours % 12;
        if(hours == 0) hours = 12;
    }
}


unsigned int am_pm_clock::get_hours() const{
    return hours;
}


void am_pm_clock::set_hours(unsigned int hrs){
    if(hrs > 0 && hrs < 13)
    hours = hrs;
    
    else throw std::invalid_argument("Hours only can be greater than 0 and less than 13!!!/n");
       
    
}


unsigned int am_pm_clock::get_minutes() const{
    return minutes;
}


void am_pm_clock::set_minutes(unsigned int mins){
    if(mins > 0 && mins < 60)
    minutes = mins;
    else throw std::invalid_argument("Minutes only can be greater than 0 and less than 60!!!/n");

}

unsigned int am_pm_clock::get_seconds() const{
    return seconds;
}


void am_pm_clock::set_seconds(unsigned int secs){
    if(secs > 0 && secs < 60)
    seconds = secs;
    else throw std::invalid_argument("Seconds only can be greater than 0 and less than 60!!!/n");
    
}


bool am_pm_clock::is_am() const{
    return am;
}


void am_pm_clock::set_am(bool am_val){
    if(am_val != true || am_val != false) throw std::invalid_argument("Boolean only can be false or true!!!/n");
    
    am = am_val;
}

am_pm_clock::~am_pm_clock(){
    
}
