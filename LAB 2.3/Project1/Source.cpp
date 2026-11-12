#include "pch.h"
#include <iostream>
#include "Money.h"

using namespace std;

// Упакована структура для порівняння розміру
#pragma pack(push, 1)
struct MoneyPacked
{
    long hryvnias;
    unsigned char kopecks;
};
#pragma pack(pop)

int main()
{
    // Створення об'єктів різними конструкторами
    Money a;
    Money b(500, 50);
    Money c(b);

    cout << "Default constructor:" << endl;
    cout << "a = " << a << endl;

    cout << "\nInitialization constructor:" << endl;
    cout << "b = " << b << endl;

    cout << "\nCopy constructor:" << endl;
    cout << "c = " << c << endl;

    // Введення суми
    cout << "\nEnter money amount:" << endl;
    cin >> a;

    if (!cin)
    {
        cout << "Invalid input!" << endl;
        return 1;
    }

    cout << "\nEntered amount: " << a << endl;

    // Віднімання
    cout << "\nSubtraction:" << endl;

    try
    {
        cout << a << " - " << b << " = " << a - b << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    // Множення на дробове число
    cout << "\nMultiplication by a fractional number:" << endl;

    try
    {
        cout << b << " * 1.5 = " << b * 1.5 << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    // Операції порівняння
    cout << "\nComparison operations:" << endl;

    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a <= b: " << (a <= b) << endl;

    // Префіксний інкремент
    Money temp = b;

    cout << "\nPrefix increment:" << endl;
    cout << "++temp = " << ++temp << endl;

    // Постфіксний інкремент
    temp = b;

    cout << "\nPostfix increment:" << endl;
    cout << "temp++ = " << temp++ << endl;
    cout << "After increment: " << temp << endl;

    // Префіксний декремент
    temp = b;

    cout << "\nPrefix decrement:" << endl;
    cout << "--temp = " << --temp << endl;

    // Постфіксний декремент
    temp = b;

    cout << "\nPostfix decrement:" << endl;
    cout << "temp-- = " << temp-- << endl;
    cout << "After decrement: " << temp << endl;

    // Оператор присвоєння
    temp = a;

    cout << "\nAssignment operator:" << endl;
    cout << "temp = a: " << temp << endl;

    // Перетворення у string
    string str = a;

    cout << "\nString conversion:" << endl;
    cout << str << endl;

    // Масив об'єктів
    Money arr[3] =
    {
        Money(100, 50),
        Money(250, 75),
        Money(500, 25)
    };

    cout << "\nArray of Money objects:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Object " << i + 1 << ": "
            << arr[i] << endl;
    }

    // Розмір класу
    cout << "\nSize of Money: "
        << sizeof(Money) << " bytes" << endl;

    cout << "Size with pack(1): "
        << sizeof(MoneyPacked) << " bytes" << endl;

    return 0;
}
