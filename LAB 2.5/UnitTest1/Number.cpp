#include "Number.h"
#include <sstream>
#include <stdexcept>
#include <cmath>

// Конструктор без параметрів
Number::Number()
{
    value = 0.0;
}

// Конструктор ініціалізації
Number::Number(double value)
{
    if (!setValue(value))
        throw invalid_argument("Invalid number!");
}

// Конструктор копіювання
Number::Number(const Number& other)
{
    value = other.value;
}

// Метод отримання значення числа
double Number::getValue() const
{
    return value;
}

// Метод зміни значення числа з перевіркою
bool Number::setValue(double value)
{
    if (!isfinite(value))
        return false;

    this->value = value;
    return true;
}

// Метод ініціалізації об'єкта
void Number::Init(double value)
{
    if (!setValue(value))
        throw invalid_argument("Invalid number!");
}

// Метод введення числа з клавіатури
void Number::Read()
{
    cout << "Enter a number: ";
    cin >> *this;
}

// Метод виведення числа на екран
void Number::Display() const
{
    cout << *this << endl;
}

// Метод перетворення числа у рядок
string Number::toString() const
{
    stringstream ss;
    ss << value;
    return ss.str();
}

// Оператор перетворення типу у string
Number::operator string() const
{
    return toString();
}

// Оператор присвоєння
Number& Number::operator = (const Number& other)
{
    if (this != &other)
        value = other.value;

    return *this;
}

// Префіксний інкремент
Number& Number::operator ++ ()
{
    value++;
    return *this;
}

// Постфіксний інкремент
Number Number::operator ++ (int)
{
    Number temp(*this);
    value++;
    return temp;
}

// Префіксний декремент
Number& Number::operator -- ()
{
    value--;
    return *this;
}

// Постфіксний декремент
Number Number::operator -- (int)
{
    Number temp(*this);
    value--;
    return temp;
}

// Оператор множення двох чисел
Number operator * (const Number& a, const Number& b)
{
    return Number(a.value * b.value);
}

// Оператор віднімання двох чисел
Number operator - (const Number& a, const Number& b)
{
    return Number(a.value - b.value);
}

// Оператор виведення числа
ostream& operator << (ostream& out, const Number& n)
{
    out << n.value;
    return out;
}

// Оператор введення числа
istream& operator >> (istream& in, Number& n)
{
    double temp;
    in >> temp;

    if (in)
    {
        if (!n.setValue(temp))
            in.setstate(ios::failbit);
    }

    return in;
}