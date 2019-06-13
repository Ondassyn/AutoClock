#include <stdexcept>

#include "am_pm_clock.h"

am_pm_clock::am_pm_clock():
  hours(12),
  minutes(0),
  seconds(0),
  am(true) {}
am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
    unsigned int secs, bool am_val):
  hours(hrs),
  minutes(mins),
  seconds(secs),
  am(am_val) {}
am_pm_clock::am_pm_clock(const am_pm_clock & clock):
  hours(clock.hours),
  minutes(clock.minutes),
  seconds(clock.seconds),
  am(clock.am) {}
am_pm_clock & am_pm_clock::operator = (const am_pm_clock & clock) {
  this -> hours = clock.hours;
  this -> minutes = clock.minutes;
  this -> seconds = clock.seconds;
  this -> am = clock.am;
  return *this;
}

unsigned int am_pm_clock::get_hours() const {
  return hours;
}
void am_pm_clock::set_hours(unsigned int hrs) {
  hours = hrs;
  if (hrs > 12 || hrs < 1) throw std::invalid_argument("is not a legal");
}
unsigned int am_pm_clock::get_minutes() const {
  return minutes;
}
void am_pm_clock::set_minutes(unsigned int mins) {
  minutes = mins;
  if (mins > 59 || mins < 0) throw std::invalid_argument("is not a legal");
}
unsigned int am_pm_clock::get_seconds() const {
  return seconds;
}
void am_pm_clock::set_seconds(unsigned int secs) {
  seconds = secs;
  if (secs > 59 || secs < 0) throw std::invalid_argument("is not a legal");
}
bool am_pm_clock::is_am() const {
  return am;
}
void am_pm_clock::set_am(bool am_val) {
  am = am_val;

}
void am_pm_clock::toggle_am_pm() {
  if (am == false) {
    am = true;
  } else {
    am = false;
  }

}
void am_pm_clock::reset() {
  hours = 12;
  minutes = 0;
  seconds = 0;
  am = true;
}
void am_pm_clock::advance_one_sec() {
  if (seconds == 59) {
    seconds = 00;
    if (minutes == 59) {
      minutes = 00;
      if (hours == 11) {
        toggle_am_pm();
        hours++;
      } else if (hours == 12) {
        hours = 1;
      } else {
        hours++;
      }

    } else {
      minutes++;
    }
  } else {
    seconds++;
  }
}
void am_pm_clock::advance_n_secs(unsigned int n) {

  int i = n - 59;
  minutes = minutes + 1;
  while (i > 59) {
    minutes = minutes + 1;
    i = i - 60;
  }
  seconds = i;
  if (minutes > 59) {
    int j = minutes - 60;
    hours = hours + 1;
    while (j > 59) {
      hours = hours + 1;
      j = j - 60;
    }
    minutes = j;
  }
  if (hours > 12) {
    hours = hours - 12;
  }
}

am_pm_clock::~am_pm_clock() {}
