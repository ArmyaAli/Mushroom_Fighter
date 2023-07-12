#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

enum LOG_LEVEL {
    INFO,
    DEBUG,
    ERROR,
    CORE_FAILIURE
};

void LOG(enum LOG_LEVEL level, const char* message);
static const char* map_log_level(enum LOG_LEVEL level);

#endif