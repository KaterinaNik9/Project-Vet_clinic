#include "Reptile.h"
#include <iostream>
using namespace std;

Reptile::Reptile(int id, const string& name, const string& breed, int age, const string& admissionDate, const string& habitatType)
    : Animal(id, name, "Reptile", breed, age, admissionDate),
    isColdBlooded(true), habitatType(habitatType) {}

string Reptile::getFeedSchedule() const 
{
    return "Рацион зависит от вида: насекомые - корм для насекомоядных, грызуны - корм для хищников, "
        "или овощи для травоядных. Частота кормления: каждые 2-7 дней.";
}

string Reptile::getTreatmentProtocol() const
{
    return "Ветеринарный протокол для рептилий:\n"
        "- Обеспечение правильного температурного градиента (24-29°C)\n"
        "- Наличие UVB-лампы необходимо для усвоения кальция\n"
        "- Мониторинг процесса линьки\n"
        "- Регулирование влажности в зависимости от вида\n"
        "- Ежегодный копрологический анализ на паразитов";
}

void Reptile::printInfo() const 
{
    Animal::printInfo();
    cout << "Холоднокровные: да" << endl;
    cout << "Тип рептилии: " << habitatType << endl;
}
