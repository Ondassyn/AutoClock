//
//  am_pm_class.cpp
//  HelloWorld
//
//  Created by Kamila Kameshova on 05.06.2019.
//  Copyright © 2019 Kamila Kameshova. All rights reserved.
//

#include <iostream>
#include <ostream>
#include "am_pm_clock.h"

am_pm_clock::am_pm_clock():hours{12},minutes{00},seconds{00},am{true}
{}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
            unsigned int secs, bool am_val)
{
    if(hrs<1 || hrs>12 || mins<0 || mins>60 || secs<0 || secs>60)
        throw std::invalid_argument("invalid argument");
    else{
    hours=hrs;
    minutes=mins;
    seconds=secs;
    am=am_val;
    }
}
am_pm_clock::am_pm_clock(const am_pm_clock &clock)
{
    hours=clock.hours;
    minutes=clock.minutes;
    seconds=clock.seconds;
    am=clock.am;
}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
    hours=clock.hours;
    minutes=clock.minutes;
    seconds=clock.seconds;
    am=clock.am;
    return *this;
}

void am_pm_clock::toggle_am_pm(){
    if (am==true) {
        am=false;
    } else {
        am=true;
    }
    
}

void am_pm_clock::reset(){
    hours=12;
    minutes=0;
    seconds=0;
    am=true;
}

void am_pm_clock::advance_one_sec()
{
    seconds++;
    if (seconds>=60) {
        minutes++;
        seconds=0;
        
        if (minutes>=60) {
            hours++;
            minutes=0;
            
            if(hours==12){
                toggle_am_pm();
            }
            
            if(hours>12){
                hours=1;
            }
        }
    }
}

void am_pm_clock::advance_n_secs(unsigned int n){
    int i=0;
    while(i!=n){
        advance_one_sec();
        i++;
    }    
}

unsigned int am_pm_clock::get_hours() const{
    return hours;
}
void am_pm_clock::set_hours(unsigned int hrs){
    if(hrs>=1 && hrs<=12){
        hours=hrs;
    }
    else{
        throw std::invalid_argument("invalid argument of hours");
    }
}

unsigned int am_pm_clock::get_minutes() const{
    return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins){
    if(mins>=0 && mins<60){
        minutes=mins;
    }
    else{
        throw std::invalid_argument("invalid argument of minutes");
    }
}

unsigned int am_pm_clock::get_seconds() const{
    return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs){
    if(secs>=0 && secs<60){
        seconds=secs;
    }
    else{
        throw std::invalid_argument("invalid argument of seconds");
    }
}
bool am_pm_clock::is_am() const{
    return am;
}
void am_pm_clock::set_am(bool am_val){
    am=am_val;
}

am_pm_clock::~am_pm_clock()
{}
