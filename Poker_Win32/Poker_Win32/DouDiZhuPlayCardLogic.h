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
		找到相同类型的牌
		cards:牌数组
		len:牌数组长度
		cardType:牌类型
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, const int len, const CardType cardType, vector<vector<int>> &outCards);
		/*
		找到大于指定牌的牌
		cards:牌数组
		len:牌数组长度
		cmpCards:指定的牌数组
		cmpLen:指定的牌数组长度
		cardType:指定牌的类型
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, const int len, const int *cmpCards, const int cmpLen, const CardType cardType, vector<vector<int>> &outCards);

		/*
		找出牌数组中所有的连牌（龙）
		cards:牌数组
		len:牌数组的长度
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		__declspec(dllexport) bool FindStraightSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindStraightPair(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindKingBomb(const int *cards, const int len, vector<vector<int>> &outCards);

	private:

		bool FindCards(const int *cards, const int len, const bool isMainSplit,const int adjacentCount, const int mainCardSum, const int subsidiaryCount,const int subsidiarySum, vector<vector<int>> &outCards);
		bool FindCards(const int *cards, const int len, const bool isCompareMinCard, const CardNumber minCard, const bool isMainSplit, const int adjacentCount, const int mainCardSum, const int subsidiaryCount, const int subsidiarySum, vector<vector<int>> &outCards);
		/*
		扑克牌值转扑克权重排序数组
		cards:扑克牌值数组
		cardsLen:扑克牌值数组长度
		sortArray:扑克权重排序数组（已排序,从小到大）3，4，5，6，7，8，9，10，J，Q，K，王
		sortArrLen:扑克权重排序数组长度（固定为14）
		return:成功返回true，失败返回false。异常抛出
		*/
		bool SortArrayCardsToCards(const vector<vector<int>> const sortCardsList, const int *cards, const int len, vector<vector<int>> &outCardsList);
		bool SortArrayCardsToCards(vector<int> sortCards, const int *cards, const int len, vector<int> &outCards);
		/*
		查找连续牌的主牌型  例如飞机带2单，飞机即为主牌型
		sortArray:扑克权重排序数组
		sortArrLen:扑克权重排序数组长度（固定为14）
		isCompareMinCard:是否查找比较大的牌
		minCard:比较牌的牌值（如果isCompareMinCard，此值无效）
		adjacentCount:连续牌的个数
		sameCount:相同牌的个数
		isSplit:是否对牌进行拆牌查找 true:拆牌查找 false:不拆牌查找
		outSortArrVec:符合要求的主牌型的扑克权重排序数组集合（带出参数）
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindMainCards(const int *sortArray, const int sortArrLen, const bool isCompareMinCard, const CardNumber minCard, const int adjacentCount, const int sameCount, const bool isSplit, vector<vector<int>> &outSortArrVec);
		/*
		查找相同牌的主牌型  例如3带1，3即为主牌型
		sortArray:扑克权重排序数组
		sortArrLen:扑克权重排序数组长度（固定为14）
		isCompareMinCard:是否查找比较大的牌
		minCard:比较牌的牌值（如果isCompareMinCard，此值无效）
		sameCount:相同牌的个数
		isSplit:是否对牌进行拆牌查找 true:拆牌查找 false:不拆牌查找
		outSortArr:符合要求的主牌型 扑克权重排序数组（带出参数）
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindMainCards(const int *sortArray, const int sortArrLen, const bool isCompareMinCard, const CardNumber minCard, const int sameCount, const bool isSplit, int* outSortArr);
		/*
		查找附属牌型  例如3带1，1即为附属牌型
		sortNoMainArray:排除主牌型的扑克权重排序数组
		sortArrLen:扑克权重排序数组长度（固定为14）
		sortArrIndex:扑克权重数组索引位置 即从此索引位置开始查找
		subsidiaryCount:附属牌的个数
		subsidiarySameCount:每个附属牌相同的数量
		isSplit:是否对牌进行拆牌查找 true:拆牌查找 false:不拆牌查找
		outSubsidiaryVec:符合要求的附属牌 值为扑克权重排序数组中的索引值（带出参数）
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindSubsidiaryCards(const int *sortNoMainArray, const int sortArrLen, const int sortArrIndex, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<int> &outSubsidiaryVec);
		bool FindAdjacentIndexCards(const int *sortArray, const int sortArrLen, const vector<int> mainCards, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outCards);
		bool FindSameIndexCards(const int *sortArray, const int sortArrLen, const int cardIndex, const int cardCount, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outCards);
		bool IsSmae(const vector<vector<int>> const hashVec, const vector<int> const subsidiaryCards);

		
	};
}