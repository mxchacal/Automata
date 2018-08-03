#include "conductor.h"

Conductor::Conductor() : _updateRate(100), _activeBank(0), _activePattern(0), _activeStep(0), _running(0), _activePage(0)
{}

void Conductor::init(Memoriae& memory, Sensibus& sense, Actum& out) {
  sense.init();
  memory.init();
  out.init();
}

void Conductor::update(Memoriae& memory, Sensibus& sense, Actum& out, Tempus& clock) {
  handleButtons(memory, sense, sense.getLastButtonPressed(), sense.newButtonPressed());
  if(_running) {
    for(int i=0; i<NB_OF_BANKS; i++) {
      if(clock.newTick()) out.update(memory, 1, i, _activeStep, 1, 1, 1);   // every tick --> update gate on/off
      if(clock.newTock()) _activeStep += 1;                                // every quarter note --> update brain.note[x]
      if(clock.newToe())  out.update(memory, 1, i, _activeStep, 1, 1, 1); // every toe --> updateGlide && output.update()
    }
  }
}

void Conductor::handleButtons(Memoriae& memory, Sensibus& sense, int button, bool buttonPressed) {
  if(!sense.newButtonPressed()) return;
  if(_pageSelected && _stepSelected) {            //from high selection level..
    doFunction(memory, button, 0);
    _stepSelected = 0;
    return;
  }
  if(_pageSelected && !_stepSelected) {
    _selectedStep = button;
    _stepSelected = 1;
  }
  if(!_pageSelected && sense.isShiftPressed()) {
    if(button >= 8) doFunction(memory, 0, button);    //..to low level
    else {
      _activePage = button;
      _pageSelected = 1;
    }
    sense.deShift();
  }
}

void Conductor::doFunction(Memoriae& memory, int value, int function) {
  int buffer;
  if(value == 0) {
    switch(function) {
      case(PLAY_BTN):
        ; //blablabla
      case(STOP_BTN):
        ; //blablabla
      case(CLEAR_BTN):
        ; //blablabla
      case(LOAD_ALL_BTN):
        ; //blablabla
      case(TRSPOSEDOWN_BTN):
        ; //blablabla
      case(TRSPOSEUP_BTN):
        ; //blablabla
      case(PLAYMODE_BTN):
        ; //blablabla
      case(PATTERN_BTN):
        ; //blablabla
      case(DUMMY_14):
        ; //blablabla
      case(DUMMY_15):
        ; //blablabla
    }
  }
  else {
    switch(_activePage) {
      case(BANK_PAGE) :
        _activeBank = value;
      case(NOTE_PAGE) :   // note page
        if(!_stepSelected) return;
        buffer = 21 + _activeOctave * 12 + value;
        memory.setNote(_activeBank, _activePattern, _activeStep, buffer);
      case(GATE_PAGE) :   // gate page
        if(!_stepSelected) return;
        memory.setGate(_activeBank, _activePattern, _activeStep, (value * 3));
      case(LGTH_PAGE) :   // gate length page
        if(!_stepSelected) return;
        memory.setGate(_activeBank, _activePattern, _activeStep, (value * 3));
      case(RACHT_PAGE) :   // rachett page
        if(!_stepSelected) return;
        memory.setRachett(_activeBank, _activePattern, _activeStep, value);
      case(LOAD_PAGE) :   // load page
        memory.loadPattern(_activeBank, value);//patternLoad function
      case(SAVE_PAGE) :   // save page
        memory.savePattern(_activeBank, value);
      case(SCALE_PAGE) :   // scale page
        memory.setScale(_activeBank, value);
    }
  }
}
