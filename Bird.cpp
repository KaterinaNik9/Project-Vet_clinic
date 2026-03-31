#include "Bird.h"
#include <iostream>
using namespace std;


Bird::Bird(int id, const string& name, const string& breed, int age, const string& admissionDate, double wingspan, bool canFly)
    : Animal(id, name, "Bird", breed, age, admissionDate), wingspan(wingspan), canFly(canFly) {} // проблема с canFly

string Bird::getFeedSchedule() const 
{
    return "Кормить ежедневно специализированным зерновым кормом для птиц, свежими фруктами и овощами. "
        "Воду менять два раза в день.";
}

string Bird::getTreatmentProtocol() const 
{
    string protocol = "Ветеринарный протокол для птиц:\n";
    protocol += "- Проведение регулярной тримминга крыльев и когтей\n";
    protocol += "- Ежегодное профилактическое обследование у ветеринара-орнитолога\n";
    protocol += "- Контроль состояния дыхательной системы\n";
    protocol += "- Введение в рацион кальциевых добавок";

    if (!canFly) 
    {
        protocol += "\n- Для нелетающих птиц требуются особые условия содержания";
    }

    return protocol;
}

void Bird::printInfo() const 
{
    Animal::printInfo();
    cout << "Размах крыльев: " << wingspan << " см" << endl;
    cout << "Может летать: " << (canFly ? "Да" : "Нет") << endl;
}
