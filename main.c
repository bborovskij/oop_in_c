#include "vehicle.h"
#include "car.h"
#include "bike.h"

int main() {
    struct car my_car;
    VEHICLE_INIT(&my_car, car, "diesel", 4, 5, 4);
    VEHICLE_CALL(&my_car, vehicle, start);
    VEHICLE_CALL(&my_car, vehicle, stop);
    VEHICLE_CALL(&my_car, car, open_door, 2);
    VEHICLE_CALL(&my_car, car, deinit);

    printf("\n");

    struct bike my_bike;
    VEHICLE_INIT(&my_bike, bike);
    VEHICLE_CALL(&my_bike, vehicle, start);
    VEHICLE_CALL(&my_bike, vehicle, stop);
    VEHICLE_CALL(&my_bike, vehicle, deinit);

    return 0;
}
