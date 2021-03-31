#include "cog.h"

// Length of the string at which the time is written
#define TIME_CHAR 26

// Standard file for logging 
static const char *log_file = "logs.log";

static int debug_mode = 0;

static enum LogLevel current_level = INFO_LEVEL;

static const char *levels_str[] = {
  "DEBUG", "INFO", "WARNING", "ERROR"
};

// 0 = not write logs
// 1 = write in the file
// 2 = write in the terminal
// 3 = write to file and terminal
static int log_scope = 1;

void set_log_file(const char *fname) {
  log_file = fname;
}

void set_debug_mode() {
  debug_mode = 1;
}

void set_log_level(enum LogLevel l) {
  current_level = l;
}

void set_log_scope(int i) {
  if (i < 0 || i > 3) {
    printf("You set the wrong value. log_scope can be from 0 to 3");
    log_scope = 1;
  } else {
    log_scope = i;
  }
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

static void write_file_log(const char *level, const char *msg, va_list args) {
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

static void write_terminal_log(const char *level, const char *msg, va_list args) {
  char c_time[TIME_CHAR];

  get_current_time(c_time);
  printf("%s::%s::", c_time, level);
  vprintf(msg, args);
  printf("\n");
}

void logging(int level, const char *msg, ...) {
  va_list args;

  if (level >= current_level || level == DEBUG_LEVEL & debug_mode == 1) {
    va_start(args, msg);

    if (log_scope >= 1 & log_scope != 2) {
      write_file_log(levels_str[level], msg, args);
    } 
    if (log_scope >= 2) {
      write_terminal_log(levels_str[level], msg, args);
    }

    va_end(args);
  }
}

void custom_log(const char *level, const char *msg, ...) {
  va_list args;
  va_start(args, msg);

  if (log_scope >= 1 & log_scope != 2) {
    write_file_log(level, msg, args);
  } 
  if (log_scope >= 2) {
    write_terminal_log(level, msg, args);
  }

  va_end(args);
}

