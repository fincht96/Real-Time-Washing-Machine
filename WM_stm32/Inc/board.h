
//********************************************************************************************************
// Board class
//
// Holds the GPIO ports and allows, indirectly through member functions, interaction with registers on the
// microcontroller.



#ifndef BOARD_H
#define BOARD_H



#include <stdint.h>
#include "pin_state.h"


// specifies number of ports utilised in Board class
#define PORTS_MAX 3

class Board
{

	public:
		// constructor initializes the pointers for ports
		Board();

        // sets the state of a specified pin on a specified port
        void setGpioOdr(const uint16_t, const uint8_t, const enum PinState) const;								

        // returns the state of a specified pin on a specified port
        enum PinState getGpioIdr(const uint16_t, const uint8_t) const;

	private:
				
				// struct holds pointers to registers associated with each port
				struct GPIO
				{
					volatile uint32_t* base_addr;
					volatile uint32_t* mode;
					volatile uint32_t* speed;
					volatile uint32_t* pull;
					volatile uint16_t* idr;
					volatile uint16_t* odr;
				};

				// GPIO[0]: connected to output peripherals
				// GPIO[1]: connected to output peripherals
				// GPIO[2]: connected to input peripherals
				struct GPIO GPIO[PORTS_MAX];

};



#endif


