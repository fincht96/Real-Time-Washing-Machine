#include "door_button.h"
#include "stm32f303_config_file.h"
#include "pin_state.h"


// constructor initialises the address pin and port of button
DoorButton::DoorButton(uint16_t button_pin_addr,  uint8_t port_addr, Board* const pBoard)
	: Button(button_pin_addr, port_addr, pBoard)
{
	
	
}


// overrides the getButtonState virtual function
ButtonState DoorButton::getButtonStatus() const
{
     // returns the state of button, either PRESSED or NOT_PRESSED
     if(m_pBoard->getGpioIdr(m_button_pin_addr, m_port_addr) == HIGH)
        return NOT_PRESSED;

     else if (m_pBoard->getGpioIdr(m_button_pin_addr, m_port_addr) == LOW)
        return PRESSED;

}
