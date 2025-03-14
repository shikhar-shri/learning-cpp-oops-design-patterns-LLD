#pragma once
#ifndef DESKTOP_BUILDER_HPP
#define DESKTOP_BUILDER_HPP

#include "desktop.hpp"
#include <memory>
using namespace std;

class DesktopBuilder{
    protected:
        unique_ptr<Desktop> desktop;
    
    public:
        DesktopBuilder(){
            desktop = make_unique<Desktop>();
        }

        virtual void buildMonitor() = 0;
        virtual void buildMouse() = 0;
        virtual void buildKeyboard() = 0;
        virtual void buildCpu() = 0;
        virtual void buildRam() = 0;
        virtual unique_ptr<Desktop> getDesktop() {
            return move(desktop);
        };
};

#endif