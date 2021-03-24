#include "cog.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Standard file for logging 
static char* log_file = "log.log";
// Standard time 
static char* cur_time = "Time is out";

void set_log_file(char *fname) {
  log_file = fname;
}

static FILE *open_log_file(void) { 
  FILE *fp;
  if ((fp = fopen(log_file, "a")) == NULL) {
    printf("File not open\n");
    return NULL;
  }
  return fp;
}

static void get_current_time(void) {
  time_t current_time = time(0);
  char *current_time_str = ctime(&current_time);
  current_time_str[strlen(current_time_str)-1] = '\0';
  cur_time = current_time_str;
}

void warning_log(char *msg) {
  FILE *fp = open_log_file();
  if (fp == NULL) {
    return;
  }
  get_current_time();
  fprintf(fp, "%s:WARNING: %s\n",cur_time, msg);
  fclose(fp);
}

void error_log(char *msg) {
  FILE *fp = open_log_file();
  if (fp == NULL) {
    return;
  }
  get_current_time();
  fprintf(fp, "%s:ERROR: %s\n",cur_time, msg);
  fclose(fp);
}

void debug_log(char *msg) {
  FILE *fp = open_log_file();
  if (fp == NULL) {
    return;
  }
  get_current_time();
  fprintf(fp, "%s:DEBUG: %s\n",cur_time, msg);
  fclose(fp);
}

void info_log(char *msg) {
  FILE *fp = open_log_file();
  if (fp == NULL) {
    return;
  }
  get_current_time();
  fprintf(fp, "%s:INFO: %s\n",cur_time, msg);
  fclose(fp);
}

