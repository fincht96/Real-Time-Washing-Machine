#ifndef DOOR_BUTTON_H
#define DOOR_BUTTON_H
#include "button.h"

// Class is unique from Button object as the default pin and port addresses are different and virtual function is
// overwritten

class DoorButton : public Button
{
    public:
        DoorButton(uint16_t button_pin_addr,  uint8_t port_addr, Board* const pBoard);

        // overrides the virtual getButtonState() function in Button class
        virtual enum ButtonState getButtonStatus() const;

};

#endif // DOOR_BUTTON_H
