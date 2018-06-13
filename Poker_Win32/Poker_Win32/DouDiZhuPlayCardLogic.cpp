#include "DouDiZhuPlayCardLogic.h"

using namespace std;

DouDiZhu::DouDiZhuPlayCardLogic::DouDiZhuPlayCardLogic() : PokerLogic(14, 15, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 82, 83)
{
}


DouDiZhu::DouDiZhuPlayCardLogic::~DouDiZhuPlayCardLogic()
{

}


/*============================ 找牌 begin ================================*/

bool DouDiZhu::DouDiZhuPlayCardLogic::FindSingle(const int *cards, const int len, std::vector<std::vector<int>> &outCards)
{
	bool result = false;
	try
	{
		vector<CardNumberSum> cnsArr;
		bool isOK = CardsToCardNumberSum(cards, len, cnsArr);
		if (isOK)
		{
			vector<vector<CardNumber>> findVec;
			bool isSame = FindCardNumber(cnsArr, 0, 1, false, findVec);
			bool isSplit = FindCardNumber(cnsArr, 0, 1, true, findVec);
			if (isSame || isSplit)
			{
				result = FineCardValue(cards, len, findVec, 1, outCards);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindPair(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		vector<CardNumberSum> cnsArr;
		bool isOK = CardsToCardNumberSum(cards, len, cnsArr);
		if (isOK)
		{
			vector<vector<CardNumber>> findVec;
			bool isSame = FindCardNumber(cnsArr, 0, 2, false, findVec);
			bool isSplit = FindCardNumber(cnsArr, 0, 2, true, findVec);
			if (isSame || isSplit)
			{
				result = FineCardValue(cards, len, findVec, 2, outCards);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

/*============================ 找牌 end ================================*/

bool DouDiZhu::DouDiZhuPlayCardLogic::CardsToCardNumberSum(const int *cards, const int cardsLen, std::vector<CardNumberSum> &cnsArr)
{
	bool result = false;
	try
	{
		if (NULL != cards && cardsLen > 0)
		{
			const int pokerLen = 14;
			int cardNums[pokerLen] = {0};
			CardNumber cardNum;
			bool isOK = false;
			for (int i = 0; i < cardsLen; ++i)
			{
				isOK = PokerLogic::ValueToCardNumber(cards[i], cardNum);
				if (isOK)
				{
					int idxCard = (int)cardNum;
					if (idxCard < 13)
					{
						cardNums[idxCard]++;
					}
					else if(idxCard == CardNumber::C_BJ || idxCard == CardNumber::C_RJ)
					{
						cardNums[13]++;
					}
				}
			}
			int idx = 0;
			isOK = false;
			CardNumberSum cns;
			for (int i = 2; i < 13; ++i)
			{
				if (cardNums[i] > 0)
				{
					cns.num = (CardNumber)i;
					cns.count = cardNums[i];
					cnsArr.push_back(cns);
					isOK = true;
				}
			}
			if (cardNums[0] > 0)
			{
				cns.num = CardNumber::C_A;
				cns.count = cardNums[0];
				cnsArr.push_back(cns);
				isOK = true;
			}
			if (cardNums[1] > 0)
			{
				cns.num = CardNumber::C_2;
				cns.count = cardNums[1];
				cnsArr.push_back(cns);
				isOK = true;
			}
			if (cardNums[13] > 0)
			{
				cns.num = CardNumber::C_RJ;
				cns.count = cardNums[13];
				cnsArr.push_back(cns);
				isOK = true;
			}
			result = isOK;
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindCardNumber(const std::vector<CardNumberSum> cnsVec, const int adjacentCount, const int sameCount, const bool isSplit, std::vector<std::vector<CardNumber>> &outCardNumVec)
{
	bool result = false;
	try
	{
		bool isAdjacent = (adjacentCount > 0);
		bool isAccord = false;//是否是符合的牌
		vector<CardNumber> cardArr;
		int cnsLen = cnsVec.size();
		for (int i = 0; i < cnsLen; ++i)
		{
			cardArr.clear();
			if (isAdjacent)//连续的牌
			{
				isAccord = (isSplit) ? cnsVec[i].count > sameCount : cnsVec[i].count == sameCount;
				if (isAccord && i + 1 < adjacentCount && i + adjacentCount < cnsLen)
				{
					int cmpNum = PokerLogic::CardNumberToWeightValue(cnsVec[i].num);
					for (int j = i + 1; j < adjacentCount; ++j)
					{
						isAccord = (isSplit) ? cnsVec[j].count > sameCount : cnsVec[j].count == sameCount;
						int curNum = PokerLogic::CardNumberToWeightValue(cnsVec[j].num);
						if (curNum == cmpNum + 1 && isAccord && cnsVec[j].num != CardNumber::C_2)
						{
							cmpNum = curNum;
							cardArr.push_back(cnsVec[j].num);
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
				isAccord = (isSplit) ? cnsVec[i].count > sameCount : cnsVec[i].count == sameCount;
				if (isAccord)
				{
					cardArr.push_back(cnsVec[i].num);
				}
			}
			if (!cardArr.empty())
			{
				result = true;
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FineCardValue(const int *cards, const int len, const vector<vector<CardNumber>> const findCards, const int count, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		if (!findCards.empty())
		{
			vector<int> arr;
			int findCount;
			CardNumber cardNum, curNum;
			bool isOK;
			for (int i = 0; i < findCards.size(); ++i)
			{
				arr.clear();
				findCount = 0;
				for (int j = 0; j < findCards[i].size(); ++j)
				{
					curNum = findCards[i][j];
					for (int m = 0; m < len; ++m)
					{
						isOK = PokerLogic::ValueToCardNumber(cards[m], cardNum);
						if (isOK && cardNum == curNum)
						{
							arr.push_back(cards[m]);
							findCount++;
							if (findCount == count)
							{
								break;
							}
						}
					}
				}
				if (!arr.empty())
				{
					outCards.push_back(arr);
				}
			}
			result = !outCards.empty();
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}
