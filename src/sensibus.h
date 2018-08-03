#ifndef SENSISBUS_H
#define SENSINBUS_H

class Sensibus
{
public:
  Sensibus();
  void init();
  void update();
  bool newButtonPressed();
  bool isShiftPressed();
  int  getLastButtonPressed();
  void deShift();

private:
  bool _newButtonPressed, _shiftPressed, _octaveUpPressed, octaveDownUpPressed;
  int  _lastButtonPressed;
};

#endif
