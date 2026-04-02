#pragma once

#include <iostream>
#include "Animal.h"

using namespace std;

class Dog : public Animal 
{
private:
    bool isVaccinated;

public:
    Dog(
        int id, 
        const string& name, 
        const string& breed, 
        int age, 
        const string& admissionDate, 
        bool isVaccinated = false
    );

    string getFeedSchedule() const override;

    string getTreatmentProtocol() const override;

    void printInfo() const override;

    void vaccinate() 
    { 
        isVaccinated = true; 
    }

    bool getIsVaccinated() const 
    { 
        return isVaccinated; 
    }
};
