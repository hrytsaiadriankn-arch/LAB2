
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Money
{
private:
    long hryvnias;
    unsigned char kopecks;

    long long ToKopecks() const;
    void FromKopecks(long long value);

public:
    Money();
    Money(long hryvnias, unsigned int kopecks);
    Money(const Money& other);
    ~Money();

    void SetHryvnias(long value);
    void SetKopecks(unsigned int value);

    long GetHryvnias() const;
    unsigned char GetKopecks() const;

    Money& operator=(const Money& other);

    operator string() const;

    Money& operator++();
    Money operator++(int);

    Money& operator--();
    Money operator--(int);

    friend Money operator-(const Money& a, const Money& b);
    friend Money operator*(const Money& a, double number);
    friend Money operator*(double number, const Money& a);

    friend bool operator==(const Money& a, const Money& b);
    friend bool operator!=(const Money& a, const Money& b);
    friend bool operator>(const Money& a, const Money& b);
    friend bool operator<(const Money& a, const Money& b);
    friend bool operator>=(const Money& a, const Money& b);
    friend bool operator<=(const Money& a, const Money& b);

    friend ostream& operator<<(ostream& out, const Money& money);
    friend istream& operator>>(istream& in, Money& money);
};
