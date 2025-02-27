#ifndef UNTITLED_BIKE_H
#define UNTITLED_BIKE_H

#include "vehicle.h"

typedef struct bike {
    /* Just the parent class. */
    vehicle super;

    /*
    Overriding init method.
    */
    void (*init)(vehicle *);
} bike;

/**
 * Construct bike object methods.
 */
void bike_ctor(bike* self);

#endif //UNTITLED_BIKE_H
