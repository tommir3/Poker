#include "stdafx.h"
#include "CppUnitTest.h"
#include "D:\learning\C++\Poker_Win32\Poker_Win32\PokerLogic.h"


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
			Assert::AreEqual<bool>(true, isOK);
			Assert::AreEqual<int>(mark, CardMark::Joker);
			Assert::AreEqual<int>(num, CardNumber::C_RJ);
			isOK = _poker->ValueToCard(33, mark, num);
			Assert::AreEqual<bool>(true, isOK);
			Assert::AreEqual<int>(mark, CardMark::Diamond);
			Assert::AreEqual<int>(num, CardNumber::C_K);
			isOK = _poker->ValueToCard(73, mark, num);
			Assert::AreEqual<bool>(true, isOK);
			Assert::AreEqual<int>(mark, CardMark::Club);
			Assert::AreEqual<int>(num, CardNumber::C_K);
			isOK = _poker->ValueToCard(70, mark, num);
			Assert::AreEqual<bool>(true, isOK);
			Assert::AreEqual<int>(mark, CardMark::Club);
			Assert::AreEqual<int>(num, CardNumber::C_10);
		}

	};
}