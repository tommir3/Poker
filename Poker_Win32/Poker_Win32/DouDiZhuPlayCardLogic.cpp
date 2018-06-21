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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindTargetCards(const int *cards, const int len, const int *cmpCards, const int cmpLen, const CardType cardType, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		//主牌型连续牌数量,主牌型数量,附属牌型个数,附属牌型数量
		int AdjacentCount = 0, MainCardSum = 0, SubsidiaryCount = 0, SubsidiarySum = 0;
		CardNumber minCard;
		bool isOK = GetCompareCardNumber(cmpCards, cmpLen, cardType, minCard);
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
			result = FindCards(cards, len, minCard, false, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
			if (!result)
			{
				result = FindCards(cards, len, minCard, true, AdjacentCount, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindPair(const int *cards, const int len, const int *cmpCards, const int cmpLen, vector<vector<int>> &outCards)
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindThreeSingle(const int *cards, const int len, vector<vector<int>> &outCards)
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindThreePair(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 0;	//主牌型连续牌数量
		int MainCardSum = 3;	//主牌型数量
		int SubsidiaryCount = 1;	//附属牌型个数
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindFour(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 0;	//主牌型连续牌数量
		int MainCardSum = 4;	//主牌型数量
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindFourSingle(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 0;	//主牌型连续牌数量
		int MainCardSum = 4;	//主牌型数量
		int SubsidiaryCount = 2;	//附属牌型个数
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindFourPair(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 0;	//主牌型连续牌数量
		int MainCardSum = 4;	//主牌型数量
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindPlane(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 2;	//主牌型连续牌数量
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindPlaneSingle(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 2;	//主牌型连续牌数量
		int MainCardSum = 3;	//主牌型数量
		int SubsidiaryCount = 2;	//附属牌型个数
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindThreePlane(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 3;	//主牌型连续牌数量
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindThreePlaneSingle(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 3;	//主牌型连续牌数量
		int MainCardSum = 3;	//主牌型数量
		int SubsidiaryCount = 3;	//附属牌型个数
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindThreePlanePair(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 3;	//主牌型连续牌数量
		int MainCardSum = 3;	//主牌型数量
		int SubsidiaryCount = 3;	//附属牌型个数
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindFourPlane(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 4;	//主牌型连续牌数量
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindFourPlaneSingle(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 4;	//主牌型连续牌数量
		int MainCardSum = 3;	//主牌型数量
		int SubsidiaryCount = 4;	//附属牌型个数
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindFivePlane(const int *cards, const int len, vector<vector<int>> &outCards)
{
	bool result = false;
	try
	{
		int AdjacentCount = 5;	//主牌型连续牌数量
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
		for (int i = 5; i < 13; ++i)
		{
			isOK = FindCards(cards, len, false, i, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
			if (isOK)
			{
				result = isOK;
			}
			else
			{
				isOK = FindCards(cards, len, true, i, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
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
		for (int i = 3; i <= 8; ++i)
		{
			isOK = FindCards(cards, len, false, i, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
			if (isOK)
			{
				result = isOK;
			}
			else
			{
				isOK = FindCards(cards, len, true, i, MainCardSum, SubsidiaryCount, SubsidiarySum, outCards);
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
//new
bool DouDiZhu::DouDiZhuPlayCardLogic::FindCards(const int *cards, const int len, const CardNumber minCard, const bool isMainSplit, const int adjacentCount, const int mainCardSum, const int subsidiaryCount, const int subsidiarySum, vector<vector<int>> &outCards)
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
				isOK = FindMainCards(sortArr, CardSortCount, minCard, adjacentCount, mainCardSum, isMainSplit, mainCardsList);
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
				isOK = FindMainCards(sortArr, CardSortCount, minCard, mainCardSum, isMainSplit, mainCards);
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

bool DouDiZhu::DouDiZhuPlayCardLogic::SortStyleValueToCardNumber(const int value, CardNumber & cardNum)
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

int DouDiZhu::DouDiZhuPlayCardLogic::CardNumberToSortArrayValue(const CardNumber cardNum)
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
				isOK = SortStyleValueToCardNumber(sortCards[i], cmpCard);
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindMainCards(const int *sortArray, const int sortArrLen, const int adjacentCount, const int sameCount, const bool isSplit, vector<vector<int>> &outSortArrVec)
{
	bool result = false;
	try
	{
		outSortArrVec.clear();
		bool isAccord = false,isFindAdjacent = false;//isAccord 是否是符合的牌 拆牌
		for (int i = 0; i < sortArrLen; ++i)
		{
			vector<int> tmpSortArr(CardSortCount);
			isAccord = (isSplit) ? sortArray[i] >= sameCount : sortArray[i] == sameCount;
			if (isAccord && i + adjacentCount < sortArrLen)
			{
				tmpSortArr[i] = sameCount;
				isFindAdjacent = true;
				for (int j = i + 1; j < i + adjacentCount; ++j)
				{
					isAccord = (isSplit) ? sortArray[j] >= sameCount : sortArray[j] == sameCount;
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

//new
bool DouDiZhu::DouDiZhuPlayCardLogic::FindMainCards(const int *sortArray, const int sortArrLen, const CardNumber minCard, const int adjacentCount, const int sameCount, const bool isSplit, vector<vector<int>> &outSortArrVec)
{
	bool result = false;
	try
	{
		outSortArrVec.clear();
		bool isAccord = false, isFindAdjacent = false;//isAccord 是否是符合的牌 拆牌
		int minIndex = CardNumberToSortArrayValue(minCard);
		if (minIndex >= 0 && minIndex + 1 < sortArrLen)
		{
			for (int i = minIndex + 1; i < sortArrLen; ++i)
			{
				vector<int> tmpSortArr(CardSortCount);
				isAccord = (isSplit) ? sortArray[i] >= sameCount : sortArray[i] == sameCount;
				if (isAccord && i + adjacentCount < sortArrLen)
				{
					tmpSortArr[i] = sameCount;
					isFindAdjacent = true;
					for (int j = i + 1; j < i + adjacentCount; ++j)
					{
						isAccord = (isSplit) ? sortArray[j] >= sameCount : sortArray[j] == sameCount;
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
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool DouDiZhu::DouDiZhuPlayCardLogic::FindMainCards(const int *sortArray, const int sortArrLen, const int sameCount, const bool isSplit, int* outSortArr)
{
	bool result = false;
	try
	{
		bool isAccord = false;//是否是符合的牌 用于拆牌
		for (int i = 0; i < sortArrLen; ++i)
		{
			isAccord = (isSplit) ? sortArray[i] >= sameCount : sortArray[i] == sameCount;
			if (isAccord)
			{
				outSortArr[i] = sameCount;
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

bool DouDiZhu::DouDiZhuPlayCardLogic::FindMainCards(const int *sortArray, const int sortArrLen, const CardNumber minCard, const int sameCount, const bool isSplit, int* outSortArr)
{
	bool result = false;
	try
	{
		bool isAccord = false;//是否是符合的牌 用于拆牌
		int minIndex = CardNumberToSortArrayValue(minCard);
		if (minIndex >= 0 && minIndex + 1 < sortArrLen)
		{
			for (int i = minIndex + 1; i < sortArrLen; ++i)
			{
				isAccord = (isSplit) ? sortArray[i] >= sameCount : sortArray[i] == sameCount;
				if (isAccord)
				{
					outSortArr[i] = sameCount;
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
				isAccord = (isSplit) ? sortNoMainArray[i] >= subsidiarySameCount : sortNoMainArray[i] == subsidiarySameCount;
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

bool DouDiZhu::DouDiZhuPlayCardLogic::GetCompareCardNumber(const int *cards, const int len, const CardType cardType, CardNumber &cardNum)
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

