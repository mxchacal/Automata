#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <Arduino.h>

/*---general parameters---*/
#define NB_OF_BANKS   1
#define PATTERN_PER_BANK 8
#define MAX_NB_OF_STEPS  16
#define TOE_RATE         100
#define PPQN             48
#define MAX_BPM          3000
#define MIN_BPM          20
#define DEFAULT_VELOCITY 99
#define DEFAULT_LENGTH   24 // PPQN/2 -- 50% width

/*----menus parameters----*/
#define BANK_PAGE        0
#define NOTE_PAGE        1
#define GATE_PAGE        2
#define LGTH_PAGE        3
#define RACHT_PAGE       4
#define LOAD_PAGE        5
#define SAVE_PAGE        6
#define SCALE_PAGE       7

/*---buttons definitions---*/
#define PLAY_BTN         8
#define STOP_BTN         9
#define CLEAR_BTN        10
#define LOAD_ALL_BTN     11
#define TRSPOSEDOWN_BTN  12
#define TRSPOSEUP_BTN    13
#define PLAYMODE_BTN     14
#define PATTERN_BTN      15
#define DUMMY_14         16
#define DUMMY_15         17
#define OCTAVEUP_BTN     18
#define OCTAVEDOWN_BTN   19

/*----pins definitions----*/
#define LATCH_PIN       16
#define CLOCK_PIN       17
#define DATA_PIN        18

struct Track {
  uint8_t note[MAX_NB_OF_STEPS];
  uint8_t velocity[MAX_NB_OF_STEPS];
  uint8_t rachett[MAX_NB_OF_STEPS];
  uint8_t gateLength[MAX_NB_OF_STEPS];
  uint8_t midiChannel;
  uint8_t patternLength;
};

#endif
