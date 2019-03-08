
#include "buzzer.h"
#include "stm32f303_config_file.h"
#include "pin_state.h"

Buzzer::Buzzer(uint16_t buzzer_pin_addr, uint8_t port_addr, Board* const pBoard)
    : m_buzzer_pin_addr(buzzer_pin_addr), m_port_addr(port_addr), m_pBoard(pBoard)
{
    this->toggleOff();
}

void Buzzer::toggleOn() const
{
    m_pBoard->setGpioOdr(m_buzzer_pin_addr, m_port_addr, HIGH);
}

void Buzzer::toggleOff() const
{
    m_pBoard->setGpioOdr(m_buzzer_pin_addr, m_port_addr, LOW);
}
