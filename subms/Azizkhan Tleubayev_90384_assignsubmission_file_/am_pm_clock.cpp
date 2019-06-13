#include "am_pm_clock.h"

am_pm_clock::am_pm_clock():
hours{12},
minutes{0},
seconds{0},
am{true} {}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val):
hours{hrs},
minutes{mins},
seconds{secs},
am{am_val} {}

am_pm_clock::am_pm_clock(const am_pm_clock &clock):
hours{clock.hours},
minutes{clock.minutes},
seconds{clock.seconds},
am{clock.am} {}


am_pm_clock& am_pm_clock::operator =(const am_pm_clock& clock)
{ am_pm_clock* a;
  a->hours=clock.hours;
  a->minutes=clock.minutes;
  a->seconds=clock.seconds;
  a->am=clock.am;
  return *a; }

void am_pm_clock::toggle_am_pm()
{
if (am) am=false; else am=true;
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
if (seconds==60) {seconds=0; minutes++;
if (minutes==60) {minutes=0; hours++;
if (hours==12) {toggle_am_pm();}
if (hours==13) {hours=1;} }}
}

void am_pm_clock::advance_n_secs(unsigned int n)
{ int time;

if ((!am) && (hours<12)) {hours=hours+12;}
if ((am) && (hours==12)) {hours=0;}

time=hours*3600+minutes*60+seconds;

time=time+n;

hours=(time/3600);
minutes=((time-(hours*3600))/60);
seconds=(time%60);

if (hours>24) {hours=hours%24;}
if (hours>12) {hours=hours%12; am=false;} else am=true;
if (hours==0) {hours=12; am=true;}
}

unsigned int am_pm_clock::get_hours() const
{return hours;}

void am_pm_clock::set_hours(unsigned int hrs)
{ if ((hrs>12) || (hrs<1)) {
	throw 	std::invalid_argument("Please enter appropriate hours"); }
  hours=hrs; }

unsigned int am_pm_clock::get_minutes() const
{return minutes;}

void am_pm_clock::set_minutes(unsigned int mins)
{  if ((mins>59) || (mins<0)) {
	throw 	std::invalid_argument("Please enter appropriate minutes");
}

	minutes=mins; }

unsigned int am_pm_clock::get_seconds() const
{return seconds;}

void am_pm_clock::set_seconds(unsigned int secs)
{ if ((secs>59) || (secs<0)) {
	throw 	std::invalid_argument("Please enter appropriate seconds");
}
	seconds=secs; }

bool am_pm_clock::is_am() const
{return am;}

void am_pm_clock::set_am(bool am_val)
{am=am_val;}

am_pm_clock::~am_pm_clock()
{delete &hours;
delete &minutes;
delete &seconds;
delete &am;}




