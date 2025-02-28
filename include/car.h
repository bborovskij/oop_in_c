#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H

#include "vehicle.h"

typedef struct car car;
typedef struct car_vtab car_vtab;

struct car_vtab {
    /*
    Override vehicle init().
    */
    void (*init)(car* self, char *fuel, char *name, int wheels, int seats, int doors);
    /* 
    Since we're overriding init() with new arguments for new attributes, parent's init() 
    won't be able to clean our derived instance. We need to override deinit() too.
    */
    void (*deinit)(car*);

    /* Method to open my car's door. */
    void (*open_door)(car*, int);
};

struct car {
    /* Base class */
    vehicle super;

    car_vtab *vtab;

    /* Number of doors my car has */
    int doors;
};

void car_init(car* self, char *fuel, char *name, int wheels, int seats, int doors);
void car_deinit(car* self);
void car_open_door(car* self, int num);
void car_stop(car* self);
void car_start(car* self);

#endif //UNTITLED_CAR_H
