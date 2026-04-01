#include "AnimalHospital.h"
#include <iostream>
#include <algorithm>

using namespace std;

void AnimalHospital::addAnimal(shared_ptr<Animal> animal) 
{
    if (animal) 
    {
        animals.push_back(animal);
    }
}

void AnimalHospital::removeAnimal(int id) 
{
    auto it = remove_if(
        animals.begin(), 
        animals.end(), 
        [id](const shared_ptr<Animal>& a) 
        { 
            return a->getId() == id; 
        }
    );
    
    animals.erase(it, animals.end());
}

shared_ptr<Animal> AnimalHospital::findAnimalById(int id) const 
{
    for (const auto& animal : animals) 
    {
        if (animal->getId() == id) 
        {
            return animal;
        }
    }
    
    return nullptr;
}

void AnimalHospital::createAppointment(
    shared_ptr<Animal> animal, 
    const string& vet, 
    const string& date, 
    const string& time, 
    const string& reason
) 
{
    schedule.push_back(
        make_unique<Appointment>(
            animal, 
            vet, 
            date, 
            time, 
            reason
        )
    );
}

void AnimalHospital::printAllAnimals() const 
{
    cout << "=== Список пациентов клиники ===" << endl;
    
    for (const auto& animal : animals) 
    {
        animal->printInfo();
        cout << "---" << endl;
    }
}

void AnimalHospital::printSchedule() const 
{
    cout << "=== График приемов ===" << endl;
    
    for (const auto& appointment : schedule) 
    {
        appointment->printAppointmentInfo();
    }
}
