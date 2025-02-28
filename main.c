#include <stdio.h>
#include <stdbool.h>

#include "car.h"
#include "bike.h"
#include "bmw.h"
#include <string.h>

int main() {
    car my_car = {0};
    car_init(&my_car, "diesel", "any car", 4, 5, 4);
    car_start(&my_car);
    car_stop(&my_car);
    car_deinit(&my_car);
    printf("car cleaned=%d\n", 0==memcmp(&my_car, &(car){0}, sizeof(my_car)));

    printf("\n");

    bike my_bike = {0};
    bike_init(&my_bike);
    bike_start(&my_bike);
    bike_stop(&my_bike);
    bike_deinit(&my_bike);
    printf("bike cleaned=%d\n", 0==memcmp(&my_bike, &(bike){0}, sizeof(my_bike)));

    printf("\n");

    bmw my_bmw = {0};
    bmw_init(&my_bmw);
    bmw_start(&my_bmw, true);
    bmw_stop(&my_bmw);
    bmw_deinit(&my_bmw);
    printf("bmw cleaned=%d\n", 0==memcmp(&my_bmw, &(bmw){0}, sizeof(my_bmw)));

    return 0;
}
