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


		__declspec(dllexport) CardType GetCardType(const int *cards, const int len);
		__declspec(dllexport) int CompareCards(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareCards(const int *cards1, const int cards1Len, const CardType card1Type, const int *cards2, const int cards2Len, const CardType card2Type);

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
		__declspec(dllexport) bool IsSixPlane(const int *cards, const int len);
		__declspec(dllexport) bool IsStraightSingle(const int *cards, const int len);
		__declspec(dllexport) bool IsStraightPair(const int *cards, const int len);
		__declspec(dllexport) bool IsKingBomb(const int *cards, const int len);

		__declspec(dllexport) int CompareSingle(const int card1, const int card2);
		__declspec(dllexport) int ComparePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareThree(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareFour(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareThreeSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareThreePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareFourSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareFourPair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int ComparePlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int ComparePlaneSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int ComparePlanePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareThreePlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareThreePlaneSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareThreePlanePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareFourPlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareFourPlaneSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareFourPlanePair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareFivePlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareFivePlaneSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareSixPlane(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareStraightSingle(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareStraightPair(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);

		static const int CardSortCount = PokerLogic::SuitsCount + 1;
		/*斗地主计算牌时排序样式 依次：3，4，5，6，7，8，9，10，J，Q，K，A，2，王*/
		int SortStyle[CardSortCount] = { 11, 12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13 };
		bool SortStyleValueToCardNumber(const int value, CardNumber & cardNum);
		int CardNumberToSortArrayValue(const CardNumber cardNum);
		bool CardsToSortArray(const int *cards, const int cardsLen, int *sortArray, const int sortArrLen);

		bool GetCompareCardNumber(const int *cards, const int len, const CardType cardType, CardNumber &cardNum);
	private:

		bool IsTrueCardType(const int *cards, const int len, const int adjacentCount, const int sameCount, const int subsidiaryCount, const int subsidiarySameCount);
		bool CloneArray(const int *cards, const int len, int *outCards);
		bool IsAdjacentCard(const int *sortArray, const int sortArrLen, const int index, const int adjacentCount, const int sameCount);
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
		/*
		比较两个相同数组大小（三张，三带一，三带对，四张，四带二，四带对）
		cards1: 第一个牌值数组
		cards1Len: 数组长度
		cards2: 第二个牌值数组
		cards2Len: 数组长度
		cnsLen: 牌型中种类个数（例如四带二，种类为：4 1 1，个数为3个）
		sameCount: 相同牌数数量（例如比较四带二，比较的就是4张相同的牌，数量为：4）
		return: 比较值。1：cards1大于cards2；0：cards1等于cards2；-1：cards1小于cards2。异常抛出
		*/
		int CompareSameArray(const int *cards1, const int cards1Len,
							const int *cards2, const int cards2Len,
							const int cnsLen, const int sameCount);
		/*
		从扑克牌信息数组中找出相同数量的牌
		cnsArr:牌面值与长度类数组
		cnsArrLen:牌面值与长度类数组长度
		findCount:找牌的数量
		outCardNum:找出的扑克牌字面值
		return:成功找出返回true，失败返回false。异常抛出
		*/
		bool GetCardNumberByCardNumberSum(const CardNumberSum *cnsArr, const int cnsArrLen, const int findCount, CardNumber *outCardNum);
		/*
		比较相邻的扑克牌
		cards1:第一组牌
		cards1Len:第一组牌数量
		cards2:第二组牌
		cards2Len:第二组牌数量
		cnsLen:牌型中种类个数（例如四带二，种类为：4 1 1，个数为3个）
		adjacentCount:相邻牌的个数
		sameCount:相同牌的数量
		return:比较值0，1，-1。1：cards1大于cards2；0：cards1等于cards2；-1：cards1小于cards2。异常抛出
		*/
		int CompareAdjacentPoker(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len, const int cnsLen, const int adjacentCount, const int sameCount);
		/*
		从相邻牌信息中获取牌值最大的牌
		cnsArr:牌面值与长度类数组
		cnsArrLen:牌面值与长度类数组长度
		adjacentCount:相邻牌的个数
		sameCount:相同牌的数量
		outCardNum:找出的最大牌值
		return:成功返回true，失败返回false。异常抛出
		*/
		bool GetMaxCompareNumberByAdjacent(const CardNumberSum *cnsArr, const int cnsArrLen, const int adjacentCount, const int sameCount, CardNumber *outCardNum);
		/*
		是否是相邻的牌
		cnsArr:牌面值与长度类数组
		cnsArrLen:牌面值与长度类数组长度
		index:遍历索引 即从此索引位置开始找相邻的牌
		adjacentCount:相邻牌的个数
		sameCount:相同牌的数量
		return:成功返回true，失败返回false。异常抛出
		*/
		bool IsAdjacent(const CardNumberSum *cnsArr, const int cnsArrLen, const int index, const int adjacentCount, const int sameCount);
	};
}