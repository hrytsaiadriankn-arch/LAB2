#include "pch.h"
#include "CppUnitTest.h"
#include "Pay.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestDefaultConstructor)
        {
            Pay p;

            Assert::AreEqual(1.0, p.GetFirst());
            Assert::AreEqual(1, p.GetSecond());
        }

        TEST_METHOD(TestParameterizedConstructor)
        {
            Pay p(15000, 20);

            Assert::AreEqual(15000.0, p.GetFirst());
            Assert::AreEqual(20, p.GetSecond());
        }

        TEST_METHOD(TestCopyConstructor)
        {
            Pay p1(18000, 22);
            Pay p2(p1);

            Assert::AreEqual(18000.0, p2.GetFirst());
            Assert::AreEqual(22, p2.GetSecond());
        }

        TEST_METHOD(TestSettersAndGetters)
        {
            Pay p;

            p.SetFirst(20000);
            p.SetSecond(18);

            Assert::AreEqual(20000.0, p.GetFirst());
            Assert::AreEqual(18, p.GetSecond());
        }

        TEST_METHOD(TestSumma)
        {
            Pay p(15000, 20);

            double result = p.summa(22);

            Assert::AreEqual(13636.363636, result, 0.001);
        }

        TEST_METHOD(TestAssignmentOperator)
        {
            Pay p1(12000, 15);
            Pay p2;

            p2 = p1;

            Assert::AreEqual(12000.0, p2.GetFirst());
            Assert::AreEqual(15, p2.GetSecond());
        }

        TEST_METHOD(TestPrefixIncrement)
        {
            Pay p(15000, 20);

            ++p;

            Assert::AreEqual(15001.0, p.GetFirst());
            Assert::AreEqual(20, p.GetSecond());
        }

        TEST_METHOD(TestPostfixIncrement)
        {
            Pay p(15000, 20);

            Pay old = p++;

            Assert::AreEqual(15000.0, old.GetFirst());
            Assert::AreEqual(20, old.GetSecond());

            Assert::AreEqual(15000.0, p.GetFirst());
            Assert::AreEqual(21, p.GetSecond());
        }

        TEST_METHOD(TestPrefixDecrement)
        {
            Pay p(15000, 20);

            --p;

            Assert::AreEqual(14999.0, p.GetFirst());
            Assert::AreEqual(20, p.GetSecond());
        }

        TEST_METHOD(TestPostfixDecrement)
        {
            Pay p(15000, 20);

            Pay old = p--;

            Assert::AreEqual(15000.0, old.GetFirst());
            Assert::AreEqual(20, old.GetSecond());

            Assert::AreEqual(15000.0, p.GetFirst());
            Assert::AreEqual(19, p.GetSecond());
        }

        TEST_METHOD(TestStringConversion)
        {
            Pay p(15000, 20);

            string result = p;

            Assert::IsTrue(result.find("15000") != string::npos);
            Assert::IsTrue(result.find("20") != string::npos);
        }

        TEST_METHOD(TestMakePay)
        {
            Pay p = makePay(20000, 18);

            Assert::AreEqual(20000.0, p.GetFirst());
            Assert::AreEqual(18, p.GetSecond());
        }
    };
}
