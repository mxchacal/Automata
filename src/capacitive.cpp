#include "capacitive.h"

Capacitive::Capacitive() {
  pinMode(multiplexer_bit0, OUTPUT); // set up output pin for multiplexer address bus
  pinMode(multiplexer_bit1, OUTPUT); // set up output pin for multiplexer address bus
  pinMode(multiplexer_bit2, OUTPUT); // set up output pin for multiplexer address bus
  pinMode(multiplexer_bit3, OUTPUT); // set up output pin for multiplexer address bus
}

void Capacitive::update() {
  for(int multiplexer = 0; multiplexer < number_of_multiplexers; multiplexer ++) { // set up loop for number of multiplexers
    current_multiplexer = multiplexer_touchread_list[multiplexer]; // get the touch read pin for the current multiplexer
    for(int channel = 0; channel < number_of_channels; channel ++) { // set up loop for number of channels per multiplexer, and read from each channel
      digitalWriteFast(multiplexer_bit0, bitRead(channel, 0)); // set the output pin for multiplexer address bus for the current address
      digitalWriteFast(multiplexer_bit1, bitRead(channel, 1)); // set the output pin for multiplexer address bus for the current address
      digitalWriteFast(multiplexer_bit2, bitRead(channel, 2)); // set the output pin for multiplexer address bus for the current address
      digitalWriteFast(multiplexer_bit3, bitRead(channel, 3)); // set the output pin for multiplexer address bus for the current address
      current = constrain(map(touchRead(current_multiplexer), 1000, 5000, 0, 127), 0, 127); // adjust these bounds for a particular setup, capacitance
      if(current != states[(multiplexer * number_of_multiplexers) + channel]) {
        states[(multiplexer * number_of_multiplexers) + channel] = current;
        usbMIDI.sendControlChange(channel + 1, current, multiplexer + 1);
        delay(3);
      }
    }
  }
}
