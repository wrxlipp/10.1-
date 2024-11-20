#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.1_A/Lab_9.1_A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTLab91A
{
	TEST_CLASS(UTLab91A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* a = new Student[2];
			a[0].fis = 3;
			a[0].math = 4;
			a[0].infor = 3;
			a[1].fis = 4;
			a[1].math = 5;
			a[1].infor = 4;
			int c = Count1(a, 2);
			Assert::AreEqual(c, 1);
		}
	};
}
