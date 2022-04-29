#include "pch.h"
#include "CppUnitTest.h"
#include "../[SibFU 6] - Theory_of_Programming - OOP/Header.h"
#include "../[SibFU 6] - Theory_of_Programming - OOP/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		std::string PATH = "..\\[SibFU 6] - Theory_of_Programming - OOP\\Test\\";
		TEST_METHOD(inTextTest)
		{
			ifstream ifst(PATH + "in\\inText.txt");
			Text* T = Text::inText(ifst);
			Assert::AreEqual(T->getMark(), 7);
			Assert::AreEqual(T->getText(), (string)"Text4Test");
		}
		TEST_METHOD(inAphorismTest)
		{
			ifstream ifst(PATH + "in\\inAphorism.txt");
			Aphorism* A = new Aphorism;
			A->inData(ifst);
			Assert::AreEqual(A->getAuthor(), (string)"Author");
		}
		TEST_METHOD(outAphorismTest)
		{
			Aphorism* A = new Aphorism();
			A->setAuthor("Pushkin");
			ofstream ofst(PATH + "out\\outAphorismActual.txt");
			A->outData("Aphirism Text", 9, ofst);
			ifstream ifstActual(PATH + "out\\outAphorismActual.txt");
			ifstream ifstExpected(PATH + "out\\outAphorismExpected.txt");
			string Expected;
			getline(ifstExpected, Expected, '\0');
			string Actual;
			getline(ifstActual, Actual, '\0');
			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(inSayingTest)
		{
			ifstream ifst(PATH + "in\\inSaying.txt");
			Saying* S = new Saying;
			S->inData(ifst);
			Assert::AreEqual(S->getCountry(), (string)"Country");
		}
		TEST_METHOD(outSayingTest)
		{
			Saying* S = new Saying();
			S->setCountry("Moldova");
			ofstream ofst(PATH + "out\\outSayingActual.txt");
			S->outData("Saying-Text.", 5, ofst);
			ifstream ifstActual(PATH + "out\\outSayingActual.txt");
			ifstream ifstExpected(PATH + "out\\outSayingExpected.txt");
			string Expected;
			getline(ifstExpected, Expected, '\0');
			string Actual;
			getline(ifstActual, Actual, '\0');
			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(inRiddleTest)
		{
			ifstream ifst(PATH + "in\\inRiddle.txt");
			Riddle* R = new Riddle;
			R->inData(ifst);
			Assert::AreEqual(R->getAnswer(), (string)"Answer");
		}
		TEST_METHOD(outRiddleTest)
		{
			Riddle* R = new Riddle();
			R->setAnswer("Love");
			ofstream ofst(PATH + "out\\outRiddleActual.txt");
			R->outData("Qute, but not qt", 9, ofst);
			ifstream ifstActual(PATH + "out\\outRiddleActual.txt");
			ifstream ifstExpected(PATH + "out\\outRiddleExpected.txt");
			string Expected;
			getline(ifstExpected, Expected, '\0');
			string Actual;
			getline(ifstActual, Actual, '\0');
			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(functionTest)
		{
			ifstream ifst(PATH + "function\\punctuation.txt");
			Text* T = Text::inText(ifst);
			Assert::AreEqual(T->textCounter(T->getText()), 4);
		}
		TEST_METHOD(compatatorTest)
		{
			ifstream ifst(PATH + "function\\comparator.txt");
			Text* first = Text::inText(ifst);
			Text* second = Text::inText(ifst);
			bool Actual = first->Compare(second);
			Assert::AreEqual(Actual, true);
		}
		TEST_METHOD(sortTest)
		{
			ifstream ifst(PATH + "function\\sort.txt");
			Container C;
			C.in(ifst);
			C.sort();
			ofstream ofst(PATH + "function\\sortActual.txt");
			C.out(ofst);
			ifstream ifstExpected(PATH + "function\\sortExpected.txt");
			ifstream ifstActual(PATH + "function\\sortActual.txt");
			string Expected;
			getline(ifstExpected, Expected, '\0');
			string Actual;
			getline(ifstActual, Actual, '\0');
			Assert::AreEqual(Expected, Actual);
		}
	};
}
