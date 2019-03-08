#include "select_button3.h"
#include "stm32f303_config_file.h"

SelectButton3::SelectButton3()
{
		m_button_pin_addr = PROG_SEL3_PIN;
		m_port_addr = PORTE;
}
