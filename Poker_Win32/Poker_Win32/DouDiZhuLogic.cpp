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
					bool isFind = PokerLogic::IsFindValue(numArr, idx, cardNums[i]);
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
