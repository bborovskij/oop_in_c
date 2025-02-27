#include "car.h"
#include "bmw.h"
#include "vehicle.h"
#include "macros.h"

static void bmw_init(vehicle* self);
static void bmw_start(vehicle* self, bool in_sport_mode);

void bmw_ctor(bmw *self) {
    VEHICLE_CTOR(&(self->super));
    self->init = bmw_init;
    self->start = bmw_start;
}

static void bmw_init(vehicle* self) {
    ((bmw *)self)->super.init(self, "gasoline", "my bmw", 4, 2, 2);

    self->log(self, INFO "Inited");
}

static void bmw_start(vehicle* self, bool in_sport_mode) {
    self->start(self);
    self->log(self, INFO "Started in sport mode %d", in_sport_mode);
}
