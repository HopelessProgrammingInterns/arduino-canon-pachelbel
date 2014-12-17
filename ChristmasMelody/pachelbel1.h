#ifndef PACHELBEL_H
#define PACHELBEL_H
#include "notes.h"

#ifndef MELODY
#define MELODY { \
	NOTE_D5, NOTE_A4, NOTE_B4, NOTE_FS4, \
	NOTE_G4, NOTE_D5, NOTE_G4, NOTE_A4, \
	NOTE_D5, NOTE_A4, NOTE_B4, NOTE_FS4, \
	NOTE_G4, NOTE_D4, PAUSE, \
	NOTE_FS5, NOTE_E5, NOTE_D4, NOTE_CS4, \
	NOTE_B4, NOTE_A4, NOTE_B4, NOTE_CS5, \
	NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, \
	\
	NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_E4, \
	NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_D4, NOTE_FS4, NOTE_E4, \
	NOTE_D4, NOTE_B0, NOTE_D4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, \
	NOTE_FS4, NOTE_D4, NOTE_E4, NOTE_CS5, NOTE_D5, NOTE_FS5, NOTE_A5, NOTE_A4, \
	NOTE_B4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_D4, NOTE_D5, NOTE_D5, NOTE_CS5, \
	\
	NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_D4, NOTE_CS4, NOTE_A4, NOTE_E4, NOTE_FS4, NOTE_D4, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_FS5, NOTE_A5, NOTE_B5, \
	NOTE_G5, NOTE_FS4, NOTE_E5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_E4, NOTE_G4, NOTE_FS4, NOTE_E4, \
	NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_E4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4, \
	NOTE_D4, NOTE_B0, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, \
	\
	NOTE_FS4, NOTE_FS5, PAUSE, NOTE_D5, NOTE_FS5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_D5, NOTE_C5, PAUSE, NOTE_B4, NOTE_D4, \
	\
	\
	0}
#define DURATION { \
	4, 4, 4, 4, \
	4, 4, 4, 4, \
	4, 4, 2, \
	4, 4, 4, 4, \
	4, 4, 4, 4, \
	4, 4, 4, 4, \
	\
	4, 4, 4, 4, \
	8, 8, 8, 8, 8, 8, 8, 8, \
	8, 8, 8, 8, 8, 8, 8, 8, \
	8, 8, 8, 8, 8, 8, 8, 8, \
	8, 8, 8, 8, 8, 8, 8, 8, \
	\
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, \
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, \
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, \
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, \
	\
	8, 8, 4, 8, 8, 4, 4, 4, 4, 4, 8, 8, 4, 8, 8, 4, \
	\
	\
	0}
#else
#  error "Do not include more than one melody file!"
#endif /* MELODY */

#endif /* PACHELBEL_H */
