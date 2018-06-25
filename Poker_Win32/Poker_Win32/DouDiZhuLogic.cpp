#include "DouDiZhuLogic.h"

DouDiZhu::DouDiZhuLogic::DouDiZhuLogic() : PokerLogic(Poker_Weight[0], Poker_Weight[1], Poker_Weight[2], Poker_Weight[3], Poker_Weight[4], 
														Poker_Weight[5], Poker_Weight[6], Poker_Weight[7], Poker_Weight[8], Poker_Weight[9], 
														Poker_Weight[10], Poker_Weight[11], Poker_Weight[12], Poker_Weight[13], Poker_Weight[14])
{

}

DouDiZhu::DouDiZhuLogic::~DouDiZhuLogic()
{

}

CardType DouDiZhu::DouDiZhuLogic::GetCardType(const int *cards, const int len)
{
	CardType result = CardType::Normal;
	try
	{
		if (len == 1)
		{
			result = CardType::Single;
		}
		else if (len == 2)
		{
			if (IsCardType(CardType::KingBomb, cards, len))//如果是双王，判定王炸优先
			{
				result = CardType::KingBomb;
			}
			else if (IsCardType(CardType::Pair, cards, len))
			{
				result = CardType::Pair;
			}
		}
		else if (len == 3 && IsCardType(CardType::Three, cards, len))
		{
			result = CardType::Three;
		}
		else if (len == 4)
		{
			if (IsCardType(CardType::Four, cards, len))//如果是炸弹，可以判定炸弹类型优先
			{
				result = CardType::Four;
			}
			else if (IsCardType(CardType::ThreeSingle, cards, len))
			{
				result = CardType::ThreeSingle;
			}
		}
		else if (len == 5 && IsCardType(CardType::ThreePair, cards, len))
		{
			result = CardType::ThreePair;
		}
		else if (len == 6)
		{
			if (IsCardType(CardType::FourSingle, cards, len))
			{
				result = CardType::FourSingle;
			}
			else if (IsCardType(CardType::Plane, cards, len))
			{
				result = CardType::Plane;
			}
		}
		else if (len == 8)//两种情况都有可能 33334444
		{
			if (IsCardType(CardType::FourPair, cards, len))//优先 四带两对
			{
				result = CardType::FourPair;
			}
			else if (IsCardType(CardType::PlaneSingle, cards, len))
			{
				result = CardType::PlaneSingle;
			}
		}
		else if (len == 9 && IsCardType(CardType::ThreePlane, cards, len))
		{
			result = CardType::ThreePlane;
		}
		else if (len == 10 && IsCardType(CardType::PlanePair, cards, len))
		{
			result = CardType::PlanePair;
		}
		else if (len == 12)//两种情况都有可能 333444555666
		{
			if (IsCardType(CardType::FourPlane, cards, len))//4个飞机判定优先
			{
				result = CardType::FourPlane;
			}
			else if (IsCardType(CardType::ThreePlaneSingle, cards, len))
			{
				result = CardType::ThreePlaneSingle;
			}
		}
		else if (len == 15)
		{
			if (IsCardType(CardType::ThreePlanePair, cards, len))
			{
				result = CardType::ThreePlanePair;
			}
			else if (IsCardType(CardType::FivePlane, cards, len))
			{
				result = CardType::FivePlane;
			}
		}
		else if (len == 16 && IsCardType(CardType::FourPlaneSingle, cards, len))
		{
			result = CardType::FourPlaneSingle;
		}
		else if (len == 18 && IsCardType(CardType::SixPlane, cards, len))
		{
			result = CardType::SixPlane;
		}
		else if (len == 20)//两种情况都有可能 33344455566677778888 (此牌只有地主，任一类型即可)
		{
			if (IsCardType(CardType::FivePlaneSingle, cards, len))//优先判断5飞机带5单
			{
				result = CardType::FivePlaneSingle;
			}
			else if (IsCardType(CardType::FourPlanePair, cards, len))
			{
				result = CardType::FourPlanePair;
			}
		}
		if(result == CardType::Normal && len >= 5)
		{
			if (IsCardType(CardType::StraightSingle, cards, len))
			{
				result = CardType::StraightSingle;
			}
			else if (IsCardType(CardType::StraightPair, cards, len))
			{
				result = CardType::StraightPair;
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsCardType(const CardType cardType, const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (cardType != CardType::Normal && NULL != cards && len > 0)
		{
			int adjacentCount = 1;
			int sameCount = 0;
			int subsidiaryCount = 0;
			int subsidiarySameCount = 0;
			switch (cardType)
			{
			case CardType::Normal:
				return result;
			case CardType::Single:
				break;
			case CardType::Pair:
				sameCount = 2;
				break;
			case CardType::Three:
				sameCount = 3;
				break;
			case CardType::ThreeSingle:
				sameCount = 3;
				subsidiaryCount = 1;
				subsidiarySameCount = 1;
				break;
			case CardType::ThreePair:
				sameCount = 3;
				subsidiaryCount = 1;
				subsidiarySameCount = 2;
				break;
			case CardType::Four:
				sameCount = 4;
				break;
			case CardType::FourSingle:
				sameCount = 4;
				subsidiaryCount = 2;
				subsidiarySameCount = 1;
				break;
			case CardType::FourPair:
				sameCount = 4;
				subsidiaryCount = 2;
				subsidiarySameCount = 2;
				break;
			case CardType::Plane:
				adjacentCount = 2;
				sameCount = 3;
				break;
			case CardType::PlaneSingle:
				adjacentCount = 2;
				sameCount = 3;
				subsidiaryCount = 2;
				subsidiarySameCount = 1;
				break;
			case CardType::PlanePair:
				adjacentCount = 2;
				sameCount = 3;
				subsidiaryCount = 2;
				subsidiarySameCount = 2;
				break;
			case CardType::ThreePlane:
				adjacentCount = 3;
				sameCount = 3;
				break;
			case CardType::ThreePlaneSingle:
				adjacentCount = 3;
				sameCount = 3;
				subsidiaryCount = 3;
				subsidiarySameCount = 1;
				break;
			case CardType::ThreePlanePair:
				adjacentCount = 3;
				sameCount = 3;
				subsidiaryCount = 3;
				subsidiarySameCount = 2;
				break;
			case CardType::FourPlane:
				adjacentCount = 4;
				sameCount = 3;
				break;
			case CardType::FourPlaneSingle:
				adjacentCount = 4;
				sameCount = 3;
				subsidiaryCount = 4;
				subsidiarySameCount = 1;
				break;
			case CardType::FourPlanePair:
				adjacentCount = 4;
				sameCount = 3;
				subsidiaryCount = 4;
				subsidiarySameCount = 2;
				break;
			case CardType::FivePlane:
				adjacentCount = 5;
				sameCount = 3;
				break;
			case CardType::FivePlaneSingle:
				adjacentCount = 5;
				sameCount = 3;
				subsidiaryCount = 5;
				subsidiarySameCount = 1;
				break;
			case CardType::SixPlane:
				adjacentCount = 6;
				sameCount = 3;
				break;
			case CardType::StraightSingle:
				adjacentCount = len;
				sameCount = 1;
				break;
			case CardType::StraightPair:
				if (len % 2 != 0)
				{
					return result;
				}
				adjacentCount = len / 2;
				sameCount = 2;
				break;
			case CardType::KingBomb:
				result = IsKingBomb(cards, len);
				return result;
			default:
				return result;
			}
			result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareCards(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		CardType card1Type = GetCardType(cards1, cards1Len);
		CardType card2Type = GetCardType(cards2, cards2Len);
		result = CompareCards(cards1, cards1Len, card1Type, cards2, cards2Len, card2Type);
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareCards(const int *cards1, const int cards1Len, const CardType card1Type, const int *cards2, const int cards2Len, const CardType card2Type)
{
	int result = -1;
	try
	{
		if (card1Type != CardType::Normal && card2Type != CardType::Normal)
		{
			if (card1Type != card2Type)
			{
				if (card1Type == CardType::KingBomb)
				{
					result = 1;
				}
				else if (card2Type == CardType::KingBomb)
				{
					result = -1;
				}
				else if (card1Type == CardType::Four)
				{
					result = 1;
				}
				else if (card2Type == CardType::Four)
				{
					result = -1;
				}
			}
			else
			{
				CardNumber cardNum1, cardNum2;
				bool isOK = GetCompareCardNumber(cards1, cards1Len, card1Type, cardNum1);
				if (isOK)
				{
					bool isOK = GetCompareCardNumber(cards2, cards2Len, card1Type, cardNum2);
					if (isOK)
					{
						result = PokerLogic::CompareCardNumber(cardNum1, cardNum2);
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

/*============================ 通用方法 begin ================================*/

bool DouDiZhu::DouDiZhuLogic::SortStyleValueToCardNumber(const int value, CardNumber & cardNum)
{
	bool result = false;
	try
	{
		for (int i = 0; i < CardSortCount; ++i)
		{
			if (SortStyle[i] == value)
			{
				if (i == 13)
				{
					cardNum = CardNumber::C_RJ;
				}
				else
				{
					cardNum = (CardNumber)i;
				}
				result = true;;
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
int DouDiZhu::DouDiZhuLogic::CardNumberToSortArrayValue(const CardNumber cardNum)
{
	int result = -1;
	try
	{
		int idxCard = (int)cardNum;
		if (idxCard < 13)
		{
			result = SortStyle[idxCard];
		}
		else if (idxCard == CardNumber::C_BJ || idxCard == CardNumber::C_RJ)
		{
			result = SortStyle[13];
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}
bool DouDiZhu::DouDiZhuLogic::CardsToSortArray(const int *cards, const int cardsLen, int *sortArray, const int sortArrLen)
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
					idxCard = CardNumberToSortArrayValue(cardNum);
					if (idxCard >= 0)
					{
						sortArray[idxCard]++;
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

bool DouDiZhu::DouDiZhuLogic::GetCompareCardNumber(const int *cards, const int len, const CardType cardType, CardNumber &cardNum)
{
	bool result = false;
	try
	{
		int sortArr[CardSortCount] = { 0 };
		bool isOK = CardsToSortArray(cards, len, sortArr, CardSortCount);
		if (isOK)
		{
			int AdjacentCount = 0, MainCardSum = 0;
			switch (cardType)
			{
			case CardType::Normal:
				return result;
			case CardType::Single:
				if (len == 1)
				{
					result = PokerLogic::ValueToCardNumber(cards[0], cardNum);
				}
				return result;
			case CardType::Pair:
				if (len == 2)
				{
					MainCardSum = 2;
				}
				break;
			case CardType::Three:
				if (len == 3)
				{
					MainCardSum = 3;
				}
				break;
			case CardType::ThreeSingle:
				if (len == 4)
				{
					MainCardSum = 3;
				}
				break;
			case CardType::ThreePair:
				if (len == 5)
				{
					MainCardSum = 3;
				}
				break;
			case CardType::Four:
				if (len == 4)
				{
					MainCardSum = 4;
				}
				break;
			case CardType::FourSingle:
				if (len == 6)
				{
					MainCardSum = 4;
				}
				break;
			case CardType::FourPair:
				if (len == 8)
				{
					MainCardSum = 4;
				}
				break;
			case CardType::Plane:
				if (len == 6)
				{
					AdjacentCount = 2;
					MainCardSum = 3;
				}
				break;
			case CardType::PlaneSingle:
				if (len == 8)
				{
					AdjacentCount = 2;
					MainCardSum = 3;
				}
				break;
			case CardType::PlanePair:
				if (len == 10)
				{
					AdjacentCount = 2;
					MainCardSum = 3;
				}
				break;
			case CardType::ThreePlane:
				if (len == 9)
				{
					AdjacentCount = 3;
					MainCardSum = 3;
				}
				break;
			case CardType::ThreePlaneSingle:
				if (len == 12)
				{
					AdjacentCount = 3;
					MainCardSum = 3;
				}
				break;
			case CardType::ThreePlanePair:
				if (len == 15)
				{
					AdjacentCount = 3;
					MainCardSum = 3;
				}
				break;
			case CardType::FourPlane:
				if (len == 12)
				{
					AdjacentCount = 4;
					MainCardSum = 3;
				}
				break;
			case CardType::FourPlaneSingle:
				if (len == 16)
				{
					AdjacentCount = 4;
					MainCardSum = 3;
				}
				break;
			case CardType::FourPlanePair:
				if (len == 20)
				{
					AdjacentCount = 4;
					MainCardSum = 3;
				}
				break;
			case CardType::FivePlane:
				if (len == 15)
				{
					AdjacentCount = 5;
					MainCardSum = 3;
				}
				break;
			case CardType::FivePlaneSingle:
				if (len == 20)
				{
					AdjacentCount = 5;
					MainCardSum = 3;
				}
				break;
			case CardType::SixPlane:
				if (len == 18)
				{
					AdjacentCount = 6;
					MainCardSum = 3;
				}
				break;
			case CardType::StraightSingle:
				if (len >= 5)
				{
					AdjacentCount = 5;
					MainCardSum = 1;
				}
				break;
			case CardType::StraightPair:
				if (len >= 6)
				{
					AdjacentCount = 3;
					MainCardSum = 2;
				}
				break;
			case CardType::KingBomb:
				if (len == 2)
				{
					cardNum = CardNumber::C_RJ;
					result = true;
				}
				return result;
			default:
				return result;
			}
			for (int i = 0; i < CardSortCount; ++i)
			{
				if (AdjacentCount > 0)//找连续的牌
				{
					if (i + AdjacentCount < CardSortCount)
					{
						bool isAdjacent = true;
						for (int j = i; j < i + AdjacentCount; ++j)
						{
							if (sortArr[j] - MainCardSum < 0)
							{
								isAdjacent = false;
								break;
							}
						}
						if (isAdjacent)
						{
							result = SortStyleValueToCardNumber(i, cardNum);
							break;
						}
					}
				}
				else//直接找牌
				{
					if (sortArr[i] == MainCardSum)
					{
						result = SortStyleValueToCardNumber(i, cardNum);
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



/*============================ 通用方法 end ================================*/




/*=======================以下为私有方法=======================*/

bool DouDiZhu::DouDiZhuLogic::IsKingBomb(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 2)
		{
			CardNumber kingArr[2];
			bool isOK = PokerLogic::ValueToCardNumber(cards, len, kingArr, 2);
			if (isOK)
			{
				if ((kingArr[0] == CardNumber::C_BJ && kingArr[1] == CardNumber::C_RJ)
					||
					(kingArr[1] == CardNumber::C_BJ && kingArr[0] == CardNumber::C_RJ))
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

bool DouDiZhu::DouDiZhuLogic::IsTrueCardType(const int *cards, const int len, const int adjacentCount, const int sameCount, const int subsidiaryCount, const int subsidiarySameCount)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == (adjacentCount * sameCount + subsidiaryCount * subsidiarySameCount))
		{
			bool isOK;
			int sortArray[CardSortCount] = { 0 }, tmpSubsidiaryCount = 0;
			isOK = CardsToSortArray(cards, len, sortArray, CardSortCount);
			if (isOK)
			{
				//找到主牌型，然后去掉
				for (int i = 0; i < CardSortCount; ++i)
				{
					if (adjacentCount > 1)//连续的牌
					{
						isOK = IsAdjacentCard(sortArray, CardSortCount, i, adjacentCount, sameCount);
						if (isOK)
						{
							for (int j = i; j < i + adjacentCount; ++j)
							{
								sortArray[j] -= sameCount;
							}
							break;
						}
					}
					else//相同的牌
					{
						if (sortArray[i] >= sameCount)
						{
							sortArray[i] -= sameCount;
							break;
						}
					}
				}
				//去掉主牌型牌后，再去掉附属牌型，再判断
				if (subsidiaryCount > 0)
				{
					for (int i = 0; i < subsidiaryCount; ++i)
					{
						for (int j = 0; j < CardSortCount; ++j)
						{
							if (sortArray[j] >= subsidiarySameCount)
							{
								sortArray[j] -= subsidiarySameCount;
								break;
							}
						}
					}
				}
				result = true;
				for (int i = 0; i < CardSortCount; ++i)
				{
					if (sortArray[i] > 0)
					{
						result = false;
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

bool DouDiZhu::DouDiZhuLogic::CloneArray(const int *cards, const int len, int *outCards)
{
	bool result = false;
	try
	{
		if (NULL != cards && len > 0)
		{
			for (int i = 0; i < len; ++i)
			{
				outCards[i] = cards[i];
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsAdjacentCard(const int *sortArray, const int sortArrLen, const int index, const int adjacentCount, const int sameCount)
{
	bool result = false;
	try
	{
		if (NULL != sortArray && sortArrLen == CardSortCount && index >= 0 && index + adjacentCount < CardSortCount)
		{
			for (int i = index; i < index + adjacentCount; ++i)
			{
				result = true;
				if (sortArray[i] < sameCount)
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

