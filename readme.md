# LLD STUFF

Just some LLD code I wrote while practicing

## A Logger using C++

#### It provides 5 log levels
- INFO
- WARNING
- DETAIL
- DEBUG
- ERROR

The logs are generated with timestamps and log level prefixes.
Eg: [2025-01-26_20:29:11] [WARNING]warning log

These logs are then appended in a file in "logs" directory with the name "module.log"

#### Rollover Supported
When the size of the log file exceeds 10 MB, the file is prefixed by a number starting from 1.
Suppose you had 2 log files, module.log and module.log.1. 
If the module.log exceeds 10 MB, the module.log is rolled over into module.log.1, and a new module.log is created.
Similarly the former module.log.1 is rolled over into module.log.2