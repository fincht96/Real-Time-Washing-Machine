
#include "stm32f303_config_file.h"
#include "board.h"

/*
* File: board.cpp
* Title: Function definitions for the Board class implementing the addressing from the washing machine ports/pins to the user-defined board
* Version: 0.01
* Created: 28/01/2018
*
* Author: Thomas Finch
* Loughborough University
* Loughborough, LE11 3TU, UK
* Copyright Thomas Finch 2018*
*/

Board::Board() 
/* 
	---------------------------------------------------------------------------------------------------------
	Function Operation:
		- Constructor for the Board class, configures all the GPIO ports based off the specified base addresses.
	  It defaults the 1st and 2nd GPIO ports to output configuration & the 3rd GPIO port to input configuration.
	Arguments:
		- pin_addr: MOtor control pin address constant
		- port_addr: GPIO port address constant (either C, D or E for Bytronix board)
		- pin_state: Either a 0 or 1 to set output device HIGH or LOW
	Returns:
		- Nothing
	---------------------------------------------------------------------------------------------------------
	*/

{

    GPIO[0].base_addr = reinterpret_cast<volatile uint32_t*>(PORTC_BASE_ADDR);
    GPIO[0].mode = reinterpret_cast<volatile uint32_t*>(PORTC_BASE_ADDR);
    GPIO[0].speed = reinterpret_cast<volatile uint32_t*>(PORTC_BASE_ADDR + 0x08);
    GPIO[0].pull = reinterpret_cast<volatile uint32_t*>(PORTC_BASE_ADDR + 0x0C);
    GPIO[0].idr = reinterpret_cast<volatile uint16_t*>(PORTC_BASE_ADDR + 0x10);
    GPIO[0].odr = reinterpret_cast<volatile uint16_t*>(PORTC_BASE_ADDR + 0x14);


    GPIO[1].base_addr = reinterpret_cast<volatile uint32_t*>(PORTD_BASE_ADDR);
    GPIO[1].mode = reinterpret_cast<volatile uint32_t*>(PORTD_BASE_ADDR);
    GPIO[1].speed = reinterpret_cast<volatile uint32_t*>(PORTD_BASE_ADDR + 0x08);
    GPIO[1].pull = reinterpret_cast<volatile uint32_t*>(PORTD_BASE_ADDR + 0x0C);
    GPIO[1].idr = reinterpret_cast<volatile uint16_t*>(PORTD_BASE_ADDR+ 0x10);
    GPIO[1].odr = reinterpret_cast<volatile uint16_t*>(PORTD_BASE_ADDR + 0x14);


    GPIO[2].base_addr = reinterpret_cast<volatile uint32_t*>(PORTE_BASE_ADDR);
    GPIO[2].mode = reinterpret_cast<volatile uint32_t*>(PORTE_BASE_ADDR);
    GPIO[2].speed = reinterpret_cast<volatile uint32_t*>(PORTE_BASE_ADDR + 0x08);
    GPIO[2].pull = reinterpret_cast<volatile uint32_t*>(PORTE_BASE_ADDR + 0x0C);
    GPIO[2].idr = reinterpret_cast<volatile uint16_t*>(PORTE_BASE_ADDR + 0x10);
    GPIO[2].odr = reinterpret_cast<volatile uint16_t*>(PORTE_BASE_ADDR + 0x14);


    // sets GPIO[0] to output
    *(GPIO[0].mode) = static_cast<uint32_t>(0x55555555); // 0b01010101010101010101010101010101  00 = input, 01 = output
    *(GPIO[0].speed) = static_cast<uint32_t>(0xFFFFFFFF); // 0b11111111111111111111111111111111  11 - high speed output only
    *(GPIO[0].pull)  = static_cast<uint32_t>(0xAAAAAAAA); // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

    // sets GPIO[1] to output
    *(GPIO[1].mode) = static_cast<uint32_t>(0x55555555); // 0b01010101010101010101010101010101  00 = input, 01 = output
    *(GPIO[1].speed) = static_cast<uint32_t>(0xFFFFFFFF); // 0b11111111111111111111111111111111  11 - high speed output only
    *(GPIO[1].pull)  = static_cast<uint32_t>(0xAAAAAAAA); // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

    // sets GPIO[2] to input
   *(GPIO[2].mode) = static_cast<uint32_t>(0x00000000); // 0b00000000000000000000000000000000  00 = input, 01 = output
   *(GPIO[2].pull)  = static_cast<uint32_t>(0x55555555); // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

}



void Board::setGpioOdr(const uint16_t pin_addr, const uint8_t gpio_port_addr, const enum PinState pin_state) const
/* 
	---------------------------------------------------------------------------------------------------------
	Function Operation:
		- General function to set the output device on the specified pin either HIGH or LOW.
	Arguments:
		- pin_addr: Pin address constant
		- port_addr: GPIO port address constant (either C, D or E for Bytronix board)
		- pin_state: Either a 0 or 1 to set output device HIGH or LOW
	Returns:
		- Nothing
	---------------------------------------------------------------------------------------------------------
	*/
{
    if(pin_state == HIGH)
       *(GPIO[gpio_port_addr].odr) |= static_cast<uint16_t>(pin_addr);

    else if (pin_state == LOW)
       *(GPIO[gpio_port_addr].odr) &= ~(static_cast<uint16_t>(pin_addr));
}



enum PinState Board::getGpioIdr(const uint16_t pin_addr, const uint8_t gpio_port_addr) const 
/* 
	---------------------------------------------------------------------------------------------------------
	Function Operation:
		- General function to read the input device on the specified pin for a 1 or not. It returns a HIGH or LOW respectively.
	Arguments:
		- pin_addr: Pin address constant
		- gpio_port_addr: GPIO port address constant (either C, D or E for Bytronix board)
	Returns:
		- HIGH if pin state was read as 1
		- LOW if pin state was NOT read as 1 (e.g 0).
	---------------------------------------------------------------------------------------------------------
*/
{
    // holds the temporary state of pin read from
	bool temp;

	temp = *(GPIO[gpio_port_addr].idr) &= static_cast<uint16_t>(pin_addr);


	if(temp)
		return HIGH;

	else
		return LOW;


}

