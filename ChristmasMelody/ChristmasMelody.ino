#include "pachelbel4.h"

/* This melody is defined in the header above. */
int const melody[] = MELODY;
#ifdef DURATION
int const duration[] = DURATION;
#endif

/********************************************************/
/* 3.) Define a constant LOUDSPEAKER_PIN containing the 
   number of the digital pin you just connected the 
   "+" pin of your loudspeaker to.
 */
#define LOUDSPEAKER_PIN 8

// time to wait between playing notes
#define NOTE_GAP 25
// duration of one measure in ms
#define MEASURE_DURATION 3000
// set to non-zero value to start playing after the given measure offset
#define CANON_MEASURE_OFFSET 0

/********************************************************/

/********************************************************/
/* 7.) Define a new function waitForTap,
   that does nothing until the analog port A0 has
   some value greater than 10.
   
   Call that function just before you call play(int, long).
 */
void waitForTap() {
 while (analogRead(0) <= 10)
   ;
}

/********************************************************/

void play(int note, long duration) {
  pinMode(LOUDSPEAKER_PIN, OUTPUT);
  /********************************************************/
  /* The variable note gives you a frequency in Hz.
     The variable duration is given in milliseconds.

     5.) Generate a rectangular wave with the given 
     frequency and duration.
     To do so, change the value at the loudspeaker pin
     to HIGH and to LOW for a sufficient number of
     times and wait an appropriate time after you set
     each value.

     Hint: Think about the resolutions you need!
     You may want to use more percise functions than the
     ones from the LEDFlash example.
   */

  /********************************************************/
  int times = 1000 / duration;
  int len = note / times;

  int i;
  for (i = 0; i < (int) len; i++) {
    digitalWrite(LOUDSPEAKER_PIN, HIGH);
    delayMicroseconds(1000000 / note / 2);
    digitalWrite(LOUDSPEAKER_PIN, LOW);
    delayMicroseconds(1000000 / note / 2);
  }

  //tone(LOUDSPEAKER_PIN, note, duration);
  //delayMicroseconds(duration * 1000);

  //delay (NOTE_GAP);

  pinMode(LOUDSPEAKER_PIN, INPUT);
}

void note(int freq, int fraction) {
  pinMode(LOUDSPEAKER_PIN, OUTPUT);

  int i;
  for (i = 0; i < freq / fraction * 3; i++) {
    digitalWrite(LOUDSPEAKER_PIN, HIGH);
    delayMicroseconds(1000000 / freq / 2);
    digitalWrite(LOUDSPEAKER_PIN, LOW);
    delayMicroseconds(1000000 / freq / 2);
  }
  
  pinMode(LOUDSPEAKER_PIN, INPUT);
}

/* the setup routine runs once when you press reset: */
void setup() {
  // Serial.begin(9600);
  pinMode(LOUDSPEAKER_PIN, INPUT);
}

/* the loop routine runs over and over again forever: */
void loop() {
  int i, d;

  //tone(LOUDSPEAKER_PIN, NOTE_A1, 2000);
  //delay(2000);

  for (i = 0; melody[i]; i++) {
    d = MEASURE_DURATION / duration[i];
    if (melody[i] == PAUSE) {
      //play(NOTE_A6, 500);
      delay(d);
    } else
      note(melody[i], duration[i]);
  }
 
  delay(500000);
}
