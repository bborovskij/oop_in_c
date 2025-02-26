#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H

#include "vehicle.h"

struct car {
    struct vehicle super;
    int doors;

    void (*deinit)(struct vehicle*);
    void (*open_door)(struct vehicle*, int);
};

void car_init(struct vehicle* self, char *fuel, int wheels, int seats, int doors);
void car_deinit(struct vehicle* self);
void car_open_door(struct vehicle* self, int num);

#endif //UNTITLED_CAR_H
