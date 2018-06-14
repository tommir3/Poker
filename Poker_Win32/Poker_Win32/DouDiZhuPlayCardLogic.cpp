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
		bool isOK = false;
		const int pokerLen = 14;
		int cardArray[pokerLen] = { 0 };
		isOK = CardValueToArray(cards, len, cardArray);
		if (isOK)
		{
			vector<CardNumberSum> cnsArr;
			isOK = CardArrayToCardNumberSum(cardArray, cnsArr);
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
		bool isOK = false;
		const int pokerLen = 14;
		int cardArray[pokerLen] = { 0 };
		isOK = CardValueToArray(cards, len, cardArray);
		if (isOK)
		{
			vector<CardNumberSum> cnsArr;
			isOK = CardArrayToCardNumberSum(cardArray, cnsArr);
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

	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindThree(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		bool isOK = false;
		const int pokerLen = 14;
		int cardArray[pokerLen] = { 0 };
		isOK = CardValueToArray(cards, len, cardArray);
		if (isOK)
		{
			vector<CardNumberSum> cnsArr;
			isOK = CardArrayToCardNumberSum(cardArray, cnsArr);
			if (isOK)
			{
				vector<vector<CardNumber>> findVec;
				bool isSame = FindCardNumber(cnsArr, 0, 3, false, findVec);
				bool isSplit = FindCardNumber(cnsArr, 0, 3, true, findVec);
				if (isSame || isSplit)
				{
					result = FineCardValue(cards, len, findVec, 3, outCards);
				}
			}
		}

	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindThreeSingle(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{

	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

/*============================ 找牌 end ================================*/


/*============================ 私有方法 ================================*/
bool DouDiZhu::DouDiZhuPlayCardLogic::CardsToWeightArray(const int *cards, const int cardsLen, int outCards[])
{
	bool result = false;
	try
	{
		if (NULL != cards && cardsLen > 0)
		{
			CardNumber cardNum;
			int idxCard;
			for (int i = 0; i < cardsLen; ++i)
			{
				result = PokerLogic::ValueToCardNumber(cards[i], cardNum);
				if (result)
				{
					idxCard = (int)cardNum;
					if (idxCard < 13)
					{
						outCards[idxCard]++;
					}
					else if (idxCard == CardNumber::C_BJ || idxCard == CardNumber::C_RJ)
					{
						outCards[13]++;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}





/*以下方法放弃使用*/
bool DouDiZhu::DouDiZhuPlayCardLogic::CardValueToArray(const int *cards, const int cardsLen, int outCards[])
{
	bool result = false;
	try
	{
		if (NULL != cards && cardsLen > 0)
		{
			CardNumber cardNum;
			int idxCard;
			for (int i = 0; i < cardsLen; ++i)
			{
				result = PokerLogic::ValueToCardNumber(cards[i], cardNum);
				if (result)
				{
					idxCard = (int)cardNum;
					if (idxCard < 13)
					{
						outCards[idxCard]++;
					}
					else if (idxCard == CardNumber::C_BJ || idxCard == CardNumber::C_RJ)
					{
						outCards[13]++;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::CardArrayToCardNumberSum(const int cardArray[], std::vector<CardNumberSum> &cnsArr)
{
	bool result = false;
	try
	{
		if (NULL != cardArray)
		{
			CardNumberSum cns;
			for (int i = 2; i < 13; ++i)
			{
				if (cardArray[i] > 0)
				{
					cns.num = (CardNumber)i;
					cns.count = cardArray[i];
					cnsArr.push_back(cns);
					result = true;
				}
			}
			if (cardArray[0] > 0)
			{
				cns.num = CardNumber::C_A;
				cns.count = cardArray[0];
				cnsArr.push_back(cns);
				result = true;
			}
			if (cardArray[1] > 0)
			{
				cns.num = CardNumber::C_2;
				cns.count = cardArray[1];
				cnsArr.push_back(cns);
				result = true;
			}
			if (cardArray[13] > 0)
			{
				cns.num = CardNumber::C_RJ;
				cns.count = cardArray[13];
				cnsArr.push_back(cns);
				result = true;
			}
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FineCardValue(const int *cards, const int len, const vector<vector<CardNumber>> const findCards, const int findCardCount, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		if (!findCards.empty() && len > 0)
		{
			vector<int> arr;
			bool isOK = false;
			for (int i = 0; i < findCards.size(); ++i)
			{
				arr.clear();
				isOK = FineCardValue(cards, len, findCards[i], findCardCount, arr);
				if (isOK)
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FineCardValue(const int *cards, const int len, const vector<CardNumber> const findCards, const int findCardCount, vector<int> &outCards)
{
	bool result = false;
	try
	{
		CardNumber cardNum, curNum;
		bool isOK = false;
		int findCount = 0;
		for (int i = 0; i < findCards.size(); ++i)
		{
			curNum = findCards[i];
			for (int j = 0; j < len; ++j)
			{
				isOK = PokerLogic::ValueToCardNumber(cards[j], cardNum);
				if (isOK && cardNum == curNum)
				{
					outCards.push_back(cards[j]);
					findCount++;
					if (findCount == findCardCount)
					{
						result = true;
						break;
					}
				}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindCardValue(const int *cards, 
													const int len, 
													const vector<vector<CardNumber>> const findCards, 
													const int findCardCount,
													const vector<vector<CardNumber>> const subsidiaryCards,
													const int subsidiaryCardCount,
													vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		if (!findCards.empty() && !subsidiaryCards.empty() && len > 0)
		{
			for (int i = 0; i < findCards.size(); ++i)
			{
				FindCardValue(cards, len, findCards[i], findCardCount, subsidiaryCards, subsidiaryCardCount, outCards);
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindCardValue(const int *cards,
													const int len,
													const vector<CardNumber> const findCards,
													const int findCardCount,
													const vector<vector<CardNumber>> const subsidiaryCards,
													const int subsidiaryCardCount,
													vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		if (!findCards.empty() && !subsidiaryCards.empty() && len > 0)
		{
			bool isOK = false;
			for (int i = 0; i < subsidiaryCards.size(); ++i)
			{
				for (int j = 0; j < subsidiaryCards[i].size(); ++j)
				{
					CardNumber rootCard = subsidiaryCards[i][j];
					for (int m = 0; m < findCards.size(); ++m)
					{

					}
				}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

//cardArr:长度14的数组，索引为牌枚举值，值为牌的数量
bool DouDiZhu::DouDiZhuPlayCardLogic::IsSubsidiaryCard(const int cardArr[], const vector<CardNumber> const findCards,
														const int findCardCount, const vector<CardNumber> const subsidiaryCards, 
														const int subsidiaryCardCount)
{
	bool result = false;
	try
	{
		if (!findCards.empty() && !subsidiaryCards.empty())
		{
			for (int i = 0; i < subsidiaryCards.size(); ++i)
			{
				CardNumber subsidiaryCard = subsidiaryCards[i];
				for (int j = 0; j < findCards.size(); ++j)
				{
					if (subsidiaryCard == findCards[j])
					{
						if (findCardCount + subsidiaryCardCount > 4)
						{
							result = false;
							return false;
						}
					}
				}
			}
			result = true;
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

