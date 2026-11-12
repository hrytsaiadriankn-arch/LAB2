#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pay
{
private:
    double first;  // Оклад
    int second;    // Кількість відпрацьованих днів

public:
    // Конструктори
    Pay();
    Pay(double, int);
    Pay(const Pay&);

    // Деструктор
    ~Pay();

    // Методи доступу
    void SetFirst(double);
    void SetSecond(int);

    double GetFirst() const;
    int GetSecond() const;

    // Метод обчислення зарплати
    double summa(int workingDaysInMonth) const;

    // Перевантаження операцій
    Pay& operator = (const Pay&);
    operator string() const;

    // Введення та виведення
    friend ostream& operator << (ostream&, const Pay&);
    friend istream& operator >> (istream&, Pay&);

    // Інкремент і декремент
    Pay& operator ++();
    Pay& operator --();

    Pay operator ++(int);
    Pay operator --(int);
};

// Функція створення об'єкта
Pay makePay(double, int);
