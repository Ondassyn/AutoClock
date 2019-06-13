#include <iostream>
#include <string>
#include "am_pm_clock.h"
using namespace std;
am_pm_clock::am_pm_clock(){ //default const
    set_hours(12);
    set_minutes(0);
    set_seconds(0);
    set_am(am);
}
am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
                         unsigned int secs, bool am_val)
{
     set_hours(hrs);
    set_minutes(mins);
    set_seconds(secs);
    set_am(am_val);


}

am_pm_clock::am_pm_clock(const am_pm_clock &clock){
    hours = clock.get_hours();
    minutes = clock.get_minutes();
    seconds = clock.get_seconds();
    am=clock.is_am();
}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock &clock) {
    hours = clock.get_hours();
    minutes=clock.get_minutes();
    seconds=clock.get_seconds();
    am=clock.is_am();
}
void am_pm_clock::toggle_am_pm() {
if(am==1){
    am=0;
}else
if(am==0){
    am=1;
}

}
void am_pm_clock::reset() {
    set_hours(12);
    set_minutes(0);
    set_seconds(0);
    set_am(am);
}
void am_pm_clock::advance_one_sec()
{
if(seconds == 59)
{
    if(minutes == 59)
    {
        if(hours==12)
        {
            hours = 1;

        }
        else
        {
            hours++;
        }

        minutes=0;
        seconds=0;
    }
    else
    {
        minutes++;
        seconds=0;
    }
}
else
{
    seconds++;
}

    if(seconds == 0)
    {
        if(minutes == 0)
        {
            if(hours==12)
            {
                toggle_am_pm();

            }

        }
    }
}

void am_pm_clock::advance_n_secs(unsigned int n) {

    // hours=n/3600;
    // minutes=n/60;
    // seconds=n+seconds;
    seconds = hours * 3600 + minutes * 60 + seconds + n-1;

    minutes = seconds / 60;
    seconds = seconds % 60;
    hours = minutes / 60;
    minutes = minutes % 60;

    if(hours/12%2!=0){
        toggle_am_pm();
    }

    if (hours >12) {
        hours = hours % 12;

    }

    if (seconds == 59) {
        if (minutes == 59) {
            if (hours==12) {
                hours = 1;

            } else {
                hours++;
            }

            minutes = 0;
            seconds = 0;
        } else {
            minutes++;
            seconds = 0;
        }
    } else {
        seconds++;
    }

    if(hours==0){
        hours=1;
    }

    if(seconds == 0)
    {
        if(minutes == 0)
        {
            if(hours==12)
            {
                toggle_am_pm();

            }

        }
    }

}

void am_pm_clock::set_hours(unsigned int hrs) {
    if(hrs>=1 && hrs<=12)
        hours=hrs;
    else
        throw invalid_argument("hour must be 0-12");
}
void am_pm_clock::set_minutes(unsigned int mins) {
    if(mins>=0 && mins<=59)
        minutes=mins;
    else
        throw invalid_argument("minutes must be 0-59");
}
void am_pm_clock::set_seconds(unsigned int secs) { //invariant
    if(secs>=0 && secs<=59)
        seconds=secs;
    else
        throw invalid_argument("seconds must be 0-59");
}

unsigned int am_pm_clock::get_minutes() const{
    return minutes;
}

unsigned int am_pm_clock::get_hours() const {
    return hours;
}
unsigned int am_pm_clock::get_seconds() const {
    return seconds;
}

bool am_pm_clock::is_am() const {
    return am;
}
void am_pm_clock::set_am(bool am_val) {
    am = am_val;
}
//postcond -
//precondition- adv one sec


am_pm_clock::~am_pm_clock() {

}