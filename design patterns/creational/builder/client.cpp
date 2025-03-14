#include "desktop_director.hpp"
#include "hp_desktop_builder.hpp"
#include "dell_desktop_builder.hpp"
#include <iostream>

using namespace std;

int main(){

    unique_ptr<DesktopBuilder> hpBuilder = make_unique<HpDesktopBuilder>();
    unique_ptr<DesktopBuilder> dellBuilder = make_unique<DellDesktopBuilder>();

    DesktopDirector desktopDirector1(move(hpBuilder));
    DesktopDirector desktopDirector2(move(dellBuilder));

    auto desktop1 = desktopDirector1.BuildDesktop();
    auto desktop2 = desktopDirector2.BuildDesktop();

    desktop1->showSpecs();
    desktop2->showSpecs();

    return 0;
}

