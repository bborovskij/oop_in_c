#ifndef UNTITLED_MACROS_H
#define UNTITLED_MACROS_H

#include "car.h"
#include "bike.h"
#include "bmw.h"
#include "vehicle.h"

/*
Use VEHICLE_CALL() to call any object's method:
- obj:                     variable holding object instance
- instance_or_parent_type: we will look for `method_name` from this type. If `obj` overrides 
  `method_name`, use instance type here. If it doesn't, use the type of the closest parent that has 
  `method_name`.
- method_name:             name of the method to call.
- ... :                    arguments (apart from `self`) the method has.
*/
#define VEHICLE_CALL(obj, instance_or_parent_type, method_name, ...) \
    ((instance_or_parent_type*)(obj))->method_name((vehicle *)(obj), ##__VA_ARGS__)

/*
Use VEHICLE_CTOR() to call specific to each object consturtor. Constructor is selected based on the object type.
*/
#define VEHICLE_CTOR(obj) \
    _Generic((obj), \
        car*: car_ctor, \
        bike*: bike_ctor, \
        bmw*: bmw_ctor, \
        vehicle*: vehicle_ctor \
    )(obj)

#endif //UNTITLED_MACROS_H
