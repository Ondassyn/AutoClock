/*
 * am_pm_clock.cpp
 *
 *  Created on: 5 θών. 2019 γ.
 *      Author: Aser
 */

#include <iostream>

using namespace std;

#include "am_pm_clock.h"

int main(){

	am_pm_clock my_clock;
	do{
		my_clock.set_hours(my_clock.get_hours());
		my_clock.set_minutes(my_clock.get_minutes());
		my_clock.set_seconds(my_clock.get_seconds());
		my_clock.toggle_am_pm();
		my_clock.print(std::cout);
	
	} while (my_clock.get_hours()<=12);
	return 0;
}


