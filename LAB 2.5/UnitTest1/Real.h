#pragma once

#include "Number.h"

// Основний клас-контейнер Real
class Real
{
private:
    Number number; // Об'єкт допоміжного класу Number

public:
    // Конструктор без параметрів
    Real();

    // Конструктор ініціалізації
    Real(double value);

    // Конструктор з об'єктом Number
    Real(const Number& value);

    // Конструктор копіювання
    Real(const Real& other);

    // Методи доступу до поля
    Number getNumber() const;
    void setNumber(const Number& value);

    // Метод ініціалізації
    void Init(double value);

    // Методи введення та виведення
    void Read();
    void Display() const;

    // Метод обчислення кореня довільного степеня
    double Root(int degree) const;

    // Метод піднесення числа PI до заданого степеня
    double PiPower(int degree) const;

    // Перетворення об'єкта у рядок
    string toString() const;
    operator string() const;

    // Оператор присвоєння
    Real& operator = (const Real& other);

    // Префіксний та постфіксний інкремент
    Real& operator ++ ();
    Real operator ++ (int);

    // Префіксний та постфіксний декремент
    Real& operator -- ();
    Real operator -- (int);

    // Оператори введення та виведення
    friend ostream& operator << (ostream& out, const Real& r);
    friend istream& operator >> (istream& in, Real& r);
};