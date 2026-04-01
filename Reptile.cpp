#include "Reptile.h"
#include <iostream>

using namespace std;

Reptile::Reptile(
    int id, 
    const string& name, 
    const string& breed, 
    int age, 
    const string& admissionDate, 
    const string& habitatType
)
    : Animal(
        id, 
        name, 
        "Reptile", 
        breed, 
        age, 
        admissionDate
    ),
      isColdBlooded(true), 
      habitatType(habitatType) 
{
}

string Reptile::getFeedSchedule() const 
{
    return "Рацион зависит от вида: насекомые - корм для насекомоядных, грызуны - корм для хищников, или овощи для травоядных. Частота кормления: каждые 2-7 дней.";
}

string Reptile::getTreatmentProtocol() const
{
    string protocol = "Ветеринарный протокол для рептилий:\n";
    
    protocol += "- Обеспечение правильного температурного градиента (24-29°C)\n";
    protocol += "- Наличие UVB-лампы необходимо для усвоения кальция\n";
    protocol += "- Мониторинг процесса линьки\n";
    protocol += "- Регулирование влажности в зависимости от вида\n";
    protocol += "- Ежегодный копрологический анализ на паразитов";

    return protocol;
}

void Reptile::printInfo() const 
{
    Animal::printInfo();
    
    cout << "Холоднокровные: Да" << endl;
    cout << "Среда обитания: " << habitatType << endl;
}
