#pragma once

#include <iostream>
#include <string>

using namespace std;

// Допоміжний клас-оболонка для типу double
class Number
{
private:
    double value; // Значення числа

public:
    // Конструктор без параметрів
    Number();

    // Конструктор ініціалізації
    Number(double value);

    // Конструктор копіювання
    Number(const Number& other);

    // Методи доступу до поля
    double getValue() const;
    bool setValue(double value);

    // Метод ініціалізації
    void Init(double value);

    // Методи введення та виведення
    void Read();
    void Display() const;

    // Перетворення числа у рядок
    string toString() const;
    operator string() const;

    // Оператор присвоєння
    Number& operator = (const Number& other);

    // Префіксний та постфіксний інкремент
    Number& operator ++ ();
    Number operator ++ (int);

    // Префіксний та постфіксний декремент
    Number& operator -- ();
    Number operator -- (int);

    // Операції множення та віднімання
    friend Number operator * (const Number& a, const Number& b);
    friend Number operator - (const Number& a, const Number& b);

    // Оператори введення та виведення
    friend ostream& operator << (ostream& out, const Number& n);
    friend istream& operator >> (istream& in, Number& n);
};