#ifndef OH_TANNENBAUM_H
#define OH_TANNENBAUM_H
#include "notes.h"

#ifndef MELODY
#  define MELODY {NOTE_C4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_C4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_E4, NOTE_G4, NOTE_F4, 0}
#else
#  error "Do not include more than one melody file!"
#endif /* MELODY */

#endif /* OH_TANNENBAUM_H */
