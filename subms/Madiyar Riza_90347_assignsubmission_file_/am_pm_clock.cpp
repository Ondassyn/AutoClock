#include <iostream>
#include <ostream>
#include "am_pm_clock.h"

am_pm_clock::am_pm_clock(){
    hours = 12;
    minutes = 0;
    seconds = 0;
    am = true;
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,unsigned int secs, bool am_val){
    set_hours(hrs);
    set_minutes(mins);
    set_seconds(secs);
    set_am(am_val);
}

am_pm_clock::am_pm_clock(const am_pm_clock &clock){
    hours = clock.get_hours();
    minutes = clock.get_minutes();
    seconds = clock.get_seconds();
    am = clock.is_am();
}

am_pm_clock& am_pm_clock::operator =(const am_pm_clock& clock){
    hours = clock.get_hours();
    minutes = clock.get_minutes();
    seconds = clock.get_seconds();
    am = clock.is_am();
    return *this;
}
void am_pm_clock::toggle_am_pm(){
    if(am == true){
        am = false;
    }
    else{
        am = true;
    }
    
    
}
void am_pm_clock::reset(){
    hours = 12;
    minutes = 0;
    seconds = 0;
    am = true;
    
}
void am_pm_clock::advance_one_sec(){
    seconds++;
    if(seconds == 60){
        seconds = 0;
        minutes++;
        if(minutes == 60){
            minutes = 0;
            hours++;
        }
        if(hours == 12){
            toggle_am_pm();
        }
        if(hours == 13){
            hours = 1;
        }
        
        
    }


    
}
void am_pm_clock::advance_n_secs(unsigned int n){
    unsigned int j=0;
    while(j<n){
        advance_one_sec();
        j++;
    }
    
}
unsigned int am_pm_clock::get_hours() const{
    return hours;
}
void am_pm_clock::set_hours(unsigned int hrs){
    if(hrs>0 && hrs<13){
        hours = hrs;
    }
    else{
        throw std::invalid_argument("It should be from 1 to 12");
    }
    
}

unsigned int am_pm_clock::get_minutes() const{
    return minutes;
}


void am_pm_clock::set_minutes(unsigned int mins){
    if(mins>=0 && mins<60){
        minutes = mins;
    }
    else{
        throw std::invalid_argument("It should be from 0 to 59");
    }
    
}

unsigned int am_pm_clock::get_seconds() const{
    return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs){
    if(secs>=0 && secs<60){
        seconds = secs;
    }
    else{
        throw std::invalid_argument("It should be from 0 to 59");
        
    }
    
}

bool am_pm_clock::is_am() const{
    return am;
    
}


void am_pm_clock::set_am(bool am_val){
    am=am_val;
}


am_pm_clock::~am_pm_clock(){
    hours = 0;
    minutes = 0;
    seconds = 0;
    
}

inline std::ostream&operator << (std::ostream& out, const am_pm_clock& clock);

