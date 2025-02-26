#include "bike.h"
#include "vehicle.h"

void bike_init(struct vehicle* self) {
    /* 
    Always call parent's init() first to be able to use inherited attributes and methods. 
    Note that we pass default for bike values to 'fuel', 'm_wheels' and 'm_seats'.
    */
    vehicle_init(self, "gasoline", "bike", 2, 2);

    struct bike* this_bike = (struct bike*)self;
    this_bike->init = bike_init;

    self->log(self, INFO "Initiated");
}
