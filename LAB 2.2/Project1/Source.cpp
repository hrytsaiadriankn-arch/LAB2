#include <iostream>
#include "Complex.h"

using namespace std;

// Упакована структура з такими самими полями
#pragma pack(push, 1)
struct ComplexPacked
{
    double re;
    double im;
};
#pragma pack(pop)

int main()
{
    // Створення об'єктів різними способами
    Complex a;
    Complex b(4, 3);
    Complex c(b);

    cout << "Default constructor:" << endl;
    cout << "a = " << a << endl;

    cout << "\nInitialization constructor:" << endl;
    cout << "b = " << b << endl;

    cout << "\nCopy constructor:" << endl;
    cout << "c = " << c << endl;

    // Введення комплексного числа
    cout << "\nEnter complex number:" << endl;
    cin >> a;

    cout << "\nEntered number: " << a << endl;

    // Додавання
    cout << "\nAddition:" << endl;
    cout << a << " + " << b << " = " << a + b << endl;

    // Віднімання
    cout << "\nSubtraction:" << endl;
    cout << a << " - " << b << " = " << a - b << endl;

    // Множення
    cout << "\nMultiplication:" << endl;
    cout << a << " * " << b << " = " << a * b << endl;

    // Ділення
    cout << "\nDivision:" << endl;

    try
    {
        cout << a << " / " << b << " = " << a / b << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    // Префіксний інкремент
    Complex temp = b;

    cout << "\nPrefix increment:" << endl;
    cout << "++b = " << ++temp << endl;

    // Постфіксний інкремент
    temp = b;

    cout << "\nPostfix increment:" << endl;
    cout << "b++ = " << temp++ << endl;
    cout << "After increment: " << temp << endl;

    // Префіксний декремент
    temp = b;

    cout << "\nPrefix decrement:" << endl;
    cout << "--b = " << --temp << endl;

    // Постфіксний декремент
    temp = b;

    cout << "\nPostfix decrement:" << endl;
    cout << "b-- = " << temp-- << endl;
    cout << "After decrement: " << temp << endl;

    // Оператор +=
    temp = a;
    temp += b;

    cout << "\nOperator +=:" << endl;
    cout << "a += b: " << temp << endl;

    // Оператор -=
    temp = a;
    temp -= b;

    cout << "\nOperator -=:" << endl;
    cout << "a -= b: " << temp << endl;

    // Оператор *=
    temp = a;
    temp *= b;

    cout << "\nOperator *=:" << endl;
    cout << "a *= b: " << temp << endl;

    // Оператор /=
    temp = a;

    cout << "\nOperator /=:" << endl;

    try
    {
        temp /= b;
        cout << "a /= b: " << temp << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    // Оператор присвоєння
    temp = a;

    cout << "\nAssignment operator:" << endl;
    cout << "temp = a: " << temp << endl;

    // Перетворення у string
    string str = a;

    cout << "\nString conversion:" << endl;
    cout << str << endl;

    // Масив об'єктів
    Complex arr[3] =
    {
        Complex(2, 3),
        Complex(4, 5),
        Complex(6, 7)
    };

    cout << "\nArray of complex numbers:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Object " << i + 1 << ": " << arr[i] << endl;
    }

    // Розмір класу
    cout << "\nSize of Complex: "
        << sizeof(Complex) << " bytes" << endl;

    cout << "Size with pack(1): "
        << sizeof(ComplexPacked) << " bytes" << endl;

    return 0;
}
