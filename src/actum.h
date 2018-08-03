#ifndef ACTUM_H
#define ACTUM_H
#include "memoriae.h"
#include "automata.h"
#include <ShiftRegister74HC595.h>
#include <mcp4728.h>

class Actum
{
public:
  Actum();
  void init();
  void update(Memoriae& data, int midiChannel, int bank, int note, int velocity, bool gate, bool lastGate);
};

#endif
