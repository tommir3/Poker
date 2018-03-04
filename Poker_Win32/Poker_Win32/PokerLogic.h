#pragma once
#include "PokerDefine.h"
#include <exception>
#include <ctime>

namespace Poker
{
	using namespace std;
	class PokerLogic
	{
	public:
		static const int PokerCount = 54;
		static const int SuitsCount = 13;
		static const int JokerCount = 2;

		__declspec(dllexport) PokerLogic();
		__declspec(dllexport) PokerLogic(int card_a, int card_2, int card_3, int card_4, int card_5,
			int card_6, int card_7, int card_8, int card_9, int card_10,
			int card_j, int card_q, int card_k, int card_bj, int card_rj);
		__declspec(dllexport) ~PokerLogic();

		/*
		创建一套扑克牌数组
		cards: 存放生成扑克牌数组
		cardsLen: 扑克牌数组大小
		return: 成功返回true，失败返回false，异常抛出
		*/
		__declspec(dllexport) bool CreatePoker(int *cards, const int cardsLen);
		/*
		创建扑克牌数组
		pokerCount: 数量（几套扑克牌）
		cards: 存放生成扑克牌数组
		cardsLen: 扑克牌数组大小
		return: 成功返回true，失败返回false，异常抛出
		*/
		__declspec(dllexport) bool CreatePoker(const int pokerCount, int *cards, const int cardsLen);
		/*
		创建一组花色扑克牌
		cardMark: 扑克牌花色枚举
		pokerIndex: 扑克牌套数的索引
		cards: 返回一组花色扑克牌值
		return: 成功返回true，失败返回false，异常抛出
		*/
		__declspec(dllexport) bool CreateCardMarkPoker(const CardMark cardMark, const int pokerIndex, int *cards, const int cardsLen);
		/*
		扑克代码值转扑克牌字面值
		cardValue: 扑克代码值
		cardMark: 转换后扑克牌类型
		cardNum: 转换后扑克牌字面值
		return: 成功返回true,失败返回false
		*/
		__declspec(dllexport) bool ValueToCard(const int cardValue, CardMark& cardMark, CardNumber& cardNum);
		/*
		获取扑克牌值
		cardMark: 扑克牌花色
		cardNum: 扑克牌字面值大小
		return: 成功返回扑克牌值，失败返回-1，异常抛出
		*/
		__declspec(dllexport) int CardToValue(const CardMark cardMark, const CardNumber cardNum);
		/*
		扑克值转扑克花色类型
		value: 扑克值
		mark: 返回CardMark花色枚举类型
		return: 成功返回true，失败返回false，异常抛出
		*/
		__declspec(dllexport) bool ValueToMark(const int value, CardMark &mark);
		/*
		扑克值转权重值
		value: 扑克值
		return: 成功返回扑克权重值，失败返回-1，异常抛出
		*/
		__declspec(dllexport) int ValueToWeightValue(const int value);
		/*
		扑克值数组转权重值数组
		values: 扑克代码值数组
		valuesLen: 扑克代码值数组长度
		cards: 转换后的扑克牌权重值数据
		cardsLen: 转换后的扑克牌权重值数据长度
		return: 成功返回true,失败返回false,异常抛出
		*/
		__declspec(dllexport) bool ValueToWeightValue(const int values[], const int valuesLen, int *cards, const int cardsLen);
		/*
		扑克值转牌面值
		value: 扑克代码值
		cardNum: 转换后的扑克牌面值
		return: 成功返回true,失败返回false,异常抛出
		*/
		__declspec(dllexport) bool ValueToCardNumber(const int value,  CardNumber &cardNum);
		/*
		扑克值数组转牌面值数组
		values: 扑克代码值数组
		valuesLen: 扑克代码值数组长度
		cardNums: 转换后的扑克牌面值数据
		cardNumsLen: 转换后的扑克牌面值数据长度
		return: 成功返回true,失败返回false,异常抛出
		*/
		__declspec(dllexport) bool ValueToCardNumber(const int values[], const int valuesLen, CardNumber *cardNums, const int cardNumsLen);
		/*
		对比两个扑克牌值
		value1: 扑克牌值1
		value1: 扑克牌值2
		return: 如果value1大于value2，返回1，小于返回-1，返回0表示相等,异常抛出
		*/
		__declspec(dllexport) int CompareValue(const int value1, const int value2);
		/*
		对比两个扑克牌值
		num1: 扑克牌牌面值1
		num2: 扑克牌牌面值2
		return: 如果card1大于card2，返回1，小于返回-1，返回0表示相等,异常抛出
		*/
		__declspec(dllexport) int CompareCardNumber(const CardNumber num1, const CardNumber num2);
		/*
		判断是否是合法的扑克值
		value: 扑克牌值
		return: 验证合法返回true，验证失败返回false，异常抛出
		*/
		__declspec(dllexport) bool IsCardValue(const int value);
		/*
		判断是否是合法的一组扑克值
		value: 扑克值数组
		len: 扑克牌数组长度
		return: 验证合法返回true，验证失败返回false，异常抛出
		*/
		__declspec(dllexport) bool IsCardValue(const int *values, const int len);
		/*
		洗牌（扑克牌数组乱序）
		cards: 扑克值数组
		cardsLen: 扑克牌数组长度
		outCards: 乱序后扑克值数组
		outCardsLen: 乱序扑克牌数组长度
		return: 成功返回true，失败返回false，异常抛出
		*/
		__declspec(dllexport) bool Shuffle(int *cards, const int cardsLen);
		/*
		排序
		cards: 排序的数组
		cardsLen: 排序数组长度
		isAscend: 是否升序 true:从小到大排序; false:从大到小排序
		return: 成功排序返回true, 失败返回false, 异常抛出
		*/
		__declspec(dllexport) void Sort(int *cards, const int cardsLen, const bool isAscend);
		/*
		找出牌在数组中出现的次数
		cards: 牌数组
		len: 数组长度
		val: 比对的值
		return: 找到返回匹配数量, 没有返回0, 异常抛出
		*/
		__declspec(dllexport) int FindCount(const CardNumber *cards, const int len, const CardNumber val);

	private:
		/*
		扑克逻辑类：
		1、扑克牌代码值：value
		2、扑克牌权重值：weight_value w_val   比较牌大小
		3、扑克牌字面值: number num           扑克牌显示的字面值
		*/
		int Card_Suits_Weight[SuitsCount] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };//13张牌的权重值
		int Card_Joker_Weight[JokerCount] = { 82, 83 };//大小王的权重值
		/*
		扑克权重值转扑克牌面值
		w_val: 权重值
		outCardNum: 扑克牌字面值
		return : 成功返回true,失败返回false
		*/
		bool WeightValueToNumber(const int w_val, CardNumber& cardNum);
		int ValueToWeightValue(const int value, const CardMark mark);
		int CardNumberToWeightValue(const CardNumber num);
		/*
		根据参考数组进行排序
		reference: 参考数组
		referenceLen: 参数数据长度
		outCards: 实际进行排序的数组
		couCardsLen: 实际排序数组长度
		isAscend: 是否是升序 true:升序 false:降序
		return: 成功返回true，失败返回false，异常抛出
		*/
		bool SortByArray(int *reference, const int referenceLen, int *outCards, const int couCardsLen, const bool isAscend);
	};
}
