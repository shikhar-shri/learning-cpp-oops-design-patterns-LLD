#include <iostream>
#include "logger.hpp"

using namespace std;

Logger *Logger::loggerInstance = nullptr;
int Logger::ctr = 0;
mutex Logger::mtx;

Logger::Logger(){
    ctr++;
    cout << "new instance created,Instance number: " << ctr << endl;
    
}

void Logger::Log(const string& msg){
    cout << msg << endl;
}

Logger* Logger::getLogger(){

    if(!loggerInstance){ //to only put the lock while initializing the logger instance

        mtx.lock(); //acquire a lock
        if(!loggerInstance){
            loggerInstance = new Logger();
        }
        mtx.unlock(); //release the lock
    
    }

    return loggerInstance;
}