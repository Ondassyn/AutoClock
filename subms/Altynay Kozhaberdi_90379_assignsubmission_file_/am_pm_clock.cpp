  #include <iostream>
    #include "am_pm_clock.h"
    using namespace std;
#include <cstdio>


    am_pm_clock::am_pm_clock():   // default constructor
    hours(12),
    minutes(0),
    seconds(0),
    am()
    {};

   am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val):  //constructor
	    hours(hrs),
    	minutes(mins),
    	seconds(secs),
    	am(am_val)
   {};


    am_pm_clock::am_pm_clock(const am_pm_clock &clock)  {  //copy constructor
    	   this->hours = clock.hours;
    		       this->minutes = clock.minutes;
    		       this->seconds = clock.seconds;
    		       this->am = clock.am;

    		      // return *this;
       }


   am_pm_clock &am_pm_clock::operator=(const am_pm_clock& clock){  //assignment operator

   }



    void am_pm_clock::toggle_am_pm(){      //toggle

    	if(am){
    		am=false;
    	}
    	else{
    		am=true;
    	}
    }

    void am_pm_clock::reset() {              //reset
    hours=12;
    minutes=0;
    seconds=0;
    am=true;
    }

    void am_pm_clock::advance_one_sec(){    //advance one sec
    seconds++;

    if(seconds > 59){
    minutes++;
    if(minutes>59){
    hours++;
    }
    }
    }


    void am_pm_clock::advance_n_secs(unsigned int n){     //advance n secs
    seconds = seconds+n;
         if(seconds>59){
    seconds = seconds-60;
    minutes = minutes+1;
    }

       if(minutes>59){
    	   minutes = minutes-60;
    	   hours = hours+1;
       }

    }

    unsigned int am_pm_clock::get_hours() const{     //get hours
    return hours;
    }


    void am_pm_clock::set_hours(unsigned int hrs){    //set hours

    	if(hrs>=0 && hrs<=12){
    	    hours = hrs;
    	}

        if(hrs>12){
    throw std::invalid_argument("Hours cannot be more than 12");
    }
    }

    unsigned int am_pm_clock::get_minutes() const {              //get minutes
    return minutes;
    }


    void am_pm_clock::set_minutes(unsigned int mins) {      //set minutes

    	if(mins>=0 && mins<=12){
    	    	    minutes = mins;
    	    	}

      /* if(mins>59)*/ else{
         throw std::invalid_argument("Range is from 0 to 59");
        }
    }

    bool am_pm_clock::is_am() const{      //is_am
    return am;
    }

    void am_pm_clock::set_am(bool am_val){             //set_am

    //if (){
    am = am_val;  // set condition
    }
    //}

 /*   int main () {


    return 0;
    }

*/
