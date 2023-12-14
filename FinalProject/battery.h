#ifndef BATTERY_H
#define BATTERY_H
#include "selftest.h"



class Battery
{
private:
    int batteryPercentage = 100;
    bool status;
public:
    Battery();
    void setBatteryPercentage(int);
    int getBatteryPercentage();
    bool getStatus();
    void setStatus(bool);
};

#endif // BATTERY_H
