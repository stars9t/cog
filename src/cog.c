#include "cog.h"

// Length of the string at which the time is written
#define TIME_CHAR 26

// Standard file for logging 
static const char* log_file = "logs.log";
static int debug_mode = 0;
static enum LogLevel level = INFO_LEVEL;

void set_log_file(const char *fname) {
  log_file = fname;
}

void set_debug_mode() {
  debug_mode = 1;
}

void set_log_level(enum LogLevel l) {
  level = l;
}

static FILE *open_log_file(void) { 
  FILE *fp;
  if ((fp = fopen(log_file, "a")) == NULL) {
    printf("File not open\n");
    return NULL;
  }
  return fp;
}

static void get_current_time(char *t) {
  time_t current_time = time(0);
  strcpy(t,ctime(&current_time));
  t[strlen(t)-1] = '\0';
}

static void write_log(const char *level, const char *msg, va_list args) {
  FILE *fp;
  char c_time[TIME_CHAR];

  if ((fp = open_log_file()) == NULL) {
    return;
  }

  get_current_time(c_time);

  fprintf(fp, "%s::%s::", c_time, level);
  vfprintf(fp, msg, args);
  fprintf(fp, "\n");

  fclose(fp);
}

void warning_log(const char *msg, ...) {
  va_list args;

  if (level <= WARNING_LEVEL) {
    va_start(args, msg);
    va_end(args);
    write_log("WARNING", msg, args);
  }
}

void error_log(const char *msg, ...) {
  va_list args;

  if (level <= ERROR_LEVEL) {
    va_start(args, msg);
    va_end(args);
    write_log("ERROR", msg, args);
  }
}

void debug_log(const char *msg, ...) {
  va_list args;

  if (debug_mode == 1) {
    va_start(args, msg);
    va_end(args);
    write_log("DEBUG", msg, args);
  }
}

void info_log(const char *msg, ...) {
  va_list args;

  if (level <= INFO_LEVEL) {
    va_start(args, msg);
    va_end(args);
    write_log("INFO", msg, args);
  }
}

void custom_log(const char *level, const char *msg, ...) {
  va_list args;
  va_start(args, msg);
  va_end(args);

  write_log(level, msg, args);
}

