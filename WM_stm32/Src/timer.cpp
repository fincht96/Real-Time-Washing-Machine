#include "timer.h"
#include "timer_config_file.h"

// hardware abstraction layer header file, used to implement HAL_Delay function
#include "stm32f3xx_hal.h"



Timer::Timer()
{
    // resets the number of time intervals
    m_num_intervals = 0;
}

void Timer::setTimer(uint32_t time_milli)
{
    // sets the number of time intervals required
    m_num_intervals = (time_milli/TIME_INTERVAL);
}


bool Timer::checkTimer()
{
    // delay for time interval
    HAL_Delay(TIME_INTERVAL);

    // decrements the number of time intervals left
    --m_num_intervals;

    // checks if number of time intervals has reached 0
    if(m_num_intervals == 0)
    {
        return true;
    }

    // if not finished return false
    return false;
}








