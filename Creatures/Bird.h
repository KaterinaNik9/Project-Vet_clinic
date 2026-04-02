#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Bird : public Animal 
{
private:
    double wingspan;
    bool canFly;

public:
    Bird(
        int id, 
        const string& name, 
        const string& breed, 
        int age, 
        const string& admissionDate, 
        double wingspan = 0.0, 
        bool canFly = true
    );

    string getFeedSchedule() const override;

    string getTreatmentProtocol() const override;

    void printInfo() const override;

    void setWingspan(double ws) 
    {
        wingspan = ws; 
    }

    double getWingspan() const 
    { 
        return wingspan; 
    }

    void setCanFly(bool status)
    {
        canFly = status;
    }

    bool getCanFly() const
    {
        return canFly;
    }
};
