#ifndef MEMORIAE_H
#define MEMORIAE_H
#include "bank.h"
#include "automata.h"

class Memoriae
{
public:
  Memoriae(){};
  void init();
  void loadLastState();

  int  getNote(int bank, int pattern, int step);
  void setNote(int bank, int pattern, int step, int value);
  int  getGate(int bank, int pattern, int step);
  void setGate(int bank, int pattern, int step, int gate);
  int  getRachett(int bank, int pattern, int step);
  void setRachett(int bank, int pattern, int step, int rachett);
  int  getMidiChannel(int bank);
  void setMidiChannel(int bank, int midiChannel);
  int  getActivePattern(int bank);
  void setActivePattern(int bank, int pattern);
  void loadPattern(int bank, int pattern) {}
  void savePattern(int bank, int pattern) {}
  void setScale(int bank, int scale) {}

  void setGlide(int bank, int pattern, int step, int glide);
  void updateGlide(int bank);

private:
  Bank  _bank[NB_OF_BANKS];
  int _glide[NB_OF_BANKS], _noteIncrement[NB_OF_BANKS], _note[NB_OF_BANKS], noteTarget[NB_OF_BANKS];
};

#endif
