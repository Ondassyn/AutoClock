//
//  am_pm_clock.cpp
//  0406-tt
//
//  Created by Tanbol Salyk on 6/5/19.
//  Copyright © 2019 tanbol salyk. All rights reserved.
//

#include "am_pm_clock.h"
#include <iostream>
#include <ostream>
#include <stdio.h>

am_pm_clock::am_pm_clock(){
    hours=12;
    minutes=0;
    seconds=0;
    am=true;
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
                         unsigned int secs, bool am_val){
    hours=hrs;
    minutes=mins;
    seconds=secs;
    am=am_val;
}
    
am_pm_clock::am_pm_clock(const am_pm_clock &clock){
    hours = clock.get_hours();
    minutes=clock.get_minutes();
    seconds=clock.get_seconds();
    am=clock.is_am();
}

am_pm_clock&am_pm_clock:: operator=(const am_pm_clock& clock){
    hours = clock.get_hours();
    minutes=clock.get_minutes();
    seconds=clock.get_seconds();
    am=clock.is_am();
    return *this;
}

void am_pm_clock::toggle_am_pm(){
    if(am){
        am=0;
    }else{
        am=1;
    }
}

void  am_pm_clock::reset(){
    hours=12;
    minutes=0;
    seconds=0;
    am=true;
}


void am_pm_clock::advance_one_sec(){
    if (seconds>=59) {
        seconds=0;
        if(minutes>=59){
            minutes=0;
            if(hours==11){
                hours++;
                toggle_am_pm();
            }else if(hours>=12){
                hours=1;
            }else{
                hours++;
            }
        }else{
            minutes++;
        }
    }else{
        seconds++;
    }

}

void am_pm_clock::advance_n_secs(unsigned int n){
    unsigned int s=0;
    while(s<n){
        advance_one_sec();
        s++;
    };
}

unsigned int am_pm_clock::get_hours() const{
    return hours;
}

void am_pm_clock::set_hours(unsigned int hrs){
    if(hrs>12){
        throw std::invalid_argument("ERROR");
    }else if(hrs<1){
        throw std::invalid_argument("ERROR");
    }
    hours=hrs;
}
bool am_pm_clock::is_am() const{
    return am;
    
}

void am_pm_clock::set_am(bool am_val){
        am=am_val;
}

unsigned int am_pm_clock::get_minutes() const{
    return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins){
    if(mins>59){
        throw std::invalid_argument("ERROR");
    }
    minutes=mins;
}

unsigned int am_pm_clock::get_seconds() const{
    return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs){
    if(secs>59){
        throw std::invalid_argument("ERROR");
    }
    seconds=secs;
}

am_pm_clock::~am_pm_clock(){
}


