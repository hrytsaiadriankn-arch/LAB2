
#include "Real.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <limits>

// Статичні лічильники об'єктів
int Real::Number::objectCount = 0;
int Real::objectCount = 0;

// ============================================
// Реалізація вкладеного класу Number
// ============================================

// Конструктор без аргументів
Real::Number::Number()
{
    value = 0.0;
    objectCount++;
}

// Конструктор ініціалізації
Real::Number::Number(double value)
{
    this->value = std::isfinite(value) ? value : 0.0;
    objectCount++;
}

// Конструктор копіювання
Real::Number::Number(const Number& other)
{
    value = other.value;
    objectCount++;
}

// Деструктор
Real::Number::~Number()
{
    objectCount--;
}

// Отримання значення
double Real::Number::GetValue() const
{
    return value;
}

// Зміна значення
bool Real::Number::SetValue(double value)
{
    if (!std::isfinite(value))
        return false;

    this->value = value;
    return true;
}

// Множення
double Real::Number::Multiply(double other) const
{
    return value * other;
}

// Віднімання
double Real::Number::Subtract(double other) const
{
    return value - other;
}

// Оператор присвоєння
Real::Number& Real::Number::operator=(const Number& other)
{
    if (this != &other)
        value = other.value;

    return *this;
}

// Оператор множення
Real::Number Real::Number::operator*(const Number& other) const
{
    return Number(value * other.value);
}

// Оператор віднімання
Real::Number Real::Number::operator-(const Number& other) const
{
    return Number(value - other.value);
}

// Префіксний інкремент
Real::Number& Real::Number::operator++()
{
    ++value;
    return *this;
}

// Префіксний декремент
Real::Number& Real::Number::operator--()
{
    --value;
    return *this;
}

// Постфіксний інкремент
Real::Number Real::Number::operator++(int)
{
    Number temp(*this);
    value++;
    return temp;
}

// Постфіксний декремент
Real::Number Real::Number::operator--(int)
{
    Number temp(*this);
    value--;
    return temp;
}

// Перетворення в рядок
Real::Number::operator std::string() const
{
    return ToString();
}

// Метод перетворення в рядок
std::string Real::Number::ToString() const
{
    std::ostringstream stream;
    stream << std::setprecision(10) << value;
    return stream.str();
}

// Оператор виведення
std::ostream& operator<<(std::ostream& out,
    const Real::Number& n)
{
    out << n.value;
    return out;
}

// Оператор введення
std::istream& operator>>(std::istream& in,
    Real::Number& n)
{
    double temp;

    if (in >> temp)
    {
        if (!n.SetValue(temp))
            in.setstate(std::ios::failbit);
    }

    return in;
}

// Кількість об'єктів Number
int Real::Number::GetObjectCount()
{
    return objectCount;
}

// ============================================
// Реалізація зовнішнього класу Real
// ============================================

// Конструктор без аргументів
Real::Real() : number()
{
    objectCount++;
}

// Конструктор ініціалізації
Real::Real(double value) : number(value)
{
    objectCount++;
}

// Конструктор копіювання
Real::Real(const Real& other) : number(other.number)
{
    objectCount++;
}

// Деструктор
Real::~Real()
{
    objectCount--;
}

// Отримання значення
double Real::GetValue() const
{
    return number.GetValue();
}

// Зміна значення
bool Real::SetValue(double value)
{
    return number.SetValue(value);
}

// Обчислення кореня довільного степеня
double Real::Root(int degree) const
{
    if (degree == 0)
        return std::numeric_limits<double>::quiet_NaN();

    double x = number.GetValue();

    if (x < 0 && degree % 2 == 0)
        return std::numeric_limits<double>::quiet_NaN();

    if (x == 0 && degree < 0)
        return std::numeric_limits<double>::quiet_NaN();

    if (x < 0)
        return -std::pow(-x, 1.0 / degree);

    return std::pow(x, 1.0 / degree);
}

// Обчислення числа PI у заданому степені
double Real::PiPower(int degree) const
{
    const double PI = 3.14159265358979323846;

    return std::pow(PI, degree);
}

// Оператор присвоєння
Real& Real::operator=(const Real& other)
{
    if (this != &other)
        number = other.number;

    return *this;
}

// Префіксний інкремент
Real& Real::operator++()
{
    ++number;
    return *this;
}

// Префіксний декремент
Real& Real::operator--()
{
    --number;
    return *this;
}

// Постфіксний інкремент
Real Real::operator++(int)
{
    Real temp(*this);
    number++;
    return temp;
}

// Постфіксний декремент
Real Real::operator--(int)
{
    Real temp(*this);
    number--;
    return temp;
}

// Перетворення в рядок
Real::operator std::string() const
{
    return ToString();
}

// Метод перетворення в рядок
std::string Real::ToString() const
{
    return number.ToString();
}

// Оператор виведення
std::ostream& operator<<(std::ostream& out, const Real& r)
{
    out << r.number;
    return out;
}

// Оператор введення
std::istream& operator>>(std::istream& in, Real& r)
{
    in >> r.number;
    return in;
}

// Кількість об'єктів Real
int Real::GetObjectCount()
{
    return objectCount;
}
