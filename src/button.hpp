#include <Arduino.h>
#include <BleKeyboard.h>

class Button
{
public:
    Button(BleKeyboard*, unsigned char pin, uint8_t button, uint8_t mode);
    void update();

private:
    BleKeyboard* keyboard;
    bool state;
    uint8_t button;
    unsigned char pin;
};
