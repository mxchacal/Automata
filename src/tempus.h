#ifndef TEMPUS_H
#define TEMPUS_H

class Tempus
{
public:
  Tempus();
  void launch();
  void update();
  void setTempo(int tempo);
  int getCount();
  bool newTick();
  bool newTock();
  bool newToe();

private:
  unsigned int _count, _bpm, _interval, _ppqn, _beacon;
  bool _running, _tick, _tock, _toe;
};
#endif
