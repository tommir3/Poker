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
	class DouDiZhuPlayCardLogic : DouDiZhuLogic
	{
	public:

		__declspec(dllexport) DouDiZhuPlayCardLogic();
		__declspec(dllexport) ~DouDiZhuPlayCardLogic();

		/*
		找到相同类型的牌（相同类型的牌）
		cards:牌数组
		len:牌数组长度
		cardType:牌类型
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, 
													const int len, 
													const CardType cardType, 
													vector<vector<int>> &outCards);
		/*
		找到大于指定牌的牌（相同类型的牌）
		cards:牌数组
		len:牌数组长度
		cmpCards:指定的牌数组
		cmpLen:指定的牌数组长度
		cardType:指定牌的类型
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, 
													const int len, 
													const int *cmpCards, 
													const int cmpLen, 
													const CardType cardType, 
													vector<vector<int>> &outCards);
		/*
		找到大于指定牌的牌（如果不是王炸不是炸，则找出炸和王炸）
		cards:牌数组
		len:牌数组长度
		cmpCards:指定的牌数组
		cmpLen:指定的牌数组长度
		cardType:指定牌的类型
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		__declspec(dllexport) bool FindGreaterThanCards(const int *cards,
														const int len,
														const int *cmpCards,
														const int cmpLen,
														const CardType cardType,
														vector<vector<int>> &outCards);
		/*----------------------- 智能拆牌 start ----------------------*/

		bool GetSendCards(const int *cards, const int len,
			const int *cmpCards,
			const int cmpLen,
			const CardType cardType,
			const int *deskCards,
			const int deskCardLen,
			const bool pos1_isFriend,
			const int pos1_CardCount,
			const bool pos2_isFriend,
			const int pos2_CardCount,
			vector<vector<int>> &outCards);
		/*
		一、自己牌最大，找优先出的牌
		1、循环拆分，取切分数量最少的
		（1)双龙
		（2）单龙
		（3）4个
		（4）3个
		（5）双王
		（5）2个
		（6）1个
		二、别人出的牌，找自己能管上的牌

		*/

		/*----------------------- 智能拆牌 end ------------------------*/

	protected:
		/*
		找出牌数组中所有的连牌（龙）
		cards:牌数组
		len:牌数组的长度
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindStraightSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		/*
		找出牌数组中所有的连牌（双龙）
		cards:牌数组
		len:牌数组的长度
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindStraightPair(const int *cards, const int len, vector<vector<int>> &outCards);
		/*
		找出牌数组中的王炸（双王）
		cards:牌数组
		len:牌数组的长度
		outCards:找出符合的所有牌数组集合
		return:成功返回true，失败返回false。异常抛出
		*/
		bool FindKingBomb(const int *cards, const int len, vector<vector<int>> &outCards);
		/*
		找牌
		cards: 牌数组
		len: 牌数组的长度
		isCompareMinCard: 是否有比较牌 即找出比此牌大的牌
		minCard: 比较牌牌值
		isMainSplit: 主牌型是否需要拆牌查找 true:拆牌 false:不拆牌
		adjacentCount: 连续牌的个数（大于1为连续牌）
		mainCardSum: 每个连续牌的数量
		subsidiaryCount: 附属牌的个数
		subsidiarySum: 每个附属牌的数量
		outCards: 找到的牌的数组（带出参数）
		return: 成功返回true，失败返回false。异常抛出
		*/
		bool FindCards(const int *cards, const int len, const bool isCompareMinCard,
						const CardNumber minCard, const bool isMainSplit, 
						const int adjacentCount, const int mainCardSum, 
						const int subsidiaryCount, const int subsidiarySum, 
						vector<vector<int>> &outCards);
		/*
		扑克权重排序数组转扑克牌值
		sortCards:扑克权重排序值的集合
		cards:扑克牌值数组
		len:扑克牌值数组长度
		outCards: 找到的牌的数组（带出参数）
		return:成功返回true，失败返回false。异常抛出
		*/ 
		bool SortArrayCardsToCards(vector<int> sortCards, const int *cards, 
									const int len, vector<int> &outCards);
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
		bool FindMainCards(const int *sortArray, const int sortArrLen, 
							const bool isCompareMinCard, const CardNumber minCard, 
							const int adjacentCount, const int sameCount, 
							const bool isSplit, vector<vector<int>> &outSortArrVec);
		/*
		查找附属牌
		sortNoMainArray: 扑克权重排序数组(去掉主牌型牌的排序数组)
		sortArrLen: 扑克权重排序数组长度（固定为14）
		subsidiaryCount: 附属牌的个数
		subsidiarySameCount: 每个附属牌的数量
		isSplit: 是否对牌进行拆牌查找 true:拆牌查找 false:不拆牌查找
		outSubsidiaryVec: 符合要求的附属牌的扑克权重排序数组集合（带出参数）
		return: 成功返回true，失败返回false。异常抛出
		*/
		bool FindSubsidiaryCards(const int *sortNoMainArray, const int sortArrLen, 
								const int subsidiaryCount, const int subsidiarySameCount, 
								const bool isSplit, vector<vector<int>> &outSubsidiaryVec);
		/*
		结合主牌型和附属牌型
		cards: 牌数组
		len: 牌数组长度
		mainCards: 主牌型集合（值为排序数组中的索引值）
		mainSum: 主牌型每个牌的数量
		subsidiaryCards: 附属牌数组集合（值为排序数组中的索引值）
		subsidiarySum: 附属牌型每个牌的数量
		outCards: 结合后的牌数组集合（带出参数）
		return: 成功返回true，失败返回false。异常抛出
		*/
		bool JoinCards(const int *cards, const int len, const vector<int> const mainCards, 
						const int mainSum, const vector<vector<int>> const subsidiaryCards, 
						const int subsidiarySum, vector<vector<int>> &outCards);
		/*
		计算C(M,N)排列组合  C(len, sub)
		len: 集合总长度 M
		sub: 要找组合的长度 N
		result: C(M,N)的结果
		*/
		bool Cmn(vector<int> cardVec, int len, int sub, vector<vector<int>> &outVec);
		/*
		排列组合找出不重样的组合数组
		preWei:前一位数值
		wei:当前位数
		r: 排列组合的临时存放数组
		len:总数据长度
		sub:位数长度
		result:保存结果的集合
		*/
		void Cmn(int preWei, int wei, vector<int> &r, int len, int sub, vector<vector<int>> &outVec);


		/*----------------------- 智能拆牌 start ----------------------*/

		struct SplitInfo
		{
			CardType _cardType;///类类型
			int _adjacentCount;///连续牌个数
			int _mainCardSum;///主牌型数量
			vector<CardNumber> _mainCardNums;///主牌型牌面值集合
			int _subsidiaryCount;///附属牌数量
			int _subsidiarySum;///附属牌个数
			vector<CardNumber> _subsidiaryCardNums;///附属牌牌面值集合
		};

		bool SplitCardArray(const int *cards, const int len, vector<vector<int>> &outCards);
		void LoopSplit(int *sortArray, vector<SplitInfo> &outCards);

		/*----------------------- 智能拆牌 end ------------------------*/
	};
}