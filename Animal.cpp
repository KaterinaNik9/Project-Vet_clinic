#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal(int id, const string& name, const string& species, const string& breed, int age, const string& admissionDate)
    : id(id), name(name), species(species), breed(breed), age(age), admissionDate(admissionDate), isActive(true) {}

void Animal::addMedicalRecord(const MedicalRecord& record) 
{
    medicalHistory.push_back(record);
}

void Animal::printMedicalHistory() const 
{
    if (medicalHistory.empty()) 
    {
        cout << "Не найдено медицинской записи для " << name << endl;
        return;
    }

    cout << "\nМедицинская история для " << name << " (ID: " << id << "):" << endl;
    cout << "------------------------------------------------" << endl;
    for (size_t i = 0; i < medicalHistory.size(); ++i) 
    {
        medicalHistory[i].display();// проблема с выводом истории
        cout << endl;
    }
}

void Animal::printInfo() const 
{
    cout << "ID: " << id <<endl;
    cout << "Имя: " << name << endl;
    cout << "Вид: " << species << endl;
    cout << "Порода: " << breed << endl;
    cout << "Возраст: " << age << " лет" << endl;
    cout << "Дата приема: " << admissionDate << endl;
    cout << "Статус: " << (isActive ? "Active" : "Discharged") << endl;
    cout << "Расписание кормления: " << getFeedSchedule() << endl;
    cout << "Протокол лечения: " << getTreatmentProtocol() << endl;
}
