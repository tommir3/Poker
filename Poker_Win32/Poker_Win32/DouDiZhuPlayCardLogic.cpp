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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindGreaterThanCards(const int *cards,
															const int len,
															const int *cmpCards,
															const int cmpLen,
															const CardType cardType,
															vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		result = FindTargetCards(cards, len, cmpCards, cmpLen, cardType, outCards);
		if (cardType != CardType::KingBomb)
		{
			if (cardType != CardType::Four)
			{
				FindTargetCards(cards, len, CardType::Four, outCards);
			}
			FindKingBomb(cards, len, outCards);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindTargetCards(const int *cards, const int len, const CardType cardType, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		//主牌型连续牌数量,主牌型数量,附属牌型个数,附属牌型数量
		int AdjacentCount = 0, MainCardSum = 0, SubsidiaryCount = 0, SubsidiarySum = 0;	
		switch (cardType)
		{
		case CardType::Normal:
			MainCardSum = 1;		//主牌型数量
			break;
		case CardType::Single:
			MainCardSum = 1;		//主牌型数量
			break;
		case CardType::Pair:
			MainCardSum = 2;		//主牌型数量
			break;
		case CardType::Three:
			MainCardSum = 3;		//主牌型数量
			break;
		case CardType::ThreeSingle:
			MainCardSum = 3;		//主牌型数量
			SubsidiaryCount = 1;	//附属牌型个数
			SubsidiarySum = 1;		//附属牌型数量
			break;
		case CardType::ThreePair:
			MainCardSum = 3;		//主牌型数量
			SubsidiaryCount = 1;	//附属牌型个数
			SubsidiarySum = 2;		//附属牌型数量
			break;
		case CardType::Four:
			MainCardSum = 4;		//主牌型数量
			break;
		case CardType::FourSingle:
			MainCardSum = 4;		//主牌型数量
			SubsidiaryCount = 2;	//附属牌型个数
			SubsidiarySum = 1;		//附属牌型数量
			break;
		case CardType::FourPair:
			MainCardSum = 4;		//主牌型数量
			SubsidiaryCount = 2;	//附属牌型个数
			SubsidiarySum = 2;		//附属牌型数量
			break;
		case CardType::Plane:
			AdjacentCount = 2;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			break;
		case CardType::PlaneSingle:
			AdjacentCount = 2;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			SubsidiaryCount = 2;	//附属牌型个数
			SubsidiarySum = 1;		//附属牌型数量
			break;
		case CardType::PlanePair:
			AdjacentCount = 2;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			SubsidiaryCount = 2;	//附属牌型个数
			SubsidiarySum = 2;		//附属牌型数量
			break;
		case CardType::ThreePlane:
			AdjacentCount = 3;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			break;
		case CardType::ThreePlaneSingle:
			AdjacentCount = 3;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			SubsidiaryCount = 3;	//附属牌型个数
			SubsidiarySum = 1;		//附属牌型数量
			break;
		case CardType::ThreePlanePair:
			AdjacentCount = 3;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			SubsidiaryCount = 3;	//附属牌型个数
			SubsidiarySum = 2;		//附属牌型数量
			break;
		case CardType::FourPlane:
			AdjacentCount = 4;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			break;
		case CardType::FourPlaneSingle:
			AdjacentCount = 4;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			SubsidiaryCount = 4;	//附属牌型个数
			SubsidiarySum = 1;		//附属牌型数量
			break;
		case CardType::FourPlanePair:
			AdjacentCount = 4;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			SubsidiaryCount = 4;	//附属牌型个数
			SubsidiarySum = 2;		//附属牌型数量
			break;
		case CardType::FivePlane:
			AdjacentCount = 5;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			break;
		case CardType::FivePlaneSingle:
			AdjacentCount = 5;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			SubsidiaryCount = 5;	//附属牌型个数
			SubsidiarySum = 1;		//附属牌型数量
			break;
		case CardType::SixPlane:
			AdjacentCount = 6;		//主牌型连续牌数量
			MainCardSum = 3;		//主牌型数量
			break;
		case CardType::StraightSingle:
			result = FindStraightSingle(cards, len, outCards);
			return result;
		case CardType::StraightPair:
			result = FindStraightPair(cards, len, outCards);
			return result;
		case CardType::KingBomb:
			result = FindKingBomb(cards, len, outCards);
			return result;
		default:
			MainCardSum = 1;		//主牌型数量
			break;
		}
		result = FindCards(cards, len, false, CardNumber::C_3, false, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
		if (!result)
		{
			result = FindCards(cards, len, false, CardNumber::C_3, true, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindTargetCards(const int *cards, const int len, const int *cmpCards, const int cmpLen, const CardType cardType, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		//主牌型连续牌数量,主牌型数量,附属牌型个数,附属牌型数量
		int AdjacentCount = 0, MainCardSum = 0, SubsidiaryCount = 0, SubsidiarySum = 0;
		CardNumber minCard;
		bool isOK = DouDiZhuLogic::GetCompareCardNumber(cmpCards, cmpLen, cardType, minCard);
		if (isOK)
		{
			switch (cardType)
			{
			case CardType::Normal:
				MainCardSum = 1;		//主牌型数量
				break;
			case CardType::Single:
				MainCardSum = 1;		//主牌型数量
				break;
			case CardType::Pair:
				MainCardSum = 2;		//主牌型数量
				break;
			case CardType::Three:
				MainCardSum = 3;		//主牌型数量
				break;
			case CardType::ThreeSingle:
				MainCardSum = 3;		//主牌型数量
				SubsidiaryCount = 1;	//附属牌型个数
				SubsidiarySum = 1;		//附属牌型数量
				break;
			case CardType::ThreePair:
				MainCardSum = 3;		//主牌型数量
				SubsidiaryCount = 1;	//附属牌型个数
				SubsidiarySum = 2;		//附属牌型数量
				break;
			case CardType::Four:
				MainCardSum = 4;		//主牌型数量
				break;
			case CardType::FourSingle:
				MainCardSum = 4;		//主牌型数量
				SubsidiaryCount = 2;	//附属牌型个数
				SubsidiarySum = 1;		//附属牌型数量
				break;
			case CardType::FourPair:
				MainCardSum = 4;		//主牌型数量
				SubsidiaryCount = 2;	//附属牌型个数
				SubsidiarySum = 2;		//附属牌型数量
				break;
			case CardType::Plane:
				AdjacentCount = 2;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				break;
			case CardType::PlaneSingle:
				AdjacentCount = 2;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				SubsidiaryCount = 2;	//附属牌型个数
				SubsidiarySum = 1;		//附属牌型数量
				break;
			case CardType::PlanePair:
				AdjacentCount = 2;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				SubsidiaryCount = 2;	//附属牌型个数
				SubsidiarySum = 2;		//附属牌型数量
				break;
			case CardType::ThreePlane:
				AdjacentCount = 3;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				break;
			case CardType::ThreePlaneSingle:
				AdjacentCount = 3;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				SubsidiaryCount = 3;	//附属牌型个数
				SubsidiarySum = 1;		//附属牌型数量
				break;
			case CardType::ThreePlanePair:
				AdjacentCount = 3;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				SubsidiaryCount = 3;	//附属牌型个数
				SubsidiarySum = 2;		//附属牌型数量
				break;
			case CardType::FourPlane:
				AdjacentCount = 4;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				break;
			case CardType::FourPlaneSingle:
				AdjacentCount = 4;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				SubsidiaryCount = 4;	//附属牌型个数
				SubsidiarySum = 1;		//附属牌型数量
				break;
			case CardType::FourPlanePair://20张 只有地主
				AdjacentCount = 4;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				SubsidiaryCount = 4;	//附属牌型个数
				SubsidiarySum = 2;		//附属牌型数量
				break;
			case CardType::FivePlane:
				AdjacentCount = 5;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				break;
			case CardType::FivePlaneSingle://20张 只有地主
				AdjacentCount = 5;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				SubsidiaryCount = 5;	//附属牌型个数
				SubsidiarySum = 1;		//附属牌型数量
				break;
			case CardType::SixPlane://18张 只有地主
				AdjacentCount = 6;		//主牌型连续牌数量
				MainCardSum = 3;		//主牌型数量
				break;
			case CardType::StraightSingle:
				if (len >= cmpLen)
				{
					AdjacentCount = cmpLen;	//主牌型连续牌数量
					MainCardSum = 1;	//主牌型数量
				}
				break;
			case CardType::StraightPair:
				if (len >= cmpLen)
				{
					AdjacentCount = cmpLen / 2;	//主牌型连续牌数量
					MainCardSum = 2;	//主牌型数量
				}
				break;
			case CardType::KingBomb:
				result = FindKingBomb(cards, len, outCards);
				return result;
			default:
				MainCardSum = 1;		//主牌型数量
				break;
			}
			result = FindCards(cards, len, true, minCard, false, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
			if (!result)
			{
				result = FindCards(cards, len, true, minCard, true, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
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
bool DouDiZhu::DouDiZhuPlayCardLogic::FindStraightSingle(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		//int AdjacentCount = 5;	//主牌型连续牌数量
		int MainCardSum = 1;	//主牌型数量
		int SubsidiaryCount = 0;	//附属牌型个数
		int SubsidiarySum = 0;		//附属牌型数量
		bool isOK = false;
		for (int i = 5; i < 12; ++i)
		{
			isOK = FindCards(cards, len, false, CardNumber::C_3, false, i, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
			if (isOK)
			{
				result = isOK;
			}
			else
			{
				isOK = FindCards(cards, len, false, CardNumber::C_3, true, i, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
				if (isOK)
				{
					result = isOK;
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindStraightPair(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		//int AdjacentCount = 5;	//主牌型连续牌数量
		int MainCardSum = 2;	//主牌型数量
		int SubsidiaryCount = 0;	//附属牌型个数
		int SubsidiarySum = 0;		//附属牌型数量
		bool isOK = false;
		for (int i = 3; i < 12; ++i)
		{
			isOK = FindCards(cards, len, false, CardNumber::C_3, false, i, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
			if (isOK)
			{
				result = isOK;
			}
			else
			{
				isOK = FindCards(cards, len, false, CardNumber::C_3, true, i, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
				if (isOK)
				{
					result = isOK;
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindKingBomb(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		if (len > 0)
		{
			CardMark mark;
			bool isOK;
			vector<int> kingVec;
			for (int i = 0; i < len; ++i)
			{
				isOK = PokerLogic::ValueToMark(cards[i], mark);
				if (isOK && mark == CardMark::Joker)
				{
					kingVec.push_back(cards[i]);
					if (kingVec.size() == 2 && kingVec[0] != kingVec[1])
					{
						outCards.push_back(kingVec);
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindCards(const int *cards, const int len, const bool isCompareMinCard, const CardNumber minCard, const bool isMainSplit, const int adjacentCount, const int mainCardSum, const int subsidiaryCount, const int subsidiarySum, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		bool isOK = false;
		int sortArr[CardSortCount] = { 0 };
		isOK = DouDiZhuLogic::CardsToSortArray(cards, len, sortArr, CardSortCount);
		if (isOK)
		{
			vector<vector<int>> mainCardsList;
			isOK = FindMainCards(sortArr, CardSortCount, isCompareMinCard, minCard, adjacentCount, mainCardSum, isMainSplit, mainCardsList);
			if (isOK)
			{
				for (int i = 0; i < mainCardsList.size(); ++i)
				{
					vector<int> mainCards = mainCardsList[i];
					vector<vector<int>> subsidiaryCardsList;
					if (subsidiaryCount > 0 && subsidiarySum > 0)//如果需要找附属牌
					{
						int cloneSortArray[CardSortCount];
						//复制排序牌
						DouDiZhuLogic::CloneArray(sortArr, CardSortCount, cloneSortArray);
						for (int j = 0; j < mainCards.size(); ++j)
						{
							cloneSortArray[mainCards[j]] -= mainCardSum;//减去主牌型的牌
						}
						//找出所有可能的附属牌
						isOK = FindSubsidiaryCards(cloneSortArray, CardSortCount, subsidiaryCount, subsidiarySum, false, subsidiaryCardsList);
						if (!isOK)//如果没找到附属牌，重新拆牌进行查找
						{
							isOK = FindSubsidiaryCards(cloneSortArray, CardSortCount, subsidiaryCount, subsidiarySum, true, subsidiaryCardsList);
						}
					}
					//合并主牌型与附属牌型
					isOK = JoinCards(cards, len, mainCards, mainCardSum, subsidiaryCardsList, subsidiarySum, outCards);
				}
				if (!outCards.empty())
				{
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
				isOK = DouDiZhuLogic::SortStyleValueToCardNumber(sortCards[i], cmpCard);
				if (isOK)
				{
					for (int j = 0; j < len; ++j)
					{
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindMainCards(const int *sortArray, const int sortArrLen, const bool isCompareMinCard, const CardNumber minCard, const int adjacentCount, const int sameCount, const bool isSplit, vector<vector<int>> &outSortArrVec)
{
	bool result = false;
	try
	{
		bool isAccord = false, isFindAdjacent = false;//isAccord 是否是符合的牌 拆牌
		vector<int> cards;
		int minIndex = 0;
		if (isCompareMinCard)
		{
			minIndex = DouDiZhuLogic::CardNumberToSortArrayValue(minCard);
			if (minIndex < 0)
			{
				return result;
			}
			minIndex += 1;
		}
		for (int i = minIndex; i < sortArrLen; ++i)
		{
			cards.clear();
			if (adjacentCount > 1)//连续的牌
			{
				isFindAdjacent = false;
				for (int j = i; j < i + adjacentCount; ++j)
				{
					isFindAdjacent = true;
					isAccord = (isSplit) ? sortArray[j] >= sameCount : sortArray[j] == sameCount;
					if (isAccord && (CardNumber)j != CardNumber::C_2 && j != sortArrLen - 1)
					{
						cards.push_back(j);
					}
					else
					{
						isFindAdjacent = false;
						break;
					}
				}
				if (isFindAdjacent)
				{
					outSortArrVec.push_back(cards);
					result = true;
				}
			}
			else//相同的牌
			{
				isAccord = (isSplit) ? sortArray[i] >= sameCount : sortArray[i] == sameCount;
				if (isAccord)
				{
					cards.push_back(i);
					outSortArrVec.push_back(cards);
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindSubsidiaryCards(const int *sortNoMainArray, const int sortArrLen, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outSubsidiaryVec)
{
	bool result = false;
	try
	{
		if (CardSortCount == sortArrLen)
		{
			bool isAccord = false;//是否是符合的牌 用于拆牌
			vector<int> subsidiaryVec;
			vector<int> otherSubsidiaryVec;//拆相同牌的附属牌 例如：4个5，已经找到对5，这个数组存放另一个对5
			for (int i = 0; i < sortArrLen; ++i)
			{
				isAccord = (isSplit) ? sortNoMainArray[i] >= subsidiarySameCount : sortNoMainArray[i] == subsidiarySameCount;
				if (isAccord)
				{
					subsidiaryVec.push_back(i);
				}
				/*如果拆分牌 并且某牌张数大于附属牌数量数，则添加另一集合中*/ 
				/*例如：找2个对，有4个5，2个5保存subsidiaryVec中，另2个5保存otherSubsidiaryVec中*/
				if(isSplit && sortNoMainArray[i] >= subsidiarySameCount * 2)
				{
					int tmpLoopNum = sortNoMainArray[i] / (subsidiarySameCount * 2);
					if (tmpLoopNum > 0)
					{
						for (int j = 0; j < tmpLoopNum; ++j)
						{
							otherSubsidiaryVec.push_back(i);
						}
					}
				}
			}
			/*如果subsidiaryVec中的个数不满足附属牌个数，并且可以拆牌*/
			/*此时再加上otherSubsidiaryVec中的附属牌*/
			if (subsidiaryVec.size() < subsidiaryCount && isSplit)
			{
				for (int m = 0; m < otherSubsidiaryVec.size(); ++m)
				{
					subsidiaryVec.push_back(otherSubsidiaryVec[m]);
				}
			}
			if (!subsidiaryVec.empty())
			{
				result = Cmn(subsidiaryVec, subsidiaryVec.size(), subsidiaryCount, outSubsidiaryVec);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::JoinCards(const int *cards, const int len, const vector<int> const mainCards, const int mainSum, const vector<vector<int>> const subsidiaryCards, const int subsidiarySum, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		bool isOK = false;
		vector<int> joinIdxVec, joinCards;
		if (len > 0 && mainCards.size() > 0)
		{
			if (subsidiaryCards.size() > 0)//有附属牌
			{
				for (int i = 0; i < subsidiaryCards.size(); ++i)
				{
					joinIdxVec.clear();
					joinCards.clear();
					//合并
					for (int j = 0; j < mainCards.size(); ++j)
					{
						for (int k = 0; k < mainSum; ++k)
						{
							joinIdxVec.push_back(mainCards[j]);
						}
					}
					for (int j = 0; j < subsidiaryCards[i].size(); ++j)
					{
						for (int k = 0; k < subsidiarySum; ++k)
						{
							joinIdxVec.push_back(subsidiaryCards[i][j]);
						}
					}
					//转扑克牌值
					isOK = SortArrayCardsToCards(joinIdxVec, cards, len, joinCards);
					if (isOK)
					{
						outCards.push_back(joinCards);//保存outCards
						result = true;
					}
				}
			}
			else//没有附属牌
			{
				for (int j = 0; j < mainCards.size(); ++j)
				{
					for (int k = 0; k < mainSum; ++k)
					{
						joinIdxVec.push_back(mainCards[j]);
					}
				}
				//转扑克牌值
				result = SortArrayCardsToCards(joinIdxVec, cards, len, joinCards);
				if (result)
				{
					outCards.push_back(joinCards);//保存outCards
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

/*
排列组合找出不重样的组合数组
preWei:前一位数值
wei:当前位数
r: 排列组合的临时存放数组
len:总数据长度
sub:位数长度
result:保存结果的集合
*/
void DouDiZhu::DouDiZhuPlayCardLogic::Cmn(int preWei, int wei, vector<int> &r, int len, int sub, vector<vector<int>> &result)
{
	if (wei + 1 == sub)
	{
		for (int k = preWei + 1; k < len; ++k)
		{
			vector<int> temp(sub);
			r[sub - 1] = k;
			for (int i = 0; i < sub; i++)
			{
				temp[i] = r[i];
			}
			result.push_back(temp);
		}
	}
	else if (wei < sub)
	{
		for (int k = preWei + 1; k < len - wei + 1; ++k)
		{
			r[wei] = k;
			Cmn(k, wei + 1, r, len, sub, result);
		}
	}
}
/*
调用例子
const int len = 5;
int arr[len] = { 1,2,3,4,5 };
const int sub = 3;
vector<vector<int>> outVec;
MyCmn(len, sub, outVec);
*/
/*
计算C(M,N)排列组合  C(len, sub)
len: 集合总长度 M
sub: 要找组合的长度 N
result: C(M,N)的结果
*/
bool DouDiZhu::DouDiZhuPlayCardLogic::Cmn(vector<int> sourceVec,int len, int sub, vector<vector<int>> &outVec)
{
	bool result = false;
	try
	{
		vector<int> vec(sub);
		vector<vector<int>> idxVec;
		Cmn(-1, 0, vec, len, sub, idxVec);
		if (!idxVec.empty())
		{
			for (int i = 0; i < idxVec.size(); ++i)
			{
				for (int j = 0; j < idxVec[i].size(); ++j)
				{
					vec[j] = sourceVec[idxVec[i][j]];
				}
				outVec.push_back(vec);
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
