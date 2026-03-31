#include "ExoticAnimal.h"
#include <iostream>
using namespace std;

ExoticAnimal::ExoticAnimal(int id, const string& name, const string& species, const string& breed, int age, const string& admissionDate,
    const string& originCountry, const std::string& specialPermitNumber)
    : Animal(id, name, species, breed, age, admissionDate),
    originCountry(originCountry), specialPermitNumber(specialPermitNumber), requiresSpecialist(true) {}

string ExoticAnimal::getFeedSchedule() const 
{
    return "ТРЕБУЕТСЯ СПЕЦИАЛИЗИРОВАННЫЙ РАЦИОН: проконсультируйтесь со специалистом по экзотическим животным. "
        "Рацион существенно различается в зависимости от естественной среды обитания и биологических особенностей вида.";
}

string ExoticAnimal::getTreatmentProtocol() const 
{
    string protocol = "ПРОТОКОЛ ЛЕЧЕНИЯ ЭКЗОТИЧЕСКИХ ЖИВОТНЫХ - ТРЕБУЕТСЯ СПЕЦИАЛИСТ:\n";
    protocol += "- Лечение осуществляется сертифицированным ветеринарным врачом по экзотическим животным\n";
    protocol += "- Карантинный период: не менее 30 дней\n";
    protocol += "- Необходимо специализированное обогащение среды обитания\n";
    protocol += "- Регулярный контроль соблюдения требований СИТЕС\n";
    protocol += "- Специальные правила обращения ввиду высокой чувствительности к стрессу";

    if (!specialPermitNumber.empty()) 
    {
        protocol += "\n- Разрешение номер: " + specialPermitNumber;
    }

    return protocol;
}

void ExoticAnimal::printInfo() const 
{
    Animal::printInfo();
    cout << "Страна обитания: " << originCountry << endl;
    cout << "Требуется специалист: Да" << endl;
    if (!specialPermitNumber.empty()) 
    {
        cout << "Специальное разрешение: " << specialPermitNumber << endl;
    }
}