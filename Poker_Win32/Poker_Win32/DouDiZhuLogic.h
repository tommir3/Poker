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

	};
}