#ifndef CAPACITIVE_H
#define CAPACITIVE_H
#include <Arduino.h>

class Capacitive {
public:
  Capacitive();
  void update();

private:
  uint8_t number_of_multiplexers = 1; // number of multiplexers to use (maximum 9)
  uint8_t number_of_channels = 16; // number of channels per multiplexer to use (maximum 16)
  uint8_t multiplexer_touchread_list[9] = { 23, 22, 19, 18, 17, 16, 15, 1, 0 };
  uint8_t current_multiplexer; // value to store the current touch read pin number
  uint8_t multiplexer_bit0 = 2; // pin number for multiplexer bit 0. assumes 4067 multiplexers
  uint8_t multiplexer_bit1 = 3; // pin number for multiplexer bit 1. assumes 4067 multiplexers
  uint8_t multiplexer_bit2 = 4; // pin number for multiplexer bit 2. assumes 4067 multiplexers
  uint8_t multiplexer_bit3 = 5; // pin number for multiplexer bit 3. assumes 4067 multiplexers
  byte states[256];   // storage for current state of an input i.e. is a note currently playing or not
  byte current;       // storage for current input
};

#endif
