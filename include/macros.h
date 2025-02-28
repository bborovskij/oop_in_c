#ifndef UNTITLED_MACROS_H
#define UNTITLED_MACROS_H

#include "car.h"
#include "bike.h"
#include "bmw.h"
#include "vehicle.h"

/**
 * Use this macros to conveniently call other methods from th object.
 * Where:
 * - obj:                     pointer to derived instance
 * - instance_or_parent_type: current or any parent type that has `method_name` object in its VTable.
 *                            Can be used to call parent or grandparent mathod.
 * - method_name            : Method name to call.
 * - ...                    : Any `method_name` arguments.
 */
#define VEHICLE_CALL(obj, instance_or_parent_type, method_name, ...) \
    ((instance_or_parent_type*)(obj))->vtab->method_name((instance_or_parent_type *)(obj), ##__VA_ARGS__)


/**
 * Initialize parent of the derived object.
 */
#define VEHICLE_INIT_PARENT(obj, ...) \
    _Generic(((obj)->super), \
        car: car_init, \
        bike: bike_init, \
        bmw: bmw_init, \
        vehicle: vehicle_init \
    )(&((obj)->super), ##__VA_ARGS__)

#endif //UNTITLED_MACROS_H
