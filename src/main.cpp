#include <Arduino.h>
#include "automata.h"
#include "conductor.h"

Tempus    clock;         //timekeeper
Sensibus  sense;         //inputs
Memoriae  memory;        //step storage
Actum     output;        //midi/cv/led output
Conductor brain;         //konducta
Debug     teller;        //whistle blower

void setup() {
  Serial.begin(115200);
  brain.init(memory, sense, output);
  clock.launch();
}

void loop() {
  sense.update();                             // check inputs
  clock.update();                             // advance clock
  brain.update(memory, sense, output, clock); // syncs
}
