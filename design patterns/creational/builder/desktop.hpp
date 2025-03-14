#ifndef DESKTOP_HPP
#define DESKTOP_HPP

#include <string>
using namespace std;

class Desktop{
    string monitor;
    string mouse;
    string keyboard;
    string ram;
    string cpu;

    public:
        void setMonitor(string monitor);
        void setMouse(string mouse);
        void setKeyboard(string keyboard);
        void setRam(string ram);
        void setCpu(string cpu);
        void showSpecs();
};

#endif