#ifndef UNTITLED_VEHICLE_H
#define UNTITLED_VEHICLE_H

#include <stdbool.h>
#include <stdio.h>

#define VEHICLE_CALL(obj, type, method, ...) \
    ((struct type*)(obj))->method((struct vehicle *)(obj), ##__VA_ARGS__)

#define VEHICLE_INIT(obj, type, ...) \
    type##_init((struct vehicle*)(obj), ##__VA_ARGS__)

/* For log() method. */
#define INFO "INFO: "
#define DEBUG "DEBUG: "
#define WARNING "WARNING: "
#define ERROR "ERROR: "

struct vehicle {
    /* Public. Intended to be called via object instance like my_car->start(...). */
    
    /* gasoline or diesel. */
    char m_fuel[16];

    /* car or bike. Just a name for logging. */
    char m_name[16];

    /* how many wheels my vehicle has. */
    int m_wheels;

    /* how many seats my vehicle has. */
    int m_seats;

    /* 
    initialize my object. This sets up all the default methods and variables. 
    Any inherited class should call its parent init().
    */
    void (*init)(struct vehicle* self, char *fuel, char *name, int wheels, int seats);

    /* 
    Clear all the instance-related data. 
    Any inherited class should call its parent init().
    */
    void (*deinit)(struct vehicle *self);

    /* 
    Start the engine by setting  _engine_started=true. 
    Inherited classes may override it and never call it.
    */
    void (*start)(struct vehicle*);

    /* 
    Stop the engine by setting  _engine_started=false. 
    Inherited classes may override it and never call it.
    */
    void (*stop)(struct vehicle*);

    /* Private. Use by methods only. Never called from the outside. */
    bool _engine_started;
    /* Log messages. It's a printf() + the m_name of the current object. */
    void (*log)(struct vehicle *self, const char * restrict fmt, ...);
};

void vehicle_init(struct vehicle* self, char *fuel, char *name, int wheels, int seats);
void vehicle_deinit(struct vehicle* self);
void __attribute__((unused)) vehicle_start(struct vehicle* self);
void __attribute__((unused)) vehicle_stop(struct vehicle* self);

#endif //UNTITLED_VEHICLE_H
