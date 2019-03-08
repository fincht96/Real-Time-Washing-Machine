#ifndef MOTOR_H
#define MOTOR_H

#include "pin_state.h"
#include "board.h"

class Motor
{
    public:
        Motor(uint16_t motor_control_pin_addr, uint16_t motor_direction_pin_addr, uint8_t port_addr, Board* const pBoard);

        void motorControlOn() const;
        void motorControlOff() const;
        void motorClockwise() const;
        void motorAntiClockwise() const;


    private:
			// holds the pin map address for motor control
			uint16_t m_motor_control_pin_addr;

			// holds the pin map address for motor direction
			uint16_t m_motor_direction_pin_addr;

			// holds the port address
			uint8_t m_port_addr;


			// holds a board object
			Board* const m_pBoard;


};

#endif // MOTOR_H
