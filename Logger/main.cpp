#include <iostream>

#include "./include/logger.h"

int main(){
    LoggerBase* logger = new InfoLogger(new WarningLogger(new DetailLogger(new DebugLogger(new ErrorLogger(nullptr)))));
    logger->log(ERROR, "error log");
    logger->log(DEBUG, "debug log");
    logger->log(DETAIL, "detail log");
    logger->log(WARNING, "warning log");
    logger->log(INFO, "info log");
}