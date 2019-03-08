#ifndef TIMER_H
#define TIMER_H

#include "stdint.h"

// Timer class now utilises HAL_Delay to improve timing accuracy.
// **NOTE, uint32_t time parameter, passed to setTimer, must be divisible by
// TIME_INTERVAL (10), which can be found in timer_config_file.h


class Timer
{
    public:
        // assigns the m_num_intervals to 0
        Timer();

        // enables a timer to be set
        void setTimer(uint32_t time_milli);

        // returns the timer status and increments time duration, if timer has completed then returns true
        bool checkTimer();

    private:
        // temporary marker that holds the number of intervals required when timer is set
        uint32_t m_num_intervals;

};

#endif // TIMER_H
