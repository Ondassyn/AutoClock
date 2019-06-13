#include <iostream>
#include "am_pm_clock.h"
 
int tests_run = 0;
int tests_correct = 0;

bool equalStr(const std::string& s1, const std::string& s2){
	if(s1.size() != s2.size()) return false;
	for(int i = 0; i < s1.size(); i++)
		if(tolower(s1[i]) != tolower(s2[i])) return false;
	return true;
}

void checkString( const std::string s, const std::string&  given, const std::string& correct )
{
   tests_run++;	
   if( !equalStr(given, correct) )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkBool( const std::string s, const bool&  given, const bool& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkSizet( const std::string s, const size_t&  given, const size_t& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

int main(){
	std::string message = "DEFAULT CONSTRUCTOR";	
	am_pm_clock defc;
	
	checkSizet(message, defc.get_hours(), 12);
	checkSizet(message, defc.get_minutes(), 0);
	checkSizet(message, defc.get_seconds(), 0);
	checkBool(message, defc.is_am(), true);
	
	message = "ARGUMENT CONSTRUCTOR";
	am_pm_clock argc{3, 58, 59, false};
	
	checkSizet(message, argc.get_hours(), 3);
	checkSizet(message, argc.get_minutes(), 58);
	checkSizet(message, argc.get_seconds(), 59);
	checkBool(message, argc.is_am(), false);

	message = "COPY CONSTRUCTOR";
	am_pm_clock copyc = argc;

	checkSizet(message, copyc.get_hours(), 3);
	checkSizet(message, copyc.get_minutes(), 58);
	checkSizet(message, copyc.get_seconds(), 59);
	checkBool(message, copyc.is_am(), false);
	
	message = "SETTERS";
	defc.set_hours(1);
	checkSizet(message, defc.get_hours(), 1);
	defc.set_minutes(2);	
	checkSizet(message, defc.get_minutes(), 2);
	defc.set_seconds(3);	
	checkSizet(message, defc.get_seconds(), 3);
	
	try {
		tests_run++;
		defc.set_hours(0);
		std::cout << "~INCORRECT " << message << " : EXCEPTION HAS NOT BEEN CAUGHT\n";
	} catch (const std::invalid_argument& e ) {
		tests_correct++;
		std::cout << "~CORRECT " << message << " : EXCEPTION HAS BEEN CAUGHT\n";	
	}

	try {
		tests_run++;
		defc.set_hours(13);
		std::cout << "~INCORRECT " << message << " : EXCEPTION HAS NOT BEEN CAUGHT\n";
	} catch (const std::invalid_argument& e ) {
		tests_correct++;
		std::cout << "~CORRECT " << message << " : EXCEPTION HAS BEEN CAUGHT\n";	
	}

	/*try {
		tests_run++;
		defc.set_minutes(-1);
		std::cout << "~INCORRECT " << message << " : EXCEPTION HAS NOT BEEN CAUGHT\n";
	} catch (const std::invalid_argument& e ) {
		tests_correct++;
		std::cout << "~CORRECT " << message << " : EXCEPTION HAS BEEN CAUGHT\n";	
	}*/

	try {
		tests_run++;
		defc.set_minutes(60);
		std::cout << "~INCORRECT " << message << " : EXCEPTION HAS NOT BEEN CAUGHT\n";
	} catch (const std::invalid_argument& e ) {
		tests_correct++;
		std::cout << "~CORRECT " << message << " : EXCEPTION HAS BEEN CAUGHT\n";	
	}

	/*
	try {
		tests_run++;
		defc.set_seconds(-1);
		std::cout << "~INCORRECT " << message << " : EXCEPTION HAS NOT BEEN CAUGHT\n";
	} catch (const std::invalid_argument& e ) {
		tests_correct++;
		std::cout << "~CORRECT " << message << " : EXCEPTION HAS BEEN CAUGHT\n";	
	}*/

	try {
		tests_run++;
		defc.set_seconds(60);
		std::cout << "~INCORRECT " << message << " : EXCEPTION HAS NOT BEEN CAUGHT\n";
	} catch (const std::invalid_argument& e ) {
		tests_correct++;
		std::cout << "~CORRECT " << message << " : EXCEPTION HAS BEEN CAUGHT\n";	
	}

	message = "RESET";
	defc.reset();
	
	checkSizet(message, defc.get_hours(), 12);
	checkSizet(message, defc.get_minutes(), 0);
	checkSizet(message, defc.get_seconds(), 0);
	checkBool(message, defc.is_am(), true);
	
	message = "ASSIGNMENT";
	defc = copyc;
	
	checkSizet(message, defc.get_hours(), 3);
	checkSizet(message, defc.get_minutes(), 58);
	checkSizet(message, defc.get_seconds(), 59);
	checkBool(message, defc.is_am(), false);

	message = "TOGGLE";
	defc.toggle_am_pm();
	checkBool(message, defc.is_am(), true);
	defc.toggle_am_pm();
	checkBool(message, defc.is_am(), false);

	message = "ADVANCE ONE SECOND";
	defc.reset();
	defc.advance_one_sec();
	checkSizet(message, defc.get_hours(), 12);
	checkSizet(message, defc.get_minutes(), 0);
	checkSizet(message, defc.get_seconds(), 1);
	checkBool(message, defc.is_am(), true);	

	argc.advance_one_sec();
	checkSizet(message, argc.get_hours(), 3);
	checkSizet(message, argc.get_minutes(), 59);
	checkSizet(message, argc.get_seconds(), 00);
	checkBool(message, argc.is_am(), false);
	
	am_pm_clock annoyc(12, 59, 59, true);
	annoyc.advance_one_sec();		
	checkSizet(message, annoyc.get_hours(), 1);
	checkSizet(message, annoyc.get_minutes(), 00);
	checkSizet(message, annoyc.get_seconds(), 00);
	checkBool(message, annoyc.is_am(), true);
	
	message = "ADVANCE N SECONDS";
	defc.advance_n_secs(1);
	checkSizet(message, defc.get_hours(), 12);
	checkSizet(message, defc.get_minutes(), 0);
	checkSizet(message, defc.get_seconds(), 2);
	checkBool(message, defc.is_am(), true);	
	
	copyc.advance_n_secs(43262);
	checkSizet(message, copyc.get_hours(), 4);
	checkSizet(message, copyc.get_minutes(), 0);
	checkSizet(message, copyc.get_seconds(), 1);
	checkBool(message, copyc.is_am(), true);	

	annoyc.advance_n_secs(654321);
	checkSizet(message, annoyc.get_hours(), 2);
	checkSizet(message, annoyc.get_minutes(), 45);
	checkSizet(message, annoyc.get_seconds(), 21);
	checkBool(message, annoyc.is_am(), false);

	std::cout << "\nTESTS RUN: " << tests_run << std::endl;
	std::cout << "\nTESTS CORRECT: " << tests_correct << std::endl;		
	return 0;
}
