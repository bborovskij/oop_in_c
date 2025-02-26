#include "car.h"
#include "vehicle.h"

void car_init(struct vehicle* self, char *fuel, char *name, int wheels, int seats, int doors) {
    /* Always call parent's init() first to be able to use inherited attributes and methods. */
    vehicle_init(self, fuel, name, wheels, seats);

    /* 
    We'll be passing 'struct car*' object as self so the attributes after 
    'struct vehicle super;' from 'struct car' should be accessible. We'll see an example in main.c. */
    struct car *this_car = (struct car *)self;

    /* car specific attribute. */
    this_car->doors = doors;

    /* car specific methods. */
    this_car->open_door = car_open_door;
    this_car->deinit = car_deinit;
    this_car->init = car_init;

    self->log(self, INFO "Initiated");
}

void car_deinit(struct vehicle* self) {
    self->log(self, INFO "De-Initiated");
    ((struct car *)self)->doors = 0;

    /* Always call parent's deinit() last so that it cleans up inherited attributes and methods. */
    vehicle_deinit(self);
}

void car_open_door(struct vehicle* self, int num) {
    /* 
    We'll be passing 'struct car*' object as self so the car specific methods 
    should be accessible. 
    */
    struct car *this_car = (struct car *)self;

    /* Note the access to car specific attribute 'door'. */
    if ((num < 1) || (num > this_car->doors)) {
        self->log(self, ERROR "This car only has %d doors, not %d", this_car->doors, num);
    } else {
        self->log(self, INFO "Opening door num %d", num);
    }
}
