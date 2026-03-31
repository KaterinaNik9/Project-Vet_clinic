#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;
//#ifndef DOG_H
//#define DOG_H
class Dog : public Animal 
{
private:
    bool isVaccinated;

public:
    Dog(int id, const string& name, const string& breed, int age, const string& admissionDate, bool isVaccinated = false);

    string getFeedSchedule() const override; // расписание кормления
    string getTreatmentProtocol() const override; // протокол лечения
    void printInfo() const override;

    // Методы для собак
    void vaccinate() 
    { 
        isVaccinated = true; 
    }
    bool getIsVaccinated() const 
    { 
        return isVaccinated; 
    }
};

//#endif

