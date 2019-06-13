#ifndef AM_PM_CLOCK_H_
#define AM_PM_CLOCK_H_

#include <ostream>

class am_pm_clock {
int hours;
int minutes;
int seconds;
bool am;




public:
am_pm_clock():
hours(12),
minutes(0),
seconds(0),
am(true)
{
}




	/*
	 * Default constructor - initial time should be midnight
	 */


am_pm_clock(int hrs, int mins, int secs, bool am_val):
	hours(hrs),
	minutes(mins),
	seconds(secs),
	am(am_val)
{
}

	/*
	 * Constructor - sets fields to the given argument values
	 */


	/*
	 * Copy constructor
	 */
	am_pm_clock(const am_pm_clock &clock);

	/*
	 * Assignment operator
	 */
	am_pm_clock& operator=(const am_pm_clock& clock);

	/*
	 * Toggles the am/pm value for the clock
	 */
	void toggle_am_pm(){
		hours=12;
		minutes=0;
		seconds=0;
		am=true;
	}
	/*
	 * Resets the time to midnight
	 */
	void reset();

	/*
	 * Advances the time of the clock by one second
	 */
	void advance_one_sec(){
			seconds=seconds+1;
	if (seconds==60){
		minutes=minutes+1;
		seconds=0;}

		if (minutes==60){
			hours=hours+1;
			minutes=0;

		}


		if (hours==13){
			hours=1;
			if(am)
				am=false;
				else
					am=true;
		}

		}



	/*
	 * Advances the time of the clock by n seconds
	 */
	void advance_n_secs( int n){
		for (int i=0; i<n; i++)
			advance_one_sec();
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
	void set_hours( int hrs){
		hours=hrs;
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
	void set_minutes( int mins){
		minutes=mins;
	}

	/*
	 * Getter for seconds field
	 */
	 int get_seconds() const{
		return seconds;
	}

	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
	void set_seconds( int secs){
		seconds=secs;
	}

	/*
	 * Getter for am field
	 */
	bool is_am() const{
		return am;
	}

	/*
	 * Setter for am field
	 */
	void set_am(bool am_val){
		am=am_val;
	}

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

#endif /* AM_PM_CLOCK_H_ */
