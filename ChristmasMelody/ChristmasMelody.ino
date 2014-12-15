#include "silent_night.h"

/* This melody is defined in the header above. */
int const melody[] = MELODY;

/********************************************************/
/* 3.) Define a constant LOUDSPEAKER_PIN containing the 
   number of the digital pin you just connected the 
   "+" pin of your loudspeaker to.
 */

/********************************************************/

/********************************************************/
/* 7.) Define a new function waitForTap,
   that does nothing until the analog port A0 has
   some value greater than 10.
   
   Call that function just before you call play(int, long).
 */

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
  pinMode(LOUDSPEAKER_PIN, INPUT);
}

/* the setup routine runs once when you press reset: */
void setup() {
  pinMode(LOUDSPEAKER_PIN, INPUT);
}

/* the loop routine runs over and over again forever: */
void loop() {
  /********************************************************/
  /* 4.) Look at the included melody.
     How can you determine how long it is?
     
     Call play(int, long) with each note in the melody.
     Play each note for 125ms.
  */

  /********************************************************/
 
  delay(500);
}
