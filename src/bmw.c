#include "car.h"
#include "bmw.h"
#include "vehicle.h"
#include "macros.h"

/**
 * Specify one overrided or new methods here.
 */
static bmw_vtab b_vtab = {
    .init = bmw_init,
    .start = bmw_start,
};

void bmw_init(bmw* self) {
    self->vtab = &b_vtab;
    VEHICLE_INIT_PARENT(self, "gasoline", "my bmw", 4, 2, 2);
    VEHICLE_CALL(self, vehicle, log, INFO "Inited");
}

void bmw_start(bmw* self, bool in_sport_mode) {
    // ((vehicle*)self)->vtab->start((vehicle*)self);
    VEHICLE_CALL(self, vehicle, start);
    // ((vehicle*)self)->vtab->log((vehicle*)self, INFO "Started in sport mode %d", in_sport_mode);
    VEHICLE_CALL(self, vehicle, log, INFO "Started in sport mode %d", in_sport_mode);
}

void bmw_stop(bmw* self) {
    VEHICLE_CALL(self, vehicle, stop);
}

void bmw_deinit(bmw* self) {
    VEHICLE_CALL(self, car, deinit);
    self->vtab = NULL;
}
