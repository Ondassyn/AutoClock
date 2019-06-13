#include "am_pm_clock.h"

am_pm_clock::am_pm_clock()
      : hours(12), minutes(0), seconds(0), am(1) {}  // default constructor

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs,
              bool am_val)
      : hours(hrs), minutes(mins), seconds(secs), am(am_val) {}  // constructor;

am_pm_clock::am_pm_clock(const am_pm_clock& clock)
      : hours(clock.hours),
        minutes(clock.minutes),
        seconds(clock.seconds),
        am(clock.am) {}  // Copy constructor;

am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
      this-> hours=clock.hours;
      this-> minutes=clock.minutes;
      this-> seconds=clock.seconds;
      this-> am=clock.am;
      return *this;
  }//Assignment operator

  void am_pm_clock::toggle_am_pm() {
    if (am == 1) {
      am = 0;
    } else
      am = 1;  // Toggles the am/pm value for the clock
  }

  void am_pm_clock::reset(){
      hours = 12;
      minutes = 0;
      seconds = 0;
      am = 1;  // Resets the time to midnight
  }

  void am_pm_clock::advance_one_sec() {
    if (seconds == 59) {
      seconds = 0;
      if (minutes == 59) {
        minutes = 0;
        if (hours == 11)
        {
          toggle_am_pm();
        }
        if (hours == 12) {
          hours = 1;
        } else {
          hours = hours + 1;
        }
      } else {
        minutes = minutes + 1;
      }
    } else {
      seconds = seconds + 1;
    }  // Advances the time of the clock by one second
  }

  void am_pm_clock::advance_n_secs(unsigned int n) {
    for (size_t a = 1; a <= n; a = a + 1) {
    if (seconds == 59) {
      seconds = 0;
      if (minutes == 59) {
        minutes = 0;
        if (hours == 11)
        {
          toggle_am_pm();
        }
        if (hours == 12) {
          hours = 1;
        } else {
          hours = hours + 1;
        }
      } else {
        minutes = minutes + 1;
      }
    } else {
      seconds = seconds + 1;
    }  // Advances the time of the clock by one second
    }  // Advances the time of the clock by n seconds
  }

  unsigned int am_pm_clock::get_hours() const {
    return hours;  // Getter for hours field
  }

  void am_pm_clock::set_hours(unsigned int hrs) {
    if (hrs < 0 || hrs > 12) {
      throw std::invalid_argument(
          "Invalid argument for hours.\n");  // if hrs is not a legal hours value throws an invalid_argument exception.
    } else {
      hours = hrs;
    }
  }

  unsigned int am_pm_clock::get_minutes() const {
    return minutes;  // Getter for minutes field
  }

  void am_pm_clock::set_minutes(unsigned int mins) {
    if (mins < 0 || mins > 59) {
      throw std::invalid_argument(
          "Invalid argument for minutes.\n");  // if mins is not a legal minutes value throws an invalid_argument exception.
    } else {
      minutes = mins;
    }
  }

  unsigned int am_pm_clock::get_seconds() const {
    return seconds;  // Getter for seconds field
  }

  void am_pm_clock::set_seconds(unsigned int secs) {
    if (secs < 0 || secs > 59) {
      throw std::invalid_argument(
          "Invalid argument for seconds.\n");  // if secs is not a legal seconds value throws an invalid_argument exception.
    } else {
      seconds = secs;
    }
  }

  bool am_pm_clock::is_am() const { return am; }

  void am_pm_clock::set_am(bool am_val) {
    am = am_val;  // Setter for am field
  }

 am_pm_clock::~am_pm_clock(){}  // Destructor