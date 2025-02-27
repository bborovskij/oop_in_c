#include "bike.h"
#include "vehicle.h"
#include "macros.h"

static void bike_init(vehicle* self);

void bike_ctor(bike* self) {
    VEHICLE_CTOR(&(self->super));

    self->init = bike_init;
}

static void bike_init(vehicle* self) {
    /* 
    Always call parent's init() first to be able to use inherited attributes and methods. 
    Note that we pass default for bike values to 'fuel', 'm_wheels' and 'm_seats'.
    */
    ((bike *)self)->super.init(self, "gasoline", "my bike", 2, 2);
    self->log(self, INFO "Initiated");
}
