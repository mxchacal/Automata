#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include <Arduino.h>
#include "automata.h"
#include "sensibus.h"
#include "memoriae.h"
#include "actum.h"
#include "tempus.h"
#include "debug.h"

class Conductor {
public:
  Conductor();
  void    init(Memoriae& memory, Sensibus& sense, Actum& out);
  void    update(Memoriae& memory, Sensibus& sense, Actum& out, Tempus& clock);
  void    handleButtons(Memoriae& memory, Sensibus& sense, int button, bool buttonPressed);
  void    doPageFunction(Memoriae& memory, int button);
  void    doDefaultFunction(int function);
  void    doFunction(Memoriae& memory, int value, int function);

private:
  int  _index;
  int  _updateRate;
  int  _activeBank, _activePattern, _activeStep;
  int  _activeOctave;
  bool _running;
  int  _activePage;
  int  _selectedStep;
  bool _pageSelected, _stepSelected;
};

#endif
