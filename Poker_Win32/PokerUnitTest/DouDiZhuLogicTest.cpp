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

		TEST_METHOD(Test)
		{
			// TODO: 在此输入测试代码
			_ddz->Test();
		}

	};
}