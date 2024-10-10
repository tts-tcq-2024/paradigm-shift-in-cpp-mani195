#pragma once
#include "ParameterMonitoring.h"
#include <memory>

class BatterySystem
{
    private:
    std::unique_ptr<ParameterMonitoring> monitorTemperature;
    std::unique_ptr<ParameterMonitoring> monitorChargeState;
    std::unique_ptr<ParameterMonitoring> monitorChargeRate;
    
    public:
        BatterySystem()=delete;
        BatterySystem(const _Float32 temperature, const _Float32 chargeState, const _Float32 chargeRate);
        bool isOk() const;
        std::string getStateStatus();
        void setTemperature(const _Float32 input);
        void setChargeState(const _Float32 input);
        void setChargeRate(const _Float32 input);
};
