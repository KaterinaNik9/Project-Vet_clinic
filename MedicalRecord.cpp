#include "MedicalRecord.h"
#include "Treatment.h"
#include <iostream>
using namespace std;

MedicalRecord::MedicalRecord(const string& date, const string& diagnosis, const string& treatmentDescription)
    : date(date), diagnosis(diagnosis), treatmentDescription(treatmentDescription), isActive(true) {}

void MedicalRecord::addTreatment(std::shared_ptr<Treatment> treatment)
{
    treatments.push_back(treatment);
}

void MedicalRecord::print() const 
{
    cout << "Дата записи: " << date << endl;
    cout << "Диагноз: " << diagnosis << endl;
    cout << "Лечение: " << treatmentDescription << endl;
    cout << "Статус: " << (isActive ? "Active" : "Completed") << endl;

    if (!treatments.empty()) 
    {
        cout << "Treatments administered:" << endl;
        for (const auto& treatment : treatments) 
        {
            treatment->printInfo();
        }
    }
}