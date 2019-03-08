#include "select_button2.h"
#include "stm32f303_config_file.h"

SelectButton2::SelectButton2()
{
    m_button_pin_addr = PROG_SEL2_PIN;
		m_port_addr = PORTE;
}
