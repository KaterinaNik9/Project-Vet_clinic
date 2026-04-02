#pragma once

#include <iostream>
#include "Animal.h"

using namespace std;

class Reptile : public Animal 
{
private:
    bool isColdBlooded;
    string habitatType;

public:
    Reptile(
        int id, 
        const string& name, 
        const string& breed, 
        int age, 
        const string& admissionDate, 
        const string& habitatType = "Террариум"
    );

    string getFeedSchedule() const override;

    string getTreatmentProtocol() const override;

    void printInfo() const override;

    void setHabitatType(const string& habitat) 
    { 
        habitatType = habitat; 
    }

    string getHabitatType() const 
    { 
        return habitatType; 
    }
};
