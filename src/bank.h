#ifndef BANK_H
#define BANK_H
#include <Arduino.h>
#include "automata.h"

struct Pattern {
  uint8_t   _note[MAX_NB_OF_STEPS];
  uint8_t   _velocity[MAX_NB_OF_STEPS];
  uint8_t   _rachett[MAX_NB_OF_STEPS];
  uint8_t   _gateLength[MAX_NB_OF_STEPS];
  uint8_t   _noteIncrement;
  uint8_t   _noteTarget;
  uint8_t   _playMode;
};

struct Bank {
  Pattern   _pattern[PATTERN_PER_BANK];
  uint8_t   _midiChannel;
  bool      _mute;
  uint8_t   _tempo;
  uint8_t   _clockSource;
  uint8_t   _activePattern;
  uint8_t   _nextPattern;
  uint8_t   _scale;
};

#endif

// sizeof(bank) = 33197
