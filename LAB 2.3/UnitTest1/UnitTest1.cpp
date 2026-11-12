#include "pch.h"
#include "CppUnitTest.h"
#include "Money.h"

#include <string>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MoneyUnitTests
{
    TEST_CLASS(MoneyTests)
    {
    public:

        // Test default constructor
        TEST_METHOD(TestDefaultConstructor)
        {
            Money money;

            Assert::AreEqual(0L, money.GetHryvnias());
            Assert::AreEqual(0, (int)money.GetKopecks());
        }

        // Test initialization constructor
        TEST_METHOD(TestInitializationConstructor)
        {
            Money money(500, 50);

            Assert::AreEqual(500L, money.GetHryvnias());
            Assert::AreEqual(50, (int)money.GetKopecks());
        }

        // Test copy constructor
        TEST_METHOD(TestCopyConstructor)
        {
            Money original(700, 25);
            Money copy(original);

            Assert::AreEqual(700L, copy.GetHryvnias());
            Assert::AreEqual(25, (int)copy.GetKopecks());
        }

        // Test setters
        TEST_METHOD(TestSetters)
        {
            Money money;

            money.SetHryvnias(300);
            money.SetKopecks(75);

            Assert::AreEqual(300L, money.GetHryvnias());
            Assert::AreEqual(75, (int)money.GetKopecks());
        }

        // Test assignment operator
        TEST_METHOD(TestAssignmentOperator)
        {
            Money first(100, 50);
            Money second;

            second = first;

            Assert::AreEqual(100L, second.GetHryvnias());
            Assert::AreEqual(50, (int)second.GetKopecks());
        }

        // Test subtraction
        TEST_METHOD(TestSubtraction)
        {
            Money first(700, 25);
            Money second(500, 50);

            Money result = first - second;

            Assert::AreEqual(199L, result.GetHryvnias());
            Assert::AreEqual(75, (int)result.GetKopecks());
        }

        // Test multiplication
        TEST_METHOD(TestMultiplication)
        {
            Money money(500, 50);

            Money result = money * 1.5;

            Assert::AreEqual(750L, result.GetHryvnias());
            Assert::AreEqual(75, (int)result.GetKopecks());
        }

        // Test multiplication with reversed operands
        TEST_METHOD(TestReverseMultiplication)
        {
            Money money(200, 00);

            Money result = 2.0 * money;

            Assert::AreEqual(400L, result.GetHryvnias());
            Assert::AreEqual(0, (int)result.GetKopecks());
        }

        // Test equality operator
        TEST_METHOD(TestEquality)
        {
            Money first(100, 50);
            Money second(100, 50);

            Assert::IsTrue(first == second);
        }

        // Test inequality operator
        TEST_METHOD(TestInequality)
        {
            Money first(100, 50);
            Money second(200, 50);

            Assert::IsTrue(first != second);
        }

        // Test greater than operator
        TEST_METHOD(TestGreaterThan)
        {
            Money first(300, 50);
            Money second(200, 50);

            Assert::IsTrue(first > second);
        }

        // Test less than operator
        TEST_METHOD(TestLessThan)
        {
            Money first(100, 25);
            Money second(200, 50);

            Assert::IsTrue(first < second);
        }

        // Test greater than or equal operator
        TEST_METHOD(TestGreaterThanOrEqual)
        {
            Money first(100, 50);
            Money second(100, 50);

            Assert::IsTrue(first >= second);
        }

        // Test less than or equal operator
        TEST_METHOD(TestLessThanOrEqual)
        {
            Money first(100, 25);
            Money second(100, 50);

            Assert::IsTrue(first <= second);
        }

        // Test prefix increment
        TEST_METHOD(TestPrefixIncrement)
        {
            Money money(100, 50);

            ++money;

            Assert::AreEqual(100L, money.GetHryvnias());
            Assert::AreEqual(51, (int)money.GetKopecks());
        }

        // Test postfix increment
        TEST_METHOD(TestPostfixIncrement)
        {
            Money money(100, 50);

            Money old = money++;

            Assert::AreEqual(50, (int)old.GetKopecks());
            Assert::AreEqual(51, (int)money.GetKopecks());
        }

        // Test prefix decrement
        TEST_METHOD(TestPrefixDecrement)
        {
            Money money(100, 50);

            --money;

            Assert::AreEqual(100L, money.GetHryvnias());
            Assert::AreEqual(49, (int)money.GetKopecks());
        }

        // Test postfix decrement
        TEST_METHOD(TestPostfixDecrement)
        {
            Money money(100, 50);

            Money old = money--;

            Assert::AreEqual(50, (int)old.GetKopecks());
            Assert::AreEqual(49, (int)money.GetKopecks());
        }

        // Test string conversion
        TEST_METHOD(TestStringConversion)
        {
            Money money(500, 50);

            std::string result = money;

            Assert::AreEqual(
                "500.50 UAH",
                result.c_str()
            );
        }
    };
}
