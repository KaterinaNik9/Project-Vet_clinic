#include "Vaccination.h"
#include <iostream>

using namespace std;

Vaccination::Vaccination(
    const string& description, 
    const string& date, 
    double cost, 
    const string& vaccineName, 
    const string& expirationDate
)
    : Treatment(
        description, 
        date, 
        cost
    ), 
      vaccineName(vaccineName), 
      expirationDate(expirationDate) 
{
}

void Vaccination::printInfo() const 
{
    cout << "Процедура: Вакцинация" << endl;
    cout << "Описание: " << description << endl;
    cout << "Препарат: " << vaccineName << endl;
    cout << "Дата: " << date << endl;
    cout << "Стоимость: " << cost << endl;
}
