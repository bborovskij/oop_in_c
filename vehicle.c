#include "vehicle.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

static void log_msg(struct vehicle *self, const char * restrict fmt, ...);

void vehicle_init(struct vehicle* self, char *fuel, char *name, int wheels, int seats) {
    strncpy(self->m_fuel, fuel, sizeof(self->m_fuel));
    strncpy(self->m_name, name, sizeof(self->m_name));
    self->m_wheels = wheels;
    self->m_seats = seats;

    self->init = vehicle_init;
    self->start = vehicle_start;
    self->stop = vehicle_stop;
    self->deinit = vehicle_deinit;
    self->log = log_msg;

    self->log(self, DEBUG "initiated vehicle running with %s with %d wheels and %d seats",
              self->m_fuel, self->m_wheels, self->m_seats);
}

void vehicle_deinit(struct vehicle* self) {
    self->log(self, DEBUG "de-initing vehicle");
    memset(self, 0, sizeof(struct vehicle));
}

void vehicle_start(struct vehicle* self) {
    self->_engine_started = true;
    self->log(self, DEBUG "vehicle running on %s started", self->m_fuel);
}

void vehicle_stop(struct vehicle* self) {
    self->_engine_started = false;
    self->log(self, DEBUG "vehicle running on %s stopped", self->m_fuel);
}

static void log_msg(struct vehicle *self, const char * restrict fmt, ...) {
    printf("[%s] ", self->m_name);
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
}
