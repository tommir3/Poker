#pragma once
#include "PokerDefine.h" 
#include <exception>
#include "PokerLogic.h"
#include <vector>

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class DouDiZhuPlayCardLogic : PokerLogic
	{
	public:
		__declspec(dllexport) DouDiZhuPlayCardLogic();
		__declspec(dllexport) ~DouDiZhuPlayCardLogic();

		/*
		�ҵ���ͬ����
		cards:������
		cardType:������
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, const CardType cardType, vector<vector<int>> &outCards);

		__declspec(dllexport) bool FindSingle(const int *cards, int *outCard);
		/*
		�ҳ��������е����ж�
		cards:������
		outCards:�ҳ��Ķ������� (��ά����)
		outLen:�������鳤�� (һά���鳤�ȣ���ά����Ϊ�ԣ��̶�2��)
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindPair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThree(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreeSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreePair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFour(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFourSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFourPair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindPlane(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindPlaneSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindPlanePair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreePlane(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreePlaneSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindThreePlanePair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFourPlane(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindFourPlaneSingle(const int *cards, int* &outCards, int &outLen);
		//bool FindFourPlanePair(const int *cards, int* &outCards, int &outLen);//20�� ֻ�е���
		__declspec(dllexport) bool FindFivePlane(const int *cards, int* &outCards, int &outLen);
		//bool FindFivePlaneSingle(const int *cards, int* &outCards, int &outLen);//20�� ֻ�е���
		//bool FindSixPlane(const int *cards, int* &outCards, int &outLen);//18�� ֻ�е���
		__declspec(dllexport) bool FindStraightSingle(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindStraightPair(const int *cards, int* &outCards, int &outLen);
		__declspec(dllexport) bool FindKingBomb(const int *cards, int* &outCards, int &outLen);

	private:
		/*
		�뵽��ͬ��������
		cnsArr:����ֵ�볤��������
		cnsLen:����ֵ�볤�������鳤��
		adjacentCount:�����Ƶĸ���
		sameCount:��ͬ�Ƶĸ���
		outCardNumVec:�˿�������ֵ���鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindCardNumber(const CardNumberSum *cnsArr, const int cnsLen, const int adjacentCount, const int sameCount, vector<vector<CardNumber>> &outCardNumVec);

	};
}