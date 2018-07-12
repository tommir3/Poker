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
		һ���Լ�����������ȳ�����
			1��ѭ����֣�ȡ�з��������ٵ�
			��1)˫��
			��2������
			��3��4��
			��4��3��
			��5��˫��
			��5��2��
			��6��1��
		�������˳����ƣ����Լ��ܹ��ϵ���

		*/

	private:
		struct Info
		{
			CardType _cardType;///������
			int _adjacentCount;///�����Ƹ���
			int _mainCardSum;///����������
			vector<CardNumber> _mainCardNums;///����������ֵ����
			int _subsidiaryCount;///����������
			int _subsidiarySum;///�����Ƹ���
			vector<CardNumber> _subsidiaryCardNums;///����������ֵ����
		};

		bool LoopSplit(const int *cards, const int len, vector<vector<int>> &outCards);

	};
}