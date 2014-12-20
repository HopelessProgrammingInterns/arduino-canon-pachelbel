/* ------ CONFIGURATION SECTION ------ */
// The song to play
#include "../ChristmasMelody/frere_jacques.h"

// If true, this arduino will send the clock signal
#define IS_MASTER 1

// The bpm with wich to play the song
#define BPM 100
// If no DURATION was defined, the default duration to use
#define DEFAULT_DURATION 4

// The master pin where the clock signal will be send
#define MASTER_PIN 2
// The slave pin where the clock signal will be received
#define SLAVE_PIN 4

// The pin the speaker is connected to
#define SPEAKER_PIN 8
// The pin the led is connected to
#define LED_PIN 13

// When to display the metronome (duration)
#define METRONOME 1
// How long the metronome should be active (duration)
#define METRONOME_LENGTH 32
/* ---- END CONFIGURATION SECTION ---- */

/* ------------- INCLUDES ------------ */
#define DIGITALIO_MANUAL // don't overwrite arduino digital* functions
#include "digitalIOPerformance.h"
#include "TimerOne.h"
/* ----------- END INCLUDES ---------- */

/* -------------- MACROS ------------- */
// The duration of a tick
#define TICK 32 // DO NOT CHANGE (or stuff will break)
// How many microseconds are in a tick
#define MICRO_32 (60000000L / (BPM * 8)) // 60,000,000 Microsecronds in a minute, BPM beats per minute and 8 32th notes per beat

// Convert from duration to number of ticks and vice versa
// The indirection is required so we can call the macro with a macro
#define FLIP_DURATION_(x) FLIP_DURATION_##x
#define FLIP_DURATION(x) FLIP_DURATION_(x)
#define FLIP_DURATION_1 32
#define FLIP_DURATION_2 16
#define FLIP_DURATION_4  8
#define FLIP_DURATION_8  4
#define FLIP_DURATION_16 2
#define FLIP_DURATION_32 1

// Wait for the next tick
// prev: the previous value read from the pin
// tick: the tick counter, used to display the metronome
#define NEXT_TICK(prev, tick) \
  do { \
    while (digitalReadSafe(SLAVE_PIN) == prev); \
    HIGH_LOW_FLIP(prev); \
    digitalWriteSafe(LED_PIN, tick++ % FLIP_DURATION(METRONOME) < FLIP_DURATION(METRONOME_LENGTH)); \
  } while (0)

// Flip a value from HIGH to LOW and vice versa
// LOW = 0x0; HIGH = 0x1
#define HIGH_LOW_FLIP(v) v ^= 0x1
/* ------------ END MACROS ----------- */

/* -------------- MUSIC -------------- */
#ifndef MELODY
  #error "no melody defined"
#endif
int const melody[] = MELODY;

// User GET_DURATION(i) to get the duration of the ith note, if no DURATION was defined DEFAULT_DURATION will be returned
#ifdef DURATION
  int const duration[] = DURATION;
  #define GET_DURATION(i) duration[i]
#else
  #define GET_DURATION(i) DEFAULT_DURATION
#endif
/* ------------ END MUSIC ------------ */

/* --------- MASTER ONLY CODE -------- */
#if IS_MASTER
uint8_t next_tick = HIGH;

void send_tick() {
  digitalWriteSafe(MASTER_PIN, next_tick);
  HIGH_LOW_FLIP(next_tick);
}
#endif
/* ------- END MASTER ONLY CODE ------ */

void setup() {
  pinMode(MASTER_PIN, OUTPUT);
  pinMode(SLAVE_PIN, INPUT);

  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

/* -------- MASTER ONLY SETUP -------- */
  #if IS_MASTER
    Timer1.initialize(MICRO_32);
    Timer1.attachInterrupt(send_tick);
  #endif
/* ------ END MASTER ONLY SETUP ------ */
}

/* ------------ MAIN CODE ------------ */
void loop() {
  // The previous value read from SLAVE_PIN
  int8_t prev = LOW;
  // The current tick count
  int8_t tick = 0;

  // Index into melody
  int i = 0;
  // The frequency of the current note
  int note;

  // Play until the end of the melody is reached
  while ((note = melody[i]) != 0) {
    // The duration of the current note
    int d = GET_DURATION(i);
    // How long the current note has been played
    // Because we count up using the duration we always have to play until j == TICK
    int j = d;

    // Wait for the next tick before stopping the current note and playing the next
    // This also means we wait until the first tick is received before we start playing
    NEXT_TICK(prev, tick);

    // Turn off the speaker to achieve a very short pause to make repetitive notes distinguishable
    // and because the next note may be a pause
    noTone(SPEAKER_PIN);

    // Start playing the note if it is note a pause
    if (note != PAUSE) tone(SPEAKER_PIN, note);

    // Wait until the correct number of ticks has passed
    // When we are done, there is still one tick left which we wait for in the next iteration of the outer loop
    while(j < TICK) {
      NEXT_TICK(prev, tick);
      j += d;
    }

    // Continue with the next note
    i += 1;
  }

  // No more notes, wait for the current note to finish...
  NEXT_TICK(prev, tick);
  // ... and turn the speaker off
  noTone(SPEAKER_PIN);

  // Do not play the melody again and again, it's better for your sanity
  while(true);
}
/* ---------- END MAIN CODE ---------- */
