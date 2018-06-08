#pragma once
#include "PokerDefine.h" 
#include <exception>
#include "PokerLogic.h"
#include <vector>

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class DouDiZhuPlayCardLogic : PokerLogic
	{
	public:
		__declspec(dllexport) DouDiZhuPlayCardLogic();
		__declspec(dllexport) ~DouDiZhuPlayCardLogic();

		/*
		找到相同的牌
		cards:牌数组
		cardType:牌类型
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, const CardType cardType, vector<vector<int>> &outCards);

		__declspec(dllexport) bool FindSingle(const int *cards, int *outCard);
		/*
		找出牌数组中的所有对
		cards:牌数组
		outCards:找出的对牌数组 (二维数组)
		outLen:对牌数组长度 (一维数组长度，二维数组为对，固定2个)
		return:成功返回true，失败返回false。异常抛出
		*/
		__declspec(dllexport) bool FindPair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThree(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreeSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreePair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFour(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFourSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFourPair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindPlane(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindPlaneSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindPlanePair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreePlane(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreePlaneSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreePlanePair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFourPlane(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFourPlaneSingle(const int *cards, int* &outCards, int &outLen);
		//bool FindFourPlanePair(const int *cards, int* &outCards, int &outLen);//20张 只有地主
		__declspec(dllexport) bool FindFivePlane(const int *cards, int* &outCards, int &outLen);
		//bool FindFivePlaneSingle(const int *cards, int* &outCards, int &outLen);//20张 只有地主
		//bool FindSixPlane(const int *cards, int* &outCards, int &outLen);//18张 只有地主
		__declspec(dllexport) bool FindStraightSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindStraightPair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindKingBomb(const int *cards, int* &outCards, int &outLen);

	private:
		/*
		想到相同数量的牌
		cnsArr:牌面值与长度类数组
		cnsLen:牌面值与长度类数组长度
		adjacentCount:连续牌的个数
		sameCount:相同牌的个数
		outCardNumVec:扑克牌子面值数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindCardNumber(const CardNumberSum *cnsArr, const int cnsLen, const int adjacentCount, const int sameCount, vector<vector<CardNumber>> &outCardNumVec);

	};
}