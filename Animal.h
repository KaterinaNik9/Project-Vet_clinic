#pragma once
#include <string>
#include <vector>
//#include "MedicalRecord.h"
using namespace std;
//#ifndef ANIMAL_H
//#define ANIMAL_H
//#include <memory>

class MedicalRecord;

class Animal 
{
protected:
    int id;
    string name;
    string species;
    string breed; // порода
    int age;
    string admissionDate; // дата приема
    vector<MedicalRecord> medicalHistory;
    bool isActive;

public:
    Animal(int id, const string& name, const string& species, const string& breed, int age, const string& admissionDate);
    virtual ~Animal() {};

    // Getters
    int getId() const 
    { 
        return id; 
    }
    string getName() const 
    { 
        return name; 
    }
    string getSpecies() const 
    { 
        return species; 
    }
    string getBreed() const 
    { 
        return breed; 
    }
    int getAge() const 
    { 
        return age; 
    }
    string getAdmissionDate() const 
    { 
        return admissionDate; 
    }
    bool getIsActive() const 
    { 
        return isActive; 
    }
    const vector<MedicalRecord>& getMedicalHistory() const 
    { 
        return medicalHistory; 
    }

    // Setters
    void setName(const string& _name) 
    { 
        name = _name; 
    }
    void setBreed(const string& _breed) 
    { 
        breed = _breed; 
    }
    void setAge(int _age) 
    { 
        age = _age; 
    }
    void setIsActive(bool active) 
    { 
        isActive = active; 
    }



    // Medical record management
    void addMedicalRecord(const MedicalRecord& record);
    void printMedicalHistory() const;

    // Pure virtual methods
    virtual std::string getFeedSchedule() const = 0;
    virtual std::string getTreatmentProtocol() const = 0;



    // Вывести информацию о животном
    virtual void printInfo() const;

    // Operator overloading for comparison (оператор сравнения)
    bool operator==(const Animal& other) const 
    { 
        return id == other.id; 
    }
};

//#endif

