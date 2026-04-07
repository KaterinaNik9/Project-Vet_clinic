#pragma once
#include <string>
#include <vector>
#include <memory>
#include "MedicalRecord.h"

using namespace std;

class Animal
{
protected:
    int id;
    string name;
    string species;
    string breed;
    int age;
    string admissionDate;
    vector<MedicalRecord> medicalHistory; 
    bool isActive;

public:
    Animal(int id, const string& name, const string& species, const string& breed, int age, const string& admissionDate);
    virtual ~Animal() {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getSpecies() const { return species; }
    string getBreed() const { return breed; }
    int getAge() const { return age; }
    string getAdmissionDate() const { return admissionDate; }
    bool getIsActive() const { return isActive; }
    const vector<MedicalRecord>& getMedicalHistory() const { return medicalHistory; }

    void setName(const string& _name) { name = _name; }
    void setBreed(const string& _breed) { breed = _breed; }
    void setAge(int _age) { age = _age; }
    void setIsActive(bool active) { isActive = active; }

    void addMedicalRecord(const MedicalRecord& record);
    void printMedicalHistory() const;

    virtual string getFeedSchedule() const = 0;
    virtual string getTreatmentProtocol() const = 0;
    virtual void printInfo() const;

    bool operator==(const Animal& other) const { return id == other.id; }
};
