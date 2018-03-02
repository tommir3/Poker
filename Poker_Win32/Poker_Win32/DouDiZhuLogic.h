#pragma once
#include "PokerDefine.h"
#include <exception>
#include "PokerLogic.h"

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class DouDiZhuLogic : public PokerLogic
	{
	public:
		__declspec(dllexport) DouDiZhuLogic();
		__declspec(dllexport) ~DouDiZhuLogic();

		/*
		是否是一对相同牌(大小王不算一对)
		cards: 判断的牌数组
		len: 数组长度
		return: 是对返回true, 不是返回false, 异常抛出
		*/
		__declspec(dllexport) bool IsPair(const int *cards, const int len);

		__declspec(dllexport) bool IsThree(const int *cards, const int len);

		__declspec(dllexport) bool IsFour(const int *cards, const int len);

		__declspec(dllexport) bool IsThreeSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsThreePair(const int *cards, const int len);

		__declspec(dllexport) bool IsFourSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsFourPair(const int *cards, const int len);

		__declspec(dllexport) bool IsPlane(const int *cards, const int len);

		__declspec(dllexport) bool IsPlaneSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsPlanePair(const int *cards, const int len);

		__declspec(dllexport) bool IsThreePlane(const int *cards, const int len);

		__declspec(dllexport) bool IsThreePlaneSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsThreePlanePair(const int *cards, const int len);

		__declspec(dllexport) bool IsFourPlane(const int *cards, const int len);

		__declspec(dllexport) bool IsFourPlaneSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsStraightSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsStraightPair(const int *cards, const int len);

		__declspec(dllexport) bool IsKingBomb(const int *cards, const int len);

	private:
		/*
		判断是否全部相同
		cards: 牌数组
		len: 数组长度
		return: 相同返回true, 不同返回false, 异常抛出
		*/
		bool IsAllSame(const int *cards, const int len);
		/*
		判断是否有指定数量的相同牌
		cards: 待验证的牌数组
		len: 数组长度
		sameCount: 指定相同牌的数量
		return: 有指定相同牌返回true, 没有返回false, 异常抛出
		*/
		bool IsSame(const int *cards, const int len, const int sameCount, CardNumber &sameNumber);
		
		bool FindNumberCount(const int *cards, const int cardsLen, CardNumberSum *sumArr, const int arrLen);
		/*
		找出相同牌的数量
		cards: 牌值数组
		cardsLen: 数组长度
		numArr: 牌面值数组
		sumArr: 每个牌面值数量数组
		arrLen: 牌面值数组和牌面数量数组长度
		return: 成功找出返回true, 失败返回false, 异常抛出
		*/
		bool FindNumberCount(const int *cards, const int cardsLen, CardNumber *numArr, int *sumArr, const int arrLen);
		/*
		是否是X数量的飞机
		cardNums: 牌面值数组(cardNums必须从小到大排序，否则无法准确查找)
		cardNumsLen: 牌面值数组长度
		x: 指定数量
		return: 成功找出返回true, 失败返回false, 异常抛出
		*/
		bool IsXPlane(const CardNumberSum *cardNums, const int cardNumsLen, const int index, const int planeCount);

		void SortCardNumberSum(CardNumberSum *cnsArr, const int cnsArrLen);
		//bool GetSame(const int *cards, const int cardsLen, const int sameCount, CardNumber *sameNumber, int &sameLen);
	};
}