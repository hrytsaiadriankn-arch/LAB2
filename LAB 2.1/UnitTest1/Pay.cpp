#include "pch.h"
#include "Pay.h"
#include <sstream>
#include <cstdlib>

// Конструктор за замовчуванням
Pay::Pay()
{
    first = 1;
    second = 1;
}

// Конструктор ініціалізації
Pay::Pay(double salary, int days)
{
    SetFirst(salary);
    SetSecond(days);
}

// Конструктор копіювання
Pay::Pay(const Pay& p)
{
    first = p.first;
    second = p.second;
}

// Деструктор
Pay::~Pay()
{
}

// Запис окладу
void Pay::SetFirst(double salary)
{
    if (salary <= 0)
    {
        cout << "Error: salary must be positive!" << endl;
        exit(1);
    }

    first = salary;
}

// Запис кількості днів
void Pay::SetSecond(int days)
{
    if (days <= 0)
    {
        cout << "Error: working days must be positive!" << endl;
        exit(1);
    }

    second = days;
}

// Отримання окладу
double Pay::GetFirst() const
{
    return first;
}

// Отримання кількості днів
int Pay::GetSecond() const
{
    return second;
}

// Обчислення нарахованої суми
double Pay::summa(int workingDaysInMonth) const
{
    if (workingDaysInMonth <= 0)
    {
        cout << "Error: invalid number of working days!" << endl;
        exit(1);
    }

    return first / workingDaysInMonth * second;
}

// Операція присвоєння
Pay& Pay::operator = (const Pay& p)
{
    if (this != &p)
    {
        first = p.first;
        second = p.second;
    }

    return *this;
}

// Перетворення об'єкта в рядок
Pay::operator string() const
{
    stringstream ss;

    ss << "Salary: " << first << endl;
    ss << "Working days: " << second << endl;

    return ss.str();
}

// Операція виведення
ostream& operator << (ostream& out, const Pay& p)
{
    out << string(p);
    return out;
}

// Операція введення
istream& operator >> (istream& in, Pay& p)
{
    double salary;
    int days;

    cout << "Enter salary: ";
    in >> salary;

    cout << "Enter working days: ";
    in >> days;

    p.SetFirst(salary);
    p.SetSecond(days);

    return in;
}

// Префіксний інкремент
Pay& Pay::operator ++()
{
    first += 1;
    return *this;
}

// Префіксний декремент
Pay& Pay::operator --()
{
    if (first > 1)
        first -= 1;

    return *this;
}

// Постфіксний інкремент
Pay Pay::operator ++(int)
{
    Pay temp(*this);
    second += 1;
    return temp;
}

// Постфіксний декремент
Pay Pay::operator --(int)
{
    Pay temp(*this);

    if (second > 1)
        second -= 1;

    return temp;
}

// Функція створення об'єкта
Pay makePay(double salary, int days)
{
    if (salary <= 0 || days <= 0)
    {
        cout << "Error: incorrect parameters!" << endl;
        exit(1);
    }

    return Pay(salary, days);
}
