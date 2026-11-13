
#include <iostream>
#include "Vector.h"

using namespace std;

// Структура без пакування
struct NormalLayout
{
    int data[100];
    int length;
};

// Структура з пакуванням 1 байт
#pragma pack(push, 1)
struct PackedLayout
{
    int data[100];
    int length;
};
#pragma pack(pop)

// Головна функція програми
int main()
{
    cout << "LABORATORY WORK 2.4" << endl;
    cout << "VARIANT 14" << endl;
    cout << "============================" << endl;

    // Створення порожнього вектора
    Vector v1;

    cout << "\nEnter the first vector:" << endl;
    cin >> v1;

    cout << "\nFirst vector: " << v1 << endl;

    // Створення вектора за допомогою конструктора ініціалізації
    int values[] = { 2, 4, 6, 8, 10 };

    Vector v2(5, values);

    cout << "\nSecond vector: " << v2 << endl;

    // Створення копії вектора
    Vector v3(v2);

    cout << "Copied vector: " << v3 << endl;

    // Використання оператора присвоєння
    Vector v4;

    v4 = v1;

    cout << "\nAssigned vector: " << v4 << endl;

    // Звернення до елемента вектора за індексом
    cout << "\nElement at index 2: " << v2[2] << endl;

    // Введення числа для множення
    int scalar;

    cout << "\nEnter a scalar: ";
    cin >> scalar;

    // Множення вектора на число
    Vector v5 = v2 * scalar;

    cout << "Vector multiplied by scalar: " << v5 << endl;

    // Порівняння двох векторів
    cout << "\nVector comparison:" << endl;

    if (v2 == v3)
        cout << "Vectors are equal." << endl;
    else
        cout << "Vectors are not equal." << endl;

    if (v1 != v2)
        cout << "The first and second vectors are different." << endl;

    // Обчислення норми векторів
    cout << "\nNorm of the first vector: " << v1.Norm() << endl;
    cout << "Norm of the second vector: " << v2.Norm() << endl;

    // Отримання розміру вектора
    cout << "\nNumber of elements in the second vector: "
        << v2.size() << endl;

    // Зміна першого елемента вектора
    v2.setElement(0, 100);

    cout << "Vector after changing the first element: " << v2 << endl;

    // Створення масиву об'єктів класу Vector
    Vector arr[2] = { v1, v2 };

    cout << "\nArray of vectors:" << endl;

    for (int i = 0; i < 2; i++)
        cout << "Vector " << i + 1 << ": " << arr[i] << endl;

    // Множення числа на вектор
    Vector v6 = scalar * v1;

    cout << "\nScalar multiplied by vector: " << v6 << endl;

    // Визначення розміру звичайної структури
    cout << "\nStructure size without packing: "
        << sizeof(NormalLayout) << " bytes" << endl;

    // Визначення розміру структури з пакуванням
    cout << "Structure size with #pragma pack(1): "
        << sizeof(PackedLayout) << " bytes" << endl;

    cout << "\nProgram finished successfully!" << endl;

    return 0;
}
