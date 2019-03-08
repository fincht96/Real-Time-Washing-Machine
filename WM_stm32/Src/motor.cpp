#include "motor.h"
#include "stm32f303_config_file.h"

Motor::Motor(uint16_t motor_control_pin_addr, uint16_t motor_direction_pin_addr, uint8_t port_addr, Board* const pBoard)
     : m_motor_control_pin_addr(motor_control_pin_addr), m_motor_direction_pin_addr(motor_direction_pin_addr), m_port_addr(port_addr), m_pBoard(pBoard)
{
    this->motorControlOff();
}




void Motor::motorControlOn() const
{
		m_pBoard->setGpioOdr(m_motor_control_pin_addr, m_port_addr, HIGH);
}

void Motor::motorControlOff() const
{
		m_pBoard->setGpioOdr(m_motor_control_pin_addr, m_port_addr, LOW);
}

void Motor::motorClockwise() const
{
		m_pBoard->setGpioOdr(m_motor_direction_pin_addr, m_port_addr, LOW);
}

void Motor::motorAntiClockwise() const
{
		m_pBoard->setGpioOdr(m_motor_direction_pin_addr, m_port_addr, HIGH);
}
