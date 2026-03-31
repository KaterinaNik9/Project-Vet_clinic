#pragma once
//#ifndef CAT_H
//#define CAT_H
#include <iostream>
#include "Animal.h"
using namespace std;

class Cat : public Animal 
{
private:
    bool isLitterTrained; // приучен к лотку

public:
    Cat(int id, const string& name, const string& breed, int age, const string& admissionDate, bool isLitterTrained = true);

    string getFeedSchedule() const override;// расписание кормления
    string getTreatmentProtocol() const override;// протокол лечения
    void printInfo() const override;

    // Методы для кошек
    void setIsLitterTrained(bool notTrained) 
    { 
        isLitterTrained = notTrained; 
    }
    bool isLitterTrained() const 
    { 
        return isLitterTrained; 
    }
};

//#endif

