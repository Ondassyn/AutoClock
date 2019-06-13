#include <ostream>
#include "knock.h"

	void toggle_am_pm(){
	
	if(am == 1){
		am = 0;
	}
	else if(am == 0){
		am = 1;
	}
	}
	/*
	 * Resets the time to midnight
	 */
	void reset(){
		hours = 12;
		minutes = 0;
		seconds = 0;
		am = 1;	
	}
	/*
	 * Advances the time of the clock by one second
	 */
	void advance_one_sec(){
		seconds++;
		if(seconds == 60){
			minutes++;
			seconds = 0;
			if(minutes == 60){
				min = 0;
				hours++;
				if hours == 13 {
					hours = 1;
					am = !am;
				}
			}
		}
	}
		

	/*
	 * Advances the time of the clock by n seconds
	 */
	void advance_n_secs(unsigned int n){
		seconds++;
		if(seconds == 60){
			minutes++;
			seconds = 0;
			if(minutes == 60){
				min = 0;
				hours++;
				if hours == 13 {
					hours = 1;
					am = !am;
				}
			}
		}
	}

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
		if(hrs > 12){
			throw std::invalid_argument("hours cannot be more than 12");
		}else hourse = hrs;
	}

	/*
	 * Getter for minutes field
	 */
	unsigned int get_minutes() const{
		return minutes;
	}

	/*
	 * Setter for minutes field; throws an invalid_argument exception
	 * if mins is not a legal minutes value
	 */
	void set_minutes(unsigned int mins){
		if(mins > 60){
			throw std::invalid_argument("mins cannot be more than 60");
		}else minutes = hrs;
	};

	/*
	 * Getter for seconds field
	 */
	unsigned int get_seconds() const{
		return seconds;
	}
	
	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
	void set_seconds(unsigned int secs){
		if(secs > 60){
			throw std::invalid_argument("secs cannot be more than 60");
		}else seconds = secs;
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
	};
		
	/*
	 * Print function - helper for output operator
	 */
	void print(std::ostream& out) const {
		char buff[11];
		std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
				( am ? 'a' : 'p' ));
		out << buff;
	}

	/*
	 * Destructor
	 */
	~am_pm_clock();
	};

	inline std::ostream& operator << (std::ostream& out, const am_pm_clock& clock) {
		clock.print(out);
	return out;
	}
int main{
	
return 0;
}

