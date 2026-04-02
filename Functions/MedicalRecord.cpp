#include "MedicalRecord.h"
#include "Treatment.h"
#include <iostream>

using namespace std;

MedicalRecord::MedicalRecord(
    const string& date, 
    const string& diagnosis, 
    const string& treatmentDescription
)
    : date(date), 
      diagnosis(diagnosis), 
      treatmentDescription(treatmentDescription), 
      isActive(true) 
{
}

void MedicalRecord::addTreatment(shared_ptr<Treatment> treatment)
{
    treatments.push_back(treatment);
}

void MedicalRecord::print() const 
{
    cout << "Дата записи: " << date << endl;
    cout << "Диагноз: " << diagnosis << endl;
    cout << "Описание лечения: " << treatmentDescription << endl;
    
    if (isActive) 
    {
        cout << "Статус: Активно" << endl;
    }
    else 
    {
        cout << "Статус: Завершено" << endl;
    }

    if (!treatments.empty()) 
    {
        cout << "Назначенные процедуры:" << endl;
        
        for (const auto& treatment : treatments) 
        {
            treatment->printInfo();
        }
    }
}
