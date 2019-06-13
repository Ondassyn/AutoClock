#include <iostream>
#include "am_pm_clock.h"

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
    hours=clock.hours;
    minutes=clock.minutes;
    seconds=clock.seconds;
    am=clock.am;
}
am_pm_clock& am_pm_clock:: operator=(const am_pm_clock& clock){
    hours=clock.hours;
    minutes=clock.minutes;
    seconds=clock.seconds;
    am=clock.am;
    return *this;
}

void am_pm_clock::toggle_am_pm(){
    
}

void am_pm_clock::reset(){
    hours=12;
    minutes=0;
    seconds=0;
    am=true;
}

void am_pm_clock::advance_one_sec(){
    seconds=+1;
    if(seconds==60){
        seconds==0;
        minutes=+1;
    }
    if (minutes == 59 && seconds==60){
        seconds==0;
        minutes = 0;
        hours += 1;
}
    if(hours=12&&minutes == 59 && seconds==60){
        seconds==0;
        minutes = 0;
        hours =1;
        am=false;
    }
}
void am_pm_clock::advance_n_secs(unsigned int n){
    seconds=+n;
    }
};
unsigned int am_pm_clock::get_hours() const{
    return hours;
}
void am_pm_clock::set_hours(unsigned int hrs){
    hours=hrs;
}
unsigned int am_pm_clock::get_minutes() const{
    return minutes;
}
void am_pm_clock::set_minutes(unsigned int mins){
    minutes=mins;
}

unsigned int am_pm_clock::get_seconds() const{
    return seconds;
}
void am_pm_clock::set_seconds(unsigned int secs){
    seconds=secs;
}
bool am_pm_clock::is_am() const{
    return am;
}
void am_pm_clock::set_am(bool am_val){
    am = am_val;}

