#include "car.h"
#include "vehicle.h"
#include "macros.h"

static void car_init(vehicle* self, char *fuel, char *name, int wheels, int seats, int doors);
static void car_deinit(vehicle* self);
static void car_open_door(vehicle* self, int num);


void car_ctor(car* self) {
    VEHICLE_CTOR(&(self->super));
    self->init = car_init;
    self->deinit = car_deinit;
    self->open_door = car_open_door;

}

static void car_init(vehicle* self, char *fuel, char *name, int wheels, int seats, int doors) {
    /* Always call parent's init() first to be able to use inherited attributes and methods. */
    ((car *)self)->super.init(self, fuel, name, wheels, seats);

    /* car specific attribute. */
    ((car *)self)->doors = doors;

    self->log(self, INFO "Initiated");
}

static void car_deinit(vehicle* self) {
    self->log(self, INFO "De-Initiated");
    ((car *)self)->doors = 0;

    /* Always call parent's deinit() last so that it cleans up inherited attributes and methods. */
    ((car *)self)->super.deinit(self);
}

static void car_open_door(vehicle* self, int num) {
    /* Note the access to car specific attribute 'door'. */
    if ((num < 1) || (num > ((car *)self)->doors)) {
        self->log(self, ERROR "This car only has %d doors, not %d", ((car *)self)->doors, num);
    } else {
        self->log(self, INFO "Opening door num %d", num);
    }
}
