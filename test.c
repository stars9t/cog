#include "src/cog.h"

int main(void) {
  set_log_file("log");
  set_log_level(WARNING_LEVEL); 
  set_debug_mode();
  //error_log("This is error log string");
  warning_log("This is erorr warning string");
  debug_log("This is error debug string");
  info_log("This is error info log");
  custom_log("This is custom log with my level", "MYLEVEL");
}
