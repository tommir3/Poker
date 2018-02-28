#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Poker_Win32\DouDiZhuLogic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PokerUnitTest1
{		
	TEST_CLASS(DouDiZhuLogicTest)
	{
	private:
		DouDiZhu::DouDiZhuLogic *_ddz = NULL;
	public:
		TEST_METHOD_INITIALIZE(SetUp)
		{
			_ddz = new DouDiZhu::DouDiZhuLogic();
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
			delete _ddz;
			_ddz = NULL;
		}

		TEST_METHOD(TestIsPair)
		{
			bool isOK = false;
			const int len = 2;
			int card1, card2;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			cards = new int[len]{ card1, card2 };
			isOK = _ddz->IsPair(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsPair(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsPair(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsThree)
		{
			bool isOK = false;
			const int len = 3;
			int card1, card2, card3;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			cards = new int[len] { card1, card2, card3 };
			isOK = _ddz->IsThree(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsFour)
		{
			bool isOK = false;
			const int len = 4;
			int card1, card2, card3, card4;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			cards = new int[len] { card1, card2, card3, card4 };
			isOK = _ddz->IsFour(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsThreeSingle)
		{
			bool isOK = false;
			const int len = 4;
			int card1, card2, card3, card4;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			cards = new int[len] { card1, card2, card3, card4 };
			isOK = _ddz->IsThreeSingle(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			cards = new int[len] { card1, card2, card3, card4 };
			isOK = _ddz->IsThreeSingle(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_6);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			cards = new int[len] { card1, card2, card3, card4 };
			isOK = _ddz->IsThreeSingle(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			cards = new int[len] { card1, card2, card3, card4 };
			isOK = _ddz->IsThreeSingle(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
		}

	};
}