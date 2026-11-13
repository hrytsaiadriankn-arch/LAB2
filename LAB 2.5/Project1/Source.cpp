#include <iostream>
#include "Number.h"
#include "Real.h"

using namespace std;

// Структура без пакування
#pragma pack(push, 8)
struct NormalLayout
{
    char marker;
    Number number;
};
#pragma pack(pop)

// Структура з пакуванням 1 байт
#pragma pack(push, 1)
struct PackedLayout
{
    char marker;
    Number number;
};
#pragma pack(pop)

// Головна функція програми
int main()
{
    cout << "LABORATORY WORK 2.5" << endl;
    cout << "VARIANT 14" << endl;
    cout << "============================" << endl;

    // Створення об'єктів класу Number
    Number n1;
    Number n2;

    cout << "\nEnter the first number:" << endl;
    cin >> n1;

    cout << "Enter the second number:" << endl;
    cin >> n2;

    cout << "\nFirst number: " << n1 << endl;
    cout << "Second number: " << n2 << endl;

    // Виконання множення
    Number product = n1 * n2;
    cout << "\nMultiplication: " << product << endl;

    // Виконання віднімання
    Number difference = n1 - n2;
    cout << "Subtraction: " << difference << endl;

    // Використання конструктора копіювання
    Number n3(n1);
    cout << "\nCopied number: " << n3 << endl;

    // Використання оператора присвоєння
    Number n4;
    n4 = n2;
    cout << "Assigned number: " << n4 << endl;

    // Демонстрація префіксного та постфіксного інкременту
    cout << "\nPrefix increment: " << ++n3 << endl;
    cout << "Postfix increment: " << n3++ << endl;
    cout << "After postfix increment: " << n3 << endl;

    // Демонстрація префіксного та постфіксного декременту
    cout << "\nPrefix decrement: " << --n3 << endl;
    cout << "Postfix decrement: " << n3-- << endl;
    cout << "After postfix decrement: " << n3 << endl;

    // Перетворення числа у рядок
    string numberText = n1;
    cout << "\nNumber as string: " << numberText << endl;

    // Створення об'єкта класу Real
    Real r1;

    cout << "\nEnter a real number:" << endl;
    cin >> r1;

    cout << "Real number: " << r1 << endl;

    // Створення копії об'єкта
    Real r2(r1);
    cout << "Copied Real object: " << r2 << endl;

    // Використання оператора присвоєння
    Real r3;
    r3 = r1;
    cout << "Assigned Real object: " << r3 << endl;

    // Введення степеня кореня
    int degree;

    cout << "\nEnter root degree: ";
    cin >> degree;

    // Обчислення кореня
    try
    {
        cout << "Root result: " << r1.Root(degree) << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    // Введення степеня числа PI
    int power;

    cout << "\nEnter power for PI: ";
    cin >> power;

    // Обчислення числа PI у заданому степені
    cout << "PI raised to power " << power
        << ": " << r1.PiPower(power) << endl;

    // Демонстрація інкременту та декременту для Real
    cout << "\nPrefix increment Real: " << ++r3 << endl;
    cout << "Postfix increment Real: " << r3++ << endl;
    cout << "After postfix increment: " << r3 << endl;

    cout << "Prefix decrement Real: " << --r3 << endl;
    cout << "Postfix decrement Real: " << r3-- << endl;
    cout << "After postfix decrement: " << r3 << endl;

    // Перетворення об'єкта Real у рядок
    string realText = r1;
    cout << "\nReal as string: " << realText << endl;

    // Створення масиву об'єктів класу Real
    Real arr[3] = {
        Real(10.5),
        Real(20.5),
        Real(30.5)
    };

    cout << "\nArray of Real objects:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Element " << i + 1 << ": "
            << arr[i] << endl;
    }

    // Виведення розмірів класів
    cout << "\nCLASS SIZES" << endl;

    cout << "Size of Number: "
        << sizeof(Number) << " bytes" << endl;

    cout << "Size of Real: "
        << sizeof(Real) << " bytes" << endl;

    // Порівняння розмірів структур із різним пакуванням
    cout << "\nSTRUCTURE SIZES" << endl;

    cout << "Without #pragma pack(1): "
        << sizeof(NormalLayout) << " bytes" << endl;

    cout << "With #pragma pack(1): "
        << sizeof(PackedLayout) << " bytes" << endl;

    cout << "\nProgram finished successfully!" << endl;

    return 0;
}