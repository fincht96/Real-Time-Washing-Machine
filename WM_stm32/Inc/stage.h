#ifndef STAGE_H
#define STAGE_H

#include "stdint.h"
#include "stage_type.h"
#include "stage_state.h"
#include "motor.h"
#include "seven_segment_display.h"
#include "timer.h"


class Stage
{
    public:
			
				// STAGE FUNCTIONALITY
				// ===================
		
				// each stage requires references to output devices
        Stage();

        // member function will execute stage functionality 
        void run();

        // member function returns the state of the stage
        enum StageState getStageState() const;

				
				// STATE CONFIGURATION
				// ===================
		
				void setType(enum StageType type);
				void setDuration(uint32_t stage_duration);
		
		
			
				// POINTER SETTERS
				// ===============
		
				void setDisplayPointer(SevenSegmentDisplay* const pSeven_seg);
				void setMotorPointer(Motor* const pMotor);
				void setTimerPointer(Timer* const pMotor);
		
		
		
    private:

        // STAGE ATTRIBUTES
        // ================

				StageType m_type;
        StageState m_state;
        int32_t m_stage_duration;



        // OUTPUT PERIPHERALS
        // ==================

        SevenSegmentDisplay* m_pSeven_seg;
        Motor* m_pMotor;



        // TIMING MANAGEMENT
        // =================

        // holds a timer object
        Timer* m_pTimer;





};



#endif // STAGE_H
