#ifndef SELFTEST_H
#define SELFTEST_H

#include <battery.h>

class Battery;

class SelfTest
{
private:
    Battery* b1;
    bool electrodeStatus;
    bool softwareIntegrity;
    bool hardwareCheck;
public:
    //Intially set everything to true
    SelfTest();
    bool performSelfTest();

    //setters
    void setBatteryStatus(bool status);
    void setElectrodeStatus(bool status);
    void setSoftwareStatus(bool status);
    void setHardwareStatus(bool status);

};

#endif // SELFTEST_H
