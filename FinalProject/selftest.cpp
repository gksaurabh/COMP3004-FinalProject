#include "selftest.h"
#include "battery.h"

SelfTest::SelfTest()
{
    b1 = new Battery();
    electrodeStatus = true;
    softwareIntegrity = true;
    hardwareCheck = true;
}

bool SelfTest::performSelfTest(){
    if((b1->getStatus() == true) && (electrodeStatus == true) && (softwareIntegrity == true) && (hardwareCheck == true)) {
      return true;
    }
    else{
        return false;
    }
}

void SelfTest::setBatteryStatus(bool status){
    b1->setStatus(status);
}

void SelfTest::setElectrodeStatus(bool status){
    electrodeStatus = status;
}

void SelfTest::setHardwareStatus(bool status){
    hardwareCheck = status;
}

void SelfTest::setSoftwareStatus(bool status){
    softwareIntegrity = status;
}
