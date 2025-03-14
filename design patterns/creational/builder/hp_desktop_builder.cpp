#include "hp_desktop_builder.hpp"

void HpDesktopBuilder::buildMonitor() {
    desktop->setMonitor("HP Monitor");
}

void HpDesktopBuilder::buildMouse() {
    desktop->setMouse("HP Mouse");
}

void HpDesktopBuilder::buildKeyboard() {
    desktop->setKeyboard("HP Keyboard");
}

void HpDesktopBuilder::buildCpu() {
    desktop->setCpu("HP CPU");
}

void HpDesktopBuilder::buildRam() {
    desktop->setRam("HP RAM");
}