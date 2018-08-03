#include "tempus.h"
#include "automata.h"
#include <Arduino.h>

Tempus::Tempus() {}

void Tempus::launch() {
  _bpm = 90;
  _running = 0;
  _tick = 0;
  _tock = 0;
  _toe = 0;
  _interval = 1000 / _bpm / PPQN; // 1sec / bpm / resolution
  _running = 1;
  _beacon = millis();
}

void Tempus::update() {
  if(millis() - _beacon >= _interval) {
    _beacon = millis();
    _count +=1;
    _tick = 1;
  }
  if(_count == PPQN) {
    _count = 0;
    _tock = 1;
  }
  if(millis() - _beacon >= 10) _toe = 1;
}

void Tempus::setTempo(int tempo) {
  if(tempo >= MAX_BPM) {
    _bpm = 3000;
    return;
  }
  if(tempo <= MIN_BPM) {
    _bpm = 20;
    return;
  }
  _bpm = tempo;
}

int Tempus::getCount() {
  return _count;
}
bool Tempus::newTick() {
  if(_tick) {
    return 1;
    _tick = 0;
  }
  return 0;
}

bool Tempus::newTock() {
  if(_tock) {
    return 1;
    _tock = 0;
  }
  return 0;
}

bool Tempus::newToe() {
  if(_toe) {
    return 1;
    _toe = 0;
  }
  return 0;
}
