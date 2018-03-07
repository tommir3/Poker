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

		TEST_METHOD(TestIsThreePair)
		{
			bool isOK = false;
			const int len = 5;
			int card1, card2, card3, card4, card5;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			cards = new int[len] { card1, card2, card3, card4, card5 };
			isOK = _ddz->IsThreePair(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			cards = new int[len] { card1, card2, card3, card4, card5 };
			isOK = _ddz->IsThreePair(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsFourSingle)
		{
			bool isOK = false;
			const int len = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			cards = new int[len] { card1, card2, card3, card4, card5, card6 };
			isOK = _ddz->IsFourSingle(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			cards = new int[len] { card1, card2, card3, card4, card5, card6 };
			isOK = _ddz->IsFourSingle(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			cards = new int[len] { card1, card2, card3, card4, card5, card6 };
			isOK = _ddz->IsFourSingle(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			cards = new int[8] { card1, card2, card3, card4, card5, card6, card7, card8 };
			isOK = _ddz->IsFourSingle(cards, 8);
			Assert::IsFalse(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsFourPair)
		{
			bool isOK = false;
			const int len = 8;
			int card1, card2, card3, card4, card5, card6, card7, card8;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			cards = new int[len]{ card1, card2, card3, card4, card5, card6, card7, card8 };
			isOK = _ddz->IsFourPair(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsPlane)
		{
			bool isOK = false;
			const int len = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			cards = new int[len] { card1, card2, card3, card4, card5, card6 };
			isOK = _ddz->IsPlane(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			cards = new int[len] { card1, card2, card3, card4, card5, card6 };
			isOK = _ddz->IsPlane(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsPlaneSingle)
		{
			bool isOK = false;
			const int len = 8;
			int card1, card2, card3, card4, card5, card6, card7, card8;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8 };
			isOK = _ddz->IsPlaneSingle(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8 };
			isOK = _ddz->IsPlaneSingle(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsPlanePair)
		{
			bool isOK = false;
			const int len = 10;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10 };
			isOK = _ddz->IsPlanePair(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsThreePlane)
		{
			bool isOK = false;
			const int len = 9;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9 };
			isOK = _ddz->IsThreePlane(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsThreePlaneSingle)
		{
			bool isOK = false;
			const int len = 12;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,card11,card12;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12 };
			isOK = _ddz->IsThreePlaneSingle(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12 };
			isOK = _ddz->IsThreePlaneSingle(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12 };
			isOK = _ddz->IsThreePlaneSingle(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsThreePlanePair)
		{
			bool isOK = false;
			const int len = 15;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12,card13,card14,card15;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15 };
			isOK = _ddz->IsThreePlanePair(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15 };
			isOK = _ddz->IsThreePlanePair(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsFourPlane)
		{
			bool isOK = false;
			const int len = 12;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12 };
			isOK = _ddz->IsFourPlane(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsFourPlanePair)
		{
			bool isOK = false;
			const int len = 20;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_7);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20 };
			isOK = _ddz->IsFourPlanePair(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsFivePlane)
		{
			bool isOK = false;
			const int len = 15;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12,card13,card14,card15;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15 };
			isOK = _ddz->IsFivePlane(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsFivePlaneSingle)
		{
			bool isOK = false;
			const int len = 20;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_9);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20 };
			isOK = _ddz->IsFivePlaneSingle(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsStraightSingle)
		{
			bool isOK = false;
			const int len = 5;
			int card1, card2, card3, card4, card5, card6, card7, card8;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			cards = new int[len] { card1, card2, card3, card4, card5 };
			isOK = _ddz->IsStraightSingle(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsStraightPair)
		{
			bool isOK = false;
			const int len = 8;
			int card1, card2, card3, card4, card5, card6, card7, card8;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_6);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8 };
			isOK = _ddz->IsStraightPair(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestIsKingBomb)
		{
			bool isOK = false;
			const int len = 2;
			int card1, card2, card3, card4, card5, card6, card7, card8;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsKingBomb(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsKingBomb(cards, len);
			Assert::IsTrue(isOK);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_2);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_2);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsKingBomb(cards, len);
			Assert::IsFalse(isOK);
			delete[] cards;
			const int len1 = 4;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_2);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_2);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_2);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_2);
			cards = new int[len1] { card1, card2 };
			isOK = _ddz->IsKingBomb(cards, len1);
			Assert::IsFalse(isOK);
			delete[] cards;
		}

		TEST_METHOD(TestComparePair)
		{
			int cmp = -2;
			const int len = 2;
			int card1, card2, card3, card4;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			cards1 = new int[len]{ card1, card2 };
			cards2 = new int[len] { card3, card4 };
			cmp = _ddz->ComparePair(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			cards1 = new int[len] { card1, card2 };
			cards2 = new int[len] { card3, card4 };
			cmp = _ddz->ComparePair(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			cards1 = new int[len] { card1, card2 };
			cards2 = new int[len] { card3, card4 };
			cmp = _ddz->ComparePair(cards1, len, cards2, len);
			Assert::AreEqual<int>(0, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareThree)
		{
			int cmp = -2;
			const int len = 3;
			int card1, card2, card3, card4,card5,card6;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			cards1 = new int[len] { card1, card2, card3 };
			cards2 = new int[len] { card4, card5, card6 };
			cmp = _ddz->CompareThree(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareFour)
		{
			int cmp = -2;
			const int len = 4;
			int card1, card2, card3, card4, card5, card6, card7,card8;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			cards1 = new int[len] { card1, card2, card3, card4 };
			cards2 = new int[len] { card5, card6, card7, card8 };
			cmp = _ddz->CompareFour(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

	};
}