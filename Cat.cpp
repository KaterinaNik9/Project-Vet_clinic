#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat(int id, const string& name, const string& breed, int age, const string& admissionDate, bool isLitterTrained)
    : Animal(id, name, "Cat", breed, age, admissionDate), isLitterTrained(isLitterTrained) {} // проблема с isLitterTrained

string Cat::getFeedSchedule() const 
{
    if (age < 1) 
    {
        return "Кормить 3-4 раза в день кормом для котенков";
    }
    else 
    {
        return "Кормить 2 раза в день кормом для взрослых кошек (смешать сухой и мокрый корма)";
    }
}

string Cat::getTreatmentProtocol() const 
{
    string protocol = "Стандартный протокол лечения собак:\n";
    protocol += "- Ежегодная вакцинация (FVRCP, бешенство)\n";
    protocol += "- Рекомендовано тестирование на FeLV/FIV\n";
    protocol += "- Регулярная дегельминтизация каждые 3 месяца\n";
    protocol += "- Уход за зубами: чистить зубы еженедельно";

    return protocol;
}

void Cat::printInfo() const 
{
    Animal::printInfo();
    cout << "Приучен к лотку: " << (isLitterTrained ? "Да" : "Нет") << endl;
}
