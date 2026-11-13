#include "pch.h"
#include "Vector.h"
#include <sstream>
#include <stdexcept>

// Конструктор без параметрів
// Створює порожній вектор
Vector::Vector()
{
    length = 0;

    for (int i = 0; i < MAX_SIZE; i++)
        data[i] = 0;
}

// Конструктор ініціалізації
// Створює вектор заданого розміру із переданими значеннями
Vector::Vector(int n, const int* values)
{
    if (n < 0 || n > MAX_SIZE)
        throw invalid_argument("Invalid vector size!");

    length = n;

    for (int i = 0; i < MAX_SIZE; i++)
        data[i] = 0;

    for (int i = 0; i < length; i++)
        data[i] = values[i];
}

// Конструктор копіювання
// Створює копію іншого вектора
Vector::Vector(const Vector& other)
{
    length = other.length;

    for (int i = 0; i < MAX_SIZE; i++)
        data[i] = other.data[i];
}

// Повертає кількість елементів вектора
int Vector::getLength() const
{
    return length;
}

// Повертає елемент за заданим індексом
int Vector::getElement(int index) const
{
    if (index < 0 || index >= length)
        throw out_of_range("Invalid index!");

    return data[index];
}

// Змінює значення елемента за заданим індексом
bool Vector::setElement(int index, int value)
{
    if (index < 0 || index >= length)
        return false;

    data[index] = value;
    return true;
}

// Повертає розмір вектора
int Vector::size() const
{
    return length;
}

// Оператор присвоєння
// Копіює значення одного вектора в інший
Vector& Vector::operator = (const Vector& other)
{
    if (this != &other)
    {
        length = other.length;

        for (int i = 0; i < MAX_SIZE; i++)
            data[i] = other.data[i];
    }

    return *this;
}

// Оператор індексації
// Дозволяє звертатися до елементів вектора через квадратні дужки
int& Vector::operator [] (int index)
{
    if (index < 0 || index >= length)
        throw out_of_range("Invalid index!");

    return data[index];
}

// Константний оператор індексації
const int& Vector::operator [] (int index) const
{
    if (index < 0 || index >= length)
        throw out_of_range("Invalid index!");

    return data[index];
}

// Перетворює вектор у текстовий рядок
Vector::operator string() const
{
    stringstream ss;

    ss << "(";

    for (int i = 0; i < length; i++)
    {
        ss << data[i];

        if (i < length - 1)
            ss << ", ";
    }

    ss << ")";

    return ss.str();
}

// Оператор виведення вектора на екран
ostream& operator << (ostream& out, const Vector& v)
{
    out << string(v);
    return out;
}

// Оператор введення елементів вектора
istream& operator >> (istream& in, Vector& v)
{
    int n;

    cout << "Enter vector size (1-100): ";
    in >> n;

    if (!in || n < 1 || n > 100)
    {
        in.setstate(ios::failbit);
        return in;
    }

    v.length = n;

    cout << "Enter vector elements:" << endl;

    for (int i = 0; i < n; i++)
        in >> v.data[i];

    return in;
}

// Множення вектора на число
Vector operator * (const Vector& v, int scalar)
{
    Vector result(v);

    for (int i = 0; i < result.length; i++)
        result.data[i] *= scalar;

    return result;
}

// Множення числа на вектор
Vector operator * (int scalar, const Vector& v)
{
    return v * scalar;
}

// Перевірка рівності двох векторів
bool operator == (const Vector& a, const Vector& b)
{
    if (a.length != b.length)
        return false;

    for (int i = 0; i < a.length; i++)
    {
        if (a.data[i] != b.data[i])
            return false;
    }

    return true;
}

// Перевірка нерівності двох векторів
bool operator != (const Vector& a, const Vector& b)
{
    return !(a == b);
}

// Обчислення норми вектора
// Норма дорівнює різниці між найбільшим і найменшим елементами
int Vector::Norm() const
{
    if (length == 0)
        return 0;

    int minValue = data[0];
    int maxValue = data[0];

    for (int i = 1; i < length; i++)
    {
        if (data[i] < minValue)
            minValue = data[i];

        if (data[i] > maxValue)
            maxValue = data[i];
    }

    return maxValue - minValue;
}
