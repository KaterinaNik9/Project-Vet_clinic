#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Animal.h"
#include "Appointment.h"

using namespace std;

class AnimalHospital 
{
private:
    vector<shared_ptr<Animal>> animals;
    vector<unique_ptr<Appointment>> schedule;

public:
    AnimalHospital() 
    {
    }

    void addAnimal(shared_ptr<Animal> animal);

    void removeAnimal(int id);

    void createAppointment(
        shared_ptr<Animal> animal, 
        const string& vet, 
        const string& date, 
        const string& time, 
        const string& reason
    );

    shared_ptr<Animal> findAnimalById(int id) const;

    void printAllAnimals() const;

    void printSchedule() const;
};
