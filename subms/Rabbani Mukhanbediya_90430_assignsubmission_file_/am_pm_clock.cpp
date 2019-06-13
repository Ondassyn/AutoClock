	#include"am_pm_clock.h"
	//Probably my code won't compile
	//But can you kind explain mine mistakes
	//TA told that general logic is rigth, but there could be an error
	//*and he was right
	//*I cannot fix it
	//----------+
	am_pm_clock(){
	am_pm_clock time= {12,0,0,1};    //How to check for boolean?
	return time;		
	}
	//----------+
	am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val){
	am_pm_clock time= {hrs,mins,secs,am_val}; 
	return time;
	}
	//----------+
	am_pm_clock(const am_pm_clock &clock){
	am_pm_clock time; 
	time=clock;
	return time;
	}
	//----------
	am_pm_clock& operator=(const am_pm_clock& clock){
		am_pm_clock time;
		time=clock;
		return time;
	}
	//-----------
	void toggle_am_pm(){
	
	if(am_pm_clock.am){
	am_pm_clock.am=false;
	} else {
	am_pm_clock.am=true;
	}
	}
	//----------+
	void reset(){
	am_pm_clock.hours=12;
	am_pm_clock.minutes=0;
	am_pm_clock.seconds=0;
	am_pm_clock.am=1;
	}
	//----------+
	void advance_one_sec(){
	unsigned int sec=am_pm_clock.seconds;
	sec++;
	if(sec>59){
	unsigned int min=am_pm_clock.minutes;
	min++;
	am_pm_clock.minutes=min;
	am_pm_clock.seconds=0;
	} else {
	am_pm_clock.seconds=sec;
	}	
	}
	//----------+
	void advance_n_secs(unsigned int n){
	unsigned int sec=am_pm_clock.seconds;
	sec=sec+n;
	unsigned int min=am_pm_clock.minutes;
	if(sec>59){
	while(sec>59){
	min++;
	am_pm_clock.minutes=min;
	sec=sec-60;
	}
	} else {
	am_pm_clock.seconds=sec;
	}
	}
	//-----------
	unsigned int get_hours() const{
	return am_pm_clock.hours;
	}
	//-----------
	void set_hours(unsigned int hrs){
	if(hrs>=1&&hrs<=12){
	am_pm_clock.hours=hrs;
	} else {
	break;
	}
	}
	//-----------
	unsigned int get_minutes() const{
	return am_pm_clock.minutes;
	}
	//----------
	void set_minutes(unsigned int mins){
	if(mins<=59&&mins>=0){
	am_pm_clock.minutes=mins;
	} else {
	throw std::invalid_argument("You set minutes wrong!!!");
	}
	}
	//----------
	unsigned int get_seconds() const{
	return am_pm_clock.seconds;
	}
	//----------
	void set_seconds(unsigned int secs){
	if(secs<=59&&secs>=0){
	am_pm_clock.seconds=secs;
	} else {
	throw std::invalid_argument("You set seconds wrong!!!");
	}
	}
	//---------
	bool is_am() const{
	if(am_pm_clock.am){
	return true;
	} else {
	return false;
	}
	return true;
	}
	//-----------
	void set_am(bool am_val){
	am_pm_clock.am=am_val;
	}
	
	
