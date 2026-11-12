#pragma once
#include <iostream>
#include <string>

using namespace std;

class Complex
{
private:
    double re;
    double im;

public:
    // Конструктори
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex& other);

    // Деструктор
    ~Complex();

    // Методи доступу
    void SetRe(double value);
    void SetIm(double value);

    double GetRe() const;
    double GetIm() const;

    // Оператор присвоєння
    Complex& operator=(const Complex& other);

    // Перетворення у рядок
    operator string() const;

    // Унарні оператори
    Complex& operator++();
    Complex operator++(int);

    Complex& operator--();
    Complex operator--(int);

    // Складені оператори
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    // Бінарні оператори
    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend Complex operator/(const Complex& a, const Complex& b);

    // Потокове введення та виведення
    friend ostream& operator<<(ostream& out, const Complex& number);
    friend istream& operator>>(istream& in, Complex& number);
};
