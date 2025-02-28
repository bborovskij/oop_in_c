#include "vehicle.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include "macros.h"

static void log_msg(vehicle *self, const char * restrict fmt, ...);

static vehicle_vtab vec_vtab = {
    .init = vehicle_init, // for derived class to initialize parent
    .deinit = vehicle_deinit,
    .start = vehicle_start,
    .stop = vehicle_stop,
    .log = log_msg,
};

void vehicle_init(vehicle* self, char *fuel, char *name, int wheels, int seats) {
    self->vtab = &vec_vtab;
    /* Assign attributes value. */
    strncpy(self->m_fuel, fuel, sizeof(self->m_fuel));
    strncpy(self->m_name, name, sizeof(self->m_name));
    self->m_wheels = wheels;
    self->m_seats = seats;

    /* Log upon completion. */
    /*
    Using VEHICLE_CALL() macro to call methods are not mandatory.
    The call to a log() method of the current object would simply resolve to `self->vtab->log()`
    Since I'm using VEHICLE_CALL() in derived from Vehicle objects, I want to use then inside base class too
    for consistency. So I use VEHICLE_CALL() every time I want to call any method from any object.
    There's only one exception though. See any derived class (car, bike, bmw) init() method implementation.
    */
    VEHICLE_CALL(self, vehicle, log, DEBUG "initiated vehicle running with %s with %d wheels and %d seats",
        self->m_fuel, self->m_wheels, self->m_seats);
}

void vehicle_deinit(vehicle* self) {
    VEHICLE_CALL(self, vehicle, log, DEBUG "de-initing vehicle");

    /* Clear the instance. */
    memset(self, 0, sizeof(vehicle));
}

void vehicle_start(vehicle* self) {
    /* 
    As per design, engine is considered started after 
    we assign internal variable _engine_started = true 
    */
    self->_engine_started = true;
    VEHICLE_CALL(self, vehicle, log, DEBUG "vehicle running on %s started", self->m_fuel);
}

void vehicle_stop(vehicle* self) {
    /* Stop the engine. */
    self->_engine_started = false;
    VEHICLE_CALL(self, vehicle, log, DEBUG "vehicle running on %s stopped", self->m_fuel);

}

static void log_msg(vehicle *self, const char * restrict fmt, ...) {
    /* printf( m_name + LOG_LVL + message + \n ) */
    printf("[%s] ", self->m_name);
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
}
