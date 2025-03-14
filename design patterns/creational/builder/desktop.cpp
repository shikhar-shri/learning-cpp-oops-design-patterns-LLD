#include "desktop.hpp"
#include <iostream>
using namespace std;

void Desktop::setMonitor(string monitor){
    this->monitor = monitor;
}

void Desktop::setMouse(string mouse){
    this->mouse = mouse;
}

void Desktop::setKeyboard(string keyboard){
    this->keyboard = keyboard;
}

void Desktop::setRam(string ram){
    this->ram = ram;
}

void Desktop::setCpu(string cpu){
    this->cpu = cpu;
}

void Desktop::showSpecs(){
    cout << "Monitor: " << monitor << endl;
    cout << "Mouse: " << mouse << endl;
    cout << "Keyboard: " << keyboard << endl;
    cout << "RAM: " << ram << endl;
    cout << "CPU: " << cpu << endl;
}