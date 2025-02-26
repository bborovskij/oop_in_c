#ifndef UNTITLED_VEHICLE_H
#define UNTITLED_VEHICLE_H

#include <stdbool.h>
#include <stdio.h>

#define VEHICLE_CALL(obj, type, method, ...) \
    ((struct type*)(obj))->method((struct vehicle *)(obj), ##__VA_ARGS__)

#define VEHICLE_INIT(obj, type, ...) \
    type##_init((struct vehicle*)(obj), ##__VA_ARGS__)

#define INFO "INFO: "
#define DEBUG "DEBUG: "
#define WARNING "WARNING: "
#define ERROR "ERROR: "

struct vehicle {
    // public
    char m_fuel[16];
    char m_name[16];
    int m_wheels;
    int m_seats;

    void (*init)(struct vehicle* self, char *fuel, char *name, int wheels, int seats);
    void (*deinit)(struct vehicle *self);
    void (*start)(struct vehicle*);
    void (*stop)(struct vehicle*);

    // private
    bool _engine_started;
    void (*log)(struct vehicle *self, const char * restrict fmt, ...);
};

void vehicle_init(struct vehicle* self, char *fuel, char *name, int wheels, int seats);
void vehicle_deinit(struct vehicle* self);
void __attribute__((unused)) vehicle_start(struct vehicle* self);
void __attribute__((unused)) vehicle_stop(struct vehicle* self);

#endif //UNTITLED_VEHICLE_H
