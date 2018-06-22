#include "stdafx.h"
#include <vector>
#include "CppUnitTest.h"
#include "..\Poker_Win32\DouDiZhuLogic.h"
#include "..\Poker_Win32\DouDiZhuPlayCardLogic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PokerUnitTest1
{		
	using namespace std;
	TEST_CLASS(DouDiZhuLogicTest)
	{
	private:
		DouDiZhu::DouDiZhuLogic *_ddz = NULL;
		DouDiZhu::DouDiZhuPlayCardLogic *_ddzCardLogic = NULL;
	public:
		TEST_METHOD_INITIALIZE(SetUp)
		{
			_ddz = new DouDiZhu::DouDiZhuLogic();
			_ddzCardLogic = new DouDiZhu::DouDiZhuPlayCardLogic();
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
			delete _ddz;
			_ddz = NULL;
			delete _ddzCardLogic;
			_ddzCardLogic = NULL;
		}

		TEST_METHOD(TestIsPair)
		{
			CardType cardType;
			bool isOK = false;
			const int len = 2;
			int card1, card2;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			cards = new int[len]{ card1, card2 };
			isOK = _ddz->IsPair(cards, len);
			Assert::IsTrue(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::Pair);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsPair(cards, len);
			Assert::IsFalse(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsFalse(cardType == CardType::Pair);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsPair(cards, len);
			Assert::IsTrue(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::KingBomb);
			Assert::IsFalse(cardType == CardType::Pair);
			delete[] cards;
		}

		TEST_METHOD(TestIsThree)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::Three);
			delete[] cards;
		}

		TEST_METHOD(TestIsFour)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::Four);
			delete[] cards;
		}

		TEST_METHOD(TestIsThreeSingle)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::ThreeSingle);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			cards = new int[len] { card1, card2, card3, card4 };
			isOK = _ddz->IsThreeSingle(cards, len);
			Assert::IsTrue(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::Four);
			Assert::IsFalse(cardType == CardType::ThreeSingle);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_6);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			cards = new int[len] { card1, card2, card3, card4 };
			isOK = _ddz->IsThreeSingle(cards, len);
			Assert::IsFalse(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsFalse(cardType == CardType::ThreeSingle);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			cards = new int[len] { card1, card2, card3, card4 };
			isOK = _ddz->IsThreeSingle(cards, len);
			Assert::IsFalse(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsFalse(cardType == CardType::ThreeSingle);
			delete[] cards;
		}

		TEST_METHOD(TestIsThreePair)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::ThreePair);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			cards = new int[len] { card1, card2, card3, card4, card5 };
			isOK = _ddz->IsThreePair(cards, len);
			Assert::IsFalse(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsFalse(cardType == CardType::ThreePair);
			delete[] cards;
		}

		TEST_METHOD(TestIsFourSingle)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::FourSingle);
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::FourSingle);
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsFalse(cardType == CardType::FourSingle);
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsFalse(cardType == CardType::FourSingle);
			delete[] cards;
		}

		TEST_METHOD(TestIsFourPair)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::FourPair);
			delete[] cards;
		}

		TEST_METHOD(TestIsPlane)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::Plane);
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsFalse(cardType == CardType::Plane);
			delete[] cards;
		}

		TEST_METHOD(TestIsPlaneSingle)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsFalse(cardType == CardType::PlaneSingle);
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::PlaneSingle);
			delete[] cards;
		}

		TEST_METHOD(TestIsPlanePair)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::PlanePair);
			delete[] cards;
		}

		TEST_METHOD(TestIsThreePlane)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::ThreePlane);
			delete[] cards;
		}

		TEST_METHOD(TestIsThreePlaneSingle)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::ThreePlaneSingle);
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::ThreePlaneSingle);
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::ThreePlaneSingle);
			delete[] cards;
		}

		TEST_METHOD(TestIsThreePlanePair)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::ThreePlanePair);
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::ThreePlanePair);
			delete[] cards;
		}

		TEST_METHOD(TestIsFourPlane)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::FourPlane);
			delete[] cards;
		}

		TEST_METHOD(TestIsFourPlaneSingle)
		{
			CardType cardType;
			bool isOK = false;
			const int len = 16;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
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
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16 };
			isOK = _ddz->IsFourPlaneSingle(cards, len);
			Assert::IsTrue(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::FourPlaneSingle);
			delete[] cards;
		}

		TEST_METHOD(TestIsFourPlanePair)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::FivePlaneSingle);
			Assert::IsFalse(cardType == CardType::FourPlanePair);
			delete[] cards;
		}

		TEST_METHOD(TestIsFivePlane)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::FivePlane);
			delete[] cards;
		}

		TEST_METHOD(TestIsFivePlaneSingle)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::FivePlaneSingle);
			delete[] cards;
		}

		TEST_METHOD(TestIsSixPlane)
		{
			CardType cardType;
			bool isOK = false;
			const int len = 18;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17, card18;
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
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17, card18 };
			isOK = _ddz->IsSixPlane(cards, len);
			Assert::IsTrue(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::SixPlane);
			delete[] cards;
		}

		TEST_METHOD(TestIsStraightSingle)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::StraightSingle);
			delete[] cards;
		}

		TEST_METHOD(TestIsStraightPair)
		{
			CardType cardType;
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
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::StraightPair);
			delete[] cards;
		}

		TEST_METHOD(TestIsKingBomb)
		{
			CardType cardType;
			bool isOK = false;
			const int len = 2;
			int card1, card2, card3, card4, card5, card6, card7, card8;
			int *cards = NULL;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsKingBomb(cards, len);
			Assert::IsTrue(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::KingBomb);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsKingBomb(cards, len);
			Assert::IsTrue(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsTrue(cardType == CardType::KingBomb);
			delete[] cards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_2);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_2);
			cards = new int[len] { card1, card2 };
			isOK = _ddz->IsKingBomb(cards, len);
			Assert::IsFalse(isOK);
			cardType = _ddz->GetCardType(cards, len);
			Assert::IsFalse(cardType == CardType::KingBomb);
			delete[] cards;
			const int len1 = 4;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_2);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_2);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_2);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_2);
			cards = new int[len1] { card1, card2 };
			isOK = _ddz->IsKingBomb(cards, len1);
			Assert::IsFalse(isOK);
			Assert::IsFalse(cardType == CardType::KingBomb);
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
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
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
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
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
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
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
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
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
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareThreeSingle)
		{
			int cmp = -2;
			const int len = 4;
			int card1, card2, card3, card4, card5, card6, card7, card8;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			cards1 = new int[len] { card1, card2, card3, card4 };
			cards2 = new int[len] { card5, card6, card7, card8 };
			cmp = _ddz->CompareThreeSingle(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareThreePair)
		{
			int cmp = -2;
			const int len = 5;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			cards1 = new int[len] { card1, card2, card3, card4, card5 };
			cards2 = new int[len] { card6, card7, card8, card9, card10 };
			cmp = _ddz->CompareThreePair(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareFourSingle)
		{
			int cmp = -2;
			const int len = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,card11,card12;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6 };
			cards2 = new int[len] { card7, card8, card9, card10, card11, card12};
			cmp = _ddz->CompareFourSingle(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareFourPair)
		{
			int cmp = -2;
			const int len = 8;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_7);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8 };
			cards2 = new int[len] { card9, card10, card11, card12, card13, card14, card15, card16};
			cmp = _ddz->CompareFourPair(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestComparePlane)
		{
			int cmp = -2;
			const int len = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_9);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6 };
			cards2 = new int[len] { card7, card8, card9, card10, card11, card12};
			cmp = _ddz->ComparePlane(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestComparePlaneSingle)
		{
			int cmp = -2;
			const int len = 8;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8 };
			cards2 = new int[len] { card9, card10, card11, card12, card13, card14, card15, card16};
			cmp = _ddz->ComparePlaneSingle(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			CardType cardType = CardType::PlaneSingle;
			cmp = _ddz->CompareCards(cards1, len, cardType, cards2, len, cardType);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestComparePlanePair)
		{
			int cmp = -2;
			const int len = 10;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18,card19,card20;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10 };
			cards2 = new int[len] { card11, card12, card13, card14, card15, card16, card17,card18,card19,card20};
			cmp = _ddz->ComparePlanePair(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareThreePlane)
		{
			int cmp = -2;
			const int len = 9;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9 };
			cards2 = new int[len] { card10, card11, card12, card13, card14, card15, card16, card17, card18};
			cmp = _ddz->CompareThreePlane(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareThreePlaneSingle)
		{
			int cmp = -2;
			const int len = 12;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18,card19,card20,
				card21,card22,card23,card24;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card21 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card22 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card23 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card24 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_2);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12 };
			cards2 = new int[len] { card13, card14, card15, card16, card17, card18, card19, card20, card21, card22, card23, card24 };
			cmp = _ddz->CompareThreePlaneSingle(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareThreePlanePair)
		{
			int cmp = -2;
			const int len = 15;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20,
				card21, card22, card23, card24, card25, card26, card27, card28, card29, card30;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_2);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_2);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card21 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card22 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card23 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card24 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card25 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card26 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card27 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card28 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card29 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card30 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15 };
			cards2 = new int[len] { card16, card17, card18, card19, card20, card21, card22, card23, card24, card25, card26, card27, card28, card29, card30 };
			cmp = _ddz->CompareThreePlanePair(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareFourPlane)
		{
			int cmp = -2;
			const int len = 12;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20,
				card21, card22, card23, card24;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card21 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card22 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card23 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card24 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12 };
			cards2 = new int[len] { card13, card14, card15, card16, card17, card18, card19, card20, card21, card22, card23, card24 };
			cmp = _ddz->CompareFourPlane(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareFourPlaneSingle)
		{
			int cmp = -2;
			const int len = 16;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20,
				card21, card22, card23, card24, card25, card26, card27, card28, card29, card30,
				card31, card32;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card21 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card22 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card23 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card24 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card25 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card26 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card27 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card28 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card29 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card30 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card31 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card32 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16 };
			cards2 = new int[len] { card17, card18, card19, card20, card21, card22, card23, card24, card25, card26, card27, card28, card29, card30, card31, card32 };
			cmp = _ddz->CompareFourPlaneSingle(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareFourPlanePair)
		{
			int cmp = -2;
			const int len = 20;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20,
				card21, card22, card23, card24, card25, card26, card27, card28, card29, card30,
				card31, card32, card33, card34, card35, card36, card37, card38, card39, card40;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card21 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card22 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card23 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card24 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card25 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card26 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card27 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card28 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card29 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card30 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card31 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card32 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card33 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card34 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_2);
			card35 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card36 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card37 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card38 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_2);
			card39 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card40 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17, card18, card19, card20 };
			cards2 = new int[len] { card21, card22, card23, card24, card25, card26, card27, card28, card29, card30, card31, card32, card33, card34, card35, card36, card37, card38, card39, card40 };
			cmp = _ddz->CompareFourPlanePair(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(-1, cmp);
			CardType cardType = CardType::FourPlanePair;
			cmp = _ddz->CompareCards(cards1, len, cardType, cards2, len, cardType);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareFivePlane)
		{
			int cmp = -2;
			const int len = 15;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20,
				card21, card22, card23, card24, card25, card26, card27, card28, card29, card30;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card21 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card22 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card23 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card24 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card25 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card26 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card27 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card28 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			card29 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card30 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15 };
			cards2 = new int[len] { card16, card17, card18, card19, card20, card21, card22, card23, card24, card25, card26, card27, card28, card29, card30 };
			cmp = _ddz->CompareFivePlane(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareFivePlaneSingle)
		{
			int cmp = -2;
			const int len = 20;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20,
				card21, card22, card23, card24, card25, card26, card27, card28, card29, card30,
				card31, card32, card33, card34, card35, card36, card37, card38, card39, card40;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_2);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card21 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card22 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card23 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card24 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card25 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card26 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card27 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card28 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card29 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card30 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card31 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card32 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card33 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			card34 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card35 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card36 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_2);
			card37 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card38 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card39 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			card40 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_2);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17, card18, card19, card20 };
			cards2 = new int[len] { card21, card22, card23, card24, card25, card26, card27, card28, card29, card30, card31, card32, card33, card34, card35, card36, card37, card38, card39, card40 };
			cmp = _ddz->CompareFivePlaneSingle(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareSixPlane)
		{
			int cmp = -2;
			const int len = 18;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20,
				card21, card22, card23, card24, card25, card26, card27, card28, card29, card30,
				card31, card32, card33, card34, card35, card36;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card21 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card22 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card23 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card24 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card25 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card26 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card27 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card28 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card29 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card30 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card31 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			card32 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card33 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card34 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			card35 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card36 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17, card18 };
			cards2 = new int[len] { card19, card20, card21, card22, card23, card24, card25, card26, card27, card28, card29, card30, card31, card32, card33, card34, card35, card36 };
			cmp = _ddz->CompareSixPlane(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareStraightSingle)
		{
			int cmp = -2;
			const int len = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_9);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6 };
			cards2 = new int[len] { card7, card8, card9, card10, card11, card12};
			cmp = _ddz->CompareStraightSingle(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareStraightPair)
		{
			int cmp = -2;
			const int len = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);	
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6 };
			cards2 = new int[len] { card7, card8, card9, card10, card11, card12};
			cmp = _ddz->CompareStraightPair(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			cmp = _ddz->CompareCards(cards1, len, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareCards_KingBomb)
		{
			int cmp = -2;
			const int len = 4;
			int card1, card2, card3, card4, card5, card6;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			cards1 = new int[len] { card1, card2, card3, card4 };
			cards2 = new int[2] { card5, card6 };
			cmp = _ddz->CompareCards(cards1, len, cards2, 2);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_2);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_2);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_2);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_2);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			cards1 = new int[2] { card5, card6 };
			cards2 = new int[len] { card1, card2, card3, card4 };
			cmp = _ddz->CompareCards(cards1, 2, cards2, len);
			Assert::AreEqual<int>(1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

		TEST_METHOD(TestCompareCards_Four)
		{
			int cmp = -2;
			const int len = 18;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, card18, card19, card20,
				card21, card22;
			int *cards1, *cards2;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card18 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card19 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card20 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card21 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card22 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			cards1 = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17, card18 };
			cards2 = new int[4] { card19, card20, card21, card22};
			cmp = _ddz->CompareCards(cards1, len, cards2, 4);
			Assert::AreEqual<int>(-1, cmp);
			delete[] cards1;
			delete[] cards2;
		}

	};
}