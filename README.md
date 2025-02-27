# OOP in C: Vehicle, Car, and Bike Classes

## Overview
This project demonstrates object-oriented programming (OOP) principles implemented in **C**. It introduces a **Vehicle** base class with three derived classes: **Car**, **Bike** and **BMW**. The implementation follows the fundamental OOP principles of **encapsulation, inheritance, and polymorphism** while avoiding dynamic memory allocation for instances.

## Limitations
This project is a simple educational demo only. The code might have many issues: missing NULL ptr checks before dereferencing, no error handlings, English grammar errors or typos.
Its goal is to provides a big picture on one of the ways to implement OOP in C.

## Features
- **Encapsulation**: Grouping attributes and methods inside objects.
- **Inheritance**: `Car` and `Bike` inherit from `Vehicle`. `BMW` inherits from `Car`.
- **Polymorphism**: Methods in derived classes override base class methods.
- **Static Allocation**: No dynamic memory allocation.

## Repository Structure
```
├── src/
│   ├── vehicle.c
│   ├── car.c
│   ├── bike.c
│   ├── bmw.c
│
├── include/
│   ├── vehicle.h
│   ├── car.h
│   ├── bike.h
│   ├── bmw.h
│   ├── macros.h
│
├── main.c
├── CMakeLists.txt
└── README.md
```

## Usage
### Build the Project
```sh
git clone https://github.com/bborovskij/oop_in_c.git
cd oop_in_c/
mkdir build/
cd build/
cmake .. # 'cmake -DCMAKE_BUILD_TYPE=Debug ..' if gdb needed
make
```

### Run the Program
```sh
./oop_vehicle
```

## Implementation Details
### **Base Class: Vehicle**
The **Vehicle** class encapsulates common functionality:
- **Attributes**: Fuel type, name, number of wheels, and seats.
- **Methods**: `init()`, `deinit()`, `start()`, `stop()`, and `log()`.
- Maintains an internal state variable `_engine_started`.

### **Derived Class: Car**
Additional attributes and methods:
- **New Attribute**: `doors`.
- **Overridden Methods**: `init()`, `deinit()`.
- **New Method**: `open_door()`.

### **Derived Class: Bike**
A simplified derived class:
- Overrides `init()` to set default values (always 2 wheels and 2 seats).
- Inherits most behavior from `Vehicle`.

### **Derived Class: BMW**
A simplified derived class:
- Overrides `init()` and `start()`.
- Inherits most behavior from `Car`.

## Instantiate and use object
1. Call object constructor to construct object methods
- Can be called directly like `car_ctor(&instance)`, `bike_ctor(&instance)` or via a macro like `VEHICLE_CTOR(&instance)`
2. Initialize object by calling `init()` method from the object. Use `VEHICLE_CALL()` macros to call any object's method
  like `VEHICLE_CALL(&my_car, car, init, "diesel", "any car", 4, 5, 4);` where:
- `&my_car` is a constructed instance of the object;
- `car` is a type name of to call `init()` from. Since `car` overrides parent's `init()`, we're calling `init()` from `car` type. If `car` didn't override `init()` and used only parent's (`vehicle`) one, the second argument would be `vehicle` (like `VEHICLE_CALL(&my_car, vehicle, init, "diesel", "any car", 4, 5, 4);`);
- `init` is the method to call.
- `"diesel", "any car", 4, 5, 4` are `init()` arguments (see `car::init()` declaration)
3. Call any object's method via `VEHICLE_CALL()` macros following the same logic as with `init()` like `VEHICLE_CALL(&instance, instance_or_parent_type_where_method_exists, method_name);`
4. Clear instance data via `instance::deinit()` Using `VEHICLE_CALL()`.

## Example Usage in `main.c`
```c
#include <stdio.h>
#include <stdbool.h>

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
```

---
**Author:** bborovskij@gmail.com

## License

[MIT](https://choosealicense.com/licenses/mit/)