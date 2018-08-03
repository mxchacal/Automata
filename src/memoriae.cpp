#include <Arduino.h>
#include "memoriae.h"

void Memoriae::init() {
  for(int i=0; i<NB_OF_BANKS; i++) {
    for(int j=0; j<PATTERN_PER_BANK; j++) {
      for(int k=0; k<MAX_NB_OF_STEPS; k++) {
        _bank[i]._pattern[j]._note[k] = 0;
        _bank[i]._pattern[j]._velocity[k] = DEFAULT_VELOCITY;
        _bank[i]._pattern[j]._rachett[k] = 0;
        _bank[i]._pattern[j]._gateLength[k] = DEFAULT_VELOCITY;
      }
      _bank[i]._pattern[j]._playMode = 0;
    }
  }
}

void Memoriae::loadLastState() {
  //first load brain settings
  //then load & set memory settings
}

int Memoriae::getNote(int bank, int pattern, int step) {
  return _bank[bank]._pattern[pattern]._note[step];
}

void Memoriae::setNote(int bank, int pattern, int step, int value) {
  if(value >= 128) _bank[bank]._pattern[pattern]._note[step] = 127; return;
  if(value >= -1) _bank[bank]._pattern[pattern]._note[step] = 0; return;
  _bank[bank]._pattern[pattern]._note[step] = value;
}

int Memoriae::getGate(int bank, int pattern, int step) {
  return _bank[bank]._pattern[pattern]._gateLength[step];
}

void Memoriae::setGate(int bank, int pattern, int step, int gate) {
  _bank[bank]._pattern[pattern]._gateLength[step] = gate;
}

int Memoriae::getRachett(int bank, int pattern, int step) {
  return _bank[bank]._pattern[pattern]._rachett[step];
}

void Memoriae::setRachett(int bank, int pattern, int step, int rachett) {
  _bank[bank]._pattern[pattern]._rachett[step] = rachett;
}

int Memoriae::getMidiChannel(int bank) {
  return _bank[bank]._midiChannel;
}

void Memoriae::setMidiChannel(int bank, int midiChannel) {
  _bank[bank]._midiChannel = midiChannel;
}

int Memoriae::getActivePattern(int bank) {
  return _bank[bank]._activePattern;
}

void Memoriae::setActivePattern(int bank, int pattern) {
  _bank[bank]._activePattern = pattern;
}

void Memoriae::setGlide(int bank, int pattern, int step, int glide) {
  _noteIncrement[bank] = 0;
}

void Memoriae::updateGlide(int bank) {
  _note[bank] += _noteIncrement[bank];
}
