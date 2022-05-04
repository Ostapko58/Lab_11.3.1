#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.3.1/Lab_11.3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student stud;
			Student stud2;
			Sort(stud, 5, "start.bin");
			ifstream f("start.bin");
			ifstream g("finish.bin");
			for (int i = 0; i < 5; i++)
			{
				f.seekg(i * (long)sizeof(Student)); // встановили вказівник
				f.read((char*)&stud, sizeof(Student));
				g.seekg(i * (long)sizeof(Student)); // встановили вказівник
				g.read((char*)&stud2, sizeof(Student));
				Assert::AreEqual(stud.prizv, stud2.prizv);
				Assert::AreEqual(stud.kyrs, stud2.kyrs);
				Assert::AreEqual(stud.math_grade, stud2.math_grade);
				Assert::AreEqual(stud.physics_grade, stud2.physics_grade);
				Assert::AreEqual(stud.chisel_metod_grade, stud2.chisel_metod_grade);
				Assert::AreEqual(stud.pedagogic_grade, stud2.pedagogic_grade);
				Assert::AreEqual(stud.programing_grade, stud2.programing_grade);
			}
		}
	};
}
