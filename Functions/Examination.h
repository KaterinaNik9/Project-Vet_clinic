#pragma once

#include "Treatment.h"

using namespace std;

class Examination : public Treatment 
{
private:
    string findings;
    string recommendations;

public:
    Examination(
        const string& description, 
        const string& date, 
        double cost, 
        const string& findings, 
        const string& recommendations
    );

    void printInfo() const override;

    void setFindings(const string& newFindings) 
    { 
        findings = newFindings; 
    }

    string getRecommendations() const 
    { 
        return recommendations; 
    }
};
