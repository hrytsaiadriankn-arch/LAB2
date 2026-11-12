
#include "Money.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <cmath>

long long Money::ToKopecks() const
{
    return static_cast<long long>(hryvnias) * 100 + kopecks;
}

void Money::FromKopecks(long long value)
{
    if (value < 0)
        throw invalid_argument("Money amount cannot be negative");

    long long h = value / 100;

    if (h > numeric_limits<long>::max())
        throw overflow_error("Money amount is too large");

    hryvnias = static_cast<long>(h);
    kopecks = static_cast<unsigned char>(value % 100);
}

Money::Money()
{
    hryvnias = 0;
    kopecks = 0;
}

Money::Money(long h, unsigned int k)
{
    if (h < 0 || k >= 100)
        throw invalid_argument("Invalid money amount");

    hryvnias = h;
    kopecks = static_cast<unsigned char>(k);
}

Money::Money(const Money& other)
{
    hryvnias = other.hryvnias;
    kopecks = other.kopecks;
}

Money::~Money()
{
}

void Money::SetHryvnias(long value)
{
    if (value < 0)
        throw invalid_argument("Hryvnias cannot be negative");

    hryvnias = value;
}

void Money::SetKopecks(unsigned int value)
{
    if (value >= 100)
        throw invalid_argument("Kopecks must be from 0 to 99");

    kopecks = static_cast<unsigned char>(value);
}

long Money::GetHryvnias() const
{
    return hryvnias;
}

unsigned char Money::GetKopecks() const
{
    return kopecks;
}

Money& Money::operator=(const Money& other)
{
    if (this != &other)
    {
        hryvnias = other.hryvnias;
        kopecks = other.kopecks;
    }

    return *this;
}

Money::operator string() const
{
    ostringstream stream;

    stream << hryvnias << "."
        << setfill('0') << setw(2)
        << static_cast<int>(kopecks)
        << " UAH";

    return stream.str();
}

Money& Money::operator++()
{
    FromKopecks(ToKopecks() + 1);
    return *this;
}

Money Money::operator++(int)
{
    Money temp(*this);
    ++(*this);
    return temp;
}

Money& Money::operator--()
{
    if (ToKopecks() == 0)
        throw underflow_error("Money cannot be negative");

    FromKopecks(ToKopecks() - 1);
    return *this;
}

Money Money::operator--(int)
{
    Money temp(*this);
    --(*this);
    return temp;
}

Money operator-(const Money& a, const Money& b)
{
    long long result = a.ToKopecks() - b.ToKopecks();

    if (result < 0)
        throw underflow_error("Result cannot be negative");

    Money temp;
    temp.FromKopecks(result);

    return temp;
}

Money operator*(const Money& a, double number)
{
    if (!isfinite(number) || number < 0)
        throw invalid_argument("Multiplier must be non-negative");

    long double result =
        static_cast<long double>(a.ToKopecks()) * number;

    if (result > static_cast<long double>(
        numeric_limits<long>::max()) * 100.0L + 99.0L)
        throw overflow_error("Money amount is too large");

    long long rounded = static_cast<long long>(round(result));

    Money temp;
    temp.FromKopecks(rounded);

    return temp;
}

Money operator*(double number, const Money& a)
{
    return a * number;
}

bool operator==(const Money& a, const Money& b)
{
    return a.ToKopecks() == b.ToKopecks();
}

bool operator!=(const Money& a, const Money& b)
{
    return !(a == b);
}

bool operator>(const Money& a, const Money& b)
{
    return a.ToKopecks() > b.ToKopecks();
}

bool operator<(const Money& a, const Money& b)
{
    return a.ToKopecks() < b.ToKopecks();
}

bool operator>=(const Money& a, const Money& b)
{
    return !(a < b);
}

bool operator<=(const Money& a, const Money& b)
{
    return !(a > b);
}

ostream& operator<<(ostream& out, const Money& money)
{
    out << money.hryvnias << "."
        << setfill('0') << setw(2)
        << static_cast<int>(money.kopecks)
        << " UAH";

    return out;
}

istream& operator>>(istream& in, Money& money)
{
    long h;
    int k;

    cout << "Enter hryvnias: ";
    in >> h;

    cout << "Enter kopecks: ";
    in >> k;

    if (in)
    {
        if (h < 0 || k < 0 || k >= 100)
        {
            in.setstate(ios::failbit);
        }
        else
        {
            money.hryvnias = h;
            money.kopecks = static_cast<unsigned char>(k);
        }
    }

    return in;
}
