#include "Medication.h"
#include <iostream>

using namespace std;

Medication::Medication(
    const string& description, 
    const string& date, 
    double cost, 
    const string& medicineName, 
    const string& dosage, 
    int durationDays
)
    : Treatment(
        description, 
        date, 
        cost
    ), 
      medicineName(medicineName), 
      dosage(dosage), 
      durationDays(durationDays) 
{
}

void Medication::printInfo() const 
{
    cout << "Процедура: Назначение лекарства" << endl;
    cout << "Препарат: " << medicineName << endl;
    cout << "Дозировка: " << dosage << endl;
    cout << "Курс приема (дней): " << durationDays << endl;
    cout << "Описание: " << description << endl;
    cout << "Стоимость: " << cost << endl;
}
