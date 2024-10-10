#include <iostream>
#include "assert.h"
#include "BatterySystem.h"

int main()
{
    BatterySystem battery(2.26, 76.0, 0.76);
    assert(battery.isOk() == true);
    std::cout <<"Battery status: " << battery.getStateStatus() <<"\n";

    battery.setTemperature(2.25);
    std::cout <<"Battery status: " << battery.getStateStatus() <<"\n";

    battery.setTemperature(2.26);
    battery.setChargeState(76.01);
    std::cout <<"Battery status: " << battery.getStateStatus() <<"\n";
    
    battery.setTemperature(2.26);
    battery.setChargeState(76.00);
    battery.setChargeRate(0.81);
    assert(battery.isOk() == false);
    std::cout <<"Battery status: " << battery.getStateStatus() <<"\n";
    return 0;
}
