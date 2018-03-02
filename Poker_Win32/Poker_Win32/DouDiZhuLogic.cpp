#include "DouDiZhuLogic.h"
#include <vector>

DouDiZhu::DouDiZhuLogic::DouDiZhuLogic() : PokerLogic(14,15,3,4,5,6,7,8,9,10,11,12,13,82,83)
{
	
}

DouDiZhu::DouDiZhuLogic::~DouDiZhuLogic()
{

}

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
		if (len == 4)
		{
			bool isSameFour = IsFour(cards, len);
			if (!isSameFour)
			{
				CardNumber num;
				result = IsSame(cards, len, 3, num);
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
			CardNumber numArr[arrLen];
			int sumArr[arrLen];
			bool isOK = FindNumberCount(cards, len, numArr, sumArr, arrLen);
			if (isOK)
			{
				if (sumArr[0] + sumArr[1] == 5
					&& 
					((sumArr[0] == 3 || sumArr[2] == 2) || (sumArr[0] == 2 || sumArr[2] == 3)))
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
			CardNumber num;
			result = IsSame(cards, len, 4, num);
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
			CardNumber numArr[arrLen];
			int sumArr[arrLen];
			bool isOK = FindNumberCount(cards, len, numArr, sumArr, arrLen);
			if (isOK)
			{
				bool isFour = false;
				bool isPair1 = false;
				bool isPair2 = false;
				for (int i = 0; i < arrLen; ++i)
				{
					if (sumArr[i] == 4)
					{
						if (isFour)
						{
							isPair1 = true;
							isPair2 = true;
							break;
						}
						isFour = true;
					}
					else if (sumArr[i] == 2)
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
		const int arrLen = 2;
		CardNumberSum cnsArr[arrLen];
		bool isOK = FindNumberCount(cards, len, cnsArr, arrLen);
		if (isOK)
		{
			//sort cnsArr
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
		const int arrLen = 4;
		CardNumberSum cnsArr[arrLen];
		bool isOK = FindNumberCount(cards, len, cnsArr, arrLen);
		if (isOK)
		{
			//sort cnsArr
			SortCardNumberSum(cnsArr, arrLen);
			bool isPlane = false;
			bool isSingle1 = false;
			bool isSingle2 = false;
			for (int i = 0; i < arrLen; ++i)
			{
				isOK = IsXPlane(cnsArr, arrLen, i, 2);
				if (isOK)
				{
					result = true;
				}
				else
				{
					if (cnsArr[i].count == 1)
					{
						if (isSingle2)//已出现2个单，再出现单直接退出不是飞机带2单
						{
							isPlane = false;
							break;
						}
						if (isSingle1)
						{
							isSingle2 = true;
						}
						else
						{
							isSingle1 = true;
						}
					}
					else if (cnsArr[i].count == 2)
					{
						if (isSingle2)//已出现2个单，再出现双直接退出不是飞机带2单
						{
							isPlane = false;
							break;
						}
						isSingle1 = true;
						isSingle2 = true;
					}
					else if (arrLen - (i + 1) < 2)
					{
						isPlane = false;
						break;
					}
				}
			}
			if (isPlane && isSingle1 && isSingle2)
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

bool DouDiZhu::DouDiZhuLogic::IsPlanePair(const int *cards, const int len)
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

bool DouDiZhu::DouDiZhuLogic::IsThreePlane(const int *cards, const int len)
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

bool DouDiZhu::DouDiZhuLogic::IsThreePlaneSingle(const int *cards, const int len)
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

bool DouDiZhu::DouDiZhuLogic::IsThreePlanePair(const int *cards, const int len)
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

bool DouDiZhu::DouDiZhuLogic::IsFourPlane(const int *cards, const int len)
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

bool DouDiZhu::DouDiZhuLogic::IsFourPlaneSingle(const int *cards, const int len)
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

bool DouDiZhu::DouDiZhuLogic::IsStraightSingle(const int *cards, const int len)
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

bool DouDiZhu::DouDiZhuLogic::IsStraightPair(const int *cards, const int len)
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

bool DouDiZhu::DouDiZhuLogic::IsKingBomb(const int *cards, const int len)
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







/*以下为私有方法*/

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

bool DouDiZhu::DouDiZhuLogic::IsSame(const int *cards, const int len, const int sameCount, CardNumber &sameNumber)
{
	bool result = false;
	CardNumber *cardNums = NULL;
	try
	{
		if (NULL != cards && len >= sameCount && sameCount > 1)
		{
			cardNums = new CardNumber[len];
			bool isOK = PokerLogic::ValueToCardNumber(cards, len, cardNums, len);
			if (isOK)
			{
				for (int i = 0; i < len; ++i)
				{
					int count = PokerLogic::FindCount(cardNums, len, cardNums[i]);
					if (count == sameCount)
					{
						result = true;
						sameNumber = cardNums[i];
						break;
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

bool DouDiZhu::DouDiZhuLogic::FindNumberCount(const int *cards, const int cardsLen, CardNumberSum *cnsArr, const int arrLen)
{
	bool result = false;
	try
	{
		CardNumber *numArr = new CardNumber[arrLen];
		int *sumArr = new int[arrLen];
		result = FindNumberCount(cards, cardsLen, numArr, sumArr, arrLen);
		if (result)
		{
			for (int i = 0; i < arrLen; ++i)
			{
				cnsArr[i].num = numArr[i];
				cnsArr[i].count = sumArr[i];
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::FindNumberCount(const int *cards, const int cardsLen, CardNumber *numArr, int *sumArr, const int arrLen)
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
					bool isFind = PokerLogic::IsFindValue((int*)numArr, idx, (int)cardNums[i]);
					if (!isFind)
					{
						if (idx >= arrLen)
						{
							result = false;
							break;
						}
						numArr[idx] = cardNums[i];
						sumArr[idx] = PokerLogic::FindCount(cardNums, cardsLen, cardNums[i]);
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
				int count = planeCount;
				int cmpCard = cardNums[index].num;
				for (int i = index + 1; i < cardNumsLen; ++i)
				{
					if (cmpCard + 1 == cardNums[i].num && cardNums[i].count == 3 && cardNums[i].num != CardNumber::C_2)
					{
						cmpCard = cardNums[i].num;
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
					if (cnsArr[j].num > cnsArr[j + 1].num)
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
