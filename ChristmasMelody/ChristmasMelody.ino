#include "pachelbel1.h"

int const melody[] = MELODY;
#ifdef DURATION
int const duration[] = DURATION;
#endif

#define CONTROL_PIN 2
#define CONTROLLER_PIN 3

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
  for (i = 0; i < freq / fraction   * 3; i++) {
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
  
  digitalWrite(CONTROLLER_PIN, HIGH);
  pinMode(CONTROLLER_PIN, OUTPUT);
  
  pinMode(CONTROL_PIN, INPUT);
  /* enable the pullup resistor on the control pin: */
  digitalWrite(CONTROL_PIN, HIGH);
}

/* the loop routine runs over and over again forever: */
void loop() {
  /* wait for the control signal to become LOW */
  while(digitalRead(CONTROL_PIN) == HIGH)  {
    ;;
  }
  /* tell the other Arduinos to start */
  digitalWrite(CONTROLLER_PIN, LOW);
  
  int i, d;

  for (i = 0; melody[i]; i++) {
    d = MEASURE_DURATION / duration[i];
    if (melody[i] == PAUSE) {
      //play(NOTE_A6, 500);
      delay(d);
    } else
      note(melody[i], duration[i]);
  }
  
  digitalWrite(CONTROLLER_PIN, HIGH);
  delay(500000);
}
