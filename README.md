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
```
int main(void) {
  set_log_file("logs.log");
  warning_log("Warning message");
  error_log("Error message");
  debug_log("Debug message");
  info_log("Info message");
  custom_log("Custom message", "CUSTOMLEVEL");
}
```

