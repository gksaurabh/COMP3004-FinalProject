#ifndef REALTIMECPRFEEDBACK_H
#define REALTIMECPRFEEDBACK_H
#include <QString>
#include <QList>
class RealtimeCPRFeedback
{
public:
    RealtimeCPRFeedback();
    int analyze(QList<int>);
    bool shock(bool);
    void CPR(bool);


};

#endif // REALTIMECPRFEEDBACK_H
