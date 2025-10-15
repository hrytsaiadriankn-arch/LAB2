// Lab_02.cpp
// <Грицай Адріан Васильович>
// Лабораторна робота №2
// Лінійні програми
// Варіант 7

#include <iostream>
#include <cmath>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main()
{
    double alpha; // вхідний параметр
    double z1;    // результат обчислення 1-го виразу
    double z2;    // результат обчислення 2-го виразу

    cout << "alpha = ";
    cin >> alpha;

    z1 = pow(cos((3.0 * M_PI / 8.0) - (alpha / 4.0)), 2)
        - pow(cos((11.0 * M_PI / 8.0) + (alpha / 4.0)), 2);

    z2 = (sqrt(2.0) / 2.0) * sin(alpha / 2.0);

    cout << endl;
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    cin.get();
    return 0;
}