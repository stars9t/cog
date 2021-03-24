#include "src/cog.h"

int main(void) {
  set_log_file("logs.log");
  //error_log("This is error log string");
  warning_log("This is erorr warning string");
  //debug_log("This is error debug string");
  info_log("This is error info log");
}
