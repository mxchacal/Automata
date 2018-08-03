#include "actum.h"
#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

ShiftRegister74HC595 trigOut (1, DATA_PIN, CLOCK_PIN, LATCH_PIN);
mcp4728 dac = mcp4728(0);

Actum::Actum() {}

void Actum::init() {
  MIDI.begin();
  trigOut.setAllLow();
  dac.begin();
  dac.setVref(0, 0, 0, 0);
  dac.analogWrite(0, 0, 0, 0);
}

void Actum::update(Memoriae& data, int midiChannel, int bank, int note, int velocity, bool gate, bool lastGate) {
  if(gate == 1 && lastGate == 1) {       //no changes, just update the dac/midi
    dac.analogWrite(bank, note);
    usbMIDI.sendPitchBend(note, midiChannel); //TODO both
    MIDI.sendPitchBend(note, midiChannel);
    return;
  }
  if(gate == 1 && lastGate == 0) {       //new gate on && dac/midi update
    usbMIDI.sendNoteOn(note, velocity, midiChannel);
    MIDI.sendNoteOn(note, velocity, midiChannel);
    dac.analogWrite(bank, note);
    trigOut.set(bank, gate);
    lastGate = 1;
    return;
  }
  if(gate == 0 && lastGate == 1) {       //new gate off && dac/midi update
    usbMIDI.sendNoteOff(note, velocity, midiChannel);
    MIDI.sendNoteOff(note, velocity, midiChannel);
    dac.analogWrite(bank, note);
    trigOut.set(bank, gate);
    lastGate = 0;
    return;
  }
}
