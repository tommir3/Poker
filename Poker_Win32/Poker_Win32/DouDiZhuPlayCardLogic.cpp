#include "DouDiZhuPlayCardLogic.h"

using namespace std;

DouDiZhu::DouDiZhuPlayCardLogic::DouDiZhuPlayCardLogic() : PokerLogic(Poker_Weight[0], Poker_Weight[1], Poker_Weight[2], Poker_Weight[3], Poker_Weight[4],
																		Poker_Weight[5], Poker_Weight[6], Poker_Weight[7], Poker_Weight[8], Poker_Weight[9],
																		Poker_Weight[10], Poker_Weight[11], Poker_Weight[12], Poker_Weight[13], Poker_Weight[14])
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
		bool isOK = false;
		int sortArr[CardSortCount] = {0};
		isOK = CardsToSortArray(cards, len, sortArr, CardSortCount);
		if (isOK)
		{
			int root[CardSortCount] = {0};
			isOK = FindMainCards(sortArr, CardSortCount, 3, false, root);
			if (isOK)
			{
				for (int i = 0; i < CardSortCount; ++i)
				{
					if (root[i] == 3)
					{
						vector<vector<int>> cardsList;
						isOK = FindCards(sortArr, CardSortCount, (CardNumber)i, 3, 1, 1, false, cardsList);
						if (isOK)
						{
							int a = 5;
						}
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

/*============================ 找牌 end ================================*/


/*============================ 私有方法 ================================*/
bool DouDiZhu::DouDiZhuPlayCardLogic::CardsToSortArray(const int *cards, const int cardsLen, int *sortArray, const int sortArrLen)
{
	bool result = false;
	try
	{
		if (NULL != cards && cardsLen > 0 && sortArray != NULL && sortArrLen == CardSortCount)
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
						sortArray[SortStyle[idxCard]]++;
					}
					else if (idxCard == CardNumber::C_BJ || idxCard == CardNumber::C_RJ)
					{
						sortArray[SortStyle[13]]++;
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindMainCards(const int *sortArray, const int sortArrLen, const int adjacentCount, const int sameCount, const bool isSplit, vector<int*> &outSortArrVec)
{
	bool result = false;
	try
	{
		outSortArrVec.clear();
		bool isAccord = false,isFindAdjacent = false;//isAccord 是否是符合的牌 拆牌
		int tmpSortArr[CardSortCount];
		for (int i = 0; i < sortArrLen; ++i)
		{
			tmpSortArr[CardSortCount] = { 0 };
			isAccord = (isSplit) ? sortArray[i] > sameCount : sortArray[i] == sameCount;
			if (isAccord && i + 1 < adjacentCount && i + adjacentCount < sortArrLen)
			{
				tmpSortArr[i]++;
				isFindAdjacent = true;
				for (int j = i + 1; j < adjacentCount; ++j)
				{
					isAccord = (isSplit) ? sortArray[j] > sameCount : sortArray[j] == sameCount;
					if (isAccord && (CardNumber)j != CardNumber::C_2)
					{
						tmpSortArr[j] = sameCount;
					}
					else
					{
						isFindAdjacent = false;
						break;
					}
				}
				if (isFindAdjacent)
				{
					//找到
					outSortArrVec.push_back(tmpSortArr);
				}
			}
		}
		result = !outSortArrVec.empty();
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindMainCards(const int *sortArray, const int sortArrLen, const int sameCount, const bool isSplit, int* outSortArrVec)
{
	bool result = false;
	try
	{
		bool isAccord = false;//是否是符合的牌 用于拆牌
		outSortArrVec[CardSortCount] = { 0 };
		for (int i = 0; i < sortArrLen; ++i)
		{
			isAccord = (isSplit) ? sortArray[i] > sameCount : sortArray[i] == sameCount;
			if (isAccord)
			{
				outSortArrVec[i] = sameCount;
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindSubsidiaryCards(const int *sortNoMainArray, const int sortArrLen, const int sortArrIndex, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<int> &outSubsidiaryVec)
{
	bool result = false;
	try
	{
		if (CardSortCount == sortArrLen)
		{
			bool isAccord = false;//是否是符合的牌 用于拆牌
			int subsidiaryIdx = 0;
			for (int i = sortArrIndex; i < sortArrLen; ++i)
			{
				isAccord = (isSplit) ? sortNoMainArray[i] > subsidiarySameCount : sortNoMainArray[i] == subsidiarySameCount;
				if (isAccord)
				{
					outSubsidiaryVec.push_back(i);
					if (outSubsidiaryVec.size() == subsidiaryCount)
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindCards(const int *sortArray, const int sortArrLen, const vector<CardNumber> cardNums, const int cardCount, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		if (CardSortCount == sortArrLen)
		{
			int cloneSortArr[CardSortCount] = { 0 };
			for (int i = 0; i < sortArrLen; ++i)
			{
				cloneSortArr[i] = sortArray[i];
			}
			bool isPopMainCard = true;
			for (int i = 0; i < cardNums.size(); ++i)
			{
				if (cloneSortArr[SortStyle[(int)cardNums[i]]] >= cardCount)
				{
					cloneSortArr[SortStyle[(int)cardNums[i]]] -= cardCount;
				}
				else
				{
					isPopMainCard = false;
					break;
				}
			}
			if (isPopMainCard)
			{
				bool isAccord = false;//是否是符合的牌 用于拆牌
				bool isFindSubsidiary = false;
				vector<int> okCards, subsidiaryCards;
				for (int i = 0; i < CardSortCount; ++i)
				{
					okCards.clear();
					subsidiaryCards.clear();
					isFindSubsidiary = FindSubsidiaryCards(cloneSortArr, CardSortCount, i, subsidiaryCount, subsidiarySameCount, isSplit, subsidiaryCards);
					if (isFindSubsidiary)
					{
						//todo:
						//判断附属牌是否已经存在，不存在保存
						for (int x = 0; x < cardNums.size(); ++x)
						{
							for (int y = 0; y < cardCount; ++y)
							{
								okCards.push_back(cardNums[x]);
							}
						}
						for (int x = 0; x < subsidiaryCount; ++x)
						{
							okCards.push_back(subsidiaryCards[x]);
						}
						outCards.push_back(okCards);
					}
				}
				result = !outCards.empty();
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindCards(const int *sortArray, const int sortArrLen, const CardNumber cardNum, const int cardCount, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		if (CardSortCount == sortArrLen)
		{
			int cloneSortArr[CardSortCount] = { 0 };
			for (int i = 0; i < sortArrLen; ++i)
			{
				cloneSortArr[i] = sortArray[i];
			}
			if (cloneSortArr[(int)cardNum] >= cardCount)
			{
				cloneSortArr[(int)cardNum] -= cardCount;
				bool isAccord = false;//是否是符合的牌 用于拆牌
				bool isFindSubsidiary = false;
				int subsidiaryIdx;
				vector<int> okCards, subsidiaryCards;
				vector<vector<int>> hashVec;
				for (int i = 0; i < CardSortCount; ++i)
				{
					okCards.clear();
					subsidiaryCards.clear();
					isFindSubsidiary = FindSubsidiaryCards(cloneSortArr, CardSortCount, i, subsidiaryCount, subsidiarySameCount, isSplit, subsidiaryCards);
					if (isFindSubsidiary)
					{
						//todo:
						//判断附属牌是否已经存在，不存在保存
						bool isSame = IsSmae(hashVec, subsidiaryCards);
						if (!isSame)
						{
							hashVec.push_back(subsidiaryCards);
							for (int x = 0; x < cardCount; ++x)
							{
								okCards.push_back(cardNum);
							}
							for (int x = 0; x < subsidiaryCount; ++x)
							{
								okCards.push_back(subsidiaryCards[x]);
							}
							outCards.push_back(okCards);
						}
					}
				}
				result = !outCards.empty();
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::IsSmae(const vector<vector<int>> const hashVec, const vector<int> const subsidiaryCards)
{
	bool result = false;
	try
	{
		if (!subsidiaryCards.empty())
		{
			for (int i = 0; i < hashVec.size(); ++i)
			{
				result = false;
				if (hashVec[i].size() == subsidiaryCards.size())
				{
					for (int j = 0; j < subsidiaryCards.size(); ++j)
					{
						if (hashVec[i][j] == subsidiaryCards[j])
						{
							result = true;
						}
						else
						{
							result = false;
							break;
						}
					}
				}
				if (result)
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

