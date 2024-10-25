#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8.1(it).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestCountPlusMinusEqual)
		{
			char s[] = "++--==++";
			int plusCount = 0, minusCount = 0, equalCount = 0;

			Count(s, plusCount, minusCount, equalCount);

			Assert::AreEqual(4, plusCount);
			Assert::AreEqual(2, minusCount);
			Assert::AreEqual(2, equalCount);
		}

		TEST_METHOD(TestChangeReplacement)
		{
			char s[] = "++--==hello";
			char expected[] = "*********hello";

			Change(s);

			Assert::IsTrue(strcmp(expected, s) == 0);
		}

		TEST_METHOD(TestChangeNoReplacement)
		{
			char s[] = "abc";
			char expected[] = "abc";

			Change(s);

			Assert::IsTrue(strcmp(expected, s) == 0);
		}
	};
}
