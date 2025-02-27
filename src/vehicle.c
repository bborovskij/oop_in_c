#include "vehicle.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>


static void vehicle_init(vehicle* self, char *fuel, char *name, int wheels, int seats);
static void vehicle_deinit(vehicle* self);
static void __attribute__((unused)) vehicle_start(vehicle* self);
static void __attribute__((unused)) vehicle_stop(vehicle* self);
static void log_msg(vehicle *self, const char * restrict fmt, ...);


void vehicle_ctor(vehicle* self) {
    self->init = vehicle_init;
    self->deinit = vehicle_deinit;
    self->start = vehicle_start;
    self->stop = vehicle_stop;
    self->log = log_msg;
}

static void vehicle_init(vehicle* self, char *fuel, char *name, int wheels, int seats) {
    /* Assign attributes value. */
    strncpy(self->m_fuel, fuel, sizeof(self->m_fuel));
    strncpy(self->m_name, name, sizeof(self->m_name));
    self->m_wheels = wheels;
    self->m_seats = seats;

    /* Log upon completion. */
    self->log(self, DEBUG "initiated vehicle running with %s with %d wheels and %d seats",
              self->m_fuel, self->m_wheels, self->m_seats);
}

static void vehicle_deinit(vehicle* self) {
    self->log(self, DEBUG "de-initing vehicle");

    /* Clear the instance. */
    memset(self, 0, sizeof(vehicle));
}

static void vehicle_start(vehicle* self) {
    /* 
    As per design, engine is considered started after 
    we assign internal variable _engine_started = true 
    */
    self->_engine_started = true;
    self->log(self, DEBUG "vehicle running on %s started", self->m_fuel);
}

static void vehicle_stop(vehicle* self) {
    /* Stop the engine. */
    self->_engine_started = false;
    self->log(self, DEBUG "vehicle running on %s stopped", self->m_fuel);
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
