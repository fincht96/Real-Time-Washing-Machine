#ifndef BUZZER_H
#define BUZZER_H

#include "board.h"
#include <stdint.h>

class Buzzer
{
    public:
        Buzzer(uint16_t buzzer_pin_addr, uint8_t port_addr, Board* const pBoard);
		
				// turns buzzer on
        void toggleOn() const;
		
				// turns buzzer off
        void toggleOff() const;

    private:
			
				// holds pin address of buzzer
				uint16_t m_buzzer_pin_addr;
		
				// holds port address of buzzer
				uint8_t m_port_addr;
		
				// holds reference to board object, used for low level interfacing
				Board* const m_pBoard;

};

#endif // BUZZER_H
