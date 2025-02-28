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
- Uses virtual method table per object, but in our case, we only store overrided or new methods in object VTable.
- for convenience, use macros to initialize parent object and call any (local or parent) object methods.

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
1. Call init(&obj) method to instantiate object.
2. Call any object public methods available in respective header.
2. Call deinit() method to clean up the instance.

## Example Usage in `main.c`
```c
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
```

Output:
```text
[any car] DEBUG: initiated vehicle running with diesel with 4 wheels and 5 seats
[any car] INFO: Initiated
[any car] DEBUG: vehicle running on diesel stopped
[any car] DEBUG: vehicle running on diesel started
[any car] INFO: De-Initiated
[any car] DEBUG: de-initing vehicle
car cleaned=1

[my bike] DEBUG: initiated vehicle running with gasoline with 2 wheels and 2 seats
[my bike] INFO: Initiated
[my bike] DEBUG: vehicle running on gasoline started
[my bike] DEBUG: vehicle running on gasoline stopped
[my bike] DEBUG: de-initing vehicle
bike cleaned=1

[my bmw] DEBUG: initiated vehicle running with gasoline with 4 wheels and 2 seats
[my bmw] INFO: Initiated
[my bmw] INFO: Inited
[my bmw] DEBUG: vehicle running on gasoline started
[my bmw] INFO: Started in sport mode 1
[my bmw] DEBUG: vehicle running on gasoline stopped
[my bmw] INFO: De-Initiated
[my bmw] DEBUG: de-initing vehicle
bmw cleaned=1
```

---
**Author:** bborovskij@gmail.com

## License

[MIT](https://choosealicense.com/licenses/mit/)