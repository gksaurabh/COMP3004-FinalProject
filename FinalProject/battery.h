#ifndef BATTERY_H
#define BATTERY_H


class Battery
{
private:
    int batteryPercentage;
    bool status;
public:
    Battery();
    void setBatteryPercentage(int);
    int getBatteryPercentage();
    bool getStatus();
    void setStatus(bool);
};

#endif // BATTERY_H