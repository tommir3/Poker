#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Poker_Win32\PokerLogic.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PokerUnitTest
{
	TEST_CLASS(PokerLogicTest)
	{
	private:
		Poker::PokerLogic *_poker;
	public:
		TEST_METHOD_INITIALIZE(SetUp)
		{
			_poker = new Poker::PokerLogic();
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

		TEST_METHOD(TestCreatePoker)
		{
			bool isOK = false;
			int card[54];
			isOK = _poker->CreatePoker(card, 54);
			Assert::IsTrue(isOK);
			int cards[54];
			isOK = _poker->CreatePoker(1, cards, 54);
			Assert::IsTrue(isOK);
			int cards1[108];
			isOK = _poker->CreatePoker(2, cards1, 108);
			Assert::IsTrue(isOK);
			int cards2[162];
			isOK = _poker->CreatePoker(3, cards2, 162);
			Assert::IsTrue(isOK);
		}

		TEST_METHOD(TestValueToMark)
		{
			bool isOK = false;
			CardMark mark;
			isOK = _poker->ValueToMark(100, mark);
			Assert::IsTrue(isOK);
		}

		TEST_METHOD(TestValueToWeightValue_p4)
		{
			bool isOK = false;
			int cards[54];
			isOK = _poker->CreatePoker(cards, 54);
			Assert::IsTrue(isOK);
			int outCards[54];
			isOK = _poker->ValueToWeightValue(cards, 54, outCards, 54);

		}

		TEST_METHOD(TestCompareValue)
		{
			int cmp, val1, val2;
			val1 = 13;
			val2 = 33;
			cmp = _poker->CompareValue(val1, val2);
			Assert::AreEqual<int>(0, cmp);
			val1 = 83;
			val2 = 10083;
			cmp = _poker->CompareValue(val1, val2);
			Assert::AreEqual<int>(0, cmp);

		}

		TEST_METHOD(CompareCardNumber)
		{
			int cmp;
			CardNumber num1, num2;
			num1 = CardNumber::C_RJ;
			num2 = CardNumber::C_K;
			cmp = _poker->CompareValue(num1, num2);
			Assert::AreEqual<int>(1, cmp);
			num1 = CardNumber::C_A;
			num2 = CardNumber::C_K;
			cmp = _poker->CompareValue(num1, num2);
			Assert::AreEqual<int>(-1, cmp);
			num1 = CardNumber::C_2;
			num2 = CardNumber::C_2;
			cmp = _poker->CompareValue(num1, num2);
			Assert::AreEqual<int>(0, cmp);

		}

		TEST_METHOD(TestIsCardValue)
		{
			bool isOK = false;
			int card[54];
			isOK = _poker->CreatePoker(card, 54);
			Assert::IsTrue(isOK);
			isOK = _poker->IsCardValue(card, 54);
			Assert::IsTrue(isOK);
			int cards[54];
			isOK = _poker->CreatePoker(1, cards, 54);
			Assert::IsTrue(isOK);
			isOK = _poker->IsCardValue(cards, 54);
			Assert::IsTrue(isOK);
			int cards1[108];
			isOK = _poker->CreatePoker(2, cards1, 108);
			Assert::IsTrue(isOK);
			isOK = _poker->IsCardValue(cards1, 108);
			Assert::IsTrue(isOK);
			int cards2[162];
			isOK = _poker->CreatePoker(3, cards2, 162);
			Assert::IsTrue(isOK);
			isOK = _poker->IsCardValue(cards2, 162);
			Assert::IsTrue(isOK);
			int errCards[] = {1,11,16,18};
			isOK = _poker->IsCardValue(errCards, 4);
			Assert::IsFalse(isOK);
		}

	};
}