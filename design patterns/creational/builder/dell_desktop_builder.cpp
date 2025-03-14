#include "dell_desktop_builder.hpp"

void DellDesktopBuilder::buildMonitor() {
    desktop->setMonitor("Dell Monitor");
}

void DellDesktopBuilder::buildMouse() {
    desktop->setMouse("Dell Mouse");
}

void DellDesktopBuilder::buildKeyboard() {
    desktop->setKeyboard("Dell Keyboard");
}

void DellDesktopBuilder::buildCpu() {
    desktop->setCpu("Dell CPU");
}

void DellDesktopBuilder::buildRam() {
    desktop->setRam("Dell RAM");
}