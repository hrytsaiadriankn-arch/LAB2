
#pragma once

#include <iostream>
#include <string>

// Зовнішній клас Real
class Real
{
public:

    // Вкладений клас Number
    class Number
    {
    private:
        double value;

        // Кількість створених об'єктів Number
        static int objectCount;

    public:

        // Конструктори
        Number();
        Number(double value);
        Number(const Number& other);

        // Деструктор
        ~Number();

        // Методи доступу
        double GetValue() const;
        bool SetValue(double value);

        // Методи множення і віднімання
        double Multiply(double other) const;
        double Subtract(double other) const;

        // Перевантаження операцій
        Number& operator=(const Number& other);
        Number operator*(const Number& other) const;
        Number operator-(const Number& other) const;

        // Префіксний інкремент і декремент
        Number& operator++();
        Number& operator--();

        // Постфіксний інкремент і декремент
        Number operator++(int);
        Number operator--(int);

        // Перетворення числа в рядок
        operator std::string() const;

        // Перетворення в рядок через метод
        std::string ToString() const;

        // Введення і виведення
        friend std::ostream& operator<<(std::ostream& out,
            const Number& n);

        friend std::istream& operator>>(std::istream& in,
            Number& n);

        // Отримання кількості об'єктів
        static int GetObjectCount();
    };

private:

    // Об'єкт вкладеного класу
    Number number;

    // Кількість створених об'єктів Real
    static int objectCount;

public:

    // Конструктори зовнішнього класу
    Real();
    Real(double value);
    Real(const Real& other);

    // Деструктор
    ~Real();

    // Методи доступу
    double GetValue() const;
    bool SetValue(double value);

    // Обчислення кореня довільного степеня
    double Root(int degree) const;

    // Обчислення числа PI у заданому степені
    double PiPower(int degree) const;

    // Перевантаження присвоєння
    Real& operator=(const Real& other);

    // Префіксний інкремент і декремент
    Real& operator++();
    Real& operator--();

    // Постфіксний інкремент і декремент
    Real operator++(int);
    Real operator--(int);

    // Перетворення в рядок
    operator std::string() const;

    std::string ToString() const;

    // Введення і виведення
    friend std::ostream& operator<<(std::ostream& out,
        const Real& r);

    friend std::istream& operator>>(std::istream& in,
        Real& r);

    // Кількість об'єктів зовнішнього класу
    static int GetObjectCount();
};
