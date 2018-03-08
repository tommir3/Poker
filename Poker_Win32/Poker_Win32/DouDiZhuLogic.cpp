#include "DouDiZhuLogic.h"

DouDiZhu::DouDiZhuLogic::DouDiZhuLogic() : PokerLogic(14,15,3,4,5,6,7,8,9,10,11,12,13,82,83)
{

}

DouDiZhu::DouDiZhuLogic::~DouDiZhuLogic()
{

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
		result = CompareXPlane(cards1, cards1Len, cards2, cards2Len, 2, 2);
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
		result = CompareXPlane(cards1, cards1Len, cards2, cards2Len, 4, 2);
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
		result = CompareXPlane(cards1, cards1Len, cards2, cards2Len, 4, 2);
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
		result = CompareXPlane(cards1, cards1Len, cards2, cards2Len, 3, 3);
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
				if (cnsArr[i].num == cardNum)
				{
					result = true;
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

int DouDiZhu::DouDiZhuLogic::CompareXPlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len, const int cnsLen, const int planeCount)
{
	int result = -1;
	CardNumberSum *cnsArr1 = NULL;
	CardNumberSum *cnsArr2 = NULL;
	try
	{
		if (NULL != cards1 && NULL != cards2 && cards1Len == cards2Len && cards1Len >= planeCount * 3)
		{
			CardNumber cmp1, cmp2;
			cnsArr1 = new CardNumberSum[cnsLen];
			bool isOK = FindCardNumberCount(cards1, cards1Len, cnsArr1, cnsLen);
			if (isOK)
			{
				SortCardNumberSum(cnsArr1, cnsLen);
				bool isFind = GetCardNumberByXPlane(cnsArr1, cnsLen, planeCount, &cmp1);
				cnsArr2 = new CardNumberSum[cnsLen];
				isOK = FindCardNumberCount(cards2, cards2Len, cnsArr2, cnsLen);
				if (isOK && isFind)
				{
					SortCardNumberSum(cnsArr2, cnsLen);
					isFind = GetCardNumberByXPlane(cnsArr2, cnsLen, planeCount, &cmp2);
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

bool DouDiZhu::DouDiZhuLogic::GetCardNumberByXPlane(const CardNumberSum *cnsArr, const int cnsArrLen, const int planeCount, CardNumber *outCardNum)
{
	bool result = false;
	try
	{
		if (NULL != cnsArr && cnsArrLen >= planeCount)
		{
			int maxNum = -1;
			for (int i = 0; i < cnsArrLen; ++i)
			{
				if (IsXPlane(cnsArr, cnsArrLen,i,planeCount))
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