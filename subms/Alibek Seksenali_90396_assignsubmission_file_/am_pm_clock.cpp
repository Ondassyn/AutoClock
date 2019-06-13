#include "am_pm_clock.h"
#include <iostream>

    am_pm_clock::am_pm_clock(){
        am = true;
        hours = 12;
        minutes = 0;
        seconds = 0;
        std::cout<<"default contructor"<<'\n';
    }

    am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
       unsigned int secs, bool am_val){
           hours = hrs;
           minutes = mins;
           seconds = secs;
           am = am_val;
           std::cout<<"contructor with fields"<<'\n';
       }

    am_pm_clock::am_pm_clock(const am_pm_clock &clock){
        hours = clock.hours;
        minutes = clock.minutes;
        seconds = clock.seconds;
        am = clock.am;
        std::cout<<"copy constructor"<<'\n';
    }

    am_pm_clock::~am_pm_clock(){
        std::cout<<"destructor"<<'\n';
    }

    /*
    * Assignment operator
    */
    am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
        hours = clock.hours;
        minutes = clock.minutes;
        seconds = clock.seconds;
        am = clock.am;
        return *this;
    }

    /*
    * Toggles the am/pm value for the clock
    */
    void am_pm_clock::toggle_am_pm(){
        if(am) am = false;
        else am = true;
    }

    /*
    * Resets the time to midnight
    */
    void am_pm_clock::reset(){
        *this = am_pm_clock();
    }

    /*
    * Advances the time of the clock by one second
    */
    void am_pm_clock::advance_one_sec(){
        seconds++;
        if(seconds == 60){
            minutes++;
            seconds = 0;
        } if(minutes == 60){
            hours++;
            minutes = 0;
        } if(hours = 13){
            hours = 1;
            toggle_am_pm();
        }
    }

    /*
    * Advances the time of the clock by n seconds
    */
    void am_pm_clock::advance_n_secs(unsigned int n){
        for(int i = 0; i < n; i++){
            advance_one_sec();
        }
    }

    /*
    * Getter for hours field
    */
    unsigned int am_pm_clock::get_hours() const{
        return hours;
    }

    /*
    * Setter for hours field; throws an invalid_argument exception
    * if hrs is not a legal hours value
    */
    void am_pm_clock::set_hours(unsigned int hrs){
        if(hrs > 0 && hrs <= 12){
            hours = hrs;
        } else {
            throw std::invalid_argument("invalid hour value");
        }
    }

    /*
    * Getter for minutes field
    */
    unsigned int am_pm_clock::get_minutes() const{
        return minutes;
    }

    /*
    * Setter for minutes field; throws an invalid_argument exception
    * if mins is not a legal minutes value
    */
    void am_pm_clock::set_minutes(unsigned int mins){
        if(mins >= 0 && mins <= 59){
            minutes = mins;
        } else {
            throw std::invalid_argument("invalid minute value");
        }
    }

    /*
    * Getter for seconds field
    */
    unsigned int am_pm_clock::get_seconds() const{
        return seconds;
    }

    /*
    * Setter for seconds field; throws an invalid_argument exception
    * if secs is not a legal seconds value
    */
    void am_pm_clock::set_seconds(unsigned int secs){
        if(secs >= 0 && secs <= 59){
            seconds = secs;
        } else {
            throw std::invalid_argument("invalid second value");
        }
    }

    /*
    * Getter for am field
    */
    bool am_pm_clock::is_am() const{
        return am;
    }

    /*
    * Setter for am field
    */
    void am_pm_clock::set_am(bool am_val){
        am = am_val;
    }
