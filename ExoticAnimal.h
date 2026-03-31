#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class ExoticAnimal : public Animal 
{
private:
    string originCountry; // место обитания
    string specialPermitNumber; // специальное разрешение
    bool requiresSpecialist; // нужен ли специалист

public:
    ExoticAnimal(int id, const string& name, const string& species, const string& breed, int age, const std::string& admissionDate,
        const std::string& originCountry, const std::string& specialPermitNumber = "");

    string getFeedSchedule() const override;
    string getTreatmentProtocol() const override;
    void printInfo() const override;

    // Методы для экзотических животных
    void setSpecialPermit(const string& permit) 
    { 
        specialPermitNumber = permit; 
    }
    string getSpecialPermit() const 
    { 
        return specialPermitNumber; 
    }
};



