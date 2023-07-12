#include "logger.h"

void LOG(enum LOG_LEVEL level, const char *message)
{
    char output[256];

    FILE *LOG_FILE;

    time_t raw_time;
    struct tm *curr_time;
    time(&raw_time);
    curr_time= localtime(&raw_time);

    sprintf(output, "[%s][%d-%02d-%02dT%02d:%02d:%02d]:[%s]\n", 
            map_log_level(level), 
            1900 + curr_time->tm_year, 
            1 + curr_time->tm_mon, 
            1 + curr_time->tm_mday, 
            curr_time->tm_hour, 
            curr_time->tm_min, 
            curr_time->tm_sec, 
    message);

    printf(output);
}

static const char* map_log_level(enum LOG_LEVEL level) {
    switch(level) {
        case INFO: return "INFO";
        case DEBUG: return "DEBUG";
        case ERROR: return "ERROR";
        case CORE_FAILIURE: return "CORE FAILIURE";
    }
}