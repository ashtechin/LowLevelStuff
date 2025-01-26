#include <iostream>

#include "loggerBase.h"

class InfoLogger: public LoggerBase{
public:
    InfoLogger(LoggerBase* nextLogger): LoggerBase(nextLogger){}

    void log(LOG_LEVEL level, string message) override{
        if(level >= INFO){
            fileLogHandler->fileLogger("[INFO]", message);
        }
        else {
            LoggerBase::log(level, message);
        }
    }
};

class WarningLogger: public LoggerBase{
public:
    WarningLogger(LoggerBase* nextLogger): LoggerBase(nextLogger){}

    void log(LOG_LEVEL level, string message) override{
        if(level >= WARNING){
            fileLogHandler->fileLogger("[WARNING]", message);
        }
        else {
            LoggerBase::log(level, message);
        }
    }
};

class DetailLogger: public LoggerBase{
public:
    DetailLogger(LoggerBase* nextLogger): LoggerBase(nextLogger){}

    void log(LOG_LEVEL level, string message) override{
        if(level >= DETAIL){
            fileLogHandler->fileLogger("[DETAIL]", message);
        }
        else {
            LoggerBase::log(level, message);
        }
    }
};

class DebugLogger: public LoggerBase{
public:
    DebugLogger(LoggerBase* nextLogger): LoggerBase(nextLogger){}

    void log(LOG_LEVEL level, string message) override{
        if(level >= DEBUG){
            fileLogHandler->fileLogger("[DEBUG]", message);
        }
        else {
            LoggerBase::log(level, message);
        }
    }
};

class ErrorLogger: public LoggerBase{
public:
    ErrorLogger(LoggerBase* nextLogger): LoggerBase(nextLogger){}

    void log(LOG_LEVEL level, string message) override{
        if(level >= ERROR){
            fileLogHandler->fileLogger("[ERROR]", message);
        }
        else {
            LoggerBase::log(level, message);
        }
    }
};