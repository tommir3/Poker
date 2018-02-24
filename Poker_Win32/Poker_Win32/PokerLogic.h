#pragma once
#include "PokerDefine.h"
#include <exception> 

using namespace std;

class PokerLogic
{
public:
	__declspec(dllexport) PokerLogic();
	//PokerLogic(int card_a, int card_2, int card_3, int card_4, int card_5,
	//	int card_6, int card_7, int card_8, int card_9, int card_10,
	//	int card_j, int card_q, int card_k, int card_bj, int card_rj);
	__declspec(dllexport) ~PokerLogic();

	/*
	扑克代码值转扑克牌字面值
	cardValue: 扑克代码值
	cardMark: 转换后扑克牌类型
	cardNum: 转换后扑克牌字面值
	return: 成功返回true,失败返回false
	*/
	__declspec(dllexport) bool ValueToCard(int cardValue, CardMark& cardMark, CardNumber& cardNum);
	/*
	获取扑克牌值
	cardMark: 扑克牌花色
	cardNum: 扑克牌字面值大小
	return: 成功返回扑克牌值，失败返回-1，异常抛出
	*/
	__declspec(dllexport) int CardToValue(CardMark cardMark, CardNumber cardNum);
	/*
	创建一组花色扑克牌
	cardMark: 扑克牌花色枚举
	pokerIndex: 扑克牌套数的索引
	cards: 返回一组花色扑克牌值
	return: 成功返回扑克牌值，失败返回-1，异常抛出
	*/
	__declspec(dllexport) bool CreateCardMarkPoker(const CardMark cardMark, const int pokerIndex, int *cards, const int cardsLen);
	///// <summary>
	///// 创建扑克牌数组
	///// </summary>
	///// <param name="pokerCount">几副扑克牌</param>
	///// <returns>扑克牌数组，失败返回null</returns>
	__declspec(dllexport) bool CreatePoker(const int pokerCount, int *cards, const int cardsLen);
	///// <summary>
	///// 创建一副扑克
	///// </summary>
	///// <returns>扑克牌值的数组</returns>
	//int* CreatePoker();
	///// <summary>
	///// 扑克值转扑克花色类型
	///// </summary>
	///// <param name="value">扑克值</param>
	///// <returns>返回CardMark花色枚举类型</returns>
	//CardMark ValueToMark(int value);
	///// <summary>
	///// 扑克值转权重值
	///// </summary>
	///// <param name="value">扑克值</param>
	///// <returns>返回扑克权重值</returns>
	//int ValueToNumber(int value);
	///// <summary>
	///// 扑克值数组转权重值数组
	///// </summary>
	///// <param name="value">扑克值数组</param>
	///// <returns>返回扑克权重值数组</returns>
	//int* ValueToNumber(int* values);
	///// <summary>
	///// 对比两个扑克牌值
	///// </summary>
	///// <param name="card1">扑克牌值1</param>
	///// <param name="card2">扑克牌值2</param>
	///// <returns>如果card1大于card2，返回1，小于返回-1，返回0表示相等</returns>
	//int CompareValue(int value1, int value2);
	///// <summary>
	///// 判断是否是合法的扑克值
	///// </summary>
	///// <param name="value">扑克牌值</param>
	///// <returns>验证合法返回true，验证失败返回false</returns>
	//bool IsCardValue(int value);
	///// <summary>
	///// 判断是否是合法的一组扑克值
	///// </summary>
	///// <param name="values">扑克值数组</param>
	///// <returns>验证合法返回true，验证失败返回false</returns>
	//bool IsCardValue(int values[]);
private:
	/*
	扑克逻辑类：
	1、扑克牌代码值：value
	2、扑克牌权重值：weight_value w_val   比较牌大小
	3、扑克牌字面值: number num           扑克牌显示的字面值
	*/
	static const int PokerCount = 54;
	static const int SuitsCount = 13;
	static const int JokerCount = 2;
	int Card_Suits_Weight[SuitsCount] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };//13张牌的权重值
	int Card_Joker_Weight[JokerCount] = { 82, 83 };//大小王的权重值
	/*
	扑克权重值转扑克牌面值
	w_val: 权重值
	outCardNum: 扑克牌字面值
	return : 成功返回true,失败返回false
	*/
	bool WeightValueToNumber(const int w_val, CardNumber& cardNum);
};