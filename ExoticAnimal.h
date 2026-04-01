#pragma once

#include <iostream>
#include "Animal.h"

using namespace std;

class ExoticAnimal : public Animal 
{
private:
    string originCountry;
    string specialPermitNumber;
    bool requiresSpecialist;

public:
    ExoticAnimal(
        int id, 
        const string& name, 
        const string& species, 
        const string& breed, 
        int age, 
        const string& admissionDate,
        const string& originCountry, 
        const string& specialPermitNumber = ""
    );

    string getFeedSchedule() const override;

    string getTreatmentProtocol() const override;

    void printInfo() const override;

    void setSpecialPermit(const string& permit) 
    { 
        specialPermitNumber = permit; 
    }

    string getSpecialPermit() const 
    { 
        return specialPermitNumber; 
    }
};
