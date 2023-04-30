#include "button.hpp"

Button::Button(BleKeyboard* keyboard, unsigned char pin, uint8_t button, uint8_t mode) : pin(pin), state(false), keyboard(keyboard), button(button)
{
    pinMode(this->pin, mode);
}

void Button::update()
{
    bool newState = digitalRead(this->pin);
    if (this->state == newState)
        return;
    this->state = newState;
    Serial.printf("Pin: %d, state: %d\n", this->pin, newState);

    if (newState)
        this->keyboard->press(this->button);
    else
        this->keyboard->release(this->button);
    delay(50);
}
