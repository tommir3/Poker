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

		__declspec(dllexport) bool IsFourPlanePair(const int *cards, const int len);

		__declspec(dllexport) bool IsFivePlane(const int *cards, const int len);

		__declspec(dllexport) bool IsFivePlaneSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsStraightSingle(const int *cards, const int len);

		__declspec(dllexport) bool IsStraightPair(const int *cards, const int len);

		__declspec(dllexport) bool IsKingBomb(const int *cards, const int len);

	private:
		class CardNumberSum
		{
		public:
			CardNumber num;
			int count;
		};
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
	};
}