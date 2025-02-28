#include "car.h"
#include "vehicle.h"
#include "macros.h"


/**
 * Specify one overrided or new methods here.
 */
static struct car_vtab c_vtab = {
    .init = car_init, // for derived class to initialize car as parent (bmw will derive from car and will call it)
    .deinit = car_deinit,
    .open_door = car_open_door,
};

void car_init(car* self, char *fuel, char *name, int wheels, int seats, int doors) {
    self->vtab = &c_vtab;
    /* Always call parent's init() first. */
    /*
    Using VEHICLE_INIT_PARENT() is not mandatory.
    I prefer using VEHICLE_INIT_PARENT() macro to initialize parent class of derived object and 
    VEHICLE_CALL() macro for any other method call.
     */
    // vehicle_init(&(self->super), fuel, name, wheels, seats);
    VEHICLE_INIT_PARENT(self, fuel, name, wheels, seats);
    /* car specific attribute. */
    self->doors = doors;
    // ((vehicle*)self)->vtab->log((vehicle*)self, INFO "Initiated");
    VEHICLE_CALL(self, vehicle, log, INFO "Initiated");
}

void car_deinit(car* self) {
    // ((vehicle*)self)->vtab->start((vehicle*)self);
    VEHICLE_CALL(self, vehicle, log, INFO "De-Initiated");
    /* Always call parent's deinit(). */
    // ((vehicle*)self)->vtab->deinit((vehicle*)self);
    VEHICLE_CALL(self, vehicle, deinit);
    self->doors = 0;
    self->vtab = NULL;
}

void car_open_door(car* self, int num) {
    /* Note the access to car specific attribute 'door'. */
    if ((num < 1) || (num > ((car *)self)->doors)) {
        VEHICLE_CALL(self, vehicle, log, ERROR "This car only has %d doors, not %d", ((car *)self)->doors, num);
    } else {
        VEHICLE_CALL(self, vehicle, log, INFO "Opening door num %d", num);
    }
}

void car_stop(car* self) {
    // ((vehicle*)self)->vtab->start((vehicle*)self);
    VEHICLE_CALL(self, vehicle, start);
}

void car_start(car* self) {
    VEHICLE_CALL(self, vehicle, stop);
}
