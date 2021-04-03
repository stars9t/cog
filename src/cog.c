#include "cog.h"

// Length of the string at which the time is written
#define TIME_SYM 21

// Standard file for logging 
static const char *log_file = "logs.log";

static int debug_mode = 0;

static enum LogLevel current_level = INFO_LEVEL;

// Write logs or not
static int is_log_allow = 1;

static enum LogPlace log_place = FILE_PLACE;

static const char *str_lvl[] = {
  "DEBUG", "INFO", "WARNING", "ERROR"
};

static FILE *open_log_file(void) { 
  FILE *fp;
  if ((fp = fopen(log_file, "a")) == NULL) {
    printf("File not open\n");
    return NULL;
  }
  return fp;
}

static void get_current_time(char *arr) {
  time_t t = time(0);
  strftime(arr, TIME_SYM, "%F::%T", localtime(&t));
}

static void write_file_log(const char *level, const char *msg, va_list args) {
  FILE *fp;
  char c_time[TIME_SYM];

  if ((fp = open_log_file()) == NULL) {
    return;
  }

  get_current_time(c_time);

  fprintf(fp, "%s::%s::", c_time, level);
  vfprintf(fp, msg, args);
  fprintf(fp, "\n");

  fclose(fp);
}

static void write_terminal_log(const char *level, const char *msg, va_list args) {
  char c_time[TIME_SYM];

  get_current_time(c_time);
  fprintf(stderr, "%s::%s::", c_time, level);
  vfprintf(stderr, msg, args);
  fprintf(stderr, "\n");
}

static void write_log(enum LogPlace lp, const char *lvl, const char *msg, va_list args) {
  va_list args_c;

  if (!is_log_allow) {
    return;
  }

  va_copy(args_c, args);
  if (lp == FILE_PLACE || lp == ANY_PLACE) {
    write_file_log(lvl, msg, args);
  } 
  if (lp == TERMINAL_PLACE || lp == ANY_PLACE) {
    write_terminal_log(lvl, msg, args_c);
  }
}

void set_log_file(const char *fname) {
  log_file = fname;
}

void set_debug_mode() {
  debug_mode = 1;
}

void set_log_level(enum LogLevel l) {
  current_level = l;
}

void set_log_place(enum LogPlace p) {
  log_place = p;
}

void disable_logging() {
  is_log_allow = 0;
}

void standard_log(enum LogLevel level, const char *msg, ...) {
  va_list args;
  if (level >= current_level || level == DEBUG_LEVEL && debug_mode == 1) {
    va_start(args, msg);
    write_log(log_place, str_lvl[level], msg, args);
    va_end(args);
  }
}

void custom_log(const char *level, const char *msg, ...) {
  va_list args;
  va_start(args, msg);
  write_log(log_place, level, msg, args);
  va_end(args);
}
