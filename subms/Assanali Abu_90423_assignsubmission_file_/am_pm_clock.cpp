#include <iostream>
using namespace std;
#include "am_pm_clock.h"
/*
	 * Default constructor - initial time should be midnight
	 */
class am_pm_clock {

	unsigned int hours, minutes, seconds;
	bool		 am;

public:
am_pm_clock(){
		hours = 12;
		minutes = 00;
		seconds = 00;
		am = true;
	};

	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val){
	set_hours(hrs);
	set_minutes(mins);
	set_seconds(mins);
	set_am(am_val);
	};
	/*
	 * Copy constructor
	 */
	am_pm_clock(const am_pm_clock &clock){
		hours = clock.hours;
		minutes = clock.minutes;
		seconds = clock.seconds;
		am = clock.am;
	};

	/*
	 * Assignment operator
	 */
	am_pm_clock& operator=(const am_pm_clock& clock){

		this->hours = clock.hours;
		this->minutes = clock.minutes;
		this->seconds = clock.seconds;
		this->am = clock.am;
		return *this;
	};

	/*
	 * Toggles the am/pm value for the clock
	 */
	void toggle_am_pm(){
	 if(am == true){
		 am = false;
	 }
	 else{
	   am = true;
	 }
	};

	/*
	 * Resets the time to midnight
	 */
	void reset(){
		hours = 12;
		minutes = 00;
		seconds = 00;
		am = true;
	}
	;
	/*
	 * Advances the time of the clock by one second
	 */
	void advance_one_sec(){
		seconds = seconds+1;
		if(seconds>59){
		  minutes = minutes+1;
		  seconds = 00;
		}
		if(minutes>59){
			minutes = 00;
			hours = hours+1;
		}
		if(hours>12){
			hours = 1;
			toggle_am_pm();
		}
	}
	;
	/*
	 * Advances the time of the clock by n seconds
	 */
	void advance_n_secs(unsigned int n){

		if((seconds+n)>59){
			minutes = minutes+n/60;
			seconds = seconds + n%60;
					if(seconds>59){
						seconds = seconds-60;
						minutes=minutes+1;
					}
			if(minutes>59){
				hours = hours + minutes/60;
				minutes = minutes + hours%60;
				if(minutes>59){
								minutes = minutes-60;
							    hours=hours+1;
									}


			}
		}
		else{
			seconds = seconds+ n;
		}
		if(hours>12){
			    if(((hours/12)%2)==0) {
			    	am =true;
			    }
			    else{
			    	am = false;
			    }
			    ;
				hours = hours%12;

			}
	}
	;
	/*
	 * Getter for hours field
	 */
	unsigned int get_hours() const{
		return hours;
	}

	/*
	 * Setter for hours field; throws an invalid_argument exception
	 * if hrs is not a legal hours value
	 */
	void set_hours(unsigned int hrs){
		hours = hrs;
		if(hours>12){
		throw std::invalid_argument( "received not a legal values" );
		}
	};

	/*
	 * Getter for minutes field
	 */
	unsigned int get_minutes() const{
		return minutes;
	};

	/*
	 * Setter for minutes field; throws an invalid_argument exception
	 * if mins is not a legal minutes value
	 */
	void set_minutes(unsigned int mins){
		minutes = mins;
		if(minutes>59){
		throw std::invalid_argument( "received not a legal values" );
		}
	};

	/*
	 * Getter for seconds field
	 */
	unsigned int get_seconds() const{
		return seconds;
	};

	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
	void set_seconds(unsigned int secs){
		seconds = secs;
		if(seconds>59){
		throw std::invalid_argument( "received not a legal values" );
	}
	};
	/*
	 * Getter for am field
	 */
	bool is_am() const{
		return am;
	};

	/*
	 * Setter for am field
	 */
	void set_am(bool am_val){
		am = am_val;
	}
	;
	/*
	 * Print function - helper for output operator
	 */
	void print(std::ostream& out) const {
		char buff[11];
		std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
				( am ? 'a' : 'p' ));
		out << buff;
	}
	;
	/*
	 * Destructor
	 */
	~am_pm_clock(){};

	inline std::ostream& operator << (std::ostream& out, const am_pm_clock& clock) {
		clock.print(out);
		return out;
	}
}
int main() {
	return 0;
}

