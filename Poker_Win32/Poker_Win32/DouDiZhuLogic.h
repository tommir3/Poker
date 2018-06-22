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


		__declspec(dllexport) CardType GetCardType(const int *cards, const int len);
		__declspec(dllexport) int CompareCards(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len);
		__declspec(dllexport) int CompareCards(const int *cards1, const int cards1Len, const CardType card1Type, const int *cards2, const int cards2Len, const CardType card2Type);

		/*
		�Ƿ���һ����ͬ��(��С������һ��)
		cards: �жϵ�������
		len: ���鳤��
		return: �ǶԷ���true, ���Ƿ���false, �쳣�׳�
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
		/*������������ʱ������ʽ ���Σ�3��4��5��6��7��8��9��10��J��Q��K��A��2����*/
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
		�ж��Ƿ�ȫ����ͬ
		cards: ������
		len: ���鳤��
		return: ��ͬ����true, ��ͬ����false, �쳣�׳�
		*/
		bool IsAllSame(const int *cards, const int len);
		/*
		�ҳ���ͬ�Ƶ�����
		cards: ��ֵ����
		cardsLen: ���鳤��
		cnsArr: ����ֵ������������
		arrLen: ����ֵ�����������鳤��
		return: �ɹ��ҳ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool FindCardNumberCount(const int *cards, const int cardsLen, CardNumberSum *cnsArr, const int arrLen);
		/*
		�Ƿ�����ƶ�����ֵ
		cnsArr: ����ֵ�볤�Ƚṹ����
		cnsArrLen: ����ֵ�볤�Ƚṹ���鳤��
		cardNum: �ƶ�����ֵ
		return: �ɹ��ҳ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool IsExistCardNumber(const CardNumberSum *cnsArr, const int cnsArrLen, const CardNumber cardNum);
		/*
		�Ƿ���X�����ķɻ�
		cardNums: ����ֵ����(cardNums�����С�������򣬷����޷�׼ȷ����)
		cardNumsLen: ����ֵ���鳤��
		x: ָ������
		return: �ɹ��ҳ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool IsXPlane(const CardNumberSum *cardNums, const int cardNumsLen, const int index, const int planeCount);
		/*
		��������ֵ�볤�Ƚṹ���飨С��������
		cnsArr: ����ֵ�볤��������
		cnsArrLen: ����ֵ�볤�������鳤��
		�쳣�׳�
		*/
		void SortCardNumberSum(CardNumberSum *cnsArr, const int cnsArrLen);
		/*
		����bool������ȷֵ(����true)
		arr: bool����
		arrLen: bool���鳤��
		count: ����true����
		return: �ɹ����÷���true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool SetArrayTrue(bool *arr, const int arrLen, const int count);
		/*
		�ж�bool�����Ƿ�ȫ����ȷ���ж��Ƿ�ȫΪtrue��
		arr: bool����
		arrLen: bool���鳤��
		return: ȫ��Ϊtrue����true, ���򷵻�false, �쳣�׳�
		*/
		bool IsArrayTrue(const bool *arr, const int arrLen);
		/*
		�Ƚ�������ͬ�����С�����ţ�����һ�������ԣ����ţ��Ĵ������Ĵ��ԣ�
		cards1: ��һ����ֵ����
		cards1Len: ���鳤��
		cards2: �ڶ�����ֵ����
		cards2Len: ���鳤��
		cnsLen: ��������������������Ĵ���������Ϊ��4 1 1������Ϊ3����
		sameCount: ��ͬ��������������Ƚ��Ĵ������Ƚϵľ���4����ͬ���ƣ�����Ϊ��4��
		return: �Ƚ�ֵ��1��cards1����cards2��0��cards1����cards2��-1��cards1С��cards2���쳣�׳�
		*/
		int CompareSameArray(const int *cards1, const int cards1Len,
							const int *cards2, const int cards2Len,
							const int cnsLen, const int sameCount);
		/*
		���˿�����Ϣ�������ҳ���ͬ��������
		cnsArr:����ֵ�볤��������
		cnsArrLen:����ֵ�볤�������鳤��
		findCount:���Ƶ�����
		outCardNum:�ҳ����˿�������ֵ
		return:�ɹ��ҳ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool GetCardNumberByCardNumberSum(const CardNumberSum *cnsArr, const int cnsArrLen, const int findCount, CardNumber *outCardNum);
		/*
		�Ƚ����ڵ��˿���
		cards1:��һ����
		cards1Len:��һ��������
		cards2:�ڶ�����
		cards2Len:�ڶ���������
		cnsLen:��������������������Ĵ���������Ϊ��4 1 1������Ϊ3����
		adjacentCount:�����Ƶĸ���
		sameCount:��ͬ�Ƶ�����
		return:�Ƚ�ֵ0��1��-1��1��cards1����cards2��0��cards1����cards2��-1��cards1С��cards2���쳣�׳�
		*/
		int CompareAdjacentPoker(const int *cards1, const int cards1Len, const int *cards2, const int cards2Len, const int cnsLen, const int adjacentCount, const int sameCount);
		/*
		����������Ϣ�л�ȡ��ֵ������
		cnsArr:����ֵ�볤��������
		cnsArrLen:����ֵ�볤�������鳤��
		adjacentCount:�����Ƶĸ���
		sameCount:��ͬ�Ƶ�����
		outCardNum:�ҳ��������ֵ
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool GetMaxCompareNumberByAdjacent(const CardNumberSum *cnsArr, const int cnsArrLen, const int adjacentCount, const int sameCount, CardNumber *outCardNum);
		/*
		�Ƿ������ڵ���
		cnsArr:����ֵ�볤��������
		cnsArrLen:����ֵ�볤�������鳤��
		index:�������� ���Ӵ�����λ�ÿ�ʼ�����ڵ���
		adjacentCount:�����Ƶĸ���
		sameCount:��ͬ�Ƶ�����
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool IsAdjacent(const CardNumberSum *cnsArr, const int cnsArrLen, const int index, const int adjacentCount, const int sameCount);
	};
}