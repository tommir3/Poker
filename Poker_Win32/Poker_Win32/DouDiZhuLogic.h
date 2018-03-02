#pragma once
#include "PokerDefine.h"
#include <exception>
#include "PokerLogic.h"

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class DouDiZhuLogic : public PokerLogic
	{
	public:
		__declspec(dllexport) DouDiZhuLogic();
		__declspec(dllexport) ~DouDiZhuLogic();

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

		__declspec(dllexport) bool IsStraightSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsStraightPair(const int *cards, const int len);

		__declspec(dllexport) bool IsKingBomb(const int *cards, const int len);

	private:
		/*
		�ж��Ƿ�ȫ����ͬ
		cards: ������
		len: ���鳤��
		return: ��ͬ����true, ��ͬ����false, �쳣�׳�
		*/
		bool IsAllSame(const int *cards, const int len);
		/*
		�ж��Ƿ���ָ����������ͬ��
		cards: ����֤��������
		len: ���鳤��
		sameCount: ָ����ͬ�Ƶ�����
		return: ��ָ����ͬ�Ʒ���true, û�з���false, �쳣�׳�
		*/
		bool IsSame(const int *cards, const int len, const int sameCount, CardNumber &sameNumber);
		
		bool FindNumberCount(const int *cards, const int cardsLen, CardNumberSum *sumArr, const int arrLen);
		/*
		�ҳ���ͬ�Ƶ�����
		cards: ��ֵ����
		cardsLen: ���鳤��
		numArr: ����ֵ����
		sumArr: ÿ������ֵ��������
		arrLen: ����ֵ����������������鳤��
		return: �ɹ��ҳ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool FindNumberCount(const int *cards, const int cardsLen, CardNumber *numArr, int *sumArr, const int arrLen);
		/*
		�Ƿ���X�����ķɻ�
		cardNums: ����ֵ����(cardNums�����С�������򣬷����޷�׼ȷ����)
		cardNumsLen: ����ֵ���鳤��
		x: ָ������
		return: �ɹ��ҳ�����true, ʧ�ܷ���false, �쳣�׳�
		*/
		bool IsXPlane(const CardNumberSum *cardNums, const int cardNumsLen, const int index, const int planeCount);

		void SortCardNumberSum(CardNumberSum *cnsArr, const int cnsArrLen);
		//bool GetSame(const int *cards, const int cardsLen, const int sameCount, CardNumber *sameNumber, int &sameLen);
	};
}