#include "pch.h"
#include "Complex.h"
#include <sstream>
#include <cmath>
#include <stdexcept>

// Конструктор за замовчуванням
Complex::Complex()
{
    re = 0;
    im = 0;
}

// Конструктор ініціалізації
Complex::Complex(double real, double imaginary)
{
    SetRe(real);
    SetIm(imaginary);
}

// Конструктор копіювання
Complex::Complex(const Complex& other)
{
    re = other.re;
    im = other.im;
}

// Деструктор
Complex::~Complex()
{
}

// Методи доступу
void Complex::SetRe(double value)
{
    if (!isfinite(value))
        throw invalid_argument("Invalid real part");

    re = value;
}

void Complex::SetIm(double value)
{
    if (!isfinite(value))
        throw invalid_argument("Invalid imaginary part");

    im = value;
}

double Complex::GetRe() const
{
    return re;
}

double Complex::GetIm() const
{
    return im;
}

// Оператор присвоєння
Complex& Complex::operator=(const Complex& other)
{
    if (this != &other)
    {
        re = other.re;
        im = other.im;
    }

    return *this;
}

// Перетворення комплексного числа у рядок
Complex::operator string() const
{
    ostringstream stream;

    stream << re;

    if (im >= 0)
        stream << " + " << im << "i";
    else
        stream << " - " << -im << "i";

    return stream.str();
}

// Префіксний інкремент
// Збільшує дійсну частину на 1
Complex& Complex::operator++()
{
    re += 1;
    return *this;
}

// Постфіксний інкремент
Complex Complex::operator++(int)
{
    Complex temp(*this);
    re += 1;
    return temp;
}

// Префіксний декремент
// Зменшує дійсну частину на 1
Complex& Complex::operator--()
{
    re -= 1;
    return *this;
}

// Постфіксний декремент
Complex Complex::operator--(int)
{
    Complex temp(*this);
    re -= 1;
    return temp;
}

// Оператор +=
Complex& Complex::operator+=(const Complex& other)
{
    re += other.re;
    im += other.im;
    return *this;
}

// Оператор -=
Complex& Complex::operator-=(const Complex& other)
{
    re -= other.re;
    im -= other.im;
    return *this;
}

// Оператор *=
Complex& Complex::operator*=(const Complex& other)
{
    double real = re * other.re - im * other.im;
    double imaginary = re * other.im + im * other.re;

    re = real;
    im = imaginary;

    return *this;
}

// Оператор /=
Complex& Complex::operator/=(const Complex& other)
{
    *this = *this / other;
    return *this;
}

// Додавання комплексних чисел
Complex operator+(const Complex& a, const Complex& b)
{
    return Complex(
        a.re + b.re,
        a.im + b.im
    );
}

// Віднімання комплексних чисел
Complex operator-(const Complex& a, const Complex& b)
{
    return Complex(
        a.re - b.re,
        a.im - b.im
    );
}

// Множення комплексних чисел
Complex operator*(const Complex& a, const Complex& b)
{
    double real = a.re * b.re - a.im * b.im;
    double imaginary = a.re * b.im + a.im * b.re;

    return Complex(real, imaginary);
}

// Ділення комплексних чисел
Complex operator/(const Complex& a, const Complex& b)
{
    double denominator = b.re * b.re + b.im * b.im;

    if (denominator == 0)
        throw domain_error("Division by zero complex number");

    double real =
        (a.re * b.re + a.im * b.im) / denominator;

    double imaginary =
        (a.im * b.re - a.re * b.im) / denominator;

    return Complex(real, imaginary);
}

// Оператор виведення
ostream& operator<<(ostream& out, const Complex& number)
{
    out << number.re;

    if (number.im >= 0)
        out << " + " << number.im << "i";
    else
        out << " - " << -number.im << "i";

    return out;
}

// Оператор введення
istream& operator>>(istream& in, Complex& number)
{
    double real, imaginary;

    cout << "Enter real part: ";
    in >> real;

    cout << "Enter imaginary part: ";
    in >> imaginary;

    if (in)
    {
        number.SetRe(real);
        number.SetIm(imaginary);
    }

    return in;
}