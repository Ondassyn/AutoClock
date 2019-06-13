#include <iostream>
#include "am_pm_clock.h" 
using namespace std;

int main()
{
//Honestly I have no idea how to do it properly.


    //1
    am_pm_clock clock{12,00,00,1};

    //2
    am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val):
        hours(hrs),
        minutes(mins),
        seconds(secs),
        am(true), {
        }

    clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val){
			        set_hours(hrs);
			        set_minutes(mins);
			        set_seconds(secs);
			        set_am(am_val);
			    }

    //3
    //4
    //5
    //6
    //7
    //8


    //9
    int clock::get_hours() const{
    return hours;
    }
    //10
    void clock::set_hours(unsigned int hrs){
    if (hrs>=0 && hrs<=23) {
        hours=hrs;}
        else {
    throw std::invalid_argument("Invalid argument! Hrs is not a legal hours value.");
        }}
   //11
   int clock::get_minutes() const{
   return minutes;
   }
   //12
   void set_minutes(unsigned int mins){
   if(mins>=0 && mins<=59){
    minutes=mins;
   }else {
   throw std::invalid_argument("Invalid argument! Mins is not a legal minutes value.");
   }}

   //13
   int clock::get_seconds() const{
   return seconds;
   }
   //14
   void set_seconds(unsigned int secs){
   if(secs>=0 && secs<=59){
    seconds=secs;
   } else {
   throw std::invalid_argument("Invalid argument! Secs is not a legal seconds value.");}
   }
   //15
   bool is_am() const {
   return am;
   }
   //16?
   void set_am(bool am_val) {
   }

    return 0;
}
