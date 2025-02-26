#ifndef UNTITLED_BIKE_H
#define UNTITLED_BIKE_H

#include "vehicle.h"

struct bike {
    struct vehicle super;
};

void bike_init(struct vehicle* self);

#endif //UNTITLED_BIKE_H
