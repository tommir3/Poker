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
			if (IsKingBomb(cards, len))//如果是双王，判定王炸优先
			{
				result = CardType::KingBomb;
			}
			else if (IsPair(cards, len))
			{
				result = CardType::Pair;
			}
		}
		else if (len == 3 && IsThree(cards, len))
		{
			result = CardType::Three;
		}
		else if (len == 4)
		{
			if (IsFour(cards, len))//如果是炸弹，可以判定炸弹类型优先
			{
				result = CardType::Four;
			}
			else if (IsThreeSingle(cards, len))
			{
				result = CardType::ThreeSingle;
			}
		}
		else if (len == 5 && IsThreePair(cards, len))
		{
			result = CardType::ThreePair;
		}
		else if (len == 6)
		{
			if (IsFourSingle(cards, len))
			{
				result = CardType::FourSingle;
			}
			else if (IsPlane(cards, len))
			{
				result = CardType::Plane;
			}
		}
		else if (len == 8)//两种情况都有可能 33334444
		{
			if (IsFourPair(cards, len))//优先 四带两对
			{
				result = CardType::FourPair;
			}
			else if (IsPlaneSingle(cards, len))
			{
				result = CardType::PlaneSingle;
			}
		}
		else if (len == 9 && IsThreePlane(cards, len))
		{
			result = CardType::ThreePlane;
		}
		else if (len == 10 && IsPlanePair(cards, len))
		{
			result = CardType::PlanePair;
		}
		else if (len == 12)//两种情况都有可能 333444555666
		{
			if (IsFourPlane(cards, len))//4个飞机判定优先
			{
				result = CardType::FourPlane;
			}
			else if (IsThreePlaneSingle(cards, len))
			{
				result = CardType::ThreePlaneSingle;
			}
		}
		else if (len == 15)
		{
			if (IsThreePlanePair(cards, len))
			{
				result = CardType::ThreePlanePair;
			}
			else if (IsFivePlane(cards, len))
			{
				result = CardType::FivePlane;
			}
		}
		else if (len == 16 && IsFourPlaneSingle(cards, len))
		{
			result = CardType::FourPlaneSingle;
		}
		else if (len == 18 && IsSixPlane(cards, len))
		{
			result = CardType::SixPlane;
		}
		else if (len == 20)//两种情况都有可能 33344455566677778888 (此牌只有地主，任一类型即可)
		{
			if (IsFivePlaneSingle(cards, len))//优先判断5飞机带5单
			{
				result = CardType::FivePlaneSingle;
			}
			else if (IsFourPlanePair(cards, len))
			{
				result = CardType::FourPlanePair;
			}
		}
		if(result == CardType::Normal && len >= 5)
		{
			if (IsStraightSingle(cards, len))
			{
				result = CardType::StraightSingle;
			}
			else if (IsStraightPair(cards, len))
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
				switch (card1Type)
				{
				case CardType::Normal:
					break;
				case CardType::Single:
					result = CompareSingle(cards1[0], cards2[0]);
					break;
				case CardType::Pair:
					result = ComparePair(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::Three:
					result = CompareThree(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::ThreeSingle:
					result = CompareThreeSingle(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::ThreePair:
					result = CompareThreePair(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::Four:
					result = CompareFour(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::FourSingle:
					result = CompareFourSingle(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::FourPair:
					result = CompareFourPair(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::Plane:
					result = ComparePlane(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::PlaneSingle:
					result = ComparePlaneSingle(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::PlanePair:
					result = ComparePlanePair(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::ThreePlane:
					result = CompareThreePlane(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::ThreePlaneSingle:
					result = CompareThreePlaneSingle(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::ThreePlanePair:
					result = CompareThreePlanePair(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::FourPlane:
					result = CompareFourPlane(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::FourPlaneSingle:
					result = CompareFourPlaneSingle(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::FourPlanePair:
					result = CompareFourPlanePair(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::FivePlane:
					result = CompareFivePlane(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::FivePlaneSingle:
					result = CompareFivePlaneSingle(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::SixPlane:
					result = CompareSixPlane(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::StraightSingle:
					result = CompareStraightSingle(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::StraightPair:
					result = CompareStraightPair(cards1, cards1Len, cards2, cards2Len);
					break;
				case CardType::KingBomb:
					result = -1;
					break;
				default:
					result = -1;
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

/*============================ 判断牌型 begin ================================*/
bool DouDiZhu::DouDiZhuLogic::IsPair(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 2)
		{
			result = IsAllSame(cards, 2);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsThree(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 3)
		{
			result = IsAllSame(cards, 3);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsFour(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 4)
		{
			result = IsAllSame(cards, 4);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsThreeSingle(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 4)
		{
			const int arrLen = 2;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				if (cnsArr[0].count == 3 || cnsArr[1].count == 3)
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

bool DouDiZhu::DouDiZhuLogic::IsThreePair(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 5)
		{
			const int arrLen = 2;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				if (cnsArr[0].count + cnsArr[1].count == 5
					&& 
					((cnsArr[0].count == 3 || cnsArr[2].count == 2) || (cnsArr[0].count == 2 || cnsArr[2].count == 3)))
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

bool DouDiZhu::DouDiZhuLogic::IsFourSingle(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 6)
		{
			const int arrLen = 3;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				for (int i = 0; i < arrLen; ++i)
				{
					if (cnsArr[i].count == 4)
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

bool DouDiZhu::DouDiZhuLogic::IsFourPair(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 8)
		{
			const int arrLen = 3;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				bool isFour = false;
				bool isPair1 = false;
				bool isPair2 = false;
				for (int i = 0; i < arrLen; ++i)
				{
					if (cnsArr[i].count == 1)
					{
						isFour = false;
						break;
					}
					else if (cnsArr[i].count == 4)
					{
						if (isFour)
						{
							isPair1 = true;
							isPair2 = true;
							break;
						}
						isFour = true;
					}
					else if (cnsArr[i].count == 2)
					{
						if (isPair1)
						{
							isPair2 = true;
						}
						else
						{
							isPair1 = true;
						}
					}
				}
				if (isFour && isPair1 && isPair2)
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

bool DouDiZhu::DouDiZhuLogic::IsPlane(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 6)
		{
			const int arrLen = 2;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				for (int i = 0; i < arrLen; ++i)
				{
					isOK = IsXPlane(cnsArr, arrLen, 0, 2);
					if (isOK)
					{
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

bool DouDiZhu::DouDiZhuLogic::IsPlaneSingle(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 8)
		{
			const int arrLen = 4;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				for (int i = 0; i < arrLen; ++i)
				{
					isOK = IsXPlane(cnsArr, arrLen, i, 2);
					if (isOK)
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

bool DouDiZhu::DouDiZhuLogic::IsPlanePair(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 10)
		{
			const int arrLen = 4;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				bool isPlane = false;
				bool arrIsPair[2] = { false,false };
				for (int i = 0; i < arrLen; )
				{
					isOK = IsXPlane(cnsArr, arrLen, i, 2);
					if (isOK)
					{
						isPlane = true;
						i += 2;
					}
					else
					{
						if (cnsArr[i].count == 1)
						{
							isPlane = false;
							break;
						}
						else if (cnsArr[i].count == 2 || cnsArr[i].count == 4)
						{
							int tmpCount = cnsArr[i].count / 2;
							isOK = SetArrayTrue(arrIsPair, 2, tmpCount);
							if (!isOK)
							{
								isPlane = false;
								break;
							}
						}
						++i;
					}
				}
				if (isPlane)
				{
					bool isPairOk = IsArrayTrue(arrIsPair, 2);
					if (isPairOk)
					{
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

bool DouDiZhu::DouDiZhuLogic::IsThreePlane(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 9)
		{
			const int arrLen = 3;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				result = IsXPlane(cnsArr, arrLen, 0, 3);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsThreePlaneSingle(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 12)
		{
			const int arrLen = 6;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				for (int i = 0; i < arrLen; ++i)
				{
					isOK = IsXPlane(cnsArr, arrLen, i, 3);
					if (isOK)
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

bool DouDiZhu::DouDiZhuLogic::IsThreePlanePair(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 15)
		{
			const int arrLen = 6;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				bool isPlane = false;
				bool arrIsPair[3] = { false,false,false };
				for (int i = 0; i < arrLen; )
				{
					isOK = IsXPlane(cnsArr, arrLen, i, 3);
					if (isOK)
					{
						isPlane = true;
						i += 3;
					}
					else
					{
						if (cnsArr[i].count == 1)
						{
							isPlane = false;
							break;
						}
						else if (cnsArr[i].count == 2 || cnsArr[i].count == 4)
						{
							int tmpCount = cnsArr[i].count / 2;
							isOK = SetArrayTrue(arrIsPair, 3, tmpCount);
							if (!isOK)
							{
								isPlane = false;
								break;
							}
						}
						++i;
					}
				}
				if (isPlane)
				{
					bool isPairOk = IsArrayTrue(arrIsPair, 3);
					if (isPairOk)
					{
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

bool DouDiZhu::DouDiZhuLogic::IsFourPlane(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 12)
		{
			const int arrLen = 4;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				result = IsXPlane(cnsArr, arrLen, 0, 4);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsFourPlaneSingle(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 16)
		{
			const int arrLen = 8;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				for (int i = 0; i < arrLen; ++i)
				{
					isOK = IsXPlane(cnsArr, arrLen, i, 4);
					if (isOK)
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

bool DouDiZhu::DouDiZhuLogic::IsFourPlanePair(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 20)
		{
			const int arrLen = 8;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				bool isPlane = false;
				bool arrIsPair[4] = { false,false,false,false };
				for (int i = 0; i < arrLen; )
				{
					isOK = IsXPlane(cnsArr, arrLen, i, 4);
					if (isOK)
					{
						isPlane = true;
						i += 4;
					}
					else
					{
						if (cnsArr[i].count == 1)
						{
							isPlane = false;
							break;
						}
						else if (cnsArr[i].count == 2 || cnsArr[i].count == 4)
						{
							int tmpCount = cnsArr[i].count / 2;
							isOK = SetArrayTrue(arrIsPair, 4, tmpCount);
							if (!isOK)
							{
								isPlane = false;
								break;
							}
						}
						++i;
					}
				}
				if (isPlane)
				{
					bool isPairOk = IsArrayTrue(arrIsPair, 4);
					if (isPairOk)
					{
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

bool DouDiZhu::DouDiZhuLogic::IsFivePlane(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 15)
		{
			const int arrLen = 5;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				result = IsXPlane(cnsArr, arrLen, 0, 5);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsFivePlaneSingle(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 20)
		{
			const int arrLen = 10;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				for (int i = 0; i < arrLen; ++i)
				{
					isOK = IsXPlane(cnsArr, arrLen, i, 5);
					if (isOK)
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

bool DouDiZhu::DouDiZhuLogic::IsSixPlane(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len == 18)
		{
			const int arrLen = 6;
			CardNumberSum cnsArr[arrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, arrLen);
				result = IsXPlane(cnsArr, arrLen, 0, 6);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsStraightSingle(const int *cards, const int len)
{
	bool result = false;
	CardNumberSum *cnsArr = NULL;
	try
	{
		if (NULL != cards && len >= 5)
		{
			cnsArr = new CardNumberSum[len];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, len);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, len);
				bool isStraight = true;
				for (int i = 0; i < len - 1; ++i)
				{
					if (cnsArr[i].count != 1 || cnsArr[i].num == CardNumber::C_2 
						|| cnsArr[i].num == CardNumber::C_BJ 
						|| cnsArr[i].num == CardNumber::C_RJ
						|| cnsArr[i].num + 1 != cnsArr[i + 1].num)
					{
						isStraight = false;
						break;
					}
				}
				result = isStraight;
			}
			if (NULL != cnsArr)
			{
				delete[] cnsArr;
			}
		}
	}
	catch (exception err)
	{
		if (NULL != cnsArr)
		{
			delete[] cnsArr;
		}
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsStraightPair(const int *cards, const int len)
{
	bool result = false;
	CardNumberSum *cnsArr = NULL;
	try
	{
		if (NULL != cards && len >= 6 && len % 2 == 0)
		{
			int cnsArrLen = len / 2;
			cnsArr = new CardNumberSum[cnsArrLen];
			bool isOK = FindCardNumberCount(cards, len, cnsArr, cnsArrLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr, cnsArrLen);
				bool isStraight = true;
				for (int i = 0; i < cnsArrLen - 1; ++i)
				{
					if (cnsArr[i].count != 2 || cnsArr[i].num == CardNumber::C_2
						|| cnsArr[i].num == CardNumber::C_BJ
						|| cnsArr[i].num == CardNumber::C_RJ
						|| cnsArr[i].num + 1 != cnsArr[i + 1].num)
					{
						isStraight = false;
						break;
					}
				}
				result = isStraight;
			}
			if (NULL != cnsArr)
			{
				delete[] cnsArr;
			}
		}
	}
	catch (exception err)
	{
		if (NULL != cnsArr)
		{
			delete[] cnsArr;
		}
		throw(err);
	}
	return result;
}

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
/*============================ 判断牌型 end ================================*/



/*============================ 比较牌型 begin ================================*/
int DouDiZhu::DouDiZhuLogic::CompareSingle(const int card1, const int card2)
{
	int result = -1;
	try
	{
		result = PokerLogic::CompareValue(card1, card2);
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::ComparePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len == 2)
		{
			int cmpVal1 = PokerLogic::CompareValue(cards1[0], cards1[1]);
			int cmpVal2 = PokerLogic::CompareValue(cards2[0], cards2[1]);
			if (cmpVal1 == cmpVal2 && cmpVal1 == 0)
			{
				result = PokerLogic::CompareValue(cards1[0], cards2[0]);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareThree(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len == 3)
		{
			bool isOK = IsAllSame(cards1, 3);
			if (isOK)
			{
				isOK = IsAllSame(cards2, 3);
				if (isOK)
				{
					result = PokerLogic::CompareValue(cards1[0], cards2[0]);
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

int DouDiZhu::DouDiZhuLogic::CompareFour(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len == 4)
		{
			bool isOK = IsAllSame(cards1, 4);
			if (isOK)
			{
				isOK = IsAllSame(cards2, 4);
				if (isOK)
				{
					result = PokerLogic::CompareValue(cards1[0], cards2[0]);
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

int DouDiZhu::DouDiZhuLogic::CompareThreeSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len == 4)
		{
			result = CompareSameArray(cards1, cards1Len, cards2, cards2Len, 2, 3);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}



int DouDiZhu::DouDiZhuLogic::CompareThreePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len == 5)
		{
			result = CompareSameArray(cards1, cards1Len, cards2, cards2Len, 2, 3);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareFourSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len == 6)
		{
			result = CompareSameArray(cards1, cards1Len, cards2, cards2Len, 3, 4);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareFourPair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len == 8)
		{
			result = CompareSameArray(cards1, cards1Len, cards2, cards2Len, 3, 4);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::ComparePlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 6 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 2, 2, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::ComparePlaneSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 8 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 4, 2, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::ComparePlanePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 10 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 4, 2, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareThreePlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 9 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 3, 3, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareThreePlaneSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 12 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 6, 3, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareThreePlanePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 15 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 6, 3, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareFourPlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 12 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 4, 4, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareFourPlaneSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 16 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 8, 4, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareFourPlanePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 20 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 8, 4, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareFivePlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 15 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 5, 5, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareFivePlaneSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 20 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 10, 5, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareSixPlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len == 18 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, 6, 6, 3);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareStraightSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len >= 5 && cards1Len == cards2Len)
		{
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, cards1Len, cards1Len, 1);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int DouDiZhu::DouDiZhuLogic::CompareStraightPair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len)
{
	int result = -1;
	try
	{
		if (cards1Len >= 6 && cards1Len == cards2Len)
		{
			int adjacentCount = cards1Len / 2;
			result = CompareAdjacentPoker(cards1, cards1Len, cards2, cards2Len, adjacentCount, adjacentCount, 2);
		}
		else
		{
			throw("length is error");
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

/*============================ 比较牌型 end ================================*/







/*=======================以下为私有方法=======================*/

bool DouDiZhu::DouDiZhuLogic::IsAllSame(const int *cards, const int len)
{
	bool result = false;
	try
	{
		if (NULL != cards && len > 1)
		{
			for (int i = 0; i < len - 1; ++i)
			{
				int cpVal = PokerLogic::CompareValue(cards[i], cards[i + 1]);
				if (cpVal != 0)
				{
					return false;
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

bool DouDiZhu::DouDiZhuLogic::FindCardNumberCount(const int *cards, const int cardsLen, CardNumberSum *cnsArr, const int arrLen)
{
	bool result = false;
	CardNumber *cardNums = NULL;
	try
	{
		if (NULL != cards && cardsLen > 0 && cardsLen >= arrLen)
		{
			cardNums = new CardNumber[cardsLen];
			bool isOK = PokerLogic::ValueToCardNumber(cards, cardsLen, cardNums, cardsLen);
			if (isOK)
			{
				int idx = 0;
				result = true;
				for (int i = 0; i < cardsLen; ++i)
				{
					bool isFind = IsExistCardNumber(cnsArr, idx, cardNums[i]);
					if (!isFind)
					{
						if (idx >= arrLen)
						{
							result = false;
							break;
						}
						cnsArr[idx].num = cardNums[i];
						cnsArr[idx].count = PokerLogic::FindCount(cardNums, cardsLen, cardNums[i]);
						idx++;
					}
				}
			}
			if (NULL != cardNums)
			{
				delete[] cardNums;
			}
		}
	}
	catch (exception err)
	{
		if (NULL != cardNums)
		{
			delete[] cardNums;
		}
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsExistCardNumber(const CardNumberSum *cnsArr, const int cnsArrLen, const CardNumber cardNum)
{
	bool result = false;
	try
	{
		if (NULL != cnsArr && cnsArrLen > 0)
		{
			for (int i = 0; i < cnsArrLen; ++i)
			{
				//如果双王，找的也是王，找到任何一个王则返回表示存在
				if (
					((cnsArr[i].num == CardNumber::C_BJ || cnsArr[i].num == CardNumber::C_RJ)
					&& 
					(cardNum == CardNumber::C_BJ || cardNum == CardNumber::C_RJ) 
					&& cnsArr[i].count == 2)
					||
					(cnsArr[i].num == cardNum))
				{
					result = true;
					break;
				}
				//if (cnsArr[i].num == cardNum)
				//{
				//	result = true;
				//	break;
				//}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsXPlane(const CardNumberSum *cardNums, const int cardNumsLen, const int index, const int planeCount)
{
	bool result = false;
	try
	{
		//cardNums必须从小到大排序，否则无法准确查找
		if (NULL != cardNums && cardNumsLen >= 2)
		{
			if (index + 1 < cardNumsLen && cardNums[index].count >= 3)
			{
				int count = planeCount - 1;
				int cmpCard = PokerLogic::CardNumberToWeightValue(cardNums[index].num);
				for (int i = index + 1; i < cardNumsLen; ++i)
				{
					int curWeight = PokerLogic::CardNumberToWeightValue(cardNums[i].num);
					if (cmpCard + 1 == curWeight && cardNums[i].count >= 3 && cardNums[i].num != CardNumber::C_2)
					{
						cmpCard = curWeight;
						count--;
						if (count == 0)
						{
							result = true;
							break;
						}
					}
					else
					{
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

void DouDiZhu::DouDiZhuLogic::SortCardNumberSum(CardNumberSum *cnsArr, const int cnsArrLen)
{
	try
	{
		if (NULL != cnsArr && cnsArrLen > 0)
		{
			for (int i = 0; i < cnsArrLen; ++i)
			{
				for (int j = 0; j < cnsArrLen - 1; ++j)
				{
					int cmp1 = PokerLogic::CardNumberToWeightValue(cnsArr[j].num);
					int cmp2 = PokerLogic::CardNumberToWeightValue(cnsArr[j + 1].num);
					if (cmp1 > cmp2)
					{
						CardNumberSum tmp = cnsArr[j];
						cnsArr[j] = cnsArr[j + 1];
						cnsArr[j + 1] = tmp;
					}
				}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
}

bool DouDiZhu::DouDiZhuLogic::SetArrayTrue(bool *arr, const int arrLen, const int count)
{
	bool result = false;
	try
	{
		if (NULL != arr && arrLen > 0)
		{
			int setCount = count;
			for (int i = 0; i < count; ++i)
			{
				for (int j = 0; j < arrLen; ++j)
				{
					if (!arr[j])
					{
						arr[j] = true;
						setCount--;
						break;
					}
				}
			}
			if (setCount == 0)
			{
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

bool DouDiZhu::DouDiZhuLogic::IsArrayTrue(const bool *arr, const int arrLen)
{
	bool result = false;
	try
	{
		if (NULL != arr && arrLen > 0)
		{
			bool isOK = true;
			for (int i = 0; i < arrLen; ++i)
			{
				if (!arr[i])
				{
					isOK = false;
					break;
				}
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

/*比较的私有方法*/

int DouDiZhu::DouDiZhuLogic::CompareSameArray(const int *cards1, const int cards1Len, 
											const int *cards2, const int cards2Len,
											const int cnsLen, const int sameCount)
{
	int result = -1;
	CardNumberSum *cnsArr1 = NULL;
	CardNumberSum *cnsArr2 = NULL;

	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len >= sameCount)
		{
			cnsArr1 = new CardNumberSum[cnsLen];
			bool isOK = FindCardNumberCount(cards1, cards1Len, cnsArr1, cnsLen);
			if (isOK)
			{
				CardNumber num1, num2;
				bool isFindNum = GetCardNumberByCardNumberSum(cnsArr1, cnsLen, sameCount, &num1);
				cnsArr2 = new CardNumberSum[cnsLen];
				isOK = FindCardNumberCount(cards2, cards1Len, cnsArr2, cnsLen);
				if (isOK && isFindNum)
				{
					isFindNum = GetCardNumberByCardNumberSum(cnsArr2, cnsLen, sameCount, &num2);
					if (isFindNum)
					{
						result = PokerLogic::CompareCardNumber(num1, num2);
					}
				}
			}
			if (NULL != cnsArr1)
			{
				delete[] cnsArr1;
			}
			if (NULL != cnsArr2)
			{
				delete[] cnsArr2;
			}
		}
	}
	catch (exception err)
	{
		if (NULL != cnsArr1)
		{
			delete[] cnsArr1;
		}
		if (NULL != cnsArr2)
		{
			delete[] cnsArr2;
		}
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::GetCardNumberByCardNumberSum(const CardNumberSum *cnsArr, const int cnsArrLen, const int findCount, CardNumber *outCardNum)
{
	bool result = false;
	try
	{
		if (NULL != cnsArr && cnsArrLen > 0)
		{
			int maxNum = -1;
			for (int i = 0; i < cnsArrLen; ++i)
			{
				if (cnsArr[i].count >= findCount)
				{
					if (maxNum != -1)
					{
						int cmp = PokerLogic::CompareCardNumber(cnsArr[i].num, (CardNumber)maxNum);
						if (cmp == 1)
						{
							maxNum = cnsArr[i].num;
						}
					}
					else
					{
						maxNum = cnsArr[i].num;
						result = true;
					}
				}
			}
			if (result)
			{
				*outCardNum = (CardNumber)maxNum;
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
比较相邻的扑克牌大小
cards1:第一组扑克牌
cards1Len:第一组扑克牌长度
cards2:第二组扑克牌
cards2Len:第二组扑克牌长度
cnsLen:不同牌数组长度
adjacentCount:相邻扑克的数量
sameCount:相同牌的数量
return:第一组 > 第二组，返回1；第一组 < 第二组，返回-1；第一组 = 第二组，返回0
*/
int DouDiZhu::DouDiZhuLogic::CompareAdjacentPoker(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len, const int cnsLen, const int adjacentCount, const int sameCount)
{
	int result = -1;
	CardNumberSum *cnsArr1 = NULL;
	CardNumberSum *cnsArr2 = NULL;
	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len >= adjacentCount * sameCount)
		{
			CardNumber cmp1, cmp2;
			cnsArr1 = new CardNumberSum[cnsLen];
			bool isOK = FindCardNumberCount(cards1, cards1Len, cnsArr1, cnsLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr1, cnsLen);
				bool isFind = GetMaxCompareNumberByAdjacent(cnsArr1, cnsLen, adjacentCount, sameCount, &cmp1);
				cnsArr2 = new CardNumberSum[cnsLen];
				isOK = FindCardNumberCount(cards2, cards2Len, cnsArr2, cnsLen);
				if (isOK && isFind)
				{
					SortCardNumberSum(cnsArr2, cnsLen);
					isFind = GetMaxCompareNumberByAdjacent(cnsArr2, cnsLen, adjacentCount, sameCount, &cmp2);
					if (isFind)
					{
						result = PokerLogic::CompareCardNumber(cmp1, cmp2);
					}
				}
			}
			if (NULL != cnsArr1)
			{
				delete[] cnsArr1;
			}
			if (NULL != cnsArr2)
			{
				delete[] cnsArr2;
			}
		}
	}
	catch (exception err)
	{
		if (NULL != cnsArr1)
		{
			delete[] cnsArr1;
		}
		if (NULL != cnsArr2)
		{
			delete[] cnsArr2;
		}
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::GetMaxCompareNumberByAdjacent(const CardNumberSum *cnsArr, const int cnsArrLen, const int adjacentCount, const int sameCount, CardNumber *outCardNum)
{
	bool result = false;
	try
	{
		if (NULL != cnsArr && cnsArrLen > 0 && cnsArrLen >= adjacentCount)
		{
			int maxNum = -1;
			for (int i = 0; i < cnsArrLen; ++i)
			{
				if (IsAdjacent(cnsArr, cnsArrLen, i, adjacentCount, sameCount))
				{
					if (maxNum != -1)
					{
						int cmp = PokerLogic::CompareCardNumber(cnsArr[i].num, (CardNumber)maxNum);
						if (cmp == 1)
						{
							maxNum = cnsArr[i].num;
						}
					}
					else
					{
						maxNum = cnsArr[i].num;
						result = true;
					}
				}
			}
			if (result)
			{
				*outCardNum = (CardNumber)maxNum;
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsAdjacent(const CardNumberSum *cnsArr, const int cnsArrLen, const int index, const int adjacentCount, const int sameCount)
{
	bool result = false;
	try
	{
		//cardNums必须从小到大排序，否则无法准确查找
		if (NULL != cnsArr && cnsArrLen > 0 && cnsArrLen >= adjacentCount)
		{
			if (index + 1 < cnsArrLen && cnsArr[index].count >= sameCount)
			{
				int count = adjacentCount - 1;
				int cmpCard = PokerLogic::CardNumberToWeightValue(cnsArr[index].num);
				for (int i = index + 1; i < cnsArrLen; ++i)
				{
					int curWeight = PokerLogic::CardNumberToWeightValue(cnsArr[i].num);
					if (cmpCard + 1 == curWeight && cnsArr[i].count >= sameCount 
						&& cnsArr[i].num != CardNumber::C_2 
						&& cnsArr[i].num != CardNumber::C_BJ
						&& cnsArr[i].num != CardNumber::C_RJ)
					{
						cmpCard = curWeight;
						count--;
						if (count == 0)
						{
							result = true;
							break;
						}
					}
					else
					{
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