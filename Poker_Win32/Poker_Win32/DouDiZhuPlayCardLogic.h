#pragma once
#include "PokerDefine.h" 
#include <exception>
#include "PokerLogic.h"
#include <vector>
#include "DouDiZhuLogic.h"

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class DouDiZhuPlayCardLogic : PokerLogic, DouDiZhuLogic
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

		__declspec(dllexport) bool FindSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		/*
		找出牌数组中的所有对
		cards:牌数组
		len:牌数组的长度
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		__declspec(dllexport) bool FindPair(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindThree(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreeSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreePair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFour(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFourSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFourPair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindPlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindPlaneSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindPlanePair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreePlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreePlaneSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreePlanePair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFourPlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFourPlaneSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		//bool FindFourPlanePair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);//20张 只有地主
		__declspec(dllexport) bool FindFivePlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		//bool FindFivePlaneSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);//20张 只有地主
		//bool FindSixPlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);//18张 只有地主
		__declspec(dllexport) bool FindStraightSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindStraightPair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindKingBomb(const int *cards, const int len, vector<vector<CardNumber>> &outCards);

	private:
		/*
		扑克牌值转扑克信息类集合
		cards:扑克牌值数组
		cardsLen:扑克牌值数组长度
		cnsArr:扑克信息类集合（已排序,从小到大）
		return:成功返回true，失败返回false。异常抛出
		*/
		bool CardsToCardNumberSum(const int *cards, const int cardsLen, std::vector<CardNumberSum> &cnsArr);
		/*
		想到相同数量的牌
		cnsVec:牌面值与长度类集合
		adjacentCount:连续牌的个数
		sameCount:相同牌的个数
		isSplit:是否对牌进行拆牌查找 true:拆牌查找 false:不拆牌查找
		outCardNumVec:扑克牌子面值数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindCardNumber(const std::vector<CardNumberSum> cnsVec, const int adjacentCount, const int sameCount, const bool isSplit, std::vector<std::vector<CardNumber>> &outCardNumVec);

		bool FineCardValue(const int *cards, const int len, const vector<vector<CardNumber>> const findCards, const int count, vector<vector<int>> &outCards);

	};
}