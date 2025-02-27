#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H

#include "vehicle.h"

typedef struct car {
    /* Base class */
    struct vehicle super;

    /* Number of doors my car has */
    int doors;

    /*
    Override vehicle init().
    */
    void (*init)(vehicle* self, char *fuel, char *name, int wheels, int seats, int doors);
    /* 
    Since we're overriding init() with new arguments for new attributes, parent's init() 
    won't be able to clean our derived instance. We need to override deinit() too.
    */
    void (*deinit)(vehicle*);

    /* Method to open my car's door. */
    void (*open_door)(vehicle*, int);
} car;

/**
 * Construct car object methods.
 */
void car_ctor(car* self);

#endif //UNTITLED_CAR_H
