#pragma once
#ifndef DELL_DESKTOP_BUILDER_HPP
#define DELL_DESKTOP_BUILDER_HPP

#include "desktop_builder.hpp"

class DellDesktopBuilder : public DesktopBuilder {
    public:
        void buildMonitor() override;
        void buildMouse() override;
        void buildKeyboard() override;
        void buildCpu() override;
        void buildRam() override;
    };

#endif // DELL_DESKTOP_BUILDER_HPP