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
	class CardIntelligentLogic : DouDiZhuPlayCardLogic
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
			（1)双龙
			（2）单龙
			（3）4个
			（4）3个
			（5）双王
			（5）2个
			（6）1个
		二、别人出的牌，找自己能管上的牌

		*/

	private:
		struct Info
		{
			CardType _cardType;///类类型
			int _adjacentCount;///连续牌个数
			int _mainCardSum;///主牌型数量
			vector<CardNumber> _mainCardNums;///主牌型牌面值集合
			int _subsidiaryCount;///附属牌数量
			int _subsidiarySum;///附属牌个数
			vector<CardNumber> _subsidiaryCardNums;///附属牌牌面值集合
		};

		bool LoopSplit(const int *cards, const int len, vector<vector<int>> &outCards);

	};
}