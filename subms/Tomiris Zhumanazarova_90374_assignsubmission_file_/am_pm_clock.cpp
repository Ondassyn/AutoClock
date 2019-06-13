#include <iostream>
#include "am_pm_clock.h"

int main() {
    am_pm_clock initial_time;
    std::cout << initial_time << "\n";

    if( initial_time.get_hours() = 12 )
        std::cout << "1. Getter for hours is correct\n";
    else
        std::cout << "1. Getter for hours is wrong\n" ;

    if( initial_time.get_minutes() = 0 )
        std::cout << "2. Getter for minutes is correct\n";
    else
        std::cout << "2. Getter for minutes is wrong\n";

    if( initial_time.get_seconds() = 0 )
        std::cout << "3. Getter for seconds is correct\n";
    else
        std::cout << "3. Getter for seconds is wrong\n";

    if( initial_time.is_am() = 1 )
        std::cout << "4. Getter for am is correct\n";
    else
        std::cout << "4. Getter for am is wrong\n";

    am_pm_clock set_time(5, 59, 59, 0);
    if(( set_time.get_hours()== 5 ) && (set_time.get_minutes() == 59) && (set_time.get_seconds() == 59) && (set_time.is_am() == 0 ))
        std::cout << "5. Constructor is correct\n";
    else
        std::cout << "5. Constructor is wrong\n";

    am_pm_clock copy_constructor = set_time;
    if(( copy_constructor.get_hours() == 5 ) && ( copy_constructor.get_minutes() == 59 ) && ( copy_constructor.get_seconds() == 59 ) && (copy_constructor.is_am() == 0 ))
        std::cout << "6. Copy constructor is correct\n";
    else
        std::cout << "6. Copy constructor is wrong\n";

    am_pm_clock assigned_operator;
    assigned_operator = initial_time;
        if(( assigned_operator.get_hours() == 12 ) && ( assigned_operator.get_minutes () == 0 ) && ( assigned_operator.get_seconds() == 0 ) && ( assigned_operator.is_am() == 1 ))
            std::cout << "7. Assignment operator is correct\n";
        else
            std::cout << "7. Assignment operator is wrong\n";

    assigned_operator.toggle_am_pm();
    initial_time.toggle_am_pm();
    set_time.toggle_am_pm();
        if(( assigned_operator.is_am() == 1 ) && ( initial_time.is_am() == 1 ) && set_time.is_am() == 0)
            std::cout << "8. Toggle am/pm value is correct\n";
        else
            std::cout << "8. Toggle am/pm value is wrong\n";

     assigned_operator.reset();
     initial_time.reset();
     set_time.reset();
        if(( assigned_operator.get_hours() == 12 ) && ( assigned_operator.get_minutes() == 0 ) && ( assigned_operator.get_seconds() == 0 ) && ( assigned_operator.is_am() == 1 ) && ( initial_time.get_hours() == 12 ) && ( initial_time.get_mintes() == 0 ) && ( initial_time.get_seconds() == 0 ) && (initial_time.is_am() == 1 ) && ( set_time.get_hours() == 12 ) && ( set_time.get_minutes() == 0 ) && ( set_time.get_seconds() == 0 ) && ( set_time.is_am() == 1 ))
            std::cout << "9. Reset to midnight is correct\n";
        else
            std::cout << "9. Reset to midnight is wrong\n";

        am_pm_clock clock1(11, 59, 59, 0);
        am_pm_clock clock2(3, 59, 59, 1);

        clock1.advance_one_sec();
        clock2.advance_one_sec();
            if(( clock1.get_hours() == 12 ) && ( clock1.get_minutes() == 0 ) && ( clock1.get_seconds() == 0 ) && ( clock1.is_am() == 1 ) && ( clock2.get_hours() == 1 ) && ( clock2.get_minutes() == 0 ) && ( clock2.get_seconds() == 0 ) && ( clock2.is_am() == 0 ))
            std::cout<< "10. Advance time by one second is correct\n";
            else
            std::cout<< "10. Advance time by one second is wrong\n";

        clock1.advance_n_secs(1);
        clock2.advance_n_secs(62);
            if(( clock1.get_hours() == 12 ) && ( clock1.get_minutes() == 0 ) && ( clock1.get_seconds() == 0 ) && (clock1.is_am() == 1) &&( clock2.get_hours() == 4 ) && ( clock2.get_minutes() == 1 ) && ( clock2.get_seconds() == 1 ) && ( clock2.is_am() == 1 ))
            std::cout<< "11. Advance time by n seconds is correct\n";
        else
            std::cout<< "11. Advance time by n seconds is wrong\n";

        clock1.set_am(0);
        clock2.set_am(0);
            if(( clock1.is_am() == 0 ) && ( clock2.is_am() == 0 ))
                std::cout << "12. Setter for am is correct\n";
            else
                std::cout << "12. Setter for am is wrong\n";

        clock1.set_hours(7);
        clock2.set_hours(13);
    if (clock2.set_hours > 12 || clock2.set_hours < 1 )
        throw std::invalid_argument("Hours are out of scope!!!");
    if(( clock1.get_hours() == 7 ) && ( clock2.get_hours() !== 13 ))
        std::cout << "13. Setter for hours is correct\n";
    else
        std::cout << "Setter for hours is wrong\n";

    clock1.set_minutes(4);
    clock2.set_minutes(-1);
    if (clock2.set_minutes < 1 || clock2.set_minutes>59)
        throw std::invalid_argument("Minutes are out of scope!!!");
    if(( clock1.get_minutes() == 4 ) && ( clock2.get_minutes() !== -1 ))
        std::cout << "14. Setter for minutes is correct\n";
    else
        std::cout << "14. Setter for minutes is wrong\n";

    clock1.set_seconds(30);
    clock2.set_seconds(114);
    if (clock2.set_seconds < 1 || clock2.set_seconds > 59)
        throw std::invalid_argument("Seconds are out of scope!!!");
    if(( clock1.get_seconds() == 30 ) && ( clock2.get_seconds() !== 114 ))
        std::cout << "15. Setter for seconds is correct\n";
    else
        std::cout << "15. Setter for seconds is wrong\n";


    try {
        am_pm_clock sample(17, 5, 5, 1);}
    catch(std::exception &error) {
        std::cout << "12. This constructor caught exception of hours!!!\n";
    }

    try {
        am_pm_clock sample(9, 74, 9, 1);}
    catch(std::exception &error) {
        std::cout << "13. This constructor caught exception of minutes!!!\n " ;
    }

    try {
        am_pm_clock sample(3, 13,  77, 1);}
    catch(std::exception &error) {
        std::cout << "14. This constructor caught exception of seconds!!!\n " ;
    }

    return 0;
}

