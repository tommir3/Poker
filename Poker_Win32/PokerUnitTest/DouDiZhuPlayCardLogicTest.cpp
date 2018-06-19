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

		/*测试DouDiZhuPlayCardLogic类中的方法*/
		TEST_METHOD(TestFindSingle)
		{
			bool isOK = false;
			const int len = 17;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards;
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
			isOK = _ddzCardLogic->FindSingle(cards, len, outCards);
			Assert::IsTrue(isOK);
		}

		TEST_METHOD(TestFindPair)
		{
			bool isOK = false;
			const int len = 17;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards;
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
			isOK = _ddzCardLogic->FindPair(cards, len, outCards);
			Assert::IsTrue(isOK);
		}

		TEST_METHOD(TestFindThree)
		{
			bool isOK = false;
			const int len = 17;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards;
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
			isOK = _ddzCardLogic->FindThree(cards, len, outCards);
			Assert::IsTrue(isOK);
		}

		TEST_METHOD(TestFindThreeSingle)
		{
			bool isOK = false;
			const int len = 17;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards;
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
			isOK = _ddzCardLogic->FindThreeSingle(cards, len, false, outCards);
			Assert::IsTrue(isOK);
		}

		TEST_METHOD(TestFindPlanePair)
		{
			bool isOK = false;
			const int len = 17;
			int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
				card11, card12, card13, card14, card15, card16, card17;
			int *cards;
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
			isOK = _ddzCardLogic->FindPlanePair(cards, len, outCards);
			Assert::IsTrue(isOK);
		}

	};
}
