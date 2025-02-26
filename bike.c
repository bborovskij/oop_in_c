#include "bike.h"
#include "vehicle.h"

void bike_init(struct vehicle* self) {
    vehicle_init(self, "gasoline", "bike", 2, 2);
    self->log(self, INFO "Initiated");
}
