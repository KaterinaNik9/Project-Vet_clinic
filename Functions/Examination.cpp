#include "Examination.h"
#include <iostream>

using namespace std;

Examination::Examination(
    const string& description, 
    const string& date, 
    double cost, 
    const string& findings, 
    const string& recommendations
)
    : Treatment(
        description, 
        date, 
        cost
    ), 
      findings(findings), 
      recommendations(recommendations) 
{
}

void Examination::printInfo() const 
{
    cout << "Процедура: Общий медицинский осмотр" << endl;
    cout << "Дата проведения: " << date << endl;
    cout << "Описание: " << description << endl;
    cout << "Результаты осмотра: " << findings << endl;
    cout << "Рекомендации врача: " << recommendations << endl;
    cout << "Стоимость: " << cost << endl;
}
