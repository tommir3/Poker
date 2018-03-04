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
		����һ���˿�������
		cards: ��������˿�������
		cardsLen: �˿��������С
		return: �ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool CreatePoker(int *cards, const int cardsLen);
		/*
		�����˿�������
		pokerCount: �����������˿��ƣ�
		cards: ��������˿�������
		cardsLen: �˿��������С
		return: �ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool CreatePoker(const int pokerCount, int *cards, const int cardsLen);
		/*
		����һ�黨ɫ�˿���
		cardMark: �˿��ƻ�ɫö��
		pokerIndex: �˿�������������
		cards: ����һ�黨ɫ�˿���ֵ
		return: �ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool CreateCardMarkPoker(const CardMark cardMark, const int pokerIndex, int *cards, const int cardsLen);
		/*
		�˿˴���ֵת�˿�������ֵ
		cardValue: �˿˴���ֵ
		cardMark: ת�����˿�������
		cardNum: ת�����˿�������ֵ
		return: �ɹ�����true,ʧ�ܷ���false
		*/
		__declspec(dllexport) bool ValueToCard(const int cardValue, CardMark& cardMark, CardNumber& cardNum);
		/*
		��ȡ�˿���ֵ
		cardMark: �˿��ƻ�ɫ
		cardNum: �˿�������ֵ��С
		return: �ɹ������˿���ֵ��ʧ�ܷ���-1���쳣�׳�
		*/
		__declspec(dllexport) int CardToValue(const CardMark cardMark, const CardNumber cardNum);
		/*
		�˿�ֵת�˿˻�ɫ����
		value: �˿�ֵ
		mark: ����CardMark��ɫö������
		return: �ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool ValueToMark(const int value, CardMark &mark);
		/*
		�˿�ֵתȨ��ֵ
		value: �˿�ֵ
		return: �ɹ������˿�Ȩ��ֵ��ʧ�ܷ���-1���쳣�׳�
		*/
		__declspec(dllexport) int ValueToWeightValue(const int value);
		/*
		�˿�ֵ����תȨ��ֵ����
		values: �˿˴���ֵ����
		valuesLen: �˿˴���ֵ���鳤��
		cards: ת������˿���Ȩ��ֵ����
		cardsLen: ת������˿���Ȩ��ֵ���ݳ���
		return: �ɹ�����true,ʧ�ܷ���false,�쳣�׳�
		*/
		__declspec(dllexport) bool ValueToWeightValue(const int values[], const int valuesLen, int *cards, const int cardsLen);
		/*
		�˿�ֵת����ֵ
		value: �˿˴���ֵ
		cardNum: ת������˿�����ֵ
		return: �ɹ�����true,ʧ�ܷ���false,�쳣�׳�
		*/
		__declspec(dllexport) bool ValueToCardNumber(const int value,  CardNumber &cardNum);
		/*
		�˿�ֵ����ת����ֵ����
		values: �˿˴���ֵ����
		valuesLen: �˿˴���ֵ���鳤��
		cardNums: ת������˿�����ֵ����
		cardNumsLen: ת������˿�����ֵ���ݳ���
		return: �ɹ�����true,ʧ�ܷ���false,�쳣�׳�
		*/
		__declspec(dllexport) bool ValueToCardNumber(const int values[], const int valuesLen, CardNumber *cardNums, const int cardNumsLen);
		/*
		�Ա������˿���ֵ
		value1: �˿���ֵ1
		value1: �˿���ֵ2
		return: ���value1����value2������1��С�ڷ���-1������0��ʾ���,�쳣�׳�
		*/
		__declspec(dllexport) int CompareValue(const int value1, const int value2);
		/*
		�Ա������˿���ֵ
		num1: �˿�������ֵ1
		num2: �˿�������ֵ2
		return: ���card1����card2������1��С�ڷ���-1������0��ʾ���,�쳣�׳�
		*/
		__declspec(dllexport) int CompareCardNumber(const CardNumber num1, const CardNumber num2);
		/*
		�ж��Ƿ��ǺϷ����˿�ֵ
		value: �˿���ֵ
		return: ��֤�Ϸ�����true����֤ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool IsCardValue(const int value);
		/*
		�ж��Ƿ��ǺϷ���һ���˿�ֵ
		value: �˿�ֵ����
		len: �˿������鳤��
		return: ��֤�Ϸ�����true����֤ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool IsCardValue(const int *values, const int len);
		/*
		ϴ�ƣ��˿�����������
		cards: �˿�ֵ����
		cardsLen: �˿������鳤��
		outCards: ������˿�ֵ����
		outCardsLen: �����˿������鳤��
		return: �ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool Shuffle(int *cards, const int cardsLen);
		/*
		����
		cards: ���������
		cardsLen: �������鳤��
		isAscend: �Ƿ����� true:��С��������; false:�Ӵ�С����
		return: �ɹ����򷵻�true, ʧ�ܷ���false, �쳣�׳�
		*/
		__declspec(dllexport) void Sort(int *cards, const int cardsLen, const bool isAscend);
		/*
		�ҳ����������г��ֵĴ���
		cards: ������
		len: ���鳤��
		val: �ȶԵ�ֵ
		return: �ҵ�����ƥ������, û�з���0, �쳣�׳�
		*/
		__declspec(dllexport) int FindCount(const CardNumber *cards, const int len, const CardNumber val);

	private:
		/*
		�˿��߼��ࣺ
		1���˿��ƴ���ֵ��value
		2���˿���Ȩ��ֵ��weight_value w_val   �Ƚ��ƴ�С
		3���˿�������ֵ: number num           �˿�����ʾ������ֵ
		*/
		int Card_Suits_Weight[SuitsCount] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };//13���Ƶ�Ȩ��ֵ
		int Card_Joker_Weight[JokerCount] = { 82, 83 };//��С����Ȩ��ֵ
		/*
		�˿�Ȩ��ֵת�˿�����ֵ
		w_val: Ȩ��ֵ
		outCardNum: �˿�������ֵ
		return : �ɹ�����true,ʧ�ܷ���false
		*/
		bool WeightValueToNumber(const int w_val, CardNumber& cardNum);
		int ValueToWeightValue(const int value, const CardMark mark);
		int CardNumberToWeightValue(const CardNumber num);
		/*
		���ݲο������������
		reference: �ο�����
		referenceLen: �������ݳ���
		outCards: ʵ�ʽ������������
		couCardsLen: ʵ���������鳤��
		isAscend: �Ƿ������� true:���� false:����
		return: �ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool SortByArray(int *reference, const int referenceLen, int *outCards, const int couCardsLen, const bool isAscend);
	};
}
