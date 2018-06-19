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
		int AdjacentCount = 0;	//主牌型连续牌数量
		int MainCardSum = 1;	//主牌型数量
		int SubsidiaryCount = 0;	//附属牌型个数
		int SubsidiarySum = 0;		//附属牌型数量
		result = FindCards(cards, len, false, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
		if (!result)
		{
			result = FindCards(cards, len, true, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
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
		int AdjacentCount = 0;	//主牌型连续牌数量
		int MainCardSum = 2;	//主牌型数量
		int SubsidiaryCount = 0;	//附属牌型个数
		int SubsidiarySum = 0;		//附属牌型数量
		result = FindCards(cards, len, false, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
		if (!result)
		{
			result = FindCards(cards, len, true, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
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
		int AdjacentCount = 0;	//主牌型连续牌数量
		int MainCardSum = 3;	//主牌型数量
		int SubsidiaryCount = 0;	//附属牌型个数
		int SubsidiarySum = 0;		//附属牌型数量
		result = FindCards(cards, len, false, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
		if (!result)
		{
			result = FindCards(cards, len, true, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindThreeSingle(const int *cards, const int len, const bool isSplit, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 0;	//主牌型连续牌数量
		int MainCardSum = 3;	//主牌型数量
		int SubsidiaryCount = 1;	//附属牌型个数
		int SubsidiarySum = 1;		//附属牌型数量
		result = FindCards(cards, len, false, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
		if (!result)
		{
			result = FindCards(cards, len, true, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindPlanePair(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 2;	//主牌型连续牌数量
		int MainCardSum = 3;	//主牌型数量
		int SubsidiaryCount = 2;	//附属牌型个数
		int SubsidiarySum = 2;		//附属牌型数量
		result = FindCards(cards, len, false, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
		if (!result)
		{
			result = FindCards(cards, len, true, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindCards(const int *cards, const int len, const bool isMainSplit, const int adjacentCount, const int mainCardSum, const int subsidiaryCount, const int subsidiarySum, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		bool isOK = false;
		int sortArr[CardSortCount] = { 0 };
		isOK = CardsToSortArray(cards, len, sortArr, CardSortCount);
		if (isOK)
		{
			if (adjacentCount > 0)//主牌型为连续牌
			{
				vector<vector<int>> mainCardsList;
				isOK = FindMainCards(sortArr, CardSortCount, adjacentCount, mainCardSum, isMainSplit, mainCardsList);
				if (isOK)
				{
					for (int i = 0; i < mainCardsList.size(); ++i)
					{
						vector<int> mainCards = mainCardsList[i];
						vector<vector<int>> cardsList;
						isOK = FindAdjacentIndexCards(sortArr, CardSortCount, mainCards, subsidiaryCount, subsidiarySum, false, cardsList);
						if (isOK)//不拆牌的找附属牌
						{
							result = SortArrayCardsToCards(cardsList, cards, len, outCards);
						}
						else//拆牌的找附属牌
						{
							isOK = FindAdjacentIndexCards(sortArr, CardSortCount, mainCards, subsidiaryCount, subsidiarySum, true, cardsList);
							if (isOK)
							{
								result = SortArrayCardsToCards(cardsList, cards, len, outCards);
							}
						}
					}
				}
			}
			else//主牌型为相同的牌
			{
				int mainCards[CardSortCount] = { 0 };
				isOK = FindMainCards(sortArr, CardSortCount, mainCardSum, isMainSplit, mainCards);
				if (isOK)
				{
					vector<vector<int>> cardsList;
					for (int i = 0; i < CardSortCount; ++i)
					{
						if (mainCards[i] == mainCardSum)
						{
							cardsList.clear();
							isOK = FindSameIndexCards(sortArr, CardSortCount, i, mainCardSum, subsidiaryCount, subsidiarySum, false, cardsList);
							if (isOK)//不拆牌的找附属牌
							{
								result = SortArrayCardsToCards(cardsList, cards, len, outCards);
							}
							else//拆牌的找附属牌
							{
								isOK = FindSameIndexCards(sortArr, CardSortCount, i, mainCardSum, subsidiaryCount, subsidiarySum, true, cardsList);
								if (isOK)
								{
									result = SortArrayCardsToCards(cardsList, cards, len, outCards);
								}
							}
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

int DouDiZhu::DouDiZhuPlayCardLogic::SortStyleValueToCardNumber(const int value)
{
	int result = -1;
	try
	{
		for (int i = 0; i < CardSortCount; ++i)
		{
			if (SortStyle[i] == value)
			{
				result = i;
				break;
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

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

bool DouDiZhu::DouDiZhuPlayCardLogic::SortArrayCardsToCards(const vector<vector<int>> const sortCardsList, const int *cards, const int len, vector<vector<int>> &outCardsList)
{
	bool result = false;
	try
	{
		vector<int> findCards;
		for (int i = 0; i < sortCardsList.size(); ++i)
		{
			findCards.clear();
			result = SortArrayCardsToCards(sortCardsList[i], cards, len, findCards);
			if (result)
			{
				outCardsList.push_back(findCards);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::SortArrayCardsToCards(vector<int> sortCards, const int *cards, const int len, vector<int> &outCards)
{
	bool result = false;
	try
	{
		if (!sortCards.empty())
		{
			CardNumber cmpCard, curCard;
			bool isOK;
			int num;
			for (int i = 0; i < sortCards.size(); ++i)
			{
				num = SortStyleValueToCardNumber(sortCards[i]);
				if (num >= 0)
				{
					cmpCard = (CardNumber)num;
					for (int j = 0; j < len; ++j)
					{
						curCard;
						isOK = PokerLogic::ValueToCardNumber(cards[j], curCard);
						if (isOK)
						{
							if (curCard == cmpCard)
							{
								if (!outCards.empty())
								{
									for (int k = 0; k < outCards.size(); ++k)
									{
										if (outCards[k] == cards[j])
										{
											isOK = false;
											break;
										}
									}
								}
								if (isOK)
								{
									outCards.push_back(cards[j]);
									result = true;
									break;
								}
							}
						}
					}
				}
				else 
				{
					result = false;
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindMainCards(const int *sortArray, const int sortArrLen, const int adjacentCount, const int sameCount, const bool isSplit, vector<vector<int>> &outSortArrVec)
{
	bool result = false;
	try
	{
		outSortArrVec.clear();
		bool isAccord = false,isFindAdjacent = false;//isAccord 是否是符合的牌 拆牌
		vector<int> tmpSortArr(CardSortCount);
		for (int i = 0; i < sortArrLen; ++i)
		{
			isAccord = (isSplit) ? sortArray[i] > sameCount : sortArray[i] == sameCount;
			if (isAccord && i + adjacentCount < sortArrLen)
			{
				tmpSortArr[i] = sameCount;
				isFindAdjacent = true;
				for (int j = i + 1; j < i + adjacentCount; ++j)
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindAdjacentIndexCards(const int *sortArray, const int sortArrLen, const vector<int> mainCards, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outCards)
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
				if (mainCards[i] > 0 && cloneSortArr[i] > mainCards[i])
				{
					cloneSortArr[i] -= mainCards[i];
				}
			}
			vector<int> okCards;
			if (subsidiaryCount > 0)
			{
				bool isFindSubsidiary = false;
				bool isAccord = false;//是否是符合的牌 用于拆牌
				vector<int> subsidiaryCards;
				vector<vector<int>> hashVec;
				for (int i = 0; i < CardSortCount; ++i)
				{
					okCards.clear();
					subsidiaryCards.clear();
					isFindSubsidiary = FindSubsidiaryCards(cloneSortArr, CardSortCount, i, subsidiaryCount, subsidiarySameCount, isSplit, subsidiaryCards);
					if (isFindSubsidiary)
					{
						//判断附属牌是否已经存在，不存在保存
						bool isSame = IsSmae(hashVec, subsidiaryCards);
						if (!isSame)
						{
							hashVec.push_back(subsidiaryCards);
							for (int x = 0; x < mainCards.size(); ++x)
							{
								if (mainCards[x] > 0)
								{
									for (int y = 0; y < mainCards[x]; ++y)
									{
										okCards.push_back(x);
									}
								}
							}
							for (int x = 0; x < subsidiaryCount; ++x)
							{
								for (int y = 0; y < subsidiarySameCount; ++y)
								{
									okCards.push_back(subsidiaryCards[x]);
								}
							}
							outCards.push_back(okCards);
							result = true;
						}
					}
				}
			}
			else
			{
				for (int x = 0; x < mainCards.size(); ++x)
				{
					if (mainCards[x] > 0)
					{
						for (int y = 0; y < mainCards[x]; ++y)
						{
							okCards.push_back(x);
						}
					}
				}
				if (!okCards.empty())
				{
					outCards.push_back(okCards);
					result = true;
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindSameIndexCards(const int *sortArray, const int sortArrLen, const int cardIndex, const int cardCount, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outCards)
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
			if (cloneSortArr[cardIndex] >= cardCount)
			{
				cloneSortArr[cardIndex] -= cardCount;
				vector<int> okCards;
				if (subsidiaryCount > 0)
				{
					bool isAccord = false;//是否是符合的牌 用于拆牌
					bool isFindSubsidiary = false;
					int subsidiaryIdx;
					vector<int> subsidiaryCards;
					vector<vector<int>> hashVec;
					for (int i = 0; i < CardSortCount; ++i)
					{
						okCards.clear();
						subsidiaryCards.clear();
						isFindSubsidiary = FindSubsidiaryCards(cloneSortArr, CardSortCount, i, subsidiaryCount, subsidiarySameCount, isSplit, subsidiaryCards);
						if (isFindSubsidiary)
						{
							//判断附属牌是否已经存在，不存在保存
							bool isSame = IsSmae(hashVec, subsidiaryCards);
							if (!isSame)
							{
								hashVec.push_back(subsidiaryCards);
								for (int x = 0; x < cardCount; ++x)
								{
									okCards.push_back(cardIndex);
								}
								for (int x = 0; x < subsidiaryCount; ++x)
								{
									for (int y = 0; y < subsidiarySameCount; ++y)
									{
										okCards.push_back(subsidiaryCards[x]);
									}
								}
								outCards.push_back(okCards);
								result = true;
							}
						}
					}
				}
				else
				{
					for (int x = 0; x < cardCount; ++x)
					{
						okCards.push_back(cardIndex);
					}
					if (!okCards.empty())
					{
						outCards.push_back(okCards);
						result = true;
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

