#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;


class Bird : public Animal 
{
private:
    double wingspan; // размах крыльев
    bool canFly; // возможность летать

public:
    Bird(int id, const string& name, const string& breed, int age, const string& admissionDate, double wingspan = 0.0, bool canFly = true);

    string getFeedSchedule() const override;// расписание кормлени€
    string getTreatmentProtocol() const override;// протокол лечени€
    void printInfo() const override;

    // ћетоды дл€ птиц
    void setWingspan(double ws) 
    {
        wingspan = ws; 
    }
    double getWingspan() const 
    { 
        return wingspan; 
    }
    void canFly()
    {
        canFly = false;
    }
    bool canFly() const
    {
        return canFly;
    }
};



