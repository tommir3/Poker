#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Poker_Win32\PokerLogic.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PokerUnitTest
{
	TEST_CLASS(PokerLogicTest)
	{
	private:
		PokerLogic *_poker;
	public:
		TEST_METHOD_INITIALIZE(SetUp)
		{
			_poker = new PokerLogic();
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
			delete _poker;
			_poker = NULL;
		}

		TEST_METHOD(TestValueToCard)
		{
			// TODO: 在此输入测试代码
			CardMark mark;
			CardNumber num;
			bool isOK = false;
			isOK = _poker->ValueToCard(83, mark, num);
			Assert::IsTrue(isOK);
			Assert::AreEqual<int>(mark, CardMark::Joker);
			Assert::AreEqual<int>(num, CardNumber::C_RJ);
			isOK = _poker->ValueToCard(33, mark, num);
			Assert::IsTrue(isOK);
			Assert::AreEqual<int>(mark, CardMark::Diamond);
			Assert::AreEqual<int>(num, CardNumber::C_K);
			isOK = _poker->ValueToCard(73, mark, num);
			Assert::IsTrue(isOK);
			Assert::AreEqual<int>(mark, CardMark::Club);
			Assert::AreEqual<int>(num, CardNumber::C_K);
			isOK = _poker->ValueToCard(70, mark, num);
			Assert::IsTrue(isOK);
			Assert::AreEqual<int>(mark, CardMark::Club);
			Assert::AreEqual<int>(num, CardNumber::C_10);
		}

		TEST_METHOD(TestCardToValue)
		{
			int card = -1;
			CardMark mark;
			CardNumber num;
			mark = CardMark::Club;
			num = CardNumber::C_6;
			card = _poker->CardToValue(mark, num);
			Assert::AreEqual<int>(66, card);
			mark = CardMark::Diamond;
			num = CardNumber::C_Q;
			card = _poker->CardToValue(mark, num);
			Assert::AreEqual<int>(32, card);
			mark = CardMark::Joker;
			num = CardNumber::C_RJ;
			card = _poker->CardToValue(mark, num);
			Assert::AreEqual<int>(83, card);
		}

		TEST_METHOD(TestCreateCardMarkPoker)
		{
			bool isOK = false;
			int cards[13];
			int joker[2];
			isOK = _poker->CreateCardMarkPoker(CardMark::Heart, 0, cards, 13);
			Assert::IsTrue(isOK);
			isOK = _poker->CreateCardMarkPoker(CardMark::Club, 1, cards, 13);
			Assert::IsTrue(isOK);
			isOK = _poker->CreateCardMarkPoker(CardMark::Joker, 2, joker, 2);
			Assert::IsTrue(isOK);
		}

	};
}