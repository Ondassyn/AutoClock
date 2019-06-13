#include "am_pm_clock.h"

#include <iostream>
    /*
	 * Default constructor - initial time should be midnight
	 */
	am_pm_clock::am_pm_clock()
    : hours{12}, minutes{00}, seconds{00}, am{true} {}

	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val)
                : hours{hrs}, minutes{mins}, seconds{secs}, am{am_val}
                {}

	/*
	 * Copy constructor
	 */
	am_pm_clock::am_pm_clock(const am_pm_clock &clock)
    : hours{clock.hours},
    minutes{clock.minutes}, 
    seconds{clock.seconds}, 
    am{clock.am} {}

	/*
	 * Assignment operator
	 */
	am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
        this->hours = clock.hours;
        this->minutes = clock.minutes;
        this->seconds = clock.seconds;
        this->am = clock.am;
        return *this;
    }

	/*
	 * Toggles the am/pm value for the clock
	 */
	void am_pm_clock::toggle_am_pm(){
        if (am == true){
            am = false;
        } else {
            am = true;
        }
        /*if (am == true){
            am = false;
        } else {
            am = true;
        }*/
    }

	/*
	 * Resets the time to midnight
	 */
	void am_pm_clock::reset(){
        hours = 12;
        minutes = 00;
        seconds = 00;
        am = true;
    }

	/*
	 * Advances the time of the clock by one second
	 */
	void am_pm_clock::advance_one_sec(){
        if (seconds < 59){
            seconds += 1;
        } else {
            seconds = 00;
            if (minutes < 59){
                minutes += 1;
            } else {
                minutes = 00;
                if (hours == 11){
                    toggle_am_pm();
                    hours = 12;
                } else if (hours == 12){
                    hours = 01;
                } else {
                    hours += 1;
                }
            }
        }
    }

	/*
	 * Advances the time of the clock by n seconds
	 */
	void am_pm_clock::advance_n_secs(unsigned int n){

        std::cerr << "DEBUG: " << n << '\n';

        unsigned int all_secs, all_mins, all_hours;
        
        all_secs = n % 60; //how many seconds to add after
        n /= 60; //how many minutes to add
        seconds += all_secs; //all seconds that are gained. Can be more than 60
        
        all_mins = (n % 60) + (seconds / 60); //all minutes to add are being counted
        n /= 60; //hours to add are being counted
        seconds %= 60; //second time check is being done to be seconds < 59 for sure
        minutes += all_mins; //all minutes are being counted

        all_hours = (n % 24) + (minutes / 60); //all hours to add are being counted
        minutes %= 60; //second check is being done to be minutes < 59 for sure
        n %= 24; //unneccessary days were ignored
        hours += all_hours; //all hours are being counted

        if(hours > 11 && all_hours != 0){
            toggle_am_pm();
            if (hours != 12){
                hours -= 12;
            }
        }
        return;

////////////////////////////////////////////

        /*if (seconds > 60){ 
             //seconds += all_secs
            //buffer += seconds / 60;
            n /= 60; 
            //all_mins = (n + buffer) % 60; 
            minutes += all_mins;
            if (all_mins > 60){
                minutes = all_mins;
                minutes = all_mins % 60;
                all_hours = all_mins / 60;
                //delete all_mins;
                all_hours += hours;
                if (all_hours < 12){
                    hours = all_hours;
                } else {
                    hours = all_hours % 12;
                    if (all_hours > 12){
                        toggle_am_pm();
                    }
                }
            }
        }*/
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
        if (hrs > 12){
            throw std::invalid_argument("Received invalid argument");
        } else {
            hours = hrs;
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
        if (mins > 60){
            throw std::invalid_argument("Received invalid argument");
        } else {
            minutes = mins;
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
        if (secs > 60){
            throw std::invalid_argument("Received invalid argument");
        } else {
            seconds = secs;
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

	/*
	 * Destructor
	 */
	am_pm_clock::~am_pm_clock() {}