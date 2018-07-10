#pragma once
#include "PokerDefine.h" 
#include "PokerLogic.h"
#include "DouDiZhuPlayCardLogic.h"
#include <vector>
#include <exception>

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class CardIntelligentLogic : PokerLogic, DouDiZhuPlayCardLogic
	{
	public:
		__declspec(dllexport) CardIntelligentLogic();
		__declspec(dllexport) ~CardIntelligentLogic();

		bool GetSendCards(const int *cards, const int len, 
							const int *cmpCards,
							const int cmpLen,
							const CardType cardType,
							const int *deskCards,
							const int deskCardLen,
							const bool pos1_isFriend,
							const int pos1_CardCount,
							const bool pos2_isFriend,
							const int pos2_CardCount,
							vector<vector<int>> &outCards);
		/*
		一、自己牌最大，找优先出的牌
			1、循环拆分，取切分数量最少的
			（1)
		二、别人出的牌，找自己能管上的牌

		*/

	private:

	};
}