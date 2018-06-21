#include "stdafx.h"
#include <vector>
#include "CppUnitTest.h"
#include "..\Poker_Win32\DouDiZhuPlayCardLogic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PokerUnitTest
{
	using namespace std;
	TEST_CLASS(DouDiZhuPlayCardLogicTest)
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

		/*-------------------------------找牌 begin-----------------------------------*/
		TEST_METHOD(TestFindSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 1;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_A);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::Single, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card16 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card5 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindPair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 2;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::Pair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card5, card7 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card10, card13 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card16, card12 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindThree)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 3;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::Three, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card6, card8, card9 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindThreeSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 4;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::ThreeSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen]{ card6 ,card8, card9,card16 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen]{ card6 ,card8, card9,card12 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindThreePair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 5;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::ThreePair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card6, card8, card9, card10,card13 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card6, card8, card9, card5,card7 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindFour)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 4;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_A);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::Four, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card11, card14, card15, card17 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card6, card7, card8, card9 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindFourSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_A);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_7);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::FourSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card11, card14, card15, card17, card1, card16  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card6, card7, card8, card9, card12, card5 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindFourPair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 8;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_A);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::FourPair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card11, card14, card15, card17, card12, card16,card10,card13  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card6, card7, card8, card9, card10, card13, card12, card16 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindPlane)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::Plane, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindPlaneSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 8;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_7);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::PlaneSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9,card1,card16  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card5, card12  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindPlanePair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 10;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::PlanePair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card16, card10, card13 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card10, card13, card5, card7 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindThreePlane)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 9;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::ThreePlane, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card16, card5  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindThreePlaneSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 12;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::ThreePlaneSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card16, card5,card7,card12,card14  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindThreePlanePair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 15;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::ThreePlanePair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card16, card5, card7, card12, card11, card15,card14,card17  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindFourPlane)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 12;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::FourPlane, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card16, card5, card10, card13, card15 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindFourPlaneSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 16;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::FourPlaneSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card16, card5, card10, card13, card15, card7,card12,card14,card17 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindFivePlane)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 15;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::FivePlane, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card16, card5, card10, card13, card15, card11, card14, card17 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindStraightSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 5;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::StraightSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card7, card11, card12, card4, card16 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card7, card11, card12, card4, card17 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[6] { card7, card11, card12, card4, card17, card16 };
			isFind = IsSameArray(findCards, 6, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindStraightPair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::StraightPair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card4, card6, card8, card1, card5 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindKingBomb)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 2;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_BJ);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Joker, CardNumber::C_RJ);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, CardType::KingBomb, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card9, card16 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}
		/*-------------------------------找牌 end-----------------------------------*/

		/*-------------------------------找能管上的牌 begin-----------------------------------*/
		TEST_METHOD(TestFindMaxSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 1;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards, minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_A);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			minCards = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			isOK = _ddzCardLogic->FindTargetCards(cards, len, &minCards, 1, CardType::Single, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card5 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
		}

		TEST_METHOD(TestFindMaxPair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 2;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards, *findCards,*minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			minCards = new int[2]{ card16, card12 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, 2, CardType::Pair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card5, card7 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card10, card13 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxThree)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 3;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,card100,card101,card102;
			int *cards, *findCards,*minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_2);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_2);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_2);
			minCards = new int[3]{ card100, card101, card102 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, 3, CardType::Three, outCards);
			Assert::IsFalse(isOK);
			delete[] cards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxThreeSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 4;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17, 
				card100, card101, card102, card103,card104,card105, card106,card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_6);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_2);
			minCards = new int[4]{ card100, card101, card102,card103 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, 4, CardType::ThreeSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card6, card8, card9, card16 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card10, card12, card13, card17 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxThreePair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 5;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_K);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_4);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_4);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_2);
			card104 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_2);
			minCards = new int[5]{ card100, card101, card102,card103,card104 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, 5, CardType::ThreePair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card6, card8, card9, card12, card16 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card6, card8, card9, card12, card16 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxFour)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 4;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_A);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_5);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_5);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			minCards = new int[findLen]{ card100, card101, card102,card103 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, findLen, CardType::Four, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card11, card14, card15, card17 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsFalse(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card6, card7, card8, card9 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxFourSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_A);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_7);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card104 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card105 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			minCards = new int[findLen] { card100, card101, card102, card103, card104, card105 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, findLen,CardType::FourSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card11, card14, card15, card17, card1, card16  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsFalse(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card6, card7, card8, card9, card12, card5 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxFourPair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 8;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_A);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_Q);
			card104 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card105 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card106 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card107 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			minCards = new int[findLen] { card100, card101, card102, card103, card104, card105, card106, card107 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, findLen,CardType::FourPair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card11, card14, card15, card17, card12, card16, card10, card13  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsFalse(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card6, card7, card8, card9, card10, card13, card12, card16 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxPlane)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 6;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card104 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card105 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			minCards = new int[findLen] { card100, card101, card102, card103, card104, card105 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, findLen, CardType::Plane, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card11, card12, card16, card14, card15, card17  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsFalse(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxPlaneSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 8;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card104 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card105 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card106 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card107 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			minCards = new int[findLen] { card100, card101, card102, card103, card104, card105, card106, card107 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, findLen,CardType::PlaneSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card7  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card11, card12, card16, card14, card15, card17, card1, card7  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsFalse(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxPlanePair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 10;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_J);
			card104 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card105 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card106 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_3);
			card107 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_3);
			card108 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card109 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_6);
			minCards = new int[findLen] { card100, card101, card102, card103, card104, card105, card106, card107, card108, card109 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, findLen,CardType::PlanePair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card16, card10, card13 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card11, card12, card7, card14, card15, card17, card1, card16, card10, card13 };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsFalse(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxThreePlane)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 9;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_7);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_7);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_6);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_10);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_6);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_6);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_8);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_9);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_7);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_9);
			card104 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card105 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card106 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card107 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			card108 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			minCards = new int[findLen] { card100, card101, card102, card103, card104, card105, card106, card107, card108 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, findLen,CardType::ThreePlane, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card10, card13, card16, card14, card12, card15, card1, card5, card7  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxThreePlaneSingle)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 12;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_J);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_10);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_7);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_9);
			card104 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card105 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card106 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card107 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			card108 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card109 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card110 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card111 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			minCards = new int[findLen] { card100, card101, card102, card103, card104, card105, card106, card107, card108,card109,card110,card111 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, findLen,CardType::ThreePlaneSingle, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card2, card3, card4, card1, card16, card5, card10, card13, card15,card7,card12, card14  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			findCards = new int[findLen] { card2, card3, card4, card6, card8, card9, card1, card16, card5, card7, card12, card14  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			delete[] minCards;
		}

		TEST_METHOD(TestFindMaxThreePlanePair)
		{
			bool isOK = false, isFind;
			const int len = 17, findLen = 15;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17,
				card100, card101, card102, card103, card104, card105, card106, card107,
				card108, card109, card110, card111, card112, card113, card114, card115;
			int *cards, *findCards, *minCards;
			vector<vector<int>> outCards;
			card1 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_Q);
			card2 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_K);
			card3 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_K);
			card4 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_K);
			card5 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_Q);
			card6 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_A);
			card7 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_9);
			card8 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_A);
			card9 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card10 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_J);
			card11 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_10);
			card12 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card13 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_J);
			card14 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_4);
			card15 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_10);
			card16 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_Q);
			card17 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_4);
			cards = new int[len] { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16, card17 };
			card100 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_7);
			card101 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_7);
			card102 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_7);
			card103 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_9);
			card104 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_9);
			card105 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_8);
			card106 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_9);
			card107 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_8);
			card108 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_8);
			card109 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_3);
			card110 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_3);
			card111 = _ddz->PokerLogic::CardToValue(CardMark::Spade, CardNumber::C_5);
			card112 = _ddz->PokerLogic::CardToValue(CardMark::Diamond, CardNumber::C_5);
			card113 = _ddz->PokerLogic::CardToValue(CardMark::Heart, CardNumber::C_A);
			card114 = _ddz->PokerLogic::CardToValue(CardMark::Club, CardNumber::C_A);
			minCards = new int[findLen] { card100, card101, card102, card103, card104, card105, card106, card107, card108, card109, card110, card111, card112, card113, card114 };
			isOK = _ddzCardLogic->FindTargetCards(cards, len, minCards, findLen, CardType::ThreePlanePair, outCards);
			Assert::IsTrue(isOK);
			delete[] cards;
			findCards = new int[findLen] { card1, card5, card16, card2, card3, card4, card6, card8, card9, 
										card7, card12, card11, card15, card14, card17  };
			isFind = IsSameArray(findCards, findLen, outCards);
			Assert::IsTrue(isFind);
			delete[] findCards;
			delete[] minCards;
		}



		/*-------------------------------找能管上的牌 end-----------------------------------*/





		/*===================================判断牌是否存在========================================*/

		bool IsSameArray(const int *cards, const int len, const vector<vector<int>> const outCards)
		{
			bool result = false;
			try
			{
				if (!outCards.empty())
				{
					for (int i = 0; i < outCards.size(); ++i)
					{
						result = IsSameArray(cards, len, outCards[i]);
						if (result)
						{
							break;
						}
					}
				}
			}
			catch (exception err)
			{
				throw(err);
			}
			return result;
		}

		bool IsSameArray(const int *cards, const int len, const vector<int> const outCards)
		{
			bool result = false;
			try
			{
				if (len == outCards.size())
				{
					int cmpNum;
					bool isFind;
					result = true;
					for (int i = 0; i < len; ++i)
					{
						cmpNum = outCards[i];
						isFind = false;
						for (int j = 0; j < len; ++j)
						{
							if (cards[j] == cmpNum)
							{
								isFind = true;
								break;
							}
						}
						if (!isFind)
						{
							result = false;
							break;
						}
					}
				}
			}
			catch (exception err)
			{
				result = false;
				throw(err);
			}
			return result;
		}

	};
}
