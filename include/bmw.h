#ifndef UNTITLED_BMW_H
#define UNTITLED_BMW_H

#include <stdbool.h>
#include "car.h"
#include "vehicle.h"

typedef struct bmw {
    car super;

    void (*init)(vehicle* self);
    /* Start and switch to sport mode. */
    void (*start)(vehicle*, bool);
} bmw;

void bmw_ctor(bmw *);

#endif //UNTITLED_BMW_H
