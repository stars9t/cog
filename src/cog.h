#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

enum LogLevel {
  DEBUG_LEVEL,
  INFO_LEVEL,
  WARNING_LEVEL,
  ERROR_LEVEL,
};

enum LogPlace {
  TERMINAL_PLACE,
  FILE_PLACE,
  ANY_PLACE
};

#define warning_log(...) standard_log(WARNING_LEVEL, __VA_ARGS__)
#define error_log(...) standard_log(ERROR_LEVEL, __VA_ARGS__)
#define debug_log(...) standard_log(DEBUG_LEVEL, __VA_ARGS__)
#define info_log(...) standard_log(INFO_LEVEL, __VA_ARGS__)

void set_log_file(const char *fname);
void set_debug_mode(void);
void set_log_level(enum LogLevel l);
void set_log_place(enum LogPlace p);
void disable_logging();

void standard_log(enum LogLevel level, const char *msg, ...);
void custom_log(const char *level, const char *msg, ...);
