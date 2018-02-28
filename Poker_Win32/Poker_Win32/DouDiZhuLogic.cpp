#include "DouDiZhuLogic.h"

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
			CardNumber threeNum;
			result = IsSame(cards, len, 3, threeNum);
			if (result)
			{

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
	try
	{
		if (NULL != cards && len >= sameCount && sameCount > 1)
		{
			for (int i = 0; i < len; ++i)
			{
				int sameSign = 1;
				for (int j = 0; j < len; ++j)
				{
					if (i != j)
					{
						int cpVal = PokerLogic::CompareValue(cards[i], cards[j]);
						if (cpVal == 0)
						{
							sameSign++;
							if (sameSign == sameCount)
							{
								CardMark mark;
								PokerLogic::ValueToCard(cards[i], mark, sameNumber);
								return true;
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