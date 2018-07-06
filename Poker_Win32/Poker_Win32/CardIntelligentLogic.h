#pragma once
#include "PokerDefine.h" 
#include "PokerLogic.h"
#include <vector>
#include <exception>

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class CardIntelligentLogic : PokerLogic
	{
	public:
		__declspec(dllexport) CardIntelligentLogic();
		__declspec(dllexport) ~CardIntelligentLogic();

		bool _isDeskRecord = false;//�Ƿ��¼�Ѿ��������ƣ�����¼��ǰ����������ƣ�

		bool GetSendCards(const int *cards, const int len, 
							const int *cmpCards,
							const int cmpLen,
							const CardType cardType,
							vector<vector<int>> &outCards);

	private:

	};
}