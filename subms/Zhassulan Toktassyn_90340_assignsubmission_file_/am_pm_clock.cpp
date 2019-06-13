#include "am_pm_clock.h"
using namespace std;

am_pm_clock::am_pm_clock(){
    hours = 12;
    minutes = 00;
    seconds = 00;
    am = true;
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,unsigned int secs, bool am_val){
    hours = hrs;
    minutes = mins;
    seconds = secs;
    am = am_val;
}
am_pm_clock:: am_pm_clock(const am_pm_clock &clock){
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock &clock) {
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
    return *this;
}

void am_pm_clock::toggle_am_pm() {
    if(am)
        am = false;
    else
        am = true;
}

void am_pm_clock::reset() {
    hours = 12;
    minutes = 00;
    seconds = 00;
    am = true;
}

void am_pm_clock::advance_one_sec() {
    advance_n_secs(1);

}

void am_pm_clock::advance_n_secs(unsigned int n) {
    int hrs = 0;
    hrs = n / 3600;
    n = n % 3600;
    int mns = 0;
    mns = n / 60;
    n = n % 60;
    hours = hours + hrs;
    minutes = minutes + mns;
    seconds = seconds + n;
    if(seconds > 59){
        minutes++;
        seconds = seconds - 60;
    }
    if(minutes > 59){
        hours++;
        minutes = minutes - 60;
    }
    if(hours > 12){
        toggle_am_pm();
        hours = hours-12;
    }
}

unsigned int am_pm_clock::get_hours() const {
    return hours;
}

void am_pm_clock::set_hours(unsigned int hrs) {
    if(hrs > 12 || hrs < 0){
        throw "invalid_argument exception";
    }
    hours = hrs;
}

unsigned int am_pm_clock::get_minutes() const {
    return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins) {
    if(mins<0 || mins > 59){
        throw "invalid_argument exception";
    }
    minutes = mins;
}

unsigned int am_pm_clock::get_seconds() const {
    return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs) {
    if(secs < 0 || secs > 59){
        throw "invalid_argument exception";
    }
    seconds = secs;
}

bool am_pm_clock::is_am() const {
    return am;
}

void am_pm_clock::set_am(bool am_val) {
    am = am_val;
}

am_pm_clock::~am_pm_clock()
{

}

