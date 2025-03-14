#pragma once
#ifndef HP_DESKTOP_BUILDER_HPP
#define HP_DESKTOP_BUILDER_HPP

#include "desktop_builder.hpp"

class HpDesktopBuilder : public DesktopBuilder {
public:
    void buildMonitor() override;
    void buildMouse() override;
    void buildKeyboard() override;
    void buildCpu() override;
    void buildRam() override;
};

#endif // HP_DESKTOP_BUILDER_HPP