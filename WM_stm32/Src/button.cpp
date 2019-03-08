#include "button.h"
#include "stm32f303_config_file.h"
#include "pin_state.h"

Button::Button(uint16_t button_pin_addr,  uint8_t port_addr, Board* const pBoard)
	:	m_button_pin_addr(button_pin_addr), m_port_addr(port_addr), m_pBoard(pBoard)
{

}


ButtonState Button::getButtonStatus() const
{
     if(m_pBoard->getGpioIdr(m_button_pin_addr, m_port_addr) == HIGH)
        return PRESSED;

     else if (m_pBoard->getGpioIdr(m_button_pin_addr, m_port_addr) == LOW)
        return NOT_PRESSED;
}
