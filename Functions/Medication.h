#pragma once

#include "Treatment.h"

using namespace std;

class Medication : public Treatment 
{
private:
    string medicineName;
    string dosage;
    int durationDays;

public:
    Medication(
        const string& description, 
        const string& date, 
        double cost, 
        const string& medicineName, 
        const string& dosage, 
        int durationDays
    );

    void printInfo() const override;

    void setDosage(const string& newDosage) 
    { 
        dosage = newDosage; 
    }

    string getMedicineName() const 
    { 
        return medicineName; 
    }
};
