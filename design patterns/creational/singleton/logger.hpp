#ifndef logger_hpp
#define logger_hpp

#include <string>
#include <mutex>
using namespace std;

class Logger {

    Logger();
    Logger(const Logger &);
    Logger& operator=(const Logger &);

    static Logger *loggerInstance;
    static int ctr;
    static mutex mtx;

public:
    static Logger *getLogger();
    void Log(const string &msg);
};

#endif