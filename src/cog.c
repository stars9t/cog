#include "cog.h"

// Length of the string at which the time is written
#define TIME_CHAR 26

// Standard file for logging 
static const char* log_file = "log.log";
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

static void write_log(const char *msg, const char *level) {
  FILE *fp = open_log_file();
  char c_time[TIME_CHAR];
  if (fp == NULL) {
    return;
  }
  get_current_time(c_time);
  fprintf(fp, "%s::%s::%s\n", c_time, level, msg);
  fclose(fp);
}

void warning_log(const char *msg) {
  if (level <= WARNING_LEVEL) {
    write_log(msg, "WARNING");
  }
}

void error_log(const char *msg) {
  if (level <= ERROR_LEVEL) {
    write_log(msg, "ERROR");
  }
}

void debug_log(const char *msg) {
  if (debug_mode == 1) {
    write_log(msg, "DEBUG");
  }
}

void info_log(const char *msg) {
  if (level <= INFO_LEVEL) {
    write_log(msg, "INFO");
  }
}

void custom_log(const char *msg, const char *level) {
  write_log(msg, level);
}

