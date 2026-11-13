
#include "pch.h"
#include "CppUnitTest.h"

#include "Number.h"
#include "Real.h"

#include <string>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(NumberTests)
    {
    public:

        // Перевірка конструктора без параметрів
        TEST_METHOD(TestNumberDefaultConstructor)
        {
            Number n;

            Assert::AreEqual(0.0, n.getValue(), 0.0001);
        }

        // Перевірка конструктора ініціалізації
        TEST_METHOD(TestNumberConstructor)
        {
            Number n(10.5);

            Assert::AreEqual(10.5, n.getValue(), 0.0001);
        }

        // Перевірка конструктора копіювання
        TEST_METHOD(TestNumberCopyConstructor)
        {
            Number n1(15.0);
            Number n2(n1);

            Assert::AreEqual(15.0, n2.getValue(), 0.0001);
        }

        // Перевірка методу setValue
        TEST_METHOD(TestNumberSetValue)
        {
            Number n;

            Assert::IsTrue(n.setValue(25.5));
            Assert::AreEqual(25.5, n.getValue(), 0.0001);
        }

        // Перевірка оператора присвоєння
        TEST_METHOD(TestNumberAssignment)
        {
            Number n1(12.0);
            Number n2;

            n2 = n1;

            Assert::AreEqual(12.0, n2.getValue(), 0.0001);
        }

        // Перевірка оператора множення
        TEST_METHOD(TestNumberMultiplication)
        {
            Number n1(6.0);
            Number n2(4.0);

            Number result = n1 * n2;

            Assert::AreEqual(24.0, result.getValue(), 0.0001);
        }

        // Перевірка оператора віднімання
        TEST_METHOD(TestNumberSubtraction)
        {
            Number n1(10.0);
            Number n2(3.0);

            Number result = n1 - n2;

            Assert::AreEqual(7.0, result.getValue(), 0.0001);
        }

        // Перевірка префіксного інкременту
        TEST_METHOD(TestNumberPrefixIncrement)
        {
            Number n(5.0);

            ++n;

            Assert::AreEqual(6.0, n.getValue(), 0.0001);
        }

        // Перевірка постфіксного інкременту
        TEST_METHOD(TestNumberPostfixIncrement)
        {
            Number n(5.0);

            Number old = n++;

            Assert::AreEqual(5.0, old.getValue(), 0.0001);
            Assert::AreEqual(6.0, n.getValue(), 0.0001);
        }

        // Перевірка префіксного декременту
        TEST_METHOD(TestNumberPrefixDecrement)
        {
            Number n(5.0);

            --n;

            Assert::AreEqual(4.0, n.getValue(), 0.0001);
        }

        // Перевірка постфіксного декременту
        TEST_METHOD(TestNumberPostfixDecrement)
        {
            Number n(5.0);

            Number old = n--;

            Assert::AreEqual(5.0, old.getValue(), 0.0001);
            Assert::AreEqual(4.0, n.getValue(), 0.0001);
        }

        // Перевірка перетворення числа у рядок
        TEST_METHOD(TestNumberToString)
        {
            Number n(10.0);

            string result = n.toString();

            Assert::AreEqual(string("10"), result);
        }
    };

    TEST_CLASS(RealTests)
    {
    public:

        // Перевірка конструктора без параметрів
        TEST_METHOD(TestRealDefaultConstructor)
        {
            Real r;

            Assert::AreEqual(0.0, r.getNumber().getValue(), 0.0001);
        }

        // Перевірка конструктора ініціалізації
        TEST_METHOD(TestRealConstructor)
        {
            Real r(25.5);

            Assert::AreEqual(25.5, r.getNumber().getValue(), 0.0001);
        }

        // Перевірка конструктора копіювання
        TEST_METHOD(TestRealCopyConstructor)
        {
            Real r1(30.0);
            Real r2(r1);

            Assert::AreEqual(30.0, r2.getNumber().getValue(), 0.0001);
        }

        // Перевірка методу Init
        TEST_METHOD(TestRealInit)
        {
            Real r;

            r.Init(45.0);

            Assert::AreEqual(45.0, r.getNumber().getValue(), 0.0001);
        }

        // Перевірка оператора присвоєння
        TEST_METHOD(TestRealAssignment)
        {
            Real r1(20.0);
            Real r2;

            r2 = r1;

            Assert::AreEqual(20.0, r2.getNumber().getValue(), 0.0001);
        }

        // Перевірка обчислення кубічного кореня
        TEST_METHOD(TestRealRoot)
        {
            Real r(64.0);

            double result = r.Root(3);

            Assert::AreEqual(4.0, result, 0.0001);
        }

        // Перевірка обчислення квадратного кореня
        TEST_METHOD(TestRealSquareRoot)
        {
            Real r(81.0);

            double result = r.Root(2);

            Assert::AreEqual(9.0, result, 0.0001);
        }

        // Перевірка кореня непарного степеня з від'ємного числа
        TEST_METHOD(TestRealNegativeRoot)
        {
            Real r(-27.0);

            double result = r.Root(3);

            Assert::AreEqual(-3.0, result, 0.0001);
        }

        // Перевірка помилки при корені нульового степеня
        TEST_METHOD(TestRealRootZeroDegree)
        {
            Real r(16.0);

            Assert::ExpectException<std::invalid_argument>(
                [&]() { r.Root(0); }
            );
        }

        // Перевірка помилки при парному корені з від'ємного числа
        TEST_METHOD(TestRealNegativeEvenRoot)
        {
            Real r(-16.0);

            Assert::ExpectException<std::invalid_argument>(
                [&]() { r.Root(2); }
            );
        }

        // Перевірка піднесення числа PI до другого степеня
        TEST_METHOD(TestRealPiPower)
        {
            Real r;

            double result = r.PiPower(2);

            Assert::AreEqual(9.8696044, result, 0.0001);
        }

        // Перевірка префіксного інкременту
        TEST_METHOD(TestRealPrefixIncrement)
        {
            Real r(10.0);

            ++r;

            Assert::AreEqual(11.0, r.getNumber().getValue(), 0.0001);
        }

        // Перевірка постфіксного інкременту
        TEST_METHOD(TestRealPostfixIncrement)
        {
            Real r(10.0);

            Real old = r++;

            Assert::AreEqual(10.0, old.getNumber().getValue(), 0.0001);
            Assert::AreEqual(11.0, r.getNumber().getValue(), 0.0001);
        }

        // Перевірка префіксного декременту
        TEST_METHOD(TestRealPrefixDecrement)
        {
            Real r(10.0);

            --r;

            Assert::AreEqual(9.0, r.getNumber().getValue(), 0.0001);
        }

        // Перевірка постфіксного декременту
        TEST_METHOD(TestRealPostfixDecrement)
        {
            Real r(10.0);

            Real old = r--;

            Assert::AreEqual(10.0, old.getNumber().getValue(), 0.0001);
            Assert::AreEqual(9.0, r.getNumber().getValue(), 0.0001);
        }

        // Перевірка перетворення об'єкта у рядок
        TEST_METHOD(TestRealToString)
        {
            Real r(15.0);

            string result = r.toString();

            Assert::AreEqual(string("15"), result);
        }
    };
}
