#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void set_log_file(const char *fname);
void warning_log(const char *msg);
void error_log(const char *msg);
void debug_log(const char *msg);
void info_log(const char *msg);
void custom_log(const char *msg, const char *level);

