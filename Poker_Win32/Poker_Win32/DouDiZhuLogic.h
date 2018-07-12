#pragma once
#include "PokerDefine.h"
#include <exception>
#include "PokerLogic.h"

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	/*斗地主牌类型的权重值数组 依次为：A 2 3 4 5 6 7 8 9 10 J Q K 小王 大王*/
	static const int Poker_Weight[PokerLogic::SuitsCount + PokerLogic::JokerCount] = { 14, 15, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 82, 83 };
	class DouDiZhuLogic : public PokerLogic
	{
	public:
		__declspec(dllexport) DouDiZhuLogic();
		__declspec(dllexport) ~DouDiZhuLogic();

		/*
		获取一组牌的配类型
		cards: 牌数组
		len: 数组长度
		return: 返回牌类型枚举, 异常抛出
		*/
		__declspec(dllexport) CardType GetCardType(const int *cards, const int len);
		/*
		判断牌数组是否是指定牌类型
		cardType: 指定牌类型
		cards: 牌数组
		len: 数组长度
		return: 是返回true, 不是返回false, 异常抛出
		*/
		__declspec(dllexport) bool IsCardType(const CardType cardType, const int *cards, const int len);
		/*
		比较两组牌大小
		cards1: 牌数组1
		cards1Len: 数组1长度
		cards2: 牌数组2
		cards2Len: 数组2长度
		return: 返回比较值。1：cards1大于cards2；0：cards1等于cards2；-1：cards1小于cards2。异常抛出
		*/
		__declspec(dllexport) int CompareCards(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		/*
		比较指定牌型的两组牌大小
		cards1: 牌数组1
		cards1Len: 数组1长度
		card1Type: 牌数组1牌型
		cards2: 牌数组2
		cards2Len: 数组2长度
		card2Type: 牌数组2牌型
		return: 返回比较值。1：cards1大于cards2；0：cards1等于cards2；-1：cards1小于cards2。异常抛出
		*/
		__declspec(dllexport) int CompareCards(const int *cards1, const int cards1Len, const CardType card1Type, const int *cards2, const int cards2Len, const CardType card2Type);

	protected:
		/*排序数组长度 3 到 K + 王*/
		static const int CardSortCount = PokerLogic::SuitsCount + 1;
		/*斗地主计算牌时排序样式 依次：3，4，5，6，7，8，9，10，J，Q，K，A，2，王*/
		int SortStyle[CardSortCount] = { 11, 12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13 };
		/*
		排序样式数组值转牌字面值
		value: 排序样式数组值
		cardNum: 牌值（带出参数）
		return: 成功返回true, 失败返回false, 异常抛出
		*/
		bool SortStyleValueToCardNumber(const int value, CardNumber & cardNum);
		/*
		牌字面值转排序数组值 （转SortStyle数组中的值）
		cardNum: 牌值
		return: 成功返回SortStyle数组中的值, 失败返回-1, 异常抛出
		*/
		int CardNumberToSortArrayValue(const CardNumber cardNum);
		/*
		牌值数组转排序数组值
		cards: 牌数组
		cardsLen: 牌数组长度
		sortArray: 排序数组（带出参数）(CardSortCount长度的数组)
		sortArrLen: 排序数组长度
		return: 成功返回true, 失败返回false, 异常抛出
		*/
		bool CardsToSortArray(const int *cards, const int cardsLen, int *sortArray, const int sortArrLen);
		/*
		获取指定类型牌中的比较牌值
		cards: 牌数组
		len: 牌数组长度
		cardType: 指定牌类型
		cardNum: 牌字面值（带出参数）
		return: 成功返回true, 失败返回false, 异常抛出
		*/
		bool GetCompareCardNumber(const int *cards, const int len, const CardType cardType, CardNumber &cardNum);
		/*
		复制数组
		cards: 牌数组
		len: 数组长度
		outCards: 复制的数组（带出单数）
		return: 成功返回true, 失败返回false, 异常抛出
		*/
		bool CloneArray(const int *cards, const int len, int *outCards);
		/*
		是否是连续的牌
		sortArray: 扑克牌的排序数组
		sortArrLen: 排序数组长度
		index: 排序数组中查找的索引位置
		adjacentCount: 连续牌的个数
		sameCount: 连续牌相同的数量
		return: 成功返回true, 失败返回false, 异常抛出
		*/
		bool IsAdjacentCard(const int *sortArray, const int sortArrLen, const int index, const int adjacentCount, const int sameCount);

	private:
		/*
		判断是否王炸
		cards: 牌数组
		len: 数组长度
		return: 成功返回true, 失败返回false, 异常抛出
		*/
		bool IsKingBomb(const int *cards, const int len);
		/*
		是否是正确的牌类型
		cards: 牌数组
		len: 数组长度
		adjacentCount: 连续牌的个数
		sameCount: 连续牌相同的数量
		subsidiaryCount: 附属牌的个数
		subsidiarySameCount: 附属牌相同的数量
		return: 成功返回true, 失败返回false, 异常抛出
		*/
		bool IsTrueCardType(const int *cards, const int len, const int adjacentCount, const int sameCount, const int subsidiaryCount, const int subsidiarySameCount);

	};
}