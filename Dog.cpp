#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog(int id, const string& name, const string& breed, int age, const string& admissionDate, bool isVaccinated)
    : Animal(id, name, "Dog", breed, age, admissionDate), isVaccinated(isVaccinated) {}

string Dog::getFeedSchedule() const 
{
    if (age < 1) 
    {
        return " Кормить 3-4 раза в день кормом для щенков";
    }
    else if (age < 7) 
    {
        return "Кормить 2 раза в день кормом для взрослых собак";
    }
    else 
    {
        return "Кормить 2 раза в день кормом для пожалых собак";
    }
}

string Dog::getTreatmentProtocol() const 
{
    string protocol = "Стандартный протокол лечения собак:\n";
    protocol += "- Ежегодная вакцинация (DHPP, бешенство)\n";
    protocol += "- Ежемесечная профилактика сердечного гельминтоза\n";
    protocol += "- Ежемесячный контроль блох/клещей\n";
    protocol += "- Ежегодная профессиональная чистка зубов";

    if (!isVaccinated) 
    {
        protocol += "\n- СРОЧНО: Требуется немедленная вакцинация!";
    }

    return protocol;
}

void Dog::printInfo() const 
{
    Animal::printInfo();
    cout << "Статус вакцинации: " << (isVaccinated ? "Вакцинирована" : "Не вакцинирована") << endl;
}
