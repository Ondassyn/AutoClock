#include "am_pm_clock.h"
#include <iostream>
#include <string>
/** @brief (one liner)
  *
  * (documentation goes here)
  */

am_pm_clock::am_pm_clock()
{
        hours=12;
	    minutes=0;
	    seconds=0;
	    am=true;
}
 am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val)
  {
    if((hrs>=0)&&(hrs<=12)&&(mins>=0)&&(mins<=60)&&(secs>=0)&&(secs<=60)){
                hours=hrs;
                minutes=mins;
                seconds=secs;
                am=am_val;
                }
        else{
                hours=12;
                minutes=0;
                seconds=0;
                }
  }

  am_pm_clock::am_pm_clock(const am_pm_clock& clock)
  {

  }

  am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock)
  {

  }

  void am_pm_clock::toggle_am_pm()
  {

  }

  void am_pm_clock::reset()
  {
    hours=12;
	minutes=0;
	seconds=0;
	am=true;
  }

  void am_pm_clock::advance_one_sec()
  {
	seconds++;
    if (seconds>=60){
            seconds=0;
            minutes++;
            }
            if (minutes>=60){
                    minutes=0;
                    hours++;
                    }
                    if (hours>=12){
                            hours=0;
                            }
  }

  void am_pm_clock::advance_n_secs(unsigned int n)
  {

  }

  unsigned int am_pm_clock::get_hours()
  {
      return hours;
  }

  void am_pm_clock::set_hours(unsigned int hrs)
  {
    hours=hrs;
    if (hours>12||hours<0){
            throw std::invalid_argument("Invalid value for hours");
            }
  }

  unsigned int am_pm_clock::get_minutes()
  {
      return minutes;
  }

  void am_pm_clock::set_minutes(unsigned int mins)
  {
    minutes=mins;
	if (minutes>59||minutes<0){
            throw std::invalid_argument("Invalid value for minutes");
	}
  }

  unsigned int am_pm_clock::get_seconds()
  {
      return seconds
  }

  void am_pm_clock::set_seconds(unsigned int secs)
  {
    seconds=secs;
	if (seconds>59||seconds<0){
            throw std::invalid_argument("Invalid value for hours for seconds");
	}
  }

  bool am_pm_clock::is_am()
  {
      return am;
  }

  void am_pm_clock::set_am(bool am_val)
  {
      am=am_val;
  }

  void am_pm_clock::print(std::ostream& out)
  {

  }


am_pm_clock::~am_pm_clock()
{
    //dtor
}
