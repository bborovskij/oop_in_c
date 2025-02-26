#include <stdio.h>

#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "bmw.h"

int main() {
    struct car my_car;
    /* Initialize it first using a direct call to car_init() because my_car->init() method isn't set yet. */
    VEHICLE_INIT(&my_car, car, "diesel", "any car", 4, 5, 4);
    VEHICLE_CALL(&my_car, vehicle, start);
    VEHICLE_CALL(&my_car, vehicle, stop);
    VEHICLE_CALL(&my_car, car, open_door, 2);
    VEHICLE_CALL(&my_car, car, deinit);

    printf("\n");

    struct bike my_bike;
    /* Initialize it first using a direct call to bike_init() because my_bike->init() method isn't set yet. */
    VEHICLE_INIT(&my_bike, bike);
    VEHICLE_CALL(&my_bike, vehicle, start);
    VEHICLE_CALL(&my_bike, vehicle, stop);
    VEHICLE_CALL(&my_bike, vehicle, deinit);

    printf("\n");

    struct bmw my_bmw;
    /* Since BWM doesn't have its own bmw_init(), it will call inherited from 'car' class. */
    VEHICLE_INIT(&my_bmw, car,  "gasoline", "bmw", 4, 2, 2);
    VEHICLE_CALL(&my_bmw, vehicle, start);
    VEHICLE_CALL(&my_bmw, vehicle, stop);
    VEHICLE_CALL(&my_bmw, car, open_door, 1);
    VEHICLE_CALL(&my_bmw, car, deinit);

    return 0;
}
