#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
//megabank /
//├── main.cpp - точка входа, демонстрация работы
//├── exceptions.h - иерархия исключений
//├── account.h / .cpp - абстрактный базовый класс Account
//├── savings.h / .cpp - класс SavingsAccount
//├── credit.h / .cpp - класс CreditAccount
//├── deposit.h / .cpp - класс DepositAccount
//├── bank.h / .cpp - класс Bank(вложенные классы Config, Statistics)
//├── structures.h - шаблонные Stack, Queue, PriorityQueue
//├── auditor.h - класс Auditor
//└── ui.h - вспомогательные функции вывода

class BankException : public std::exception
{
protected:
    string message;
public:
    explicit BankException(const string& _message): message(_message){}

    const string& get_message() const { return message; }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

class InsufficientFundsEx : public BankException
{
    explicit InsufficientFundsEx(const string& _message) : BankException(_message) {}

    explicit InsufficientFundsEx(int accountId, double requested, double available)
        : BankException("Недостаточно средств на счете " + std::to_string(accountId) + ": запрошено " + std::to_string(requested) +
            ", доступно " + std::to_string(available)) {}
};

class NegativeAmountEx : public BankException
{
    explicit NegativeAmountEx(const string& _message) : BankException(_message) {}

    explicit NegativeAmountEx(int amount)
        : BankException("Недоступное цисло: " + std::to_string(amount) +
            ". Оно должно быть положительным.") {}
};

class AccountNotFoundEx : public BankException
{
    explicit AccountNotFoundEx(const string& _message) : BankException(_message) {}

    explicit AccountNotFoundEx(int accountId)
        : BankException("Предоставленный ID: " + std::to_string(accountId) + "не найден") {
    }
};

class DuplicateAccountEx : public BankException
{
    explicit DuplicateAccountEx(const string& _message) :BankException(_message) {}

    explicit DuplicateAccountEx(int accountId)
        : BankException("Предоставленный ID: " + std::to_string(accountId) + "уже существует") {
    }
};


struct Transaction
{
    double amount;
    string timestamp;
    string counterparty;
    string type;

    explicit Transaction(double _amount = 0.0, const string& _timestamp, const string& _counterparty, const string& _type)
        : amount(_amount), timestamp(_timestamp), counterparty(_counterparty), type(_type) {}
    string toString() const
    {
        if (type == "deposit")
        {
            cout << "[" << timestamp << "] ПОПОЛНЕНИЕ: +" << amount << " руб.";
        }

        if (type == "withdraw")
        {
            cout << "[" << timestamp << "] СНЯТИЕ: -" << amount << " руб.";
        }

        if (type == "transfer_in")
        {
            cout << "[" << timestamp << "] ПЕРЕВОД (входящий): +" << amount << " руб." << "Отправитель: " << counterparty;
        }

        if (type == "transfer_out")
        {
            cout << "[" << timestamp << "] ПЕРЕВОД (исходящий): -" << amount << " руб." << "Получатель: " << counterparty;
        }

        if (type == "open")
        {
            cout << "[" << timestamp << "]ОТКРЫТИЕ СЧЁТА: начальный баланс +" << amount << " руб.";
        }

        if (type == "interest")
        {
            cout << "[" << timestamp << "] НАЧИСЛЕНИЕ ПРОЦЕНТОВ: +" << amount << " руб.";
        }

        if (type == "close")
        {
            cout << "[" << timestamp << "] ЗАКРЫТИЕ СЧЁТА: остаток выведен -" << amount << " руб.";
        }
        
        return timestamp;
    }
};

class Account
{
private:
    int id;
    static int totalAccounts;
    static double totalMoneyInSystem;

protected:
    string ownerName;
    double balance;
    string currency;
    Stack<Transaction> history;

public:
    Account(int _id, const string& _ownerName, double _balance = 0.0, string _currency = "RUB") 
        : id(_id), ownerName(_ownerName), balance(_balance), currency(_currency) 
    {
        totalAccounts++;
        totalMoneyInSystem += balance;
    }
    Account() {}
    Account(const Account& other) : id(id + other.id), ownerName(other.ownerName),balance(other.balance), currency(other.currency)
    {
        totalAccounts++;
        totalMoneyInSystem += balance;
    }
    virtual ~Account() 
    {
        totalAccounts--;
        totalMoneyInSystem -= balance;
    }


    int getId() const 
    {
        return id;
    }

    string getOwner() const
    {
        return ownerName;
    }

    int getBalance() const
    {
        return balance;
    }

    string getCurrency() const
    {
        return currency;
    }


    void setOwner(const string& name) 
    {
        this->ownerName = ownerName;
    }

    void addHistory(const Transaction& transaction)
    {
        history.push(transaction);
    }


    string printHistory()
    {
        if (history.isEmpty())
        {
            cout << "История транзакций пуста" << endl;
        }
        if (!history.isEmpty())
        {
            cout << history.pop().toString() <<endl;
        }
    }

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual std::string getType() const = 0;
    virtual double getAvailable() const = 0;
    virtual void printInfo() const
    {
        cout << "Тип счёта: " << getType() << std::endl;
        cout << "ID: " << id << std::endl;
        cout << "Владелец: " << ownerName << std::endl;
        cout << "Баланс: " << balance << " " << currency << std::endl;
        cout << "Доступно для снятия: " << getAvailable() << " " << currency << std::endl;
        
    }

    int getTotalAccounts()
    {
        return totalAccounts;
    }

    double getTotalMoneyInSystem()
    {
        return totalMoneyInSystem;
    }

    bool operator==(const Account& other) const;
    bool operator!=(const Account& other) const;
    bool operator<(const Account& other) const;
    Account& operator+=(double amount);
    Account& operator-=(double amount);
    static friend ostream& operator<<(std::ostream& os, const Account& account);
};




int Account::getTotalAccounts() {
    
}

double Account::getTotalMoneyInSystem() {
    return totalMoneyInSystem;
}

// Перегруженные операторы
bool Account::operator==(const Account& other) const 
{
    return id == other.id;
}

bool Account::operator!=(const Account& other) const 
{
    return !(*this == other);
}

bool Account::operator<(const Account& other) const 
{
    return balance < other.balance;
}

Account& Account::operator+=(double amount) 
{
    deposit(amount);
    return *this;
}

Account& Account::operator-=(double amount) 
{
    withdraw(amount);
    return *this;
}

ostream& operator<<(std::ostream& os, const Account& account)
{
    os << "[" << account.getType() << "|" << account.id << "] " << account.ownerName << " : " << account.balance << " " << account.currency;
    return os;
}


//    Дружественные классы : Auditor, Bank

int main()
{
    std::cout << "Hello World!\n";
}

