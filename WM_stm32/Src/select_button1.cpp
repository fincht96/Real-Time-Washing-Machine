#include "select_button1.h"
#include "stm32f303_config_file.h"

SelectButton1::SelectButton1()
{
		m_button_pin_addr = PROG_SEL1_PIN;
		m_port_addr = PORTE;
}
