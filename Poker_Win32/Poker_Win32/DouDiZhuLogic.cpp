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
			if (IsKingBomb(cards, len))//�����˫�����ж���ը����
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
			if (IsFour(cards, len))//�����ը���������ж�ը����������
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
		else if (len == 8)//����������п��� 33334444
		{
			if (IsFourPair(cards, len))//���� �Ĵ�����
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
		else if (len == 12)//����������п��� 333444555666
		{
			if (IsFourPlane(cards, len))//4���ɻ��ж�����
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
		else if (len == 20)//����������п��� 33344455566677778888 (����ֻ�е�������һ���ͼ���)
		{
			if (IsFivePlaneSingle(cards, len))//�����ж�5�ɻ���5��
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

/*============================ �ж����� begin ================================*/
bool DouDiZhu::DouDiZhuLogic::IsPair(const int *cards, const int len)
{
	bool result = false;
	try
	{
		int adjacentCount = 1;
		int sameCount = 2;
		int subsidiaryCount = 0;
		int subsidiarySameCount = 0;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 2)
		//{
		//	result = IsAllSame(cards, 2);
		//}
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
		int adjacentCount = 1;
		int sameCount = 3;
		int subsidiaryCount = 0;
		int subsidiarySameCount = 0;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 3)
		//{
		//	result = IsAllSame(cards, 3);
		//}
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
		int adjacentCount = 1;
		int sameCount = 4;
		int subsidiaryCount = 0;
		int subsidiarySameCount = 0;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 4)
		//{
		//	result = IsAllSame(cards, 4);
		//}
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
		int adjacentCount = 1;
		int sameCount = 3;
		int subsidiaryCount = 1;
		int subsidiarySameCount = 1;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 4)
		//{
		//	const int arrLen = 2;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		if (cnsArr[0].count == 3 || cnsArr[1].count == 3)
		//		{
		//			result = true;
		//		}
		//	}
		//}
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
		int adjacentCount = 1;
		int sameCount = 3;
		int subsidiaryCount = 1;
		int subsidiarySameCount = 2;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 5)
		//{
		//	const int arrLen = 2;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		if (cnsArr[0].count + cnsArr[1].count == 5
		//			&& 
		//			((cnsArr[0].count == 3 || cnsArr[2].count == 2) || (cnsArr[0].count == 2 || cnsArr[2].count == 3)))
		//		{
		//			result = true;
		//		}
		//	}
		//}
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
		int adjacentCount = 1;
		int sameCount = 4;
		int subsidiaryCount = 2;
		int subsidiarySameCount = 1;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 6)
		//{
		//	const int arrLen = 3;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		for (int i = 0; i < arrLen; ++i)
		//		{
		//			if (cnsArr[i].count == 4)
		//			{
		//				result = true;
		//				break;
		//			}
		//		}
		//	}
		//}
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
		int adjacentCount = 1;
		int sameCount = 4;
		int subsidiaryCount = 2;
		int subsidiarySameCount = 2;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 8)
		//{
		//	const int arrLen = 3;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		bool isFour = false;
		//		bool isPair1 = false;
		//		bool isPair2 = false;
		//		for (int i = 0; i < arrLen; ++i)
		//		{
		//			if (cnsArr[i].count == 1)
		//			{
		//				isFour = false;
		//				break;
		//			}
		//			else if (cnsArr[i].count == 4)
		//			{
		//				if (isFour)
		//				{
		//					isPair1 = true;
		//					isPair2 = true;
		//					break;
		//				}
		//				isFour = true;
		//			}
		//			else if (cnsArr[i].count == 2)
		//			{
		//				if (isPair1)
		//				{
		//					isPair2 = true;
		//				}
		//				else
		//				{
		//					isPair1 = true;
		//				}
		//			}
		//		}
		//		if (isFour && isPair1 && isPair2)
		//		{
		//			result = true;
		//		}
		//	}
		//}
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
		int adjacentCount = 2;
		int sameCount = 3;
		int subsidiaryCount = 0;
		int subsidiarySameCount = 0;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 6)
		//{
		//	const int arrLen = 2;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		for (int i = 0; i < arrLen; ++i)
		//		{
		//			isOK = IsXPlane(cnsArr, arrLen, 0, 2);
		//			if (isOK)
		//			{
		//				result = true;
		//			}
		//		}
		//	}
		//}
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
		int adjacentCount = 2;
		int sameCount = 3;
		int subsidiaryCount = 2;
		int subsidiarySameCount = 1;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 8)
		//{
		//	const int arrLen = 4;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		for (int i = 0; i < arrLen; ++i)
		//		{
		//			isOK = IsXPlane(cnsArr, arrLen, i, 2);
		//			if (isOK)
		//			{
		//				result = true;
		//				break;
		//			}
		//		}
		//	}
		//}
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
		int adjacentCount = 2;
		int sameCount = 3;
		int subsidiaryCount = 2;
		int subsidiarySameCount = 2;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 10)
		//{
		//	const int arrLen = 4;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		bool isPlane = false;
		//		bool arrIsPair[2] = { false,false };
		//		for (int i = 0; i < arrLen; )
		//		{
		//			isOK = IsXPlane(cnsArr, arrLen, i, 2);
		//			if (isOK)
		//			{
		//				isPlane = true;
		//				i += 2;
		//			}
		//			else
		//			{
		//				if (cnsArr[i].count == 1)
		//				{
		//					isPlane = false;
		//					break;
		//				}
		//				else if (cnsArr[i].count == 2 || cnsArr[i].count == 4)
		//				{
		//					int tmpCount = cnsArr[i].count / 2;
		//					isOK = SetArrayTrue(arrIsPair, 2, tmpCount);
		//					if (!isOK)
		//					{
		//						isPlane = false;
		//						break;
		//					}
		//				}
		//				++i;
		//			}
		//		}
		//		if (isPlane)
		//		{
		//			bool isPairOk = IsArrayTrue(arrIsPair, 2);
		//			if (isPairOk)
		//			{
		//				result = true;
		//			}
		//		}
		//	}
		//}
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
		int adjacentCount = 3;
		int sameCount = 3;
		int subsidiaryCount = 0;
		int subsidiarySameCount = 0;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 9)
		//{
		//	const int arrLen = 3;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		result = IsXPlane(cnsArr, arrLen, 0, 3);
		//	}
		//}
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
		int adjacentCount = 3;
		int sameCount = 3;
		int subsidiaryCount = 3;
		int subsidiarySameCount = 1;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 12)
		//{
		//	const int arrLen = 6;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		for (int i = 0; i < arrLen; ++i)
		//		{
		//			isOK = IsXPlane(cnsArr, arrLen, i, 3);
		//			if (isOK)
		//			{
		//				result = true;
		//				break;
		//			}
		//		}
		//	}
		//}
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
		int adjacentCount = 3;
		int sameCount = 3;
		int subsidiaryCount = 3;
		int subsidiarySameCount = 2;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 15)
		//{
		//	const int arrLen = 6;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		bool isPlane = false;
		//		bool arrIsPair[3] = { false,false,false };
		//		for (int i = 0; i < arrLen; )
		//		{
		//			isOK = IsXPlane(cnsArr, arrLen, i, 3);
		//			if (isOK)
		//			{
		//				isPlane = true;
		//				i += 3;
		//			}
		//			else
		//			{
		//				if (cnsArr[i].count == 1)
		//				{
		//					isPlane = false;
		//					break;
		//				}
		//				else if (cnsArr[i].count == 2 || cnsArr[i].count == 4)
		//				{
		//					int tmpCount = cnsArr[i].count / 2;
		//					isOK = SetArrayTrue(arrIsPair, 3, tmpCount);
		//					if (!isOK)
		//					{
		//						isPlane = false;
		//						break;
		//					}
		//				}
		//				++i;
		//			}
		//		}
		//		if (isPlane)
		//		{
		//			bool isPairOk = IsArrayTrue(arrIsPair, 3);
		//			if (isPairOk)
		//			{
		//				result = true;
		//			}
		//		}
		//	}
		//}
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
		int adjacentCount = 4;
		int sameCount = 3;
		int subsidiaryCount = 0;
		int subsidiarySameCount = 0;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 12)
		//{
		//	const int arrLen = 4;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		result = IsXPlane(cnsArr, arrLen, 0, 4);
		//	}
		//}
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
		int adjacentCount = 4;
		int sameCount = 3;
		int subsidiaryCount = 4;
		int subsidiarySameCount = 1;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 16)
		//{
		//	const int arrLen = 8;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		for (int i = 0; i < arrLen; ++i)
		//		{
		//			isOK = IsXPlane(cnsArr, arrLen, i, 4);
		//			if (isOK)
		//			{
		//				result = true;
		//				break;
		//			}
		//		}
		//	}
		//}
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
		int adjacentCount = 4;
		int sameCount = 3;
		int subsidiaryCount = 4;
		int subsidiarySameCount = 2;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 20)
		//{
		//	const int arrLen = 8;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		bool isPlane = false;
		//		bool arrIsPair[4] = { false,false,false,false };
		//		for (int i = 0; i < arrLen; )
		//		{
		//			isOK = IsXPlane(cnsArr, arrLen, i, 4);
		//			if (isOK)
		//			{
		//				isPlane = true;
		//				i += 4;
		//			}
		//			else
		//			{
		//				if (cnsArr[i].count == 1)
		//				{
		//					isPlane = false;
		//					break;
		//				}
		//				else if (cnsArr[i].count == 2 || cnsArr[i].count == 4)
		//				{
		//					int tmpCount = cnsArr[i].count / 2;
		//					isOK = SetArrayTrue(arrIsPair, 4, tmpCount);
		//					if (!isOK)
		//					{
		//						isPlane = false;
		//						break;
		//					}
		//				}
		//				++i;
		//			}
		//		}
		//		if (isPlane)
		//		{
		//			bool isPairOk = IsArrayTrue(arrIsPair, 4);
		//			if (isPairOk)
		//			{
		//				result = true;
		//			}
		//		}
		//	}
		//}
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
		int adjacentCount = 5;
		int sameCount = 3;
		int subsidiaryCount = 0;
		int subsidiarySameCount = 0;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 15)
		//{
		//	const int arrLen = 5;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		result = IsXPlane(cnsArr, arrLen, 0, 5);
		//	}
		//}
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
		int adjacentCount = 5;
		int sameCount = 3;
		int subsidiaryCount = 5;
		int subsidiarySameCount = 1;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 20)
		//{
		//	const int arrLen = 10;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		for (int i = 0; i < arrLen; ++i)
		//		{
		//			isOK = IsXPlane(cnsArr, arrLen, i, 5);
		//			if (isOK)
		//			{
		//				result = true;
		//				break;
		//			}
		//		}
		//	}
		//}
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
		int adjacentCount = 6;
		int sameCount = 3;
		int subsidiaryCount = 0;
		int subsidiarySameCount = 0;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len == 18)
		//{
		//	const int arrLen = 6;
		//	CardNumberSum cnsArr[arrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, arrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, arrLen);
		//		result = IsXPlane(cnsArr, arrLen, 0, 6);
		//	}
		//}
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
	/*CardNumberSum *cnsArr = NULL;*/
	try
	{
		int adjacentCount = len;
		int sameCount = 1;
		int subsidiaryCount = 0;
		int subsidiarySameCount = 0;
		result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		//if (NULL != cards && len >= 5)
		//{
		//	cnsArr = new CardNumberSum[len];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, len);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, len);
		//		bool isStraight = true;
		//		for (int i = 0; i < len - 1; ++i)
		//		{
		//			if (cnsArr[i].count != 1 || cnsArr[i].num == CardNumber::C_2 
		//				|| cnsArr[i].num == CardNumber::C_BJ 
		//				|| cnsArr[i].num == CardNumber::C_RJ
		//				|| cnsArr[i].num + 1 != cnsArr[i + 1].num)
		//			{
		//				isStraight = false;
		//				break;
		//			}
		//		}
		//		result = isStraight;
		//	}
		//	if (NULL != cnsArr)
		//	{
		//		delete[] cnsArr;
		//	}
		//}
	}
	catch (exception err)
	{
		/*if (NULL != cnsArr)
		{
			delete[] cnsArr;
		}*/
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuLogic::IsStraightPair(const int *cards, const int len)
{
	bool result = false;
	/*CardNumberSum *cnsArr = NULL;*/
	try
	{
		if (len % 2 == 0)
		{
			int adjacentCount = len / 2;
			int sameCount = 2;
			int subsidiaryCount = 0;
			int subsidiarySameCount = 0;
			result = IsTrueCardType(cards, len, adjacentCount, sameCount, subsidiaryCount, subsidiarySameCount);
		}

		//if (NULL != cards && len >= 6 && len % 2 == 0)
		//{
		//	int cnsArrLen = len / 2;
		//	cnsArr = new CardNumberSum[cnsArrLen];
		//	bool isOK = FindCardNumberCount(cards, len, cnsArr, cnsArrLen);
		//	if (isOK)
		//	{
		//		SortCardNumberSum(cnsArr, cnsArrLen);
		//		bool isStraight = true;
		//		for (int i = 0; i < cnsArrLen - 1; ++i)
		//		{
		//			if (cnsArr[i].count != 2 || cnsArr[i].num == CardNumber::C_2
		//				|| cnsArr[i].num == CardNumber::C_BJ
		//				|| cnsArr[i].num == CardNumber::C_RJ
		//				|| cnsArr[i].num + 1 != cnsArr[i + 1].num)
		//			{
		//				isStraight = false;
		//				break;
		//			}
		//		}
		//		result = isStraight;
		//	}
		//	if (NULL != cnsArr)
		//	{
		//		delete[] cnsArr;
		//	}
		//}
	}
	catch (exception err)
	{
		//if (NULL != cnsArr)
		//{
		//	delete[] cnsArr;
		//}
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
/*============================ �ж����� end ================================*/



/*============================ �Ƚ����� begin ================================*/
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

/*============================ �Ƚ����� end ================================*/

/*============================ ͨ�÷��� begin ================================*/

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
				if (AdjacentCount > 0)//����������
				{
					if (i + AdjacentCount < CardSortCount)
					{
						bool isAdjacent = true;
						for (int j = i; j < i + AdjacentCount; ++j)
						{
							if (sortArr[j] != MainCardSum)
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
				else//ֱ������
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



/*============================ ͨ�÷��� end ================================*/




/*=======================����Ϊ˽�з���=======================*/

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
				//�ҵ������ͣ�Ȼ��ȥ��
				for (int i = 0; i < CardSortCount; ++i)
				{
					if (adjacentCount > 1)//��������
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
					else//��ͬ����
					{
						if (sortArray[i] >= sameCount)
						{
							sortArray[i] -= sameCount;
							break;
						}
					}
				}
				//ȥ���������ƺ���ȥ���������ͣ����ж�
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
				//���˫�����ҵ�Ҳ�������ҵ��κ�һ�����򷵻ر�ʾ����
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
		//cardNums�����С�������򣬷����޷�׼ȷ����
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

/*�Ƚϵ�˽�з���*/

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
�Ƚ����ڵ��˿��ƴ�С
cards1:��һ���˿���
cards1Len:��һ���˿��Ƴ���
cards2:�ڶ����˿���
cards2Len:�ڶ����˿��Ƴ���
cnsLen:��ͬ�����鳤��
adjacentCount:�����˿˵�����
sameCount:��ͬ�Ƶ�����
return:��һ�� > �ڶ��飬����1����һ�� < �ڶ��飬����-1����һ�� = �ڶ��飬����0
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
		//cardNums�����С�������򣬷����޷�׼ȷ����
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