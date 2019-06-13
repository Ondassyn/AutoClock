#include "am_pm_clock.h "

am_pm_clock::am_pm_clock() : hours{12}, minutes{0}, seconds{0}, am{false}{}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
	unsigned int secs, bool am_val) : hours{hrs}, minutes{mins}, seconds{secs}, am{am_val}{}

am_pm_clock::am_pm_clock(const am_pm_clock &clock) {
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
}

am_pm_clock::am_pm_clock& operator=(const am_pm_clock& clock) {
	hours = clock.hours;
	minutes = clock.minutes;
	seconds = clock.seconds;
	am = clock.am;
}

void am_pm_clock::toggle_am_pm() {
	if(am == true) {
		am = false;
	}
	else {
		am = true;
	}

}


void am_pm_clock::reset() {
	hours = 0;
	minutes = 0;
	seconds = 0;
	am = false;
}

void am_pm_clock::advance_one_sec() {
	seconds++;
	if(seconds >= 60) {
		minutes++;
		seconds -= 60;
		if(minutes >= 60) {
			hours++;
			minutes -= 60;
			if(hours > 12) {
				toggle_am_pm();
				hours -= 12;
			}
		}
	}
}
void am_pm_clock::advance_n_secs(unsigned int n) {
	seconds += n;
	if(seconds >= 60) {
		minutes++;
		seconds -= 60;
		if(minutes >= 60) {
			hours++;
			minutes -= 60;
			if(hours > 12) {
				toggle_am_pm();
				hours -= 12;
			}
		}
	}
}

unsigned int am_pm_clock::get_hours() const {
	return clock.hours;
}

void am_pm_clock::set_hours(unsigned int hrs){
	if (hrs < 0 || hrs > 12) throw std::invalid_argument("try another input");
	else clock.hours = hrs;
}

unsigned int am_pm_clock::get_minutes() const{
	return clock.minutes();
}

void am_pm_clock:set_minutes(unsigned int mins){
	if (mins < 0 || mins > 60) throw std::invalid_argument("try another input");
	else clock.mins = mins;
}

unsigned int am_pm_clock::get_seconds() const{
	return clock.seconds;
}

void am_pm_clock::set_seconds(unsigned int secs){
	if (secs < 0 || secs > 60) throw std::invalid_argument("try another input");
	else clock.seconds = secs;
}

bool am_pm_clock::is_am() const{
	return clock.am;
}

void am_pm_clock::set_am(bool am_val){
	clock.am = am_val;
}
