#include <iostream>
#include <memory>
#include <string>
#include <limits>
#include <vector>
#include <clocale>

#include "AnimalHospital.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "Reptile.h"
#include "ExoticAnimal.h"
#include "MedicalRecord.h"
#include "Vaccination.h"
#include "Surgery.h"
#include "Medication.h"
#include "Examination.h"

using namespace std;

void clearInput() 
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showMainMenu() 
{
    cout << "1. Регистрация нового пациента" << endl;
    cout << "2. Список всех пациентов" << endl;
    cout << "3. Работа с медицинской картой" << endl;
    cout << "4. Запланировать визит" << endl;
    cout << "5. График приемов" << endl;
    cout << "6. Удалить запись" << endl;
    cout << "0. Выход" << endl;
    cout << "Выбор: ";
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    AnimalHospital hospital;
    int mainChoice = -1;

    while (mainChoice != 0) 
    {
        showMainMenu();
        cin >> mainChoice;
        clearInput();

        if (mainChoice == 1) 
        {
            int type, id, age;
            string name, breed, date;

            cout << "Тип (1-Собака, 2-Кошка, 3-Птица, 4-Рептилия, 5-Экзот): ";
            cin >> type;
            clearInput();

            cout << "ID: "; cin >> id; clearInput();
            cout << "Кличка: "; getline(cin, name);
            cout << "Порода: "; getline(cin, breed);
            cout << "Возраст: "; cin >> age; clearInput();
            cout << "Дата поступления: "; getline(cin, date);

            shared_ptr<Animal> newAnimal = nullptr;

            if (type == 1) newAnimal = make_shared<Dog>(id, name, breed, age, date, true);
            else if (type == 2) newAnimal = make_shared<Cat>(id, name, breed, age, date, true);
            else if (type == 3) newAnimal = make_shared<Bird>(id, name, breed, age, date, 30.0, true);
            else if (type == 4) newAnimal = make_shared<Reptile>(id, name, breed, age, date, "Террариум");
            else if (type == 5) newAnimal = make_shared<ExoticAnimal>(id, name, "Экзотическое", breed, age, date, "Неизвестно", "НЕТ");

            if (newAnimal) 
            {
                hospital.addAnimal(newAnimal);
                
                cout << "Нужно ли лечение? (1-Да, 0-Нет): ";
                int needTreatment;
                cin >> needTreatment;
                clearInput();

                if (needTreatment == 1) 
                {
                    string diag;
                    cout << "Диагноз: ";
                    getline(cin, diag);
                    MedicalRecord initialRecord(date, diag, "Требуется наблюдение");
                    initialRecord.setIsActive(true);
                    newAnimal->addMedicalRecord(initialRecord);
                }
            }
        }
        else if (mainChoice == 2) 
        {
            hospital.printAllAnimals();
        }
        else if (mainChoice == 3) 
        {
            int id;
            cout << "ID пациента: ";
            cin >> id;
            clearInput();

            auto animal = hospital.findAnimalById(id);
            if (animal) 
            {
                cout << "Состояние: 1.Здоров, 2.Болен (назначить процедуру): ";
                int status;
                cin >> status;
                clearInput();

                if (status == 1) 
                {
                    MedicalRecord healthyRecord("2026-04-01", "Здоров", "Осмотрен, жалоб нет");
                    healthyRecord.setIsActive(false);
                    animal->addMedicalRecord(healthyRecord);
                }
                else 
                {
                    string diag, desc;
                    cout << "Диагноз: "; getline(cin, diag);
                    cout << "План лечения: "; getline(cin, desc);

                    MedicalRecord record("2026-04-01", diag, desc);
                    record.setIsActive(true);

                    cout << "Процедура (1-Вакцина, 2-Операция, 3-Лекарство, 4-Осмотр, 0-Нет): ";
                    int tType;
                    cin >> tType;
                    clearInput();

                    if (tType == 1) record.addTreatment(make_shared<Vaccination>("Вакцинация", "2026-04-01", 1000.0, "Стандарт", "2027-01-01"));
                    else if (tType == 2) record.addTreatment(make_shared<Surgery>("Операция", "2026-04-01", 5000.0, "Общая", "Низкий"));
                    else if (tType == 3) record.addTreatment(make_shared<Medication>("Лекарство", "2026-04-01", 300.0, "Препарат", "1т/день", 5));
                    else if (tType == 4) record.addTreatment(make_shared<Examination>("Осмотр", "2026-04-01", 500.0, "Норма", "Без рекомендаций"));

                    animal->addMedicalRecord(record);
                }
            }
        }
        else if (mainChoice == 4) 
        {
            int id;
            cout << "ID пациента: "; cin >> id; clearInput();
            auto animal = hospital.findAnimalById(id);
            
            if (animal) 
            {
                string vet, d, t, r;
                cout << "Врач: "; getline(cin, vet);
                cout << "Дата: "; getline(cin, d);
                cout << "Время: "; getline(cin, t);
                cout << "Причина: "; getline(cin, r);

                hospital.createAppointment(animal, vet, d, t, r);
            }
        }
        else if (mainChoice == 5) 
        {
            hospital.printSchedule();
        }
        else if (mainChoice == 6) 
        {
            int id;
            cout << "ID для удаления: ";
            cin >> id;
            hospital.removeAnimal(id);
        }
    }

    return 0;
}
