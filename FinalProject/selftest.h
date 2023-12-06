#ifndef SELFTEST_H
#define SELFTEST_H

#include<battery.h>

class SelfTest
{
private:
    Battery* b1;
    bool electrodeStatus;
    bool softwareIntegrity;
    bool haradwareCheck;
public:
    //Intially set everything to true
    SelfTest();
    bool performSelfTest();

};

#endif // SELFTEST_H
