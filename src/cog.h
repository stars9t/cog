#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

enum LogLevel {
  DEBUG_LEVEL,
  INFO_LEVEL,
  WARNING_LEVEL,
  ERROR_LEVEL
};

#define warning_log(...) logging(WARNING_LEVEL, __VA_ARGS__)
#define error_log(...) logging(ERROR_LEVEL, __VA_ARGS__)
#define debug_log(...) logging(DEBUG_LEVEL, __VA_ARGS__)
#define info_log(...) logging(INFO_LEVEL, __VA_ARGS__)

void set_log_file(const char *fname);
void set_debug_mode(void);
void set_log_level(enum LogLevel l);

void logging(int level, const char *msg, ...);
void custom_log(const char *level, const char *msg, ...);
