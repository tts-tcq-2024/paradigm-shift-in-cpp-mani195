
BatterySystem::BatterySystem(const _Float32 temperature, const _Float32 chargeState, const _Float32 chargeRate)
 : monitorTemperature(std::make_unique<ParameterMonitoring>("TEMPERATURE", temperature,0.0,45.0,45.0 *0.05)),
 monitorChargeState(std::make_unique<ParameterMonitoring>("SOC", chargeState,20.0,80.0,80.0 *0.05)),
 monitorChargeRate(std::make_unique<ParameterMonitoring>("CHARGE_RATE", chargeRate,0.0,0.8,0.8 *0.05))
{
}

bool BatterySystem::isOk() const{
 return monitorTemperature->isOk() && monitorChargeState->isOk() && monitorChargeRate->isOk();
}

std::string BatterySystem::getStateStatus()
{
 return monitorTemperature->getStateStatus() + " " + monitorChargeState->getStateStatus() + " " + monitorChargeRate->getStateStatus();
}

void BatterySystem::setTemperature(const _Float32 input)
{
 monitorTemperature->setValue(input);
}

void BatteryBatterySystem::setChargeState(const _Float32 input)
{
 monitorChargeState->setValue(input);
}

void BatterySystem::setChargeRate(const _Float32 input)
{
 monitorChargeRate->setValue(input);
}
