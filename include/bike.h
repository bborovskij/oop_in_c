#ifndef UNTITLED_BIKE_H
#define UNTITLED_BIKE_H

#include "vehicle.h"

struct bike {
    /* Just the parent class. */
    struct vehicle super;

    /* init() with fewer arguments than the parent class has. */
    void (*init)(struct vehicle*);
};

void bike_init(struct vehicle* self);

#endif //UNTITLED_BIKE_H
