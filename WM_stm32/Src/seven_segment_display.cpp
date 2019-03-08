#include "seven_segment_display.h"
#include "stm32f303_config_file.h"

SevenSegmentDisplay::SevenSegmentDisplay(uint16_t s7a_pin_addr, uint16_t s7b_pin_addr, uint16_t s7c_pin_addr, 
																				 uint16_t s7d_pin_addr, uint8_t port_addr, Board* const pBoard)
																				 
																				 
    : m_s7a_pin_addr(s7a_pin_addr), 
			m_s7b_pin_addr(s7b_pin_addr), 
			m_s7c_pin_addr(s7c_pin_addr), 
			m_s7d_pin_addr(s7d_pin_addr), 
			m_port_addr(port_addr), 
			m_pBoard(pBoard)

{
    this->writeValue(0);
}


void SevenSegmentDisplay::writeValue(const uint8_t val) const
{
	switch(val)
	{

	case 0:
		// set all bits low
		// clears the seven segment display
			m_pBoard->setGpioOdr(m_s7a_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7b_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7c_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7d_pin_addr, m_port_addr, LOW);
			break;

	case 1:
		// set 'A' bit high, all others low
			m_pBoard->setGpioOdr(m_s7a_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7b_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7c_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7d_pin_addr, m_port_addr, LOW);
			break;


	case 2:
			// set 'B' bit high, all others low
			m_pBoard->setGpioOdr(m_s7a_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7b_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7c_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7d_pin_addr, m_port_addr, LOW);
			break;

	case 3:
			// set 'A', 'B' high, all others low
			m_pBoard->setGpioOdr(m_s7a_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7b_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7c_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7d_pin_addr, m_port_addr, LOW);
			break;

	case 4:
			// set 'C' bit high, all others low
			m_pBoard->setGpioOdr(m_s7a_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7b_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7c_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7d_pin_addr, m_port_addr, LOW);
			break;

	case 5:
			// set 'C', 'A' high, all others low
			m_pBoard->setGpioOdr(m_s7a_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7b_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7c_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7d_pin_addr, m_port_addr, LOW);
			break;

	case 6:
			// set 'C', 'B' high, all others low
			m_pBoard->setGpioOdr(m_s7a_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7b_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7c_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7d_pin_addr, m_port_addr, LOW);
			break;


	case 7:
			// set 'A', 'B', 'C' high, all others low
			m_pBoard->setGpioOdr(m_s7a_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7b_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7c_pin_addr, m_port_addr, HIGH);
			m_pBoard->setGpioOdr(m_s7d_pin_addr, m_port_addr, LOW);
			break;

	case 8:
			// set 'D' high, all others low
			m_pBoard->setGpioOdr(m_s7a_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7b_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7c_pin_addr, m_port_addr, LOW);
			m_pBoard->setGpioOdr(m_s7d_pin_addr, m_port_addr, HIGH);
			break;


	default:
		break;

	}



}
