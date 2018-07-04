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


/*============================ ���� begin ================================*/

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
		//����������������,����������,�������͸���,������������
		int AdjacentCount = 0, MainCardSum = 0, SubsidiaryCount = 0, SubsidiarySum = 0;	
		switch (cardType)
		{
		case CardType::Normal:
			MainCardSum = 1;		//����������
			break;
		case CardType::Single:
			MainCardSum = 1;		//����������
			break;
		case CardType::Pair:
			MainCardSum = 2;		//����������
			break;
		case CardType::Three:
			MainCardSum = 3;		//����������
			break;
		case CardType::ThreeSingle:
			MainCardSum = 3;		//����������
			SubsidiaryCount = 1;	//�������͸���
			SubsidiarySum = 1;		//������������
			break;
		case CardType::ThreePair:
			MainCardSum = 3;		//����������
			SubsidiaryCount = 1;	//�������͸���
			SubsidiarySum = 2;		//������������
			break;
		case CardType::Four:
			MainCardSum = 4;		//����������
			break;
		case CardType::FourSingle:
			MainCardSum = 4;		//����������
			SubsidiaryCount = 2;	//�������͸���
			SubsidiarySum = 1;		//������������
			break;
		case CardType::FourPair:
			MainCardSum = 4;		//����������
			SubsidiaryCount = 2;	//�������͸���
			SubsidiarySum = 2;		//������������
			break;
		case CardType::Plane:
			AdjacentCount = 2;		//����������������
			MainCardSum = 3;		//����������
			break;
		case CardType::PlaneSingle:
			AdjacentCount = 2;		//����������������
			MainCardSum = 3;		//����������
			SubsidiaryCount = 2;	//�������͸���
			SubsidiarySum = 1;		//������������
			break;
		case CardType::PlanePair:
			AdjacentCount = 2;		//����������������
			MainCardSum = 3;		//����������
			SubsidiaryCount = 2;	//�������͸���
			SubsidiarySum = 2;		//������������
			break;
		case CardType::ThreePlane:
			AdjacentCount = 3;		//����������������
			MainCardSum = 3;		//����������
			break;
		case CardType::ThreePlaneSingle:
			AdjacentCount = 3;		//����������������
			MainCardSum = 3;		//����������
			SubsidiaryCount = 3;	//�������͸���
			SubsidiarySum = 1;		//������������
			break;
		case CardType::ThreePlanePair:
			AdjacentCount = 3;		//����������������
			MainCardSum = 3;		//����������
			SubsidiaryCount = 3;	//�������͸���
			SubsidiarySum = 2;		//������������
			break;
		case CardType::FourPlane:
			AdjacentCount = 4;		//����������������
			MainCardSum = 3;		//����������
			break;
		case CardType::FourPlaneSingle:
			AdjacentCount = 4;		//����������������
			MainCardSum = 3;		//����������
			SubsidiaryCount = 4;	//�������͸���
			SubsidiarySum = 1;		//������������
			break;
		case CardType::FourPlanePair:
			AdjacentCount = 4;		//����������������
			MainCardSum = 3;		//����������
			SubsidiaryCount = 4;	//�������͸���
			SubsidiarySum = 2;		//������������
			break;
		case CardType::FivePlane:
			AdjacentCount = 5;		//����������������
			MainCardSum = 3;		//����������
			break;
		case CardType::FivePlaneSingle:
			AdjacentCount = 5;		//����������������
			MainCardSum = 3;		//����������
			SubsidiaryCount = 5;	//�������͸���
			SubsidiarySum = 1;		//������������
			break;
		case CardType::SixPlane:
			AdjacentCount = 6;		//����������������
			MainCardSum = 3;		//����������
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
			MainCardSum = 1;		//����������
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
		//����������������,����������,�������͸���,������������
		int AdjacentCount = 0, MainCardSum = 0, SubsidiaryCount = 0, SubsidiarySum = 0;
		CardNumber minCard;
		bool isOK = DouDiZhuLogic::GetCompareCardNumber(cmpCards, cmpLen, cardType, minCard);
		if (isOK)
		{
			switch (cardType)
			{
			case CardType::Normal:
				MainCardSum = 1;		//����������
				break;
			case CardType::Single:
				MainCardSum = 1;		//����������
				break;
			case CardType::Pair:
				MainCardSum = 2;		//����������
				break;
			case CardType::Three:
				MainCardSum = 3;		//����������
				break;
			case CardType::ThreeSingle:
				MainCardSum = 3;		//����������
				SubsidiaryCount = 1;	//�������͸���
				SubsidiarySum = 1;		//������������
				break;
			case CardType::ThreePair:
				MainCardSum = 3;		//����������
				SubsidiaryCount = 1;	//�������͸���
				SubsidiarySum = 2;		//������������
				break;
			case CardType::Four:
				MainCardSum = 4;		//����������
				break;
			case CardType::FourSingle:
				MainCardSum = 4;		//����������
				SubsidiaryCount = 2;	//�������͸���
				SubsidiarySum = 1;		//������������
				break;
			case CardType::FourPair:
				MainCardSum = 4;		//����������
				SubsidiaryCount = 2;	//�������͸���
				SubsidiarySum = 2;		//������������
				break;
			case CardType::Plane:
				AdjacentCount = 2;		//����������������
				MainCardSum = 3;		//����������
				break;
			case CardType::PlaneSingle:
				AdjacentCount = 2;		//����������������
				MainCardSum = 3;		//����������
				SubsidiaryCount = 2;	//�������͸���
				SubsidiarySum = 1;		//������������
				break;
			case CardType::PlanePair:
				AdjacentCount = 2;		//����������������
				MainCardSum = 3;		//����������
				SubsidiaryCount = 2;	//�������͸���
				SubsidiarySum = 2;		//������������
				break;
			case CardType::ThreePlane:
				AdjacentCount = 3;		//����������������
				MainCardSum = 3;		//����������
				break;
			case CardType::ThreePlaneSingle:
				AdjacentCount = 3;		//����������������
				MainCardSum = 3;		//����������
				SubsidiaryCount = 3;	//�������͸���
				SubsidiarySum = 1;		//������������
				break;
			case CardType::ThreePlanePair:
				AdjacentCount = 3;		//����������������
				MainCardSum = 3;		//����������
				SubsidiaryCount = 3;	//�������͸���
				SubsidiarySum = 2;		//������������
				break;
			case CardType::FourPlane:
				AdjacentCount = 4;		//����������������
				MainCardSum = 3;		//����������
				break;
			case CardType::FourPlaneSingle:
				AdjacentCount = 4;		//����������������
				MainCardSum = 3;		//����������
				SubsidiaryCount = 4;	//�������͸���
				SubsidiarySum = 1;		//������������
				break;
			case CardType::FourPlanePair://20�� ֻ�е���
				AdjacentCount = 4;		//����������������
				MainCardSum = 3;		//����������
				SubsidiaryCount = 4;	//�������͸���
				SubsidiarySum = 2;		//������������
				break;
			case CardType::FivePlane:
				AdjacentCount = 5;		//����������������
				MainCardSum = 3;		//����������
				break;
			case CardType::FivePlaneSingle://20�� ֻ�е���
				AdjacentCount = 5;		//����������������
				MainCardSum = 3;		//����������
				SubsidiaryCount = 5;	//�������͸���
				SubsidiarySum = 1;		//������������
				break;
			case CardType::SixPlane://18�� ֻ�е���
				AdjacentCount = 6;		//����������������
				MainCardSum = 3;		//����������
				break;
			case CardType::StraightSingle:
				if (len >= cmpLen)
				{
					AdjacentCount = cmpLen;	//����������������
					MainCardSum = 1;	//����������
				}
				break;
			case CardType::StraightPair:
				if (len >= cmpLen)
				{
					AdjacentCount = cmpLen / 2;	//����������������
					MainCardSum = 2;	//����������
				}
				break;
			case CardType::KingBomb:
				result = FindKingBomb(cards, len, outCards);
				return result;
			default:
				MainCardSum = 1;		//����������
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



/*============================ ���� end ================================*/


/*============================ ˽�з��� ================================*/
bool DouDiZhu::DouDiZhuPlayCardLogic::FindStraightSingle(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		//int AdjacentCount = 5;	//����������������
		int MainCardSum = 1;	//����������
		int SubsidiaryCount = 0;	//�������͸���
		int SubsidiarySum = 0;		//������������
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
		//int AdjacentCount = 5;	//����������������
		int MainCardSum = 2;	//����������
		int SubsidiaryCount = 0;	//�������͸���
		int SubsidiarySum = 0;		//������������
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
					if (subsidiaryCount > 0 && subsidiarySum > 0)//�����Ҫ�Ҹ�����
					{
						int cloneSortArray[CardSortCount];
						//����������
						DouDiZhuLogic::CloneArray(sortArr, CardSortCount, cloneSortArray);
						for (int j = 0; j < mainCards.size(); ++j)
						{
							cloneSortArray[mainCards[j]] -= mainCardSum;//��ȥ�����͵���
						}
						//�ҳ����п��ܵĸ�����
						isOK = FindSubsidiaryCards(cloneSortArray, CardSortCount, subsidiaryCount, subsidiarySum, false, subsidiaryCardsList);
						if (!isOK)//���û�ҵ������ƣ����²��ƽ��в���
						{
							isOK = FindSubsidiaryCards(cloneSortArray, CardSortCount, subsidiaryCount, subsidiarySum, true, subsidiaryCardsList);
						}
					}
					//�ϲ��������븽������
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
		bool isAccord = false, isFindAdjacent = false;//isAccord �Ƿ��Ƿ��ϵ��� ����
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
			if (adjacentCount > 1)//��������
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
			else//��ͬ����
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
			bool isAccord = false;//�Ƿ��Ƿ��ϵ��� ���ڲ���
			vector<int> subsidiaryVec;
			vector<int> otherSubsidiaryVec;//����ͬ�Ƶĸ����� ���磺4��5���Ѿ��ҵ���5�������������һ����5
			for (int i = 0; i < sortArrLen; ++i)
			{
				isAccord = (isSplit) ? sortNoMainArray[i] >= subsidiarySameCount : sortNoMainArray[i] == subsidiarySameCount;
				if (isAccord)
				{
					subsidiaryVec.push_back(i);
				}
				/*�������� ����ĳ���������ڸ��������������������һ������*/ 
				/*���磺��2���ԣ���4��5��2��5����subsidiaryVec�У���2��5����otherSubsidiaryVec��*/
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
			/*���subsidiaryVec�еĸ��������㸽���Ƹ��������ҿ��Բ���*/
			/*��ʱ�ټ���otherSubsidiaryVec�еĸ�����*/
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
			if (subsidiaryCards.size() > 0)//�и�����
			{
				for (int i = 0; i < subsidiaryCards.size(); ++i)
				{
					joinIdxVec.clear();
					joinCards.clear();
					//�ϲ�
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
					//ת�˿���ֵ
					isOK = SortArrayCardsToCards(joinIdxVec, cards, len, joinCards);
					if (isOK)
					{
						outCards.push_back(joinCards);//����outCards
						result = true;
					}
				}
			}
			else//û�и�����
			{
				for (int j = 0; j < mainCards.size(); ++j)
				{
					for (int k = 0; k < mainSum; ++k)
					{
						joinIdxVec.push_back(mainCards[j]);
					}
				}
				//ת�˿���ֵ
				result = SortArrayCardsToCards(joinIdxVec, cards, len, joinCards);
				if (result)
				{
					outCards.push_back(joinCards);//����outCards
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
��������ҳ����������������
preWei:ǰһλ��ֵ
wei:��ǰλ��
r: ������ϵ���ʱ�������
len:�����ݳ���
sub:λ������
result:�������ļ���
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
��������
const int len = 5;
int arr[len] = { 1,2,3,4,5 };
const int sub = 3;
vector<vector<int>> outVec;
MyCmn(len, sub, outVec);
*/
/*
����C(M,N)�������  C(len, sub)
len: �����ܳ��� M
sub: Ҫ����ϵĳ��� N
result: C(M,N)�Ľ��
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
