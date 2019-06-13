#include <iostream>
using namespace std;


class am_pm_clock {

	unsigned int hours, minutes, seconds;
	bool		 am;

public:
    am_pm_clock() {
        hours=12;
        minutes=00;
        seconds=00;
        am=true;
    }

    am_pm_clock(unsigned int hrs, unsigned int mins,
    			    unsigned int secs, bool am_val) {
    	hours=hrs;
    	minutes=mins;
    	seconds=secs;
    	am=am_val;
    }

    am_pm_clock(const am_pm_clock &clock){
    hours=clock.hours;
    minutes=clock.minutes;
    seconds=clock.seconds;
    am=clock.am;
    }

    const am_pm_clock& operator=(const am_pm_clock &clock) {
    	hours=clock.hours;
    	minutes=clock.minutes;
    	seconds=clock.seconds;
    	am=clock.am;
    	return clock;
    }

    void toggle_am_pm() {
    	if (hours>12) {
    		hours=hours-12;
    		am=false;
    	} else {
    		am=true;
    	}
    }

    void reset() {
        hours=12;
        minutes=00;
        seconds=00;
        am=false;
    }

    void advance_one_sec() {
    	seconds++;
    	if (seconds>59) {
    		seconds=0;
    	}
    }
    void advance_n_secs(unsigned int n) {
    	seconds=seconds+n;
    	if (seconds>59) {
    		seconds=seconds-59;
    	}
    }

    unsigned int get_hours() const {
    	return hours;
    }

    void set_hours(unsigned int hrs) {
    	hours=hrs;
    	if (hrs>12) {
    		throw std::invalid_argument("Invalid syntax.");
    	}
    }

    unsigned int get_minutes() const {
    	return minutes;
    }

    void set_minutes(unsigned int mins) {
    	minutes=mins;
    	if (mins>59) {
    		throw std::invalid_argument("Invalid value");
    	}
    }

    unsigned int get_seconds() const {
    	return seconds;
    }

    void set_seconds(unsigned int secs) {
    	seconds=secs;
    	if (secs>59) {
    		throw std::invalid_argument("Invalid value");
    	}
    }

    bool is_am() const {
    	return am;
    }

    void set_am(bool am_val)  {
    	am=am_val;
    }

    void print(std::ostream& out) const {
    	char buff[11];
    	std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
    			( am ? 'a' : 'p' ));
    	out << buff;
    }

} ;
int main() {


    return 0;
}

