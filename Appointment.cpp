#include "Appointment.h"
#include <iostream>

using namespace std;

Appointment::Appointment(
    shared_ptr<Animal> animal, 
    const string& vetName, 
    const string& date, 
    const string& time, 
    const string& reason
)
    : animal(animal), 
      vetName(vetName), 
      date(date), 
      time(time), 
      reason(reason) 
{
}

void Appointment::printAppointmentInfo() const 
{
    cout << "--- Запись на прием ---" << endl;
    cout << "Дата и время: " << date << " | " << time << endl;
    cout << "Врач: " << vetName << endl;
    cout << "Причина: " << reason << endl;
    
    if (animal) 
    {
        cout << "Пациент: " << animal->getName() << " (" << animal->getSpecies() << ")" << endl;
    }
    
    cout << "-----------------------" << endl;
}
