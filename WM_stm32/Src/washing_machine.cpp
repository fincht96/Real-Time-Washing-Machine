
#include "stm32f303_config_file.h"
#include "washing_machine.h"


WashingMachine::WashingMachine()
	: 
		m_accept_button(ACCEPT_PIN, PORTE, &m_board),
		m_cancel_button(CANCEL_PIN, PORTE, &m_board),
		m_sel_1(PROG_SEL1_PIN, PORTE, &m_board),
		m_sel_2(PROG_SEL2_PIN, PORTE, &m_board), 
		m_sel_3(PROG_SEL3_PIN, PORTE, &m_board),
		m_door(DOOR_PIN, PORTE, &m_board),
		
		m_motor(MOTOR_CONTROL_PIN, MOTOR_DIRECTION_PIN, PORTD, &m_board), 
		m_buzzer(BUZZER_PIN, PORTC, &m_board), 
		m_seg(S7A_PIN, S7B_PIN, S7C_PIN, S7D_PIN, PORTD, &m_board), 
		m_latch(LATCH_PIN, PORTD, &m_board),
		
		
		
		m_program(&m_seg, &m_motor, &m_timer),
		m_program_manager(&m_program),
		m_sys(&m_program, &m_program_manager, &m_timer, &m_accept_button, &m_cancel_button,
					&m_sel_1, &m_sel_2, &m_sel_3, &m_door, &m_buzzer, &m_latch, &m_seg)
		
{
		
}




