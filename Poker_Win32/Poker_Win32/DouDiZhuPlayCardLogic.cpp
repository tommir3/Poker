#include "DouDiZhuPlayCardLogic.h"



DouDiZhu::DouDiZhuPlayCardLogic::DouDiZhuPlayCardLogic()
{
}


DouDiZhu::DouDiZhuPlayCardLogic::~DouDiZhuPlayCardLogic()
{

}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindSingle(const int *cards, int *outCard)
{
	bool result = false;
	try
	{
		CardsToCardNumberSum();
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindCardNumber(const CardNumberSum *cnsArr, const int cnsLen, const int adjacentCount, const int sameCount, vector<vector<CardNumber>> &outCardNumVec)
{
	bool result = false;
	try
	{
		bool isAdjacent = (adjacentCount > 0);
		vector<CardNumber> cardArr;
		for (int i = 0; i < cnsLen; ++i)
		{
			cardArr.clear();
			if (isAdjacent)//Á¬ÐøµÄÅÆ
			{
				if (cnsArr[i].count >= sameCount && i + 1 < adjacentCount && i + adjacentCount < cnsLen)
				{
					int cmpNum = PokerLogic::CardNumberToWeightValue(cnsArr[i].num);
					for (int j = i + 1; j < adjacentCount; ++j)
					{
						int curNum = PokerLogic::CardNumberToWeightValue(cnsArr[j].num);
						if (curNum == cmpNum + 1 && cnsArr[j].count >= sameCount && cnsArr[j].num != CardNumber::C_2)
						{
							cmpNum = curNum;
							cardArr.push_back(cnsArr[j].num);
						}
						else
						{
							cardArr.clear();
							break;
						}
					}
				}
			}
			else
			{
				if (cnsArr[i].count >= sameCount)
				{
					cardArr.push_back(cnsArr[i].num);
				}
			}
			if (!cardArr.empty)
			{
				outCardNumVec.push_back(cardArr);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}
