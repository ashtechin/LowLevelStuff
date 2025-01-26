#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <filesystem>

#define LOGFILE "./logs/module.log"
#define LOGDIRPATH "./logs"

using namespace std;

class FileHandler{
    static FileHandler* fileHandler;
    ofstream filePointer;
    FileHandler(const string& filePath) {
        filePointer.open(filePath, ios::out | ios::app);  
        if (!filePointer) {
            cerr << "Failed to open log file!" << endl;
            exit(1); 
        }
    }

public:

    FileHandler(FileHandler& handler) = delete;
    void operator=(FileHandler& handler) = delete;

    static FileHandler* getInstance(const string& filePath = LOGFILE){
        if(fileHandler == nullptr)
            fileHandler = new FileHandler(filePath);
        
        return fileHandler;
    }

    void fileLogger(string logType, string message){
        auto now = chrono::system_clock::now();
        auto now_c = chrono::system_clock::to_time_t(now);
        tm tm = *localtime(&now_c);
        char formatted_time[100];
        strftime(formatted_time, sizeof(formatted_time), "%F_%T", &tm);

        filePointer << "[" << formatted_time << "] " << logType << message << endl;
        lapseLogFile();
    }

    void lapseLogFile(){
        if(filePointer){
            filesystem::path p = LOGFILE;

            int fileSize = filesystem::file_size(p);
            if(fileSize > 1000000){
                filesystem::path dirPath = LOGDIRPATH;
                for (const auto& entry : filesystem::directory_iterator(dirPath)) {
                    if (filesystem::is_regular_file(entry.status())) {
                        string fileName = entry.path().filename().string();
                        if(fileName.back() >= 48 && fileName.back() <= 57){
                            int index;
                            string number = "";
                            for(index = fileName.size() - 1; index >= 0 && fileName[index] != '.'; index++){
                                number.insert(number.begin(), fileName[index]);
                            }
                            number = to_string(stoi(number) + 1);
                            fileName.erase(index+1);
                            fileName += number;


                        }
                        // Older files renamed. Now for the current log file
                        else {
                            fileName += ".1";

                        }
                        filesystem::rename(entry.path(), fileName);
                    }
                }
            }
        }
    }

    ~FileHandler() {
        if (filePointer.is_open()) {
            filePointer.close();
        }
    }
    
};
