#include "am_pm_clock.h"
	am_pm_clock::am_pm_clock():
		hours(12),
		minutes(0),
		seconds(0),
		am(1)
	{};
	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val):
			    	hours(hrs),
					minutes(mins),
					seconds(secs),
					am(am_val)
	{};
	am_pm_clock::am_pm_clock(const am_pm_clock &clock)
	{
		hours=clock.hours;
	    minutes=clock.minutes;
	    seconds=clock.seconds;
	    am=clock.am;
	}
	am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
	hours=clock.hours;
	minutes=clock.minutes;
	seconds=clock.seconds;
	am=clock.am;
	}
	void am_pm_clock::toggle_am_pm(){

		if(hours == 11 && minutes == 59 && seconds == 59 && am == 1)
		{seconds++;
		am=0;}
		else if(hours == 11 && minutes == 59 && seconds == 59 && am == 0)
		{seconds++;
		am=1;}
	}
	void am_pm_clock::reset(){
		hours=12;
		minutes=0;
		seconds=0;
		am=1;
	}
	void am_pm_clock::advance_one_sec(){
		seconds++;
	}
	void am_pm_clock::advance_n_secs(unsigned int n){
		seconds+=n;
	}
	unsigned int am_pm_clock::get_hours() const{
			return hours;
	}
	void am_pm_clock::set_hours(unsigned int hrs){
			if(hrs>12)
			throw std::invalid_argument("Is not a legal hours value");
			hours=hrs;
	}
	unsigned int am_pm_clock::get_minutes() const{
			return minutes;
	}
		void am_pm_clock::set_minutes(unsigned int mins){
			if(mins>59)
			throw std::invalid_argument("Is not a legal minutes value");
			minutes=mins;
		}
		unsigned int am_pm_clock::get_seconds() const{
			return seconds;
		}
		void am_pm_clock::set_seconds(unsigned int secs){
			if(secs>59)
			throw std::invalid_argument("Is not a legal seconds value");
			seconds=secs;
		}
		bool am_pm_clock::is_am() const{
			if(am)
				return true;
			else
				return false;
		}
		void am_pm_clock::set_am(bool am_val){
			am=am_val;
		}
		void am_pm_clock::print(std::ostream& out) const {
			char buff[11];
			std::sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
					( am ? 'a' : 'p' ));
			out << buff;
		}
		am_pm_clock::~am_pm_clock()
		{
	};

