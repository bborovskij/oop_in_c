#ifndef UNTITLED_BMW_H
#define UNTITLED_BMW_H

#include <stdbool.h>
#include "car.h"
#include "vehicle.h"

typedef struct bmw bmw;
typedef struct bmw_vtab bmw_vtab;

struct bmw_vtab {
    /*
    Override Car's init.
    */
    void (*init)(bmw* self);
    /* Start and switch to sport mode. */
    void (*start)(bmw*, bool);
};

struct bmw {
    car super;
    bmw_vtab *vtab;
};

void bmw_init(bmw* self);
void bmw_start(bmw* self, bool in_sport_mode);
void bmw_stop(bmw* self);
void bmw_deinit(bmw* self);

#endif //UNTITLED_BMW_H
