#ifndef UNTITLED_BIKE_H
#define UNTITLED_BIKE_H

#include "vehicle.h"

typedef struct bike {
    /* Just the parent class. */
    vehicle super;

    void (*init)(vehicle *);
} bike;

void bike_ctor(bike* self);

#endif //UNTITLED_BIKE_H
