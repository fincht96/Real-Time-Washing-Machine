#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include "button_state.h"
#include "board.h"

class Button
{
    public:
		    
        Button(uint16_t button_pin_addr,  uint8_t port_addr, Board* const pBoard);	
		
        // returns whether button is pressed or not pressed
        virtual enum ButtonState getButtonStatus() const;


    protected:

        // holds the button pin address
        uint16_t m_button_pin_addr;

        // holds the port address
        uint8_t m_port_addr;

        // holds a board object pointer
        Board* const m_pBoard;


};

#endif // BUTTON_H
