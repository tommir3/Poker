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

	};
}