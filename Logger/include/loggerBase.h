#include <string>

#include "enums.h"
#include "fileWriter.h"
using namespace std;

FileHandler* FileHandler::fileHandler = nullptr;

class LoggerBase{
public:
    LOG_LEVEL level;
    LoggerBase* nextLogLevel = nullptr;
    FileHandler* fileLogHandler;

    LoggerBase(LoggerBase* logger = nullptr): nextLogLevel(logger), fileLogHandler(FileHandler::getInstance()){}

    virtual void log(LOG_LEVEL level, string message){
        if(nextLogLevel != nullptr)
            nextLogLevel->log(level, message);
    }
};
