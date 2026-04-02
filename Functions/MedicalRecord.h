#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Treatment;

class MedicalRecord {
private:
    string date;
    string diagnosis;
    string treatmentDescription;
    vector<shared_ptr<Treatment>> treatments;
    bool isActive;

public:
    MedicalRecord(const string& date, const string& diagnosis, const string& treatmentDescription);

    void addTreatment(shared_ptr<Treatment> treatment);
    void print() const;
    string getDate() const 
    { 
        return date; 
    }
    string getDiagnosis() const 
    { 
        return diagnosis; 
    }
    bool getIsActive() const 
    { 
        return isActive; 
    }
    void setIsActive(bool active) 
    { 
        isActive = active; 
    }
};


