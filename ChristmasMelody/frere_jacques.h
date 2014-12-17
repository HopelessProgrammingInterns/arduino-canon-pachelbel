#ifndef FRERE_JACQUES_H
#define FRERE_JACQUES_H
#include "notes.h"

#ifndef MELODY
#define MELODY { \
	NOTE_F4, NOTE_G4, NOTE_A4, NOTE_F4, \
	NOTE_F4, NOTE_G4, NOTE_A4, NOTE_F4, \
	NOTE_A4, NOTE_AS4, NOTE_C5, \
	NOTE_A4, NOTE_AS4, NOTE_C5, \
	NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_F4, \
	NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_F4, \
	NOTE_G4, NOTE_C4, NOTE_F4, \
	NOTE_G4, NOTE_C4, NOTE_F4, \
	0}
#define DURATION { \
	4, 4, 4, 4, \
	4, 4, 4, 4, \
	4, 4, 2, \
	4, 4, 2, \
	8, 8, 8, 8, 4, 4, \
	4, 4, 2, \
	4, 4, 2, \
	0}
#else
#  error "Do not include more than one melody file!"
#endif /* MELODY */

#endif /* FRERE_JACQUES_H */
