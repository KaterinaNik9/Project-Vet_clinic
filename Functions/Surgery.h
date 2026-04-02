#pragma once

#include "Treatment.h"

using namespace std;

class Surgery : public Treatment 
{
private:
    string surgeryType;
    string riskLevel;

public:
    Surgery(
        const string& description, 
        const string& date, 
        double cost, 
        const string& surgeryType, 
        const string& riskLevel
    );

    void printInfo() const override;
};
