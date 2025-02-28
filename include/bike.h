#ifndef UNTITLED_BIKE_H
#define UNTITLED_BIKE_H

#include "vehicle.h"

typedef struct bike bike;
typedef struct bike_vtab bike_vtab;

struct bike_vtab {
    /*
    Overriding init method.
    */
    void (*init)(bike *);
};

struct bike {
    /* Just the parent class. */
    vehicle super;
    bike_vtab *vtab;
};


void bike_init(bike* self);
void bike_start(bike* self);
void bike_stop(bike* self);
void bike_deinit(bike* self);

#endif //UNTITLED_BIKE_H
