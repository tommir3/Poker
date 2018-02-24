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
	�˿˴���ֵת�˿�������ֵ
	cardValue: �˿˴���ֵ
	cardMark: ת�����˿�������
	cardNum: ת�����˿�������ֵ
	return: �ɹ�����true,ʧ�ܷ���false
	*/
	__declspec(dllexport) bool ValueToCard(int cardValue, CardMark& cardMark, CardNumber& cardNum);
	/*
	��ȡ�˿���ֵ
	cardMark: �˿��ƻ�ɫ
	cardNum: �˿�������ֵ��С
	return: �ɹ������˿���ֵ��ʧ�ܷ���-1���쳣�׳�
	*/
	__declspec(dllexport) int CardToValue(CardMark cardMark, CardNumber cardNum);
	/*
	����һ�黨ɫ�˿���
	cardMark: �˿��ƻ�ɫö��
	pokerIndex: �˿�������������
	cards: ����һ�黨ɫ�˿���ֵ
	return: �ɹ������˿���ֵ��ʧ�ܷ���-1���쳣�׳�
	*/
	__declspec(dllexport) bool CreateCardMarkPoker(const CardMark cardMark, const int pokerIndex, int *cards, const int cardsLen);
	///// <summary>
	///// �����˿�������
	///// </summary>
	///// <param name="pokerCount">�����˿���</param>
	///// <returns>�˿������飬ʧ�ܷ���null</returns>
	__declspec(dllexport) bool CreatePoker(const int pokerCount, int *cards, const int cardsLen);
	///// <summary>
	///// ����һ���˿�
	///// </summary>
	///// <returns>�˿���ֵ������</returns>
	//int* CreatePoker();
	///// <summary>
	///// �˿�ֵת�˿˻�ɫ����
	///// </summary>
	///// <param name="value">�˿�ֵ</param>
	///// <returns>����CardMark��ɫö������</returns>
	//CardMark ValueToMark(int value);
	///// <summary>
	///// �˿�ֵתȨ��ֵ
	///// </summary>
	///// <param name="value">�˿�ֵ</param>
	///// <returns>�����˿�Ȩ��ֵ</returns>
	//int ValueToNumber(int value);
	///// <summary>
	///// �˿�ֵ����תȨ��ֵ����
	///// </summary>
	///// <param name="value">�˿�ֵ����</param>
	///// <returns>�����˿�Ȩ��ֵ����</returns>
	//int* ValueToNumber(int* values);
	///// <summary>
	///// �Ա������˿���ֵ
	///// </summary>
	///// <param name="card1">�˿���ֵ1</param>
	///// <param name="card2">�˿���ֵ2</param>
	///// <returns>���card1����card2������1��С�ڷ���-1������0��ʾ���</returns>
	//int CompareValue(int value1, int value2);
	///// <summary>
	///// �ж��Ƿ��ǺϷ����˿�ֵ
	///// </summary>
	///// <param name="value">�˿���ֵ</param>
	///// <returns>��֤�Ϸ�����true����֤ʧ�ܷ���false</returns>
	//bool IsCardValue(int value);
	///// <summary>
	///// �ж��Ƿ��ǺϷ���һ���˿�ֵ
	///// </summary>
	///// <param name="values">�˿�ֵ����</param>
	///// <returns>��֤�Ϸ�����true����֤ʧ�ܷ���false</returns>
	//bool IsCardValue(int values[]);
private:
	/*
	�˿��߼��ࣺ
	1���˿��ƴ���ֵ��value
	2���˿���Ȩ��ֵ��weight_value w_val   �Ƚ��ƴ�С
	3���˿�������ֵ: number num           �˿�����ʾ������ֵ
	*/
	static const int PokerCount = 54;
	static const int SuitsCount = 13;
	static const int JokerCount = 2;
	int Card_Suits_Weight[SuitsCount] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };//13���Ƶ�Ȩ��ֵ
	int Card_Joker_Weight[JokerCount] = { 82, 83 };//��С����Ȩ��ֵ
	/*
	�˿�Ȩ��ֵת�˿�����ֵ
	w_val: Ȩ��ֵ
	outCardNum: �˿�������ֵ
	return : �ɹ�����true,ʧ�ܷ���false
	*/
	bool WeightValueToNumber(const int w_val, CardNumber& cardNum);
};