#pragma once
#include "PokerDefine.h" 
#include <exception>
#include "PokerLogic.h"
#include <vector>

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class DouDiZhuPlayCardLogic
	{
	public:
		/*
		找到相同的牌
		*/
		bool FindTargetCards(const int *cards, const CardType cardType, vector<vector<int>> outCards);

		bool FindSingle(const int *cards, int *outCard);
		/*
		找出牌数组中的所有对
		cards:牌数组
		outCards:找出的对牌数组 (二维数组)
		outLen:对牌数组长度 (一维数组长度，二维数组为对，固定2个)
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindPair(const int *cards, int* &outCards, int &outLen);
		bool FindThree(const int *cards, int* &outCards, int &outLen);
		bool FindThreeSingle(const int *cards, int* &outCards, int &outLen);
		bool FindThreePair(const int *cards, int* &outCards, int &outLen);
		bool FindFour(const int *cards, int* &outCards, int &outLen);
		bool FindFourSingle(const int *cards, int* &outCards, int &outLen);
		bool FindFourPair(const int *cards, int* &outCards, int &outLen);
		bool FindPlane(const int *cards, int* &outCards, int &outLen);
		bool FindPlaneSingle(const int *cards, int* &outCards, int &outLen);
		bool FindPlanePair(const int *cards, int* &outCards, int &outLen);
		bool FindThreePlane(const int *cards, int* &outCards, int &outLen);
		bool FindThreePlaneSingle(const int *cards, int* &outCards, int &outLen);
		bool FindThreePlanePair(const int *cards, int* &outCards, int &outLen);
		bool FindFourPlane(const int *cards, int* &outCards, int &outLen);
		bool FindFourPlaneSingle(const int *cards, int* &outCards, int &outLen);
		//bool FindFourPlanePair(const int *cards, int* &outCards, int &outLen);//20张 只有地主
		bool FindFivePlane(const int *cards, int* &outCards, int &outLen);
		//bool FindFivePlaneSingle(const int *cards, int* &outCards, int &outLen);//20张 只有地主
		//bool FindSixPlane(const int *cards, int* &outCards, int &outLen);//18张 只有地主
		bool FindStraightSingle(const int *cards, int* &outCards, int &outLen);
		bool FindStraightPair(const int *cards, int* &outCards, int &outLen);
		bool FindKingBomb(const int *cards, int* &outCards, int &outLen);

		/*
		想到相同数量的牌
		cnsArr:牌面值与长度类数组
		cnsLen:牌面值与长度类数组长度
		adjacentCount:连续牌的个数
		sameCount:相同牌的个数
		outCnsIdxArr:牌面值与长度类数组所在的索引值数组
		outCnsIdxLen:牌面值与长度类数组所在的索引值数组长度
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindCardNumberSum(const CardNumberSum *cnsArr, const int cnsLen, const int adjacentCount, const int sameCount, int* &outCnsIdxArr, int &outCnsIdxLen);

	private:

	};
}