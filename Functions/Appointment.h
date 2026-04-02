#pragma once

#include <string>
#include <memory>
#include "Animal.h"

using namespace std;

class Appointment 
{
private:
    shared_ptr<Animal> animal;
    string vetName;
    string date;
    string time;
    string reason;

public:
    Appointment(
        shared_ptr<Animal> animal, 
        const string& vetName, 
        const string& date, 
        const string& time, 
        const string& reason
    );

    void printAppointmentInfo() const;

    string getDate() const 
    { 
        return date; 
    }

    shared_ptr<Animal> getAnimal() const 
    { 
        return animal; 
    }
};
