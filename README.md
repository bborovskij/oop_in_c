# OOP in C: Vehicle, Car, and Bike Classes

## Overview
This project demonstrates object-oriented programming (OOP) principles implemented in **C**. It introduces a **Vehicle** base class with three derived classes: **Car**, **Bike** and **BMW**. The implementation follows the fundamental OOP principles of **encapsulation, inheritance, and polymorphism** while avoiding dynamic memory allocation for instances.

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
│   ├── main.c
│
├── include/
│   ├── vehicle.h
│   ├── car.h
│   ├── bike.h
│   ├── bmw.h
│
├── main.c
├── CMakeLists.txt
└── README.md
```

## Usage
### Build the Project
```sh
git clone https://github.com/bborovskij/oop_in_c.git
cd oop_in_c
mkdir build
cd build
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
- **New Attribute**: `doors` (number of doors in the car).
- **Overridden Methods**: `init()`, `deinit()`.
- **New Method**: `open_door()`.

### **Derived Class: Bike**
A simplified derived class:
- Overrides `init()` to set default values (always 2 wheels and 2 seats).
- Inherits most behavior from `Vehicle`.

## Example Usage in `main.c`
```c
#include "vehicle.h"
#include "car.h"
#include "bike.h"

int main() {
    struct car my_car;
    car_init((struct vehicle *)&my_car, "diesel", 4, 5, 4);
    my_car.super.start((struct vehicle *)&my_car);
    my_car.super.stop((struct vehicle *)&my_car);
    my_car.open_door((struct vehicle *)&my_car, 2);
    my_car.super.deinit((struct vehicle *)&my_car);

    struct bike my_bike;
    bike_init((struct vehicle *)&my_bike);
    my_bike.super.start((struct vehicle *)&my_bike);
    my_bike.super.stop((struct vehicle *)&my_bike);
    my_bike.super.deinit((struct vehicle *)&my_bike);

    return 0;
}
```

## GitHub Repository
Find the complete implementation here: [GitHub - OOP in C](https://github.com/bborovskij/oop_in_c)

---
**Author:** Bohdan Borovskyi
