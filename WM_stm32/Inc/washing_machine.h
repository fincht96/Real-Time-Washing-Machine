#ifndef WASHING_MACHINE_H
#define WASHING_MACHINE_H

#include "stdint.h"
#include "stm32f303_config_file.h"
#include "board.h"
#include "motor.h"
#include "button.h"
#include "button_latch.h"
#include "door_button.h"
#include "seven_segment_display.h"
#include "timer.h"
#include "buzzer.h"
#include "stage.h"
#include "program.h"
#include "program_manager.h"
#include "system_operator.h"

class WashingMachine
{
	public:	
		WashingMachine();
		
	
	
	private:
		
	
	
		// low level hardware interface
		Board m_board;
	
		// inputs
		Button m_accept_button;
		Button m_cancel_button;
		Button m_sel_1;
		Button m_sel_2;
		Button m_sel_3;
		DoorButton m_door;
	
		// outputs
		Motor m_motor;
		Buzzer m_buzzer;
		SevenSegmentDisplay m_seg;
	
		// control
		Timer m_timer;
		ButtonLatch m_latch;
	
		// program management
		Program m_program;
		ProgramManager m_program_manager;
		SystemOperator m_sys;
	
};









#endif
