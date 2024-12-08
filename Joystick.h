#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include <Arduino.h>

class Joystick {
public:
    Joystick();
    int obtenirDirection();
};

#endif // JOYSTICK_H_
