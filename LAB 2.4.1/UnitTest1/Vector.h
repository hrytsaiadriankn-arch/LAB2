
#pragma once

#include <iostream>
#include <string>

using namespace std;

// Клас для роботи з вектором цілих чисел
class Vector
{
private:
    // Максимальна кількість елементів вектора
    static const int MAX_SIZE = 100;

    // Масив для зберігання елементів вектора
    int data[MAX_SIZE];

    // Поточна кількість елементів вектора
    int length;

public:
    // Конструктор без параметрів
    Vector();

    // Конструктор ініціалізації
    Vector(int n, const int* values);

    // Конструктор копіювання
    Vector(const Vector& other);

    // Отримання кількості елементів
    int getLength() const;

    // Отримання елемента за індексом
    int getElement(int index) const;

    // Зміна значення елемента
    bool setElement(int index, int value);

    // Отримання розміру вектора
    int size() const;

    // Оператор присвоєння
    Vector& operator = (const Vector& other);

    // Оператор індексації
    int& operator [] (int index);
    const int& operator [] (int index) const;

    // Перетворення вектора у рядок
    operator string() const;

    // Оператори введення та виведення
    friend ostream& operator << (ostream& out, const Vector& v);
    friend istream& operator >> (istream& in, Vector& v);

    // Множення вектора на число
    friend Vector operator * (const Vector& v, int scalar);
    friend Vector operator * (int scalar, const Vector& v);

    // Порівняння двох векторів
    friend bool operator == (const Vector& a, const Vector& b);
    friend bool operator != (const Vector& a, const Vector& b);

    // Обчислення норми вектора
    int Norm() const;
};
