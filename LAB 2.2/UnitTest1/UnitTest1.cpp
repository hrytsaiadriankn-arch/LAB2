#include "pch.h"
#include "CppUnitTest.h"
#include "Complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestDefaultConstructor)
        {
            Complex a;

            Assert::AreEqual(0.0, a.GetRe());
            Assert::AreEqual(0.0, a.GetIm());
        }

        TEST_METHOD(TestParameterizedConstructor)
        {
            Complex a(5, 2);

            Assert::AreEqual(5.0, a.GetRe());
            Assert::AreEqual(2.0, a.GetIm());
        }

        TEST_METHOD(TestCopyConstructor)
        {
            Complex a(4, 3);
            Complex b(a);

            Assert::AreEqual(4.0, b.GetRe());
            Assert::AreEqual(3.0, b.GetIm());
        }

        TEST_METHOD(TestSettersAndGetters)
        {
            Complex a;

            a.SetRe(5);
            a.SetIm(2);

            Assert::AreEqual(5.0, a.GetRe());
            Assert::AreEqual(2.0, a.GetIm());
        }

        TEST_METHOD(TestAssignmentOperator)
        {
            Complex a(5, 2);
            Complex b;

            b = a;

            Assert::AreEqual(5.0, b.GetRe());
            Assert::AreEqual(2.0, b.GetIm());
        }

        TEST_METHOD(TestAddition)
        {
            Complex a(5, 2);
            Complex b(4, 3);

            Complex c = a + b;

            Assert::AreEqual(9.0, c.GetRe());
            Assert::AreEqual(5.0, c.GetIm());
        }

        TEST_METHOD(TestSubtraction)
        {
            Complex a(5, 2);
            Complex b(4, 3);

            Complex c = a - b;

            Assert::AreEqual(1.0, c.GetRe());
            Assert::AreEqual(-1.0, c.GetIm());
        }

        TEST_METHOD(TestMultiplication)
        {
            Complex a(5, 2);
            Complex b(4, 3);

            Complex c = a * b;

            Assert::AreEqual(14.0, c.GetRe());
            Assert::AreEqual(23.0, c.GetIm());
        }

        TEST_METHOD(TestDivision)
        {
            Complex a(5, 2);
            Complex b(4, 3);

            Complex c = a / b;

            Assert::AreEqual(1.04, c.GetRe(), 0.0001);
            Assert::AreEqual(-0.28, c.GetIm(), 0.0001);
        }

        TEST_METHOD(TestDivisionByZero)
        {
            Complex a(5, 2);
            Complex b(0, 0);

            Assert::ExpectException<std::domain_error>(
                [&]() { a / b; }
            );
        }

        TEST_METHOD(TestPrefixIncrement)
        {
            Complex a(4, 3);

            ++a;

            Assert::AreEqual(5.0, a.GetRe());
            Assert::AreEqual(3.0, a.GetIm());
        }

        TEST_METHOD(TestPostfixIncrement)
        {
            Complex a(4, 3);

            Complex old = a++;

            Assert::AreEqual(4.0, old.GetRe());
            Assert::AreEqual(3.0, old.GetIm());

            Assert::AreEqual(5.0, a.GetRe());
            Assert::AreEqual(3.0, a.GetIm());
        }

        TEST_METHOD(TestPrefixDecrement)
        {
            Complex a(4, 3);

            --a;

            Assert::AreEqual(3.0, a.GetRe());
            Assert::AreEqual(3.0, a.GetIm());
        }

        TEST_METHOD(TestPostfixDecrement)
        {
            Complex a(4, 3);

            Complex old = a--;

            Assert::AreEqual(4.0, old.GetRe());
            Assert::AreEqual(3.0, old.GetIm());

            Assert::AreEqual(3.0, a.GetRe());
            Assert::AreEqual(3.0, a.GetIm());
        }

        TEST_METHOD(TestAdditionAssignment)
        {
            Complex a(5, 2);
            Complex b(4, 3);

            a += b;

            Assert::AreEqual(9.0, a.GetRe());
            Assert::AreEqual(5.0, a.GetIm());
        }

        TEST_METHOD(TestSubtractionAssignment)
        {
            Complex a(5, 2);
            Complex b(4, 3);

            a -= b;

            Assert::AreEqual(1.0, a.GetRe());
            Assert::AreEqual(-1.0, a.GetIm());
        }

        TEST_METHOD(TestMultiplicationAssignment)
        {
            Complex a(5, 2);
            Complex b(4, 3);

            a *= b;

            Assert::AreEqual(14.0, a.GetRe());
            Assert::AreEqual(23.0, a.GetIm());
        }

        TEST_METHOD(TestDivisionAssignment)
        {
            Complex a(5, 2);
            Complex b(4, 3);

            a /= b;

            Assert::AreEqual(1.04, a.GetRe(), 0.0001);
            Assert::AreEqual(-0.28, a.GetIm(), 0.0001);
        }

        TEST_METHOD(TestDivisionAssignmentByZero)
        {
            Complex a(5, 2);
            Complex b(0, 0);

            Assert::ExpectException<std::domain_error>(
                [&]() { a /= b; }
            );
        }

        TEST_METHOD(TestStringConversion)
        {
            Complex a(5, 2);

            string result = a;

            Assert::AreEqual(string("5 + 2i"), result);
        }
    };
}
