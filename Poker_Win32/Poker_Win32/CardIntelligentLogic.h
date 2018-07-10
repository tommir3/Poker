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
		һ���Լ�����������ȳ�����
			1��ѭ����֣�ȡ�з��������ٵ�
			��1)
		�������˳����ƣ����Լ��ܹ��ϵ���

		*/

	private:

	};
}