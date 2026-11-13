
#include "pch.h"
#include "CppUnitTest.h"
#include "Real.h"

#include <string>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(RealTests)
    {
    public:

        // Перевірка конструктора Number без аргументів
        TEST_METHOD(TestNumberDefaultConstructor)
        {
            Real::Number n;

            Assert::AreEqual(0.0, n.GetValue(), 0.0001);
        }

        // Перевірка конструктора Number з параметром
        TEST_METHOD(TestNumberParameterizedConstructor)
        {
            Real::Number n(15.5);

            Assert::AreEqual(15.5, n.GetValue(), 0.0001);
        }

        // Перевірка конструктора копіювання Number
        TEST_METHOD(TestNumberCopyConstructor)
        {
            Real::Number n1(25.0);
            Real::Number n2(n1);

            Assert::AreEqual(25.0, n2.GetValue(), 0.0001);
        }

        // Перевірка SetValue
        TEST_METHOD(TestNumberSetValue)
        {
            Real::Number n(10.0);

            Assert::IsTrue(n.SetValue(50.0));
            Assert::AreEqual(50.0, n.GetValue(), 0.0001);

            Assert::IsFalse(n.SetValue(NAN));
        }

        // Перевірка множення
        TEST_METHOD(TestNumberMultiplication)
        {
            Real::Number n1(6.0);
            Real::Number n2(4.0);

            Real::Number result = n1 * n2;

            Assert::AreEqual(24.0, result.GetValue(), 0.0001);
        }

        // Перевірка віднімання
        TEST_METHOD(TestNumberSubtraction)
        {
            Real::Number n1(15.0);
            Real::Number n2(5.0);

            Real::Number result = n1 - n2;

            Assert::AreEqual(10.0, result.GetValue(), 0.0001);
        }

        // Перевірка методу Multiply
        TEST_METHOD(TestNumberMultiplyMethod)
        {
            Real::Number n(8.0);

            Assert::AreEqual(40.0, n.Multiply(5.0), 0.0001);
        }

        // Перевірка методу Subtract
        TEST_METHOD(TestNumberSubtractMethod)
        {
            Real::Number n(20.0);

            Assert::AreEqual(12.0, n.Subtract(8.0), 0.0001);
        }

        // Перевірка оператора присвоєння Number
        TEST_METHOD(TestNumberAssignment)
        {
            Real::Number n1(30.0);
            Real::Number n2;

            n2 = n1;

            Assert::AreEqual(30.0, n2.GetValue(), 0.0001);
        }

        // Перевірка префіксного інкременту Number
        TEST_METHOD(TestNumberPrefixIncrement)
        {
            Real::Number n(10.0);

            ++n;

            Assert::AreEqual(11.0, n.GetValue(), 0.0001);
        }

        // Перевірка префіксного декременту Number
        TEST_METHOD(TestNumberPrefixDecrement)
        {
            Real::Number n(10.0);

            --n;

            Assert::AreEqual(9.0, n.GetValue(), 0.0001);
        }

        // Перевірка постфіксного інкременту Number
        TEST_METHOD(TestNumberPostfixIncrement)
        {
            Real::Number n(10.0);

            Real::Number old = n++;

            Assert::AreEqual(10.0, old.GetValue(), 0.0001);
            Assert::AreEqual(11.0, n.GetValue(), 0.0001);
        }

        // Перевірка постфіксного декременту Number
        TEST_METHOD(TestNumberPostfixDecrement)
        {
            Real::Number n(10.0);

            Real::Number old = n--;

            Assert::AreEqual(10.0, old.GetValue(), 0.0001);
            Assert::AreEqual(9.0, n.GetValue(), 0.0001);
        }

        // Перевірка перетворення Number у рядок
        TEST_METHOD(TestNumberToString)
        {
            Real::Number n(25.0);

            std::string result = static_cast<std::string>(n);

            Assert::AreEqual(std::string("25"), result);
        }

        // Перевірка конструктора Real без аргументів
        TEST_METHOD(TestRealDefaultConstructor)
        {
            Real r;

            Assert::AreEqual(0.0, r.GetValue(), 0.0001);
        }

        // Перевірка конструктора Real з параметром
        TEST_METHOD(TestRealParameterizedConstructor)
        {
            Real r(45.0);

            Assert::AreEqual(45.0, r.GetValue(), 0.0001);
        }

        // Перевірка конструктора копіювання Real
        TEST_METHOD(TestRealCopyConstructor)
        {
            Real r1(60.0);
            Real r2(r1);

            Assert::AreEqual(60.0, r2.GetValue(), 0.0001);
        }

        // Перевірка зміни значення Real
        TEST_METHOD(TestRealSetValue)
        {
            Real r(10.0);

            Assert::IsTrue(r.SetValue(75.0));
            Assert::AreEqual(75.0, r.GetValue(), 0.0001);

            Assert::IsFalse(r.SetValue(INFINITY));
        }

        // Перевірка обчислення квадратного кореня
        TEST_METHOD(TestRealSquareRoot)
        {
            Real r(81.0);

            Assert::AreEqual(9.0, r.Root(2), 0.0001);
        }

        // Перевірка обчислення кубічного кореня
        TEST_METHOD(TestRealCubeRoot)
        {
            Real r(125.0);

            Assert::AreEqual(5.0, r.Root(3), 0.0001);
        }

        // Перевірка кореня четвертого степеня
        TEST_METHOD(TestRealFourthRoot)
        {
            Real r(81.0);

            Assert::AreEqual(3.0, r.Root(4), 0.0001);
        }

        // Перевірка кореня від'ємного числа непарного степеня
        TEST_METHOD(TestRealNegativeRoot)
        {
            Real r(-27.0);

            Assert::AreEqual(-3.0, r.Root(3), 0.0001);
        }

        // Перевірка кореня нульового степеня
        TEST_METHOD(TestRealZeroDegreeRoot)
        {
            Real r(25.0);

            Assert::IsTrue(std::isnan(r.Root(0)));
        }

        // Перевірка кореня парного степеня від'ємного числа
        TEST_METHOD(TestRealInvalidRoot)
        {
            Real r(-16.0);

            Assert::IsTrue(std::isnan(r.Root(2)));
        }

        // Перевірка обчислення PI у квадраті
        TEST_METHOD(TestRealPiPowerTwo)
        {
            Real r;

            Assert::AreEqual(
                9.869604401,
                r.PiPower(2),
                0.0001
            );
        }

        // Перевірка обчислення PI у кубі
        TEST_METHOD(TestRealPiPowerThree)
        {
            Real r;

            Assert::AreEqual(
                31.00627668,
                r.PiPower(3),
                0.0001
            );
        }

        // Перевірка оператора присвоєння Real
        TEST_METHOD(TestRealAssignment)
        {
            Real r1(100.0);
            Real r2;

            r2 = r1;

            Assert::AreEqual(100.0, r2.GetValue(), 0.0001);
        }

        // Перевірка префіксного інкременту Real
        TEST_METHOD(TestRealPrefixIncrement)
        {
            Real r(10.0);

            ++r;

            Assert::AreEqual(11.0, r.GetValue(), 0.0001);
        }

        // Перевірка префіксного декременту Real
        TEST_METHOD(TestRealPrefixDecrement)
        {
            Real r(10.0);

            --r;

            Assert::AreEqual(9.0, r.GetValue(), 0.0001);
        }

        // Перевірка постфіксного інкременту Real
        TEST_METHOD(TestRealPostfixIncrement)
        {
            Real r(10.0);

            Real old = r++;

            Assert::AreEqual(10.0, old.GetValue(), 0.0001);
            Assert::AreEqual(11.0, r.GetValue(), 0.0001);
        }

        // Перевірка постфіксного декременту Real
        TEST_METHOD(TestRealPostfixDecrement)
        {
            Real r(10.0);

            Real old = r--;

            Assert::AreEqual(10.0, old.GetValue(), 0.0001);
            Assert::AreEqual(9.0, r.GetValue(), 0.0001);
        }

        // Перевірка перетворення Real у рядок
        TEST_METHOD(TestRealToString)
        {
            Real r(50.0);

            std::string result = static_cast<std::string>(r);

            Assert::AreEqual(std::string("50"), result);
        }

        // Перевірка підрахунку об'єктів Real
        TEST_METHOD(TestRealObjectCount)
        {
            int before = Real::GetObjectCount();

            {
                Real r1(10.0);
                Real r2(20.0);

                Assert::AreEqual(
                    before + 2,
                    Real::GetObjectCount()
                );
            }

            Assert::AreEqual(
                before,
                Real::GetObjectCount()
            );
        }

        // Перевірка підрахунку об'єктів Number
        TEST_METHOD(TestNumberObjectCount)
        {
            int before = Real::Number::GetObjectCount();

            {
                Real::Number n1(10.0);
                Real::Number n2(20.0);

                Assert::AreEqual(
                    before + 2,
                    Real::Number::GetObjectCount()
                );
            }

            Assert::AreEqual(
                before,
                Real::Number::GetObjectCount()
            );
        }

        // Перевірка кількості вкладених об'єктів Real
        TEST_METHOD(TestNestedNumberObjectCount)
        {
            int before = Real::Number::GetObjectCount();

            {
                Real r1(10.0);
                Real r2(20.0);

                Assert::AreEqual(
                    before + 2,
                    Real::Number::GetObjectCount()
                );
            }

            Assert::AreEqual(
                before,
                Real::Number::GetObjectCount()
            );
        }
    };
}
