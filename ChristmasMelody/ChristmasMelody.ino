#include "pachelbel2_fixed.h"

int const melody[] = MELODY;
#ifdef DURATION
int const duration[] = DURATION;
#endif

#define LOUDSPEAKER_PIN 8
// time to wait between playing notes
#define NOTE_GAP 25
// duration of one measure in ms
#define MEASURE_DURATION 3000
// set to non-zero value to start playing after the given measure offset
#define CANON_MEASURE_OFFSET 0

void waitForTap() {
 while (analogRead(0) <= 10)
   ;
}

/********************************************************/

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
