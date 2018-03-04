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

		__declspec(dllexport) bool IsFourPlanePair(const int *cards, const int len);

		__declspec(dllexport) bool IsFivePlane(const int *cards, const int len);

		__declspec(dllexport) bool IsFivePlaneSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsStraightSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsStraightPair(const int *cards, const int len);

		__declspec(dllexport) bool IsKingBomb(const int *cards, const int len);

	private:
		class CardNumberSum
		{
		public:
			CardNumber num;
			int count;
		};
		/*
		判断是否全部相同
		cards: 牌数组
		len: 数组长度
		return: 相同返回true, 不同返回false, 异常抛出
		*/
		bool IsAllSame(const int *cards, const int len);
		/*
		找出相同牌的数量
		cards: 牌值数组
		cardsLen: 数组长度
		cnsArr: 牌面值与数量类数组
		arrLen: 牌面值与数量类数组长度
		return: 成功找出返回true, 失败返回false, 异常抛出
		*/
		bool FindCardNumberCount(const int *cards, const int cardsLen, CardNumberSum *cnsArr, const int arrLen);
		/*
		是否存在制定牌面值
		cnsArr: 牌面值与长度结构数组
		cnsArrLen: 牌面值与长度结构数组长度
		cardNum: 制定牌面值
		return: 成功找出返回true, 失败返回false, 异常抛出
		*/
		bool IsExistCardNumber(const CardNumberSum *cnsArr, const int cnsArrLen, const CardNumber cardNum);
		/*
		是否是X数量的飞机
		cardNums: 牌面值数组(cardNums必须从小到大排序，否则无法准确查找)
		cardNumsLen: 牌面值数组长度
		x: 指定数量
		return: 成功找出返回true, 失败返回false, 异常抛出
		*/
		bool IsXPlane(const CardNumberSum *cardNums, const int cardNumsLen, const int index, const int planeCount);
		/*
		排序牌面值与长度结构数组（小到大排序）
		cnsArr: 牌面值与长度类数组
		cnsArrLen: 牌面值与长度类数组长度
		异常抛出
		*/
		void SortCardNumberSum(CardNumberSum *cnsArr, const int cnsArrLen);
		/*
		设置bool数组正确值(设置true)
		arr: bool数组
		arrLen: bool数组长度
		count: 设置true数量
		return: 成功设置返回true, 失败返回false, 异常抛出
		*/
		bool SetArrayTrue(bool *arr, const int arrLen, const int count);
		/*
		判断bool数组是否全部正确（判断是否全为true）
		arr: bool数组
		arrLen: bool数组长度
		return: 全部为true返回true, 否则返回false, 异常抛出
		*/
		bool IsArrayTrue(const bool *arr, const int arrLen);
	};
}