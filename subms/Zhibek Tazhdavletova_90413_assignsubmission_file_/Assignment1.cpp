#include "am_pm_clock.h"

am_pm_clock::am_pm_clock( ):
    hours{12},
    minutes{0},
    seconds{0},
    am{true}
{}
am_pm_clock::~am_pm_clock( )
{}
am_pm_clock::am_pm_clock( unsigned int hrs, unsigned int mins, unsigned int secs, bool am_val ):
    hours{hrs},
    minutes{mins},
    seconds{secs},
    am{am_val}
{}
am_pm_clock::am_pm_clock( const am_pm_clock &clock ):
    hours{clock.hours},
    minutes{clock.minutes},
    seconds{clock.seconds},
    am{clock.am}
{}
void am_pm_clock::toggle_am_pm( )
{}
