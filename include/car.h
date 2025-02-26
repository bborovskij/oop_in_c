#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H

#include "vehicle.h"

struct car {
    /* Base class */
    struct vehicle super;

    /* Number of doors my car has */
    int doors;

    /* 
    Since we're adding new argument 'doors', parent init() cannot be used. 
    We need to override it. 
    */
    void (*init)(struct vehicle*, char*, char *, int, int, int);

    /* 
    Since we're overriding init() with new arguments for new attributes, parent's init() 
    won't be able to clean our derived instance. We need to override deinit() too.
    */
    void (*deinit)(struct vehicle*);

    /* Method to open my car's door. */
    void (*open_door)(struct vehicle*, int);
};

void car_init(struct vehicle* self, char *fuel, char *name, int wheels, int seats, int doors);
void car_deinit(struct vehicle* self);
void car_open_door(struct vehicle* self, int num);

#endif //UNTITLED_CAR_H
