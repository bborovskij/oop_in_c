#ifndef UNTITLED_MACROS_H
#define UNTITLED_MACROS_H

#include "car.h"
#include "bike.h"
#include "bmw.h"
#include "vehicle.h"

#define VEHICLE_CALL(obj, type, method, ...) \
    ((type*)(obj))->method((vehicle *)(obj), ##__VA_ARGS__)

#define VEHICLE_CTOR(obj) \
    _Generic((obj), \
        car*: car_ctor, \
        bike*: bike_ctor, \
        bmw*: bmw_ctor, \
        vehicle*: vehicle_ctor \
    )(obj)

#endif //UNTITLED_MACROS_H
