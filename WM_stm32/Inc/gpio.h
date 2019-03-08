#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

#include <stdint.h>

struct GPIO
{
    volatile uint32_t* base_addr;
    volatile uint32_t* mode;
    volatile uint32_t* speed;
    volatile uint32_t* pull;
    volatile uint16_t* idr;
    volatile uint16_t* odr;
};


#endif // GPIO_H_INCLUDED
