#include "am_pm_clock.h"
#include <stdexcept>
#include <iostream>

using namespace std;

am_pm_clock::am_pm_clock(){
        hours=12;
        minutes=0;
        seconds=0;
        am=1;
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val){
        hours=hrs;
        minutes=mins;
        seconds=secs;
        am=am_val;
}

am_pm_clock::~am_pm_clock(){}

am_pm_clock::am_pm_clock(const am_pm_clock& clock){
        hours = clock.hours;
        minutes = clock.minutes;
        seconds = clock.seconds;
        am = clock.am;
}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
        this->hours = clock.hours;
        this->minutes = clock.minutes;
        this->seconds = clock.seconds;
        this->am = clock.am;
        return *this;
}

void am_pm_clock::toggle_am_pm(){
 if (am == 1){
                am = 0;
        } else {
                am = 1;
        }
}

void am_pm_clock::reset(){
        am=1;
        hours=12;
        minutes=0;
        seconds=0;
}

void am_pm_clock::advance_one_sec(){
        if (seconds<59){
                seconds++;
        } else {
                if(minutes<59){
                        seconds=0;
                        minutes++;
                } else {
                        if (hours<11){
                                seconds=0;
                                minutes=0;
                                hours++;
                        } else if(hours==12) {
                                hours=1;
                                minutes=0;
                                seconds=0;
                        } else if(hours==11){
                                hours++;
                                minutes=0;
                                seconds=0;
                                toggle_am_pm();
                        }
                }
}
}

void am_pm_clock::advance_n_secs(unsigned int n){
        size_t i=0;
        for(i=1;i<=n;i++){
                advance_one_sec();
        };
}

void am_pm_clock::set_hours(unsigned int hrs){
        if (hrs<=12 && hrs>=1){
                hours=hrs;
        } else {
                throw std::invalid_argument ("recieved a number out of range");
        }
}

void am_pm_clock::set_minutes(unsigned int mins){
        if (mins<=59 && mins>=1){
                minutes=mins;
        } else {
                throw std::invalid_argument ("recieved a number out of range");
        }
}

void am_pm_clock::set_seconds(unsigned int secs){
        if (secs<=59 && secs>=1){
                seconds = secs;
        } else {
                throw std::invalid_argument ("recieved a number out of range");
        }
}

unsigned int am_pm_clock::get_hours() const{
        return hours;
}

unsigned int am_pm_clock::get_minutes() const{
        return minutes;
}

unsigned int am_pm_clock::get_seconds() const{
        return seconds;
}

bool am_pm_clock::is_am() const{
        return am;
}

void am_pm_clock::set_am(bool am_val){
        am = am_val;
}
