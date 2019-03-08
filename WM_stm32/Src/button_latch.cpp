#include "button_latch.h"
#include "stm32f303_config_file.h"
#include "pin_state.h"

ButtonLatch::ButtonLatch(uint16_t latch_pin_addr, uint8_t port_addr, Board* const pBoard)
    : m_latch_pin_addr(latch_pin_addr), m_port_addr(port_addr), m_pBoard(pBoard)
{

    this->resetLatch();
}


ButtonLatch::~ButtonLatch()
{
}


void ButtonLatch::setLatch() const
{
		m_pBoard->setGpioOdr(m_latch_pin_addr, m_port_addr, HIGH);
}


void ButtonLatch::resetLatch() const
{
		m_pBoard->setGpioOdr(m_latch_pin_addr, m_port_addr, LOW);
}
