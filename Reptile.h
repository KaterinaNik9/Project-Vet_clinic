#pragma once

#include <iostream>
#include "Animal.h"
using namespace std;

class Reptile : public Animal 
{
private:
    bool isColdBlooded; // холоднокровное животное 
    string habitatType; // тип (где живет)

public:
    Reptile(int id, const string& name, const string& breed, int age, const string& admissionDate, const string& habitatType = "Террариум");

    string getFeedSchedule() const override;// расписание кормления
    string getTreatmentProtocol() const override;// протокол лечения
    void printInfo() const override;

    // Методы для рептилий
    void setHabitatType(const string& habitat) 
    { 
        habitatType = habitat; 
    }
    string getHabitatType() const 
    { 
        return habitatType; 
    }
};



