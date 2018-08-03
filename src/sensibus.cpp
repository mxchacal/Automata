#include "automata.h"
#include "sensibus.h"
#include "analogmuxdemux.h"

Sensibus::Sensibus() : _newButtonPressed(0), _lastButtonPressed(0)
{

}

void Sensibus::init() {
  //set pins for buttons 4051 & pots
}

void Sensibus::update() {
  //check if buttons have been pressed & tell the brain for menu/value change
  //bounce buttons
}

bool Sensibus::newButtonPressed() {
  return _newButtonPressed;
}

bool Sensibus::isShiftPressed() {
  return _shiftPressed;
}

int Sensibus::getLastButtonPressed() {
  return _lastButtonPressed;
}

void Sensibus::deShift() {
  _shiftPressed = 0;
}

/*TODO:
    - define buttons attributes
    ---- 16 buttons (steps)
    ----
*/
