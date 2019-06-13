#define AM_PM_CLOCK_H_
#ifndef AM_PM_CLOCK_H_

#include <ostream>
#include <cstdio>

class am_pm_clock {

	unsigned int hrs, mins, secs;
	bool		 am;

public:

	/*
	 * Default constructor - initial time should be midnight
	 */
	am_pm_clock();

	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val);

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
	void toggle_am_pm();

	/*
	 * Resets the time to midnight
	 */
	void reset();

	/*
	 * Advances the time of the clock by one second
	 */
	void advance_one_sec();

	/*
	 * Advances the time of the clock by n secs
	 */
	void advance_n_secs(unsigned int n);

	/*
	 * Getter for hrs field
	 */
	unsigned int get_hrs() const;

	/*
	 * Setter for hrs field; throws an invalid_argument exception
	 * if hrs is not a legal hrs value
	 */
	void set_hrs(unsigned int hrs);

	/*
	 * Getter for mins field
	 */
	unsigned int get_mins() const;

	/*
	 * Setter for mins field; throws an invalid_argument exception
	 * if mins is not a legal mins value
	 */
	void set_mins(unsigned int mins);

	/*
	 * Getter for secs field
	 */
	unsigned int get_secs() const;

	/*
	 * Setter for secs field; throws an invalid_argument exception
	 * if secs is not a legal secs value
	 */
	void set_secs(unsigned int secs);

	/*
	 * Getter for am field
	 */
	bool is_am() const;

	/*
	 * Setter for am field
	 */
	void set_am(bool am_val);

	/*
	 * Print function - helper for output operator
	 */
	void print(std::ostream& out) const {
		char buf[11];
		std::sprintf(buf, "%02d:%02d:%02d%cm", hrs, mins, secs,
				( am ? 'a' : 'p' ));
		out << buf;
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
