#pragma once

#include "Treatment.h"

using namespace std;

class Vaccination : public Treatment 
{
private:
    string vaccineName;
    string expirationDate;

public:
    Vaccination(
        const string& description, 
        const string& date, 
        double cost, 
        const string& vaccineName, 
        const string& expirationDate
    );

    void printInfo() const override;
};
