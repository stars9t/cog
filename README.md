# COG (C LOG)
This is a simple library for keeping program logs.

## Functions
So far, a small amount of functionality is available.
In order to start keeping logs, you must specify a file to which these logs will be kept(By default, there is a logs.log file).
To do this, use the set_log_file(file_name)
```
int main(void) {
  set_log_file("logs.log");
}
```
After that, you can use 4 levels of logging or use a custom.
You can also enable a certain level of logging. In this case, all messages below the enabled will not be recorded in the logs.
After comments it is indicated which logs will be recorded

```
int main(void) {
  set_log_level(WARNING); // WARNING
  set_log_level(ERROR); // WARNING, ERROR
  set_log_level(INFO); // WARNING, ERROR, INFO
}
```
You can also enable logs for the debug level(They are disabled by default).
```
int main(void) {
  set_debug_mode(); // Enable DEBUG level
}
```

Small examples of how you can keep logs:
```
int main(void) {
  set_log_file("logs.log");
  warning_log("Please %s the programm", "restart");
  error_log("1 != %d", 6);
  debug_log("Array ended");
  info_log("Info message");
  custom_log("MYLVL", "%d^2 = %d", 7, 49);
}
```

After adding new feature, you can use the log scope, which allows you to determine where the log will be written.
```
int main(void) {
  // 0 = not write the log
  // 1 = write log in file
  // 2 = write log in terminal
  // 3 = write log to terminal and file
  set_log_scope(3);
}
```
