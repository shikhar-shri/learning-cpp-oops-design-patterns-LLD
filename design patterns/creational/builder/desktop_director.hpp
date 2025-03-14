#pragma once
#ifndef DESKTOP_DIRECTOR_HPP
#define DESKTOP_DIRECTOR_HPP

#include "desktop_builder.hpp"

class DesktopDirector {
    private:
        unique_ptr<DesktopBuilder> desktopBuilder;

    public:
        DesktopDirector(unique_ptr<DesktopBuilder> ptr){
            desktopBuilder = move(ptr);
        }
        unique_ptr<Desktop> BuildDesktop(){
            desktopBuilder->buildMonitor();
            desktopBuilder->buildMouse();
            desktopBuilder->buildKeyboard();
            desktopBuilder->buildCpu();
            desktopBuilder->buildRam();
            return desktopBuilder->getDesktop();
        }

};

#endif