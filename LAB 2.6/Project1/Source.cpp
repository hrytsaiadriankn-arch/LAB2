
#include <iostream>
#include <string>
#include <cmath>
#include "Real.h"

using namespace std;

int main()
{
    cout << "LABORATORY WORK 2.6" << endl;
    cout << "Variant 14" << endl;
    cout << "Nested classes and object counting" << endl;

    cout << "\n========== CONSTRUCTORS ==========\n";

    // Створення об'єкта за замовчуванням
    Real r1;

    // Створення об'єкта з параметром
    Real r2(81.0);

    // Створення об'єкта за допомогою копіювання
    Real r3(r2);

    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r3 = " << r3 << endl;

    cout << "\n========== INPUT ==========\n";

    cout << "Enter a real number: ";
    if (!(cin >> r1))
    {
        cout << "Invalid input!" << endl;
        return 1;
    }

    cout << "Entered number: " << r1 << endl;

    cout << "\n========== NUMBER OPERATIONS ==========\n";

    // Створення об'єктів вкладеного класу
    Real::Number n1(12.0);
    Real::Number n2(4.0);

    cout << "First number: " << n1 << endl;
    cout << "Second number: " << n2 << endl;

    cout << "Multiplication: " << n1 * n2 << endl;
    cout << "Subtraction: " << n1 - n2 << endl;

    cout << "Multiply method: " << n1.Multiply(3.0) << endl;
    cout << "Subtract method: " << n1.Subtract(3.0) << endl;

    cout << "\n========== INCREMENT AND DECREMENT ==========\n";

    Real::Number n3(10.0);

    cout << "Initial value: " << n3 << endl;

    cout << "Prefix increment: " << ++n3 << endl;
    cout << "Prefix decrement: " << --n3 << endl;

    cout << "Postfix increment: " << n3++ << endl;
    cout << "Value after postfix increment: " << n3 << endl;

    cout << "Postfix decrement: " << n3-- << endl;
    cout << "Value after postfix decrement: " << n3 << endl;

    cout << "\n========== REAL OPERATIONS ==========\n";

    Real r4(81.0);

    cout << "Number: " << r4 << endl;
    cout << "Square root: " << r4.Root(2) << endl;
    cout << "Cube root: " << r4.Root(3) << endl;
    cout << "Fourth root: " << r4.Root(4) << endl;

    cout << "PI squared: " << r4.PiPower(2) << endl;
    cout << "PI cubed: " << r4.PiPower(3) << endl;

    cout << "\n========== REAL INCREMENT AND DECREMENT ==========\n";

    Real r5(20.0);

    cout << "Initial value: " << r5 << endl;
    cout << "Prefix increment: " << ++r5 << endl;
    cout << "Prefix decrement: " << --r5 << endl;
    cout << "Postfix increment: " << r5++ << endl;
    cout << "Value after increment: " << r5 << endl;
    cout << "Postfix decrement: " << r5-- << endl;
    cout << "Value after decrement: " << r5 << endl;

    cout << "\n========== ASSIGNMENT ==========\n";

    Real r6;
    r6 = r4;

    cout << "Assigned object: " << r6 << endl;

    cout << "\n========== STRING CONVERSION ==========\n";

    string text = static_cast<string>(r4);

    cout << "Number as string: " << text << endl;

    string numberText = static_cast<string>(n1);

    cout << "Nested Number as string: " << numberText << endl;

    cout << "\n========== OBJECT ARRAYS ==========\n";

    // Масив об'єктів зовнішнього класу
    Real realArray[3] = {
        Real(10.0),
        Real(20.0),
        Real(30.0)
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "realArray[" << i << "] = "
            << realArray[i] << endl;
    }

    // Масив об'єктів вкладеного класу
    Real::Number numberArray[3] = {
        Real::Number(5.0),
        Real::Number(10.0),
        Real::Number(15.0)
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "numberArray[" << i << "] = "
            << numberArray[i] << endl;
    }

    cout << "\n========== OBJECT COUNTING ==========\n";

    cout << "Real objects: "
        << Real::GetObjectCount() << endl;

    cout << "Number objects: "
        << Real::Number::GetObjectCount() << endl;

    cout << "\n========== CLASS SIZE ==========\n";

    // Звичайний розмір класів
    cout << "Real class size: "
        << sizeof(Real) << " bytes" << endl;

    cout << "Number class size: "
        << sizeof(Real::Number) << " bytes" << endl;

    // Структури для демонстрації pack(1)
#pragma pack(push, 1)

    struct PackedNumber
    {
        double value;
    };

    struct PackedReal
    {
        PackedNumber number;
    };

#pragma pack(pop)

    cout << "\nClass size with pack(1):" << endl;

    cout << "Real: "
        << sizeof(PackedReal) << " bytes" << endl;

    cout << "Number: "
        << sizeof(PackedNumber) << " bytes" << endl;

    cout << "\n========== END OF PROGRAM ==========\n";

    return 0;
}
