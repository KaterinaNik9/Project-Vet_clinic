#pragma once

#include <string>
#include <iostream>

using namespace std;

class Treatment 
{
protected:
    string description;
    string date;
    double cost;

public:
    Treatment(
        const string& description, 
        const string& date, 
        double cost
    );

    virtual ~Treatment() 
    {
    }

    virtual void printInfo() const = 0;

    string getDescription() const 
    { 
        return description; 
    }

    string getDate() const 
    { 
        return date; 
    }

    double getCost() const 
    { 
        return cost; 
    }
};
