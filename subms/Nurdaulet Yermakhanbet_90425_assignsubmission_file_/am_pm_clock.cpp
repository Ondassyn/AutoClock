#include "am_pm_clock.h"
	
	am_pm_clock::am_pm_clock():
		hours{12},	
		minutes{00},
		seconds{00},
		am{true}{

		}

	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val):
		hours{hrs},
		minutes{mins},
		seconds{secs},
		am{am_val}{

		}
	/*
	 * Copy constructor
	 */
	am_pm_clock::am_pm_clock(const am_pm_clock &clock):
		hours{clock.hours},
		minutes{clock.minutes},
		seconds{clock.seconds},
		am{clock.am}
		{

		}

	
	am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
	
		hours = clock.hours;
		minutes = clock.minutes;
		seconds = clock.seconds;
		am = clock.am;

		return *this;
	}
	
	void am_pm_clock::toggle_am_pm() {
		if(am) am = false;
		if(!am) am = true;
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
		if(hours == 11 && minutes == 59 && seconds == 59){
			hours = 12;
			minutes = 0;
			seconds = 0;
			if(am)
				am = false;
			else 
				am = true;
			return ;
		}
		if(seconds < 59){
			seconds++;
			return;	
		}
		if(seconds == 59){
			seconds = 0;
			if(minutes < 59){
				minutes++;
				return;
			}
			if(minutes == 59){
				minutes == 0;
				hours++;
				return;
			}	
		}
	}

	void am_pm_clock::advance_n_secs(unsigned int n){
		int memory = seconds;
		seconds = seconds + n;
		if(seconds >= 60){
			seconds = seconds % 60;
			int addition = (memory + n) /60;
			minutes = minutes + addition;
			memory = minutes;
			if(minutes >= 60){
				minutes %= 60;
				hours += memory / 60;
				if(hours > 11){
					if((hours / 12) % 2  == 0)
						toggle_am_pm();
					hours = hours % 12;
					if(hours == 0)
						hours = hours + 12;
				}
			}
		}
	}

	/*
	 * Getter for hours field
	 */
	unsigned int am_pm_clock::get_hours() const { return hours; }
		

	/*
	 * Setter for hours field; throws an invalid_argument exception
	 * if hrs is not a legal hours value
	 */
	void am_pm_clock::set_hours(unsigned int hrs) {
		hours = hrs;
	}

	/*
	 * Getter for minutes field
	 */
	unsigned int am_pm_clock::get_minutes() const { return minutes; }

	/*
	 * Setter for minutes field; throws an invalid_argument exception
	 * if mins is not a legal minutes value
	 */
	void am_pm_clock::set_minutes(unsigned int mins) {
		minutes = mins;
	}

	/*
	 * Getter for seconds field
	 */
	unsigned int am_pm_clock::get_seconds() const { return seconds; }

	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
	void am_pm_clock::set_seconds(unsigned int secs) {
		seconds = secs;
	}

	/*
	 * Getter for am field
	 */
	bool am_pm_clock::is_am() const { return am; }

	/*
	 * Setter for am field
	 */
	void am_pm_clock::set_am(bool am_val) {
		am = am_val;	
	}

	am_pm_clock::~am_pm_clock() {}