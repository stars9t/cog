#include "src/cog.h"

int main(void) {
  set_log_file("log");
  set_log_level(INFO_LEVEL); 
  set_debug_mode();
  error_log("You must %s the program", "restart");
  warning_log("Oh no! 1 != %d", 5);
  debug_log("4*4 = %d", 4*4);
  info_log("This state %d", 1);
  custom_log("MYLEVEL", "Just message with float %f", 1.0);
}
