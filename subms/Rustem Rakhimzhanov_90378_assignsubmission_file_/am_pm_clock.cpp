#include <iostream>

class am_pm_clock {

public:
	int seconds, minutes, hours;
	bool am;

	am_pm_clock() {
		seconds = 0;
		minutes = 0;
		hours = 12;
		am = true;
	}

	am_pm_clock(unsigned int hrs, unsigned int mins,
				    unsigned int secs, bool am_val) {
		seconds = secs;
		minutes = mins;
		hours = hrs;
		am = am_val;
	}

	void toggle_am_pm() {
		if(am == true) {
			am = false;
		} else {
			am = true;
		}
	}

	void reset() {
		seconds = 0;
		minutes = 0;
		hours = 12;
		am = true;
	}

	void advance_one_sec() {
		seconds = seconds + 1;
		if(seconds > 59) {
			seconds = 0;
			minutes = minutes + 1;
		}
		if(minutes > 59) {
			minutes = 0;
			hours = hours + 1;
		}
		if(hours > 12) {
			hours = 0;
			if(am == true) {
				am = false;
			} else {
				am = true;
			}
		}
	}

	void advance_n_secs(unsigned int n) {
		seconds = seconds + n;
		if(seconds > 59) {
			unsigned int new_seconds = seconds%60;
			minutes = minutes + seconds/60;
			seconds = new_seconds;
		}
		if(minutes > 59) {
			unsigned int new_minutes = minutes%60;
			hours = hours + minutes/60;
			minutes = new_minutes;
		}
		if(hours > 12) {
			unsigned int new_hours = hours%12;
			if(am == true && (hours/12)%2 == 0) {
				am = true;
			} else if(am == true && (hours/12)%2 != 0) {
				am = false;
			} else {
				am = false;
			}
			hours = new_hours;
		}
	}

	unsigned int get_hours() const {
		return hours;
	}

	void set_hours(unsigned int hrs) {
		if(hrs < 0 && hrs > 12) {
			throw std::invalid_argument("Wrong value!");
		} else {
			hours = hrs;
		}
	}

	unsigned int get_minutes() const {
		return minutes;
	}

	void set_minutes(unsigned int mins) {
		if(mins < 0 && mins > 59) {
			throw std::invalid_argument("Wrong value!");
		} else {
			minutes = mins;
		}
	}

	unsigned int get_seconds() const {
		return seconds;
	}

	void set_seconds(unsigned int secs) {
		if(secs < 0 && secs > 59) {
					throw std::invalid_argument("Wrong value!");
				} else {
					minutes = secs;
				}
	}

	bool is_am() const {
		return am;
	}

	void set_am(bool am_val) {
		am = am_val;
	}


};

int main() {
	/* What I supposed to write here? */
}
