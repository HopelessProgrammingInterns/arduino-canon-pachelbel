#ifndef PACHELBEL_H
#define PACHELBEL_H
#include "notes.h"

#ifndef MELODY
#define MELODY { \
	0}

#define DURATION { \
	0}

#else
#  error "Do not include more than one melody file!"
#endif /* MELODY */

#endif /* PACHELBEL_H */

