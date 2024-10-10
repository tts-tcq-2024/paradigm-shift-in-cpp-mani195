#pragma once
#include <iostream>
#include <map>
#include "utils.h"

class ParameterMonitoring
{
    private:
        std::string name;
        _Float32 value;
        _Float32 min;
        _Float32 max;
        _Float32 tolerance;
        const std::map<std::pair<_Float32, _Float32>, std::string> stateList =
        {
            {{-100, min}, "LOW_" + name +"_BREACH"},
            {{min + 0.01, min + tolerance}, "LOW_" + name +"_WARNING"},
            {{min + tolerance + 0.01, max - tolerance}, "NORMAL_" + name +"_STATE"},
            {{max - tolerance + 0.01, max}, "HIGH_" + name +"_WARNING"},
            {{max + 0.01, 100}, "HIGH_" + name +"_BREACH"},
        };
        bool warning = true;
        bool isLow() const;
        bool isHigh() const;

    public:
        ParameterMonitoring(const std::string name, const _Float32 value, const _Float32 min, const _Float32 max, const _Float32 tolerance);
        std::string getStateStatus();
        void setValue(const _Float32 input);
        void configureWarning(const bool input);
        bool isOk() const;        
};
