#include "ParameterMonitoring.h"

ParameterMonitoring::ParameterMonitoring(std::string name, _Float32 value, _Float32 min, _Float32 max, _Float32 tolerance)
: name(name), value(value), min(min), max(max), tolerance(tolerance)
{    
}

bool ParameterMonitoring::isOk() const
{
    return (Helper::isInRange(value, min + tolerance + 0.01, max - tolerance));   
}

std::string ParameterMonitoring::getStateStatus()//_Float32 actual, std::map<std::pair<_Float32, _Float32>, std::string> stateList
{
    for(const auto& temp : stateList)
    {
        if(Helper::isInRange(value, temp.first.first, temp.first.second))
        {
            return temp.second;
        }
    }
    return "INVALID";
}

void ParameterMonitoring::setValue(const _Float32 input)
{
    value = input;
}

void ParameterMonitoring::configureWarning(const bool input)
{
    warning = input;   
}

bool ParameterMonitoring::isLow() const
{
    return (warning && utils::isInRange(value, min + 0.01, min + tolerance));
}

bool ParameterMonitoring::isHigh() const
{
    return (warning && utils::isInRange(value, max - tolerance + 0.01, max));
}
