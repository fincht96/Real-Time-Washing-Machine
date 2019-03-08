#include "program.h"
#include "stage_type.h"
#include "stdint.h"
#include "stage_item.h"



// NOTE PROGRAM HANGS ON FINSISHED(COMPLETE) DISPLAYING 8 ON SEVEN SEG


Program::Program(SevenSegmentDisplay* const pSeven_seg, Motor* const pMotor, Timer* const pTimer)
{

		// configures pointers to peripherals for the stage items
		for(int i = 0; i < STAGE_LIST_SIZE; i++)
		{
				m_stage[i].setDisplayPointer(pSeven_seg);
				m_stage[i].setMotorPointer(pMotor);
				m_stage[i].setTimerPointer(pTimer);
		}
	
	
	
		// resets the array index
		m_array_index = 0;
	
    // by default current stage is set to 0
    m_current_selected_stage = 0;

    // by default when program object is created, sets program state to not running
    m_program_state = PROGRAM_NOT_RUNNING;
	
}


void Program::setState(enum ProgramState state)
{
			
	
    // sets the program state to specified state
    m_program_state = state;
	
	
		// checks if currently selected stage has finsihed
		if( m_stage[m_current_selected_stage].getStageState() ==  STAGE_FINISHED)
		{
				// if so, increments the currently selected stage
				++m_current_selected_stage;
		}
	
		// checks if currently selected stage is outside the scope of program
		if(m_current_selected_stage >= m_array_index)
		{
				// if so, program state is set to finshed
				m_program_state = PROGRAM_FINISHED;
			
		}
		
	
		switch(m_program_state)
		{
				case PROGRAM_NOT_RUNNING:
						// does nothing
            break;
			
				
				case PROGRAM_RUNNING:
            // runs the selected stage
            m_stage[m_current_selected_stage].run();
            break;
				
				case PROGRAM_PAUSED:
            // does nothing
            break;


        case PROGRAM_SUSPENDED:
             // does nothing
             break;

        case PROGRAM_FINISHED:
							reset();
              break;
			
		}
		
		
		

}


enum ProgramState Program::getState() const
{
     // returns current state of program
    return m_program_state;
}


void Program::reset()
{
    // sets program state to not running
    m_program_state = PROGRAM_NOT_RUNNING;

    // resets the array index
    m_array_index = 0;
			
		// resets the currently selected stage
		m_current_selected_stage = 0;

}


void Program::incrementSelectedStage()
{
    // increments the currently selected stage
    ++m_current_selected_stage;
}


void Program::addStage(enum StageType type, uint32_t duration)
{
		// converts duration into milliseconds
		duration = (duration * 1000);
	
		// if array is already full, does nothing
		if(m_array_index >= STAGE_LIST_SIZE)
		{
				return;
		}
	
		
		// updates the information in stages in array
		m_stage[m_array_index].setType(type);
		m_stage[m_array_index].setDuration(duration);
	
	
		// increments the array index 
		++m_array_index;
		
}






