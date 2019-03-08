#ifndef SEVEN_SEGMENT_DISPLAY_H
#define SEVEN_SEGMENT_DISPLAY_H


#include "board.h"
#include <stdint.h>
#include "pin_state.h"

class SevenSegmentDisplay
{
    public:
        // initialises the pin and port addresses
        SevenSegmentDisplay(uint16_t s7a_pin_addr, uint16_t s7b_pin_addr, uint16_t s7c_pin_addr, 
														uint16_t s7d_pin_addr, uint8_t port_addr, Board* const pBoard);


        // writes value to seven segment display
        void writeValue(const uint8_t) const;


	private:
        // holds the pin addresses of seven segment display
        uint16_t m_s7a_pin_addr;
        uint16_t m_s7b_pin_addr;
        uint16_t m_s7c_pin_addr;
        uint16_t m_s7d_pin_addr;

        // holds the port address
        uint8_t m_port_addr;


        // holds a board object
        Board* const m_pBoard;


};

#endif // SEVEN_SEGMENT_DISPLAY_H
