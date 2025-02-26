#include "car.h"
#include "vehicle.h"

void car_init(struct vehicle* self, char *fuel, int wheels, int seats, int doors) {
    vehicle_init(self, fuel, "car", wheels, seats);

    struct car *this_car = (struct car *)self;
    this_car->doors = doors;
    this_car->open_door = car_open_door;
    this_car->deinit = car_deinit;

    self->log(self, INFO "Initiated");
}

void car_deinit(struct vehicle* self) {
    self->log(self, INFO "De-Initiated");
    ((struct car *)self)->doors = 0;
    vehicle_deinit(self);
}

void car_open_door(struct vehicle* self, int num) {
    struct car *this_car = (struct car *)self;
    if ((num < 1) || (num > this_car->doors)) {
        self->log(self, ERROR "This car only has %d doors, not %d", this_car->doors, num);
    } else {
        self->log(self, INFO "Opening door num %d", num);
    }
}
