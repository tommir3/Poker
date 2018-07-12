#pragma once
#include "PokerDefine.h"
#include <exception>
#include "PokerLogic.h"

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	/*�����������͵�Ȩ��ֵ���� ����Ϊ��A 2 3 4 5 6 7 8 9 10 J Q K С�� ����*/
	static const int Poker_Weight[PokerLogic::SuitsCount + PokerLogic::JokerCount] = { 14, 15, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 82, 83 };
	class DouDiZhuLogic : public PokerLogic
	{
	public:
		__declspec(dllexport) DouDiZhuLogic();
		__declspec(dllexport) ~DouDiZhuLogic();

		/*
		��ȡһ���Ƶ�������
		cards: ������
		len: ���鳤��
		return: ����������ö��, �쳣�׳�
		*/
		__declspec(dllexport) CardType GetCardType(const int *cards, const int len);
		/*
		�ж��������Ƿ���ָ��������
		cardType: ָ��������
		cards: ������
		len: ���鳤��
		return: �Ƿ���true, ���Ƿ���false, �쳣�׳�
		*/
		__declspec(dllexport) bool IsCardType(const CardType cardType, const int *cards, const int len);
		/*
		�Ƚ������ƴ�С
		cards1: ������1
		cards1Len: ����1����
		cards2: ������2
		cards2Len: ����2����
		return: ���رȽ�ֵ��1��cards1����cards2��0��cards1����cards2��-1��cards1С��cards2���쳣�׳�
		*/
		__declspec(dllexport) int CompareCards(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		/*
		�Ƚ�ָ�����͵������ƴ�С
		cards1: ������1
		cards1Len: ����1����
		card1Type: ������1����
		cards2: ������2
		cards2Len: ����2����
		card2Type: ������2����
		return: ���رȽ�ֵ��1��cards1����cards2��0��cards1����cards2��-1��cards1С��cards2���쳣�׳�
		*/
		__declspec(dllexport) int CompareCards(const int *cards1, const int cards1Len, const CardType card1Type, const int *cards2, const int cards2Len, const CardType card2Type);

	protected:
		/*�������鳤�� 3 �� K + ��*/
		static const int CardSortCount = PokerLogic::SuitsCount + 1;
		/*������������ʱ������ʽ ���Σ�3��4��5��6��7��8��9��10��J��Q��K��A��2����*/
		int SortStyle[CardSortCount] = { 11, 12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13 };
		/*
		������ʽ����ֵת������ֵ
		value: ������ʽ����ֵ
		cardNum: ��ֵ������������
		return: �ɹ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool SortStyleValueToCardNumber(const int value, CardNumber & cardNum);
		/*
		������ֵת��������ֵ ��תSortStyle�����е�ֵ��
		cardNum: ��ֵ
		return: �ɹ�����SortStyle�����е�ֵ, ʧ�ܷ���-1, �쳣�׳�
		*/
		int CardNumberToSortArrayValue(const CardNumber cardNum);
		/*
		��ֵ����ת��������ֵ
		cards: ������
		cardsLen: �����鳤��
		sortArray: �������飨����������(CardSortCount���ȵ�����)
		sortArrLen: �������鳤��
		return: �ɹ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool CardsToSortArray(const int *cards, const int cardsLen, int *sortArray, const int sortArrLen);
		/*
		��ȡָ���������еıȽ���ֵ
		cards: ������
		len: �����鳤��
		cardType: ָ��������
		cardNum: ������ֵ������������
		return: �ɹ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool GetCompareCardNumber(const int *cards, const int len, const CardType cardType, CardNumber &cardNum);
		/*
		��������
		cards: ������
		len: ���鳤��
		outCards: ���Ƶ����飨����������
		return: �ɹ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool CloneArray(const int *cards, const int len, int *outCards);
		/*
		�Ƿ�����������
		sortArray: �˿��Ƶ���������
		sortArrLen: �������鳤��
		index: ���������в��ҵ�����λ��
		adjacentCount: �����Ƶĸ���
		sameCount: ��������ͬ������
		return: �ɹ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool IsAdjacentCard(const int *sortArray, const int sortArrLen, const int index, const int adjacentCount, const int sameCount);

	private:
		/*
		�ж��Ƿ���ը
		cards: ������
		len: ���鳤��
		return: �ɹ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool IsKingBomb(const int *cards, const int len);
		/*
		�Ƿ�����ȷ��������
		cards: ������
		len: ���鳤��
		adjacentCount: �����Ƶĸ���
		sameCount: ��������ͬ������
		subsidiaryCount: �����Ƶĸ���
		subsidiarySameCount: ��������ͬ������
		return: �ɹ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool IsTrueCardType(const int *cards, const int len, const int adjacentCount, const int sameCount, const int subsidiaryCount, const int subsidiarySameCount);

	};
}