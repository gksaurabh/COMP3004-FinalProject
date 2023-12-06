#include "battery.h"

Battery::Battery()
{
    batteryPercentage = 100;
    status = true;
}

void Battery::setBatteryPercentage(int percentage){
    batteryPercentage = percentage;
}
int Battery::getBatteryPercentage(){
    return batteryPercentage;
}
bool Battery::getStatus(){
    return  status;
}

void Battery::setStatus(bool stat){
    status = stat;
}
