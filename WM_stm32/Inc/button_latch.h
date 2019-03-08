#ifndef BUTTON_LATCH_H
#define BUTTON_LATCH_H

#include <stdint.h>
#include "board.h"
#include "pin_state.h"


class ButtonLatch
{
    public:
        ButtonLatch(uint16_t latch_pin_addr, uint8_t port_addr, Board* const pBoard);
        ~ButtonLatch();
        void setLatch() const;
		void resetLatch() const;

    private:
        uint16_t m_latch_pin_addr;
				uint8_t m_port_addr;
				Board* const m_pBoard;

};

#endif // BUTTON_LATCH_H
