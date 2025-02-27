#ifndef UNTITLED_VEHICLE_H
#define UNTITLED_VEHICLE_H

#include <stdbool.h>
#include <stdio.h>


/* For log() method. */
#define INFO "INFO: "
#define DEBUG "DEBUG: "
#define WARNING "WARNING: "
#define ERROR "ERROR: "

typedef struct vehicle {
    /* Public. Intended to be called via object instance like my_car->start(...). */
    
    /* gasoline or diesel. */
    char m_fuel[16];

    /* car or bike. Just a name for logging. */
    char m_name[16];

    /* how many wheels my vehicle has. */
    int m_wheels;

    /* how many seats my vehicle has. */
    int m_seats;

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
} vehicle;

void vehicle_ctor(vehicle* self);

#endif //UNTITLED_VEHICLE_H
