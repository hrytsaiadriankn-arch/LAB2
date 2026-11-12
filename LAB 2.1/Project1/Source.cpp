
#include <iostream>
#include "Pay.h"

using namespace std;

// Структура для демонстрації вирівнювання pack(1)
#pragma pack(push, 1)
struct PayPacked
{
    double first;
    int second;
};
#pragma pack(pop)

int main()
{
    // Створення об'єктів різними способами
    Pay p1;
    Pay p2(15000, 20);
    Pay p3(p2);

    cout << "Object p1:" << endl;
    cout << p1 << endl;

    cout << "Object p2:" << endl;
    cout << p2 << endl;

    cout << "Object p3 (copy):" << endl;
    cout << p3 << endl;

    // Використання методів доступу
    cout << "Salary: " << p2.GetFirst() << endl;
    cout << "Working days: " << p2.GetSecond() << endl;

    // Обчислення зарплати
    cout << "\nCalculated salary: "
        << p2.summa(22) << endl;

    // Перевантаження присвоєння
    p1 = p2;

    cout << "\nAfter assignment:" << endl;
    cout << p1 << endl;

    // Перевантаження інкременту
    cout << "\nPostfix increment:" << endl;
    cout << p2++ << endl;
    cout << "After increment:" << endl;
    cout << p2 << endl;

    cout << "\nPrefix increment:" << endl;
    cout << ++p2 << endl;

    // Перевантаження декременту
    cout << "\nPostfix decrement:" << endl;
    cout << p2-- << endl;
    cout << "After decrement:" << endl;
    cout << p2 << endl;

    cout << "\nPrefix decrement:" << endl;
    cout << --p2 << endl;

    // Перетворення в рядок
    string str = p2;
    cout << "\nString representation:" << endl;
    cout << str << endl;

    // Функція створення об'єкта
    Pay p4 = makePay(20000, 18);

    cout << "Object created by makePay:" << endl;
    cout << p4 << endl;

    // Введення об'єкта
    Pay p5;
    cout << "\nEnter new Pay object:" << endl;
    cin >> p5;

    cout << "\nEntered object:" << endl;
    cout << p5 << endl;

    // Масив об'єктів
    Pay arr[3] = {
        Pay(12000, 15),
        Pay(18000, 20),
        Pay(22000, 22)
    };

    cout << "\nArray of Pay objects:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "\nObject " << i + 1 << endl;
        cout << arr[i];
    }

    // Розмір класу та pack(1)
    cout << "\nSize of Pay: "
        << sizeof(Pay) << " bytes" << endl;

    cout << "Size with pack(1): "
        << sizeof(PayPacked) << " bytes" << endl;

    return 0;
}
