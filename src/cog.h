#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum LogLevel {
  INFO_LEVEL,
  WARNING_LEVEL,
  ERROR_LEVEL
};

void set_log_file(const char *fname);
void set_debug_mode(void);
void set_log_level(enum LogLevel l);

void warning_log(const char *msg);
void error_log(const char *msg);
void debug_log(const char *msg);
void info_log(const char *msg);
void custom_log(const char *msg, const char *level);

