#include "pch.h"
#include "CppUnitTest.h"
#include "D:/2 курс 1 семестр/LAB 2.4.1/Project1/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Перевірка конструктора без параметрів
        TEST_METHOD(TestDefaultConstructor)
        {
            Vector v;

            Assert::AreEqual(0, v.getLength());
            Assert::AreEqual(0, v.size());
        }

        // Перевірка конструктора ініціалізації
        TEST_METHOD(TestInitializationConstructor)
        {
            int values[] = { 1, 2, 3, 4, 5 };
            Vector v(5, values);

            Assert::AreEqual(5, v.getLength());
            Assert::AreEqual(1, v[0]);
            Assert::AreEqual(5, v[4]);
        }

        // Перевірка конструктора копіювання
        TEST_METHOD(TestCopyConstructor)
        {
            int values[] = { 10, 20, 30 };
            Vector v1(3, values);
            Vector v2(v1);

            Assert::AreEqual(3, v2.size());
            Assert::AreEqual(10, v2[0]);
            Assert::AreEqual(20, v2[1]);
            Assert::AreEqual(30, v2[2]);
        }

        // Перевірка оператора присвоєння
        TEST_METHOD(TestAssignmentOperator)
        {
            int values[] = { 4, 5, 6 };
            Vector v1(3, values);
            Vector v2;

            v2 = v1;

            Assert::AreEqual(3, v2.size());
            Assert::AreEqual(4, v2[0]);
            Assert::AreEqual(5, v2[1]);
            Assert::AreEqual(6, v2[2]);
        }

        // Перевірка оператора індексації
        TEST_METHOD(TestIndexOperator)
        {
            int values[] = { 7, 8, 9 };
            Vector v(3, values);

            Assert::AreEqual(7, v[0]);
            Assert::AreEqual(8, v[1]);
            Assert::AreEqual(9, v[2]);
        }

        // Перевірка зміни елемента
        TEST_METHOD(TestSetElement)
        {
            int values[] = { 1, 2, 3 };
            Vector v(3, values);

            Assert::IsTrue(v.setElement(1, 100));
            Assert::AreEqual(100, v[1]);

            Assert::IsFalse(v.setElement(5, 10));
        }

        // Перевірка множення вектора на число
        TEST_METHOD(TestVectorMultiplication)
        {
            int values[] = { 1, 2, 3 };
            Vector v(3, values);

            Vector result = v * 2;

            Assert::AreEqual(2, result[0]);
            Assert::AreEqual(4, result[1]);
            Assert::AreEqual(6, result[2]);
        }

        // Перевірка множення числа на вектор
        TEST_METHOD(TestScalarMultiplication)
        {
            int values[] = { 2, 3, 4 };
            Vector v(3, values);

            Vector result = 3 * v;

            Assert::AreEqual(6, result[0]);
            Assert::AreEqual(9, result[1]);
            Assert::AreEqual(12, result[2]);
        }

        // Перевірка рівності векторів
        TEST_METHOD(TestEqualityOperator)
        {
            int values1[] = { 1, 2, 3 };
            int values2[] = { 1, 2, 3 };

            Vector v1(3, values1);
            Vector v2(3, values2);

            Assert::IsTrue(v1 == v2);
        }

        // Перевірка нерівності векторів
        TEST_METHOD(TestInequalityOperator)
        {
            int values1[] = { 1, 2, 3 };
            int values2[] = { 4, 5, 6 };

            Vector v1(3, values1);
            Vector v2(3, values2);

            Assert::IsTrue(v1 != v2);
        }

        // Перевірка обчислення норми вектора
        TEST_METHOD(TestNorm)
        {
            int values[] = { 2, 8, 4, 10, 5 };
            Vector v(5, values);

            Assert::AreEqual(8, v.Norm());
        }

        // Перевірка норми вектора з від'ємними числами
        TEST_METHOD(TestNormNegativeNumbers)
        {
            int values[] = { -10, -3, 5, 2 };
            Vector v(4, values);

            Assert::AreEqual(15, v.Norm());
        }

        // Перевірка перетворення вектора у рядок
        TEST_METHOD(TestStringConversion)
        {
            int values[] = { 1, 2, 3 };
            Vector v(3, values);

            string result = v;

            Assert::AreEqual(string("(1, 2, 3)"), result);
        }
    };
}

