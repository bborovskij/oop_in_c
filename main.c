#include <stdio.h>
#include <stdbool.h>

#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "bmw.h"
#include "macros.h"

int main() {
    car my_car;

    /* Or just call directly instead of VEHICLE_CTOR() */
    // car_ctor(&my_car);
    VEHICLE_CTOR(&my_car);

    VEHICLE_CALL(&my_car, car, init, "diesel", "any car", 4, 5, 4);
    VEHICLE_CALL(&my_car, vehicle, start);
    VEHICLE_CALL(&my_car, vehicle, stop);
    VEHICLE_CALL(&my_car, car, open_door, 2);
    VEHICLE_CALL(&my_car, car, deinit);

    printf("\n");

    bike my_bike;
    /* Or just call directly instead of VEHICLE_CTOR() */
    // bike_ctor(&my_car);
    VEHICLE_CTOR(&my_bike);

    VEHICLE_CALL(&my_bike, bike, init);
    VEHICLE_CALL(&my_bike, vehicle, start);
    VEHICLE_CALL(&my_bike, vehicle, stop);
    VEHICLE_CALL(&my_bike, vehicle, deinit);

    printf("\n");

    bmw my_bmw;
    /* Or just call directly instead of VEHICLE_CTOR() */
    // bmw_ctor(&my_car);
    VEHICLE_CTOR(&my_bmw);

    VEHICLE_CALL(&my_bmw, bmw, init);
    VEHICLE_CALL(&my_bmw, bmw, start, true);
    VEHICLE_CALL(&my_bmw, vehicle, stop);
    VEHICLE_CALL(&my_bmw, car, open_door, 1);
    VEHICLE_CALL(&my_bmw, car, deinit);

    return 0;
}
