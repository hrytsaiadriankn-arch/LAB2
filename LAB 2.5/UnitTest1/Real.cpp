#include "pch.h"
#include "Real.h"
#include <sstream>
#include <cmath>
#include <stdexcept>

// Конструктор без параметрів
Real::Real()
{
    number = Number();
}

// Конструктор ініціалізації
Real::Real(double value)
{
    number = Number(value);
}

// Конструктор з об'єктом Number
Real::Real(const Number& value)
{
    number = value;
}

// Конструктор копіювання
Real::Real(const Real& other)
{
    number = other.number;
}

// Метод отримання об'єкта Number
Number Real::getNumber() const
{
    return number;
}

// Метод зміни об'єкта Number
void Real::setNumber(const Number& value)
{
    number = value;
}

// Метод ініціалізації об'єкта Real
void Real::Init(double value)
{
    number.Init(value);
}

// Метод введення числа з клавіатури
void Real::Read()
{
    cout << "Enter a real number: ";
    cin >> number;
}

// Метод виведення числа на екран
void Real::Display() const
{
    cout << *this << endl;
}

// Метод обчислення кореня довільного степеня
double Real::Root(int degree) const
{
    if (degree == 0)
        throw invalid_argument("Root degree cannot be zero!");

    double x = number.getValue();

    if (x < 0 && degree % 2 == 0)
        throw invalid_argument("Even root of a negative number is not real!");

    if (x < 0)
        return -pow(-x, 1.0 / degree);

    return pow(x, 1.0 / degree);
}

// Метод обчислення числа PI у заданому степені
double Real::PiPower(int degree) const
{
    const double PI = acos(-1.0);

    return pow(PI, degree);
}

// Метод перетворення об'єкта у рядок
string Real::toString() const
{
    stringstream ss;
    ss << number;
    return ss.str();
}

// Оператор перетворення типу у string
Real::operator string() const
{
    return toString();
}

// Оператор присвоєння
Real& Real::operator = (const Real& other)
{
    if (this != &other)
        number = other.number;

    return *this;
}

// Префіксний інкремент
Real& Real::operator ++ ()
{
    ++number;
    return *this;
}

// Постфіксний інкремент
Real Real::operator ++ (int)
{
    Real temp(*this);
    number++;
    return temp;
}

// Префіксний декремент
Real& Real::operator -- ()
{
    --number;
    return *this;
}

// Постфіксний декремент
Real Real::operator -- (int)
{
    Real temp(*this);
    number--;
    return temp;
}

// Оператор виведення об'єкта Real
ostream& operator << (ostream& out, const Real& r)
{
    out << r.number;
    return out;
}

// Оператор введення об'єкта Real
istream& operator >> (istream& in, Real& r)
{
    in >> r.number;
    return in;
}