#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Cat : public Animal 
{
private:
    bool isLitterTrained;

public:
    Cat(
        int id, 
        const string& name, 
        const string& breed, 
        int age, 
        const string& admissionDate, 
        bool isLitterTrained = true
    );

    string getFeedSchedule() const override;

    string getTreatmentProtocol() const override;

    void printInfo() const override;

    void setIsLitterTrained(bool trained) 
    { 
        isLitterTrained = trained; 
    }

    bool getIsLitterTrained() const 
    { 
        return isLitterTrained; 
    }
};
