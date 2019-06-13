#include "am_pm_clock.h"

am_pm_clock::am_pm_clock():
hours(12),
minutes(0),
seconds(0),
am(true)
{

}

am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
		unsigned int secs, bool am_val)

{
	hours=hrs;
	minutes=mins;
	seconds=secs;
	am=am_val;
}

am_pm_clock::am_pm_clock(const am_pm_clock &clock)
{
	hours=clock.hours;
	minutes=clock.minutes;
	seconds=clock.seconds;
	am=clock.am;
}

void am_pm_clock::advance_n_secs(unsigned int n)
{
	unsigned int remainder = 12*60*60 - get_hours()*3600-get_minutes()*60-get_seconds();

	if(remainder<n){
		set_am(!is_am());
	}

	int seconds = get_seconds();

	set_seconds((get_seconds()+n)%60);

	int minutes = get_minutes();

	set_minutes((get_minutes()+(n+seconds)/60)%60);

	set_hours((get_hours()+(minutes+(n+seconds)/60)/60)%12);

}

void am_pm_clock::advance_one_sec()
{
	set_seconds((get_seconds()+1)%60);
	if(get_seconds()==0){
		set_minutes((get_minutes()+1)%60);
		if(get_minutes()==0){
			set_hours((get_hours()+1)%12);
			if(get_hours()==12){
				set_am(!is_am());
			}
		}
	}
}

unsigned int am_pm_clock::get_hours() const
{
	return hours;
}

unsigned int am_pm_clock::get_minutes() const
{
	return minutes;
}

unsigned int am_pm_clock::get_seconds() const
{
	return seconds;
}

bool am_pm_clock::is_am() const
{
	return am;
}
//
//const am_pm_clock& am_pm_clock::operator = (const am_pm_clock& clock)
//{
//	hours=clock.hours;
//	minutes=clock.minutes;
//	seconds=clock.seconds;
//	am=clock.am;
//	return clock;
//}

void am_pm_clock::print(std::ostream& out) const
{
	char buff[11];
	sprintf(buff, "%02d:%02d:%02d%cm", hours, minutes, seconds,
			( am ? 'a' : 'p' ));
	out << buff;
}


void am_pm_clock::reset()
{
	hours=12;
	minutes=0;
	seconds=0;
	am=true;
}

void am_pm_clock::set_am(bool am_val)
{
	am=am_val;
}

void am_pm_clock::set_hours(unsigned int hrs)
{
	if(hrs>=1 && hrs<=12){
		hours=hrs;
	}else{
		hours=12; // by default
	}

}

void am_pm_clock::set_minutes(unsigned int mins)
{
	if(mins>=0 && mins<=59){
		minutes=mins;
	}else{
		minutes=0; // by default
	}
}

void am_pm_clock::set_seconds(unsigned int secs)
{
	if(secs>=0 && secs<=59){
		seconds=secs;
	}else{
		seconds=0; // by default
	}
}

void am_pm_clock::toggle_am_pm()
{
	if(hours==11&&minutes==59&&seconds==59){
		am=!am;
	}
}

std::ostream& operator << (std::ostream& out, const am_pm_clock& clock);

am_pm_clock::~am_pm_clock() {}
