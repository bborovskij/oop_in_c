#include "bike.h"
#include "vehicle.h"
#include "macros.h"

/**
 * Specify one overrided or new methods here.
 */
static bike_vtab b_vtab = {
    .init = bike_init,
};

void bike_init(bike* self) {
    /* 
    Always call parent's init() first to be able to use inherited attributes and methods. 
    Note that we pass default for bike values to 'fuel', 'm_wheels' and 'm_seats'.
    */
    self->vtab = &b_vtab;
    VEHICLE_INIT_PARENT(self, "gasoline", "my bike", 2, 2);
    VEHICLE_CALL(self, vehicle, log, INFO "Initiated");
}

void bike_start(bike* self) {
    VEHICLE_CALL(self, vehicle, start);
}

void bike_stop(bike* self) {
    VEHICLE_CALL(self, vehicle, stop);
}

void bike_deinit(bike* self) {
    VEHICLE_CALL(self, vehicle, deinit);
    self->vtab = NULL;
}
