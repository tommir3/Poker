#pragma once
#include "PokerDefine.h" 
#include <exception>
#include "PokerLogic.h"
#include <vector>

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class DouDiZhuPlayCardLogic
	{
	public:
		/*
		�ҵ���ͬ����
		*/
		bool FindTargetCards(const int *cards, const CardType cardType, vector<vector<int>> outCards);

		bool FindSingle(const int *cards, int *outCard);
		/*
		�ҳ��������е����ж�
		cards:������
		outCards:�ҳ��Ķ������� (��ά����)
		outLen:�������鳤�� (һά���鳤�ȣ���ά����Ϊ�ԣ��̶�2��)
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindPair(const int *cards, int* &outCards, int &outLen);
		bool FindThree(const int *cards, int* &outCards, int &outLen);
		bool FindThreeSingle(const int *cards, int* &outCards, int &outLen);
		bool FindThreePair(const int *cards, int* &outCards, int &outLen);
		bool FindFour(const int *cards, int* &outCards, int &outLen);
		bool FindFourSingle(const int *cards, int* &outCards, int &outLen);
		bool FindFourPair(const int *cards, int* &outCards, int &outLen);
		bool FindPlane(const int *cards, int* &outCards, int &outLen);
		bool FindPlaneSingle(const int *cards, int* &outCards, int &outLen);
		bool FindPlanePair(const int *cards, int* &outCards, int &outLen);
		bool FindThreePlane(const int *cards, int* &outCards, int &outLen);
		bool FindThreePlaneSingle(const int *cards, int* &outCards, int &outLen);
		bool FindThreePlanePair(const int *cards, int* &outCards, int &outLen);
		bool FindFourPlane(const int *cards, int* &outCards, int &outLen);
		bool FindFourPlaneSingle(const int *cards, int* &outCards, int &outLen);
		//bool FindFourPlanePair(const int *cards, int* &outCards, int &outLen);//20�� ֻ�е���
		bool FindFivePlane(const int *cards, int* &outCards, int &outLen);
		//bool FindFivePlaneSingle(const int *cards, int* &outCards, int &outLen);//20�� ֻ�е���
		//bool FindSixPlane(const int *cards, int* &outCards, int &outLen);//18�� ֻ�е���
		bool FindStraightSingle(const int *cards, int* &outCards, int &outLen);
		bool FindStraightPair(const int *cards, int* &outCards, int &outLen);
		bool FindKingBomb(const int *cards, int* &outCards, int &outLen);

		/*
		�뵽��ͬ��������
		cnsArr:����ֵ�볤��������
		cnsLen:����ֵ�볤�������鳤��
		adjacentCount:�����Ƶĸ���
		sameCount:��ͬ�Ƶĸ���
		outCnsIdxArr:����ֵ�볤�����������ڵ�����ֵ����
		outCnsIdxLen:����ֵ�볤�����������ڵ�����ֵ���鳤��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindCardNumberSum(const CardNumberSum *cnsArr, const int cnsLen, const int adjacentCount, const int sameCount, int* &outCnsIdxArr, int &outCnsIdxLen);

	private:

	};
}