#include "stage.h"
#include "mark_space_ratio.h"
#include "stage_config.h"
#include "stage_type.h"


Stage::Stage()
{
	
		m_pSeven_seg = 0;
		m_pMotor = 0;
		m_pTimer = 0;
	
    // sets default state of stage
    m_state = STAGE_INCOMPLETE;
		
    // resets the stage duration so far
    m_stage_duration = 0;
}




void Stage::run()
{
		
	
	
		// executes appropriate function based on stage type
    switch(m_type)
    {
        case WASH_SLOW:
						m_pSeven_seg->writeValue(4);
				
            // set motor direction
            m_pMotor->motorAntiClockwise();

            // turn motor on
            m_pMotor->motorControlOn();

            // sets a timer
            m_pTimer->setTimer(static_cast<uint32_t>(INTERVAL_PERIOD*MARK));

            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }

            // turns motor off
            m_pMotor->motorControlOff();

            // sets a timer
            m_pTimer->setTimer(INTERVAL_PERIOD*SPACE);


            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }


            break;


        case WASH_HIGH:
						m_pSeven_seg->writeValue(4);
				
            m_pMotor->motorAntiClockwise();
            m_pMotor->motorControlOn();
            m_pTimer->setTimer(static_cast<uint32_t>(INTERVAL_PERIOD));

            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }


            m_pMotor->motorControlOff();
            break;




        case RINSE_SLOW:
						m_pSeven_seg->writeValue(5);
				
            m_pMotor->motorClockwise();
            m_pMotor->motorControlOn();

            // sets a timer
            m_pTimer->setTimer(INTERVAL_PERIOD*MARK);

            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }

            // turns motor off
            m_pMotor->motorControlOff();

            // sets a timer
            m_pTimer->setTimer(static_cast<uint32_t>(INTERVAL_PERIOD*SPACE));


            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }
            break;

        case RINSE_HIGH:
						m_pSeven_seg->writeValue(5);
				
            m_pMotor->motorClockwise();
            m_pMotor->motorControlOn();

            m_pTimer->setTimer(static_cast<uint32_t>(INTERVAL_PERIOD));

            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }


            m_pMotor->motorControlOff();
            break;

        case EMPTY:
						 m_pSeven_seg->writeValue(1);
				
             m_pTimer->setTimer(static_cast<uint32_t>(INTERVAL_PERIOD));

            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }
            break;

        case DRY:
						 m_pSeven_seg->writeValue(7);
				
             m_pTimer->setTimer(static_cast<uint32_t>(INTERVAL_PERIOD));

            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }
            break;

        case FILL:
						
						m_pSeven_seg->writeValue(2);
				
            m_pTimer->setTimer(static_cast<uint32_t>(INTERVAL_PERIOD));

            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }
            break;

        case HEAT:
						m_pSeven_seg->writeValue(3);
				
            m_pTimer->setTimer(static_cast<uint32_t>(INTERVAL_PERIOD));

            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }
            break;


        case COMPLETE:
						m_pSeven_seg->writeValue(8);
				
            m_pTimer->setTimer(static_cast<uint32_t>(INTERVAL_PERIOD));

            // waits until timer is complete
            while(m_pTimer->checkTimer() == false)
            {
                // does nothing....
            }
            break;
						
						
    }
	
		
		// subtracts 50 ms from stage duration
		m_stage_duration = m_stage_duration - 50;
		
		// if time duration is 0 or less, stage has finished
		if(m_stage_duration <= 0)
		{
				// sets stage state to finished
				m_state = STAGE_FINISHED;
			
				// sets the stage duration to 0
				m_stage_duration = 0;
			
		}
		
}


enum StageState Stage::getStageState() const
{
    return m_state;
}






void Stage::setType(enum StageType type)
{
		m_type = type;
		m_state = STAGE_INCOMPLETE;
}



void Stage::setDuration(uint32_t stage_duration)
{
		m_stage_duration = stage_duration;
		m_state = STAGE_INCOMPLETE;
}






void Stage::setDisplayPointer(SevenSegmentDisplay* const pSeven_seg)
{
		m_pSeven_seg = pSeven_seg;
}



void Stage::setMotorPointer(Motor* const pMotor)
{
		m_pMotor = pMotor;
}





void Stage::setTimerPointer(Timer* const pTimer)
{
		m_pTimer = pTimer;
}	















