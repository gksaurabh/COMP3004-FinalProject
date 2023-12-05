#ifndef PERSON_H
#define PERSON_H
#include<QString>

class Person
{
private:
    QString type;
    int age;
    int weight;
public:
    Person();
    Person(QString, int, int);

};

#endif // PERSON_H
