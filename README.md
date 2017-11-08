# Logger
Logger file for debugging purpose

Using this file you can add logs in your application.
You only need to include log.h and log.cpp in your project.
After including those files use following functions:

**'SetLogConfiguration()'** for setting the basic configurations of log file such as filename.

**'WriteLog()'** wherever necessary.

At the end, don't forget to use **'EndLogConfiguration()'**, this closes your log file handle.
