#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4it/lab6.4it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 5;
			double r[size] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
			double C = 3.0;

			int count = CountElementsLessThanC(r, size, C);

			Assert::AreEqual(2, count);
		}
	};
}
