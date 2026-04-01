#include "Surgery.h"
#include <iostream>

using namespace std;

Surgery::Surgery(
    const string& description, 
    const string& date, 
    double cost, 
    const string& surgeryType, 
    const string& riskLevel
)
    : Treatment(
        description, 
        date, 
        cost
    ), 
      surgeryType(surgeryType), 
      riskLevel(riskLevel) 
{
}

void Surgery::printInfo() const 
{
    cout << "Процедура: Хирургическое вмешательство" << endl;
    cout << "Тип операции: " << surgeryType << endl;
    cout << "Уровень риска: " << riskLevel << endl;
    cout << "Дата: " << date << endl;
    cout << "Стоимость: " << cost << endl;
}
