#include "am_pm_clock.h"

am_pm_clock::am_pm_clock()
{
    hours = 12;
    minutes = 0;
    seconds = 0;
    am = true;
}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val)
{
    hours = hrs;
    minutes = mins;
    seconds = secs;
    am = am_val;
}

am_pm_clock::am_pm_clock(const am_pm_clock &clock)
{
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
}

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock)
{
    hours = clock.hours;
    minutes = clock.minutes;
    seconds = clock.seconds;
    am = clock.am;
}

void am_pm_clock::toggle_am_pm()
{
    if(am == true){
        am = false;
    }
    else
        am = true;
}

void am_pm_clock::reset()
{
    hours = 12;
    minutes = 0;
    seconds = 0;
    am = true;
}

void am_pm_clock::advance_one_sec()
{
    seconds++;
    if(seconds == 60){
        seconds = 0;
        minutes++;
        if(minutes == 60){
            minutes = 0;
            hours++;
            if(hours == 12){
                minutes = seconds = 0;
                toggle_am_pm();
            }
            if(hours == 13){
                hours = 1;
                minutes = seconds = 0;
            }
        }
    }
}

void am_pm_clock::advance_n_secs(unsigned int n)
{
    size_t i;
    for(i = 1; i <= n; i++){
        advance_one_sec();
    }
}

unsigned int am_pm_clock::get_hours() const
{
    return hours;
}

void am_pm_clock::set_hours(unsigned int hrs)
{
    if(hrs <= 12 && hrs >= 1){
        hours = hrs;
    }
    else
    {
        throw
            std::invalid_argument("error");
    }
}

unsigned int am_pm_clock::get_minutes() const
{
    return minutes;
}

void am_pm_clock::set_minutes(unsigned int mins)
{
    if(mins < 60){
        minutes = mins;
    }
    else
    {
        throw
            std::invalid_argument("error");
    }
}

unsigned int am_pm_clock::get_seconds() const
{
    return seconds;
}

void am_pm_clock::set_seconds(unsigned int secs)
{
    if(secs < 60){
        seconds = secs;
    }
    else
    {
        throw
            std::invalid_argument("error");
    }
}

bool am_pm_clock::is_am() const
{

    return am;
}

void am_pm_clock::set_am(bool am_val)
{
    am = am_val;
}

am_pm_clock::~am_pm_clock(){
    hours = minutes = seconds = am = 0;
}

