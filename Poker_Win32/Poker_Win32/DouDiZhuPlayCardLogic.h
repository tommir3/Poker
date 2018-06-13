#pragma once
#include "PokerDefine.h" 
#include <exception>
#include "PokerLogic.h"
#include <vector>
#include "DouDiZhuLogic.h"

namespace DouDiZhu
{
	using namespace std;
	using namespace Poker;
	class DouDiZhuPlayCardLogic : PokerLogic, DouDiZhuLogic
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

		__declspec(dllexport) bool FindSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		/*
		�ҳ��������е����ж�
		cards:������
		len:������ĳ���
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindPair(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindThree(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreeSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreePair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFour(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFourSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFourPair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindPlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindPlaneSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindPlanePair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreePlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreePlaneSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindThreePlanePair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFourPlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindFourPlaneSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		//bool FindFourPlanePair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);//20�� ֻ�е���
		__declspec(dllexport) bool FindFivePlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		//bool FindFivePlaneSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);//20�� ֻ�е���
		//bool FindSixPlane(const int *cards, const int len, vector<vector<CardNumber>> &outCards);//18�� ֻ�е���
		__declspec(dllexport) bool FindStraightSingle(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindStraightPair(const int *cards, const int len, vector<vector<CardNumber>> &outCards);
		__declspec(dllexport) bool FindKingBomb(const int *cards, const int len, vector<vector<CardNumber>> &outCards);

	private:
		/*
		�˿���ֵת�˿���Ϣ�༯��
		cards:�˿���ֵ����
		cardsLen:�˿���ֵ���鳤��
		cnsArr:�˿���Ϣ�༯�ϣ�������,��С����
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool CardsToCardNumberSum(const int *cards, const int cardsLen, std::vector<CardNumberSum> &cnsArr);
		/*
		�뵽��ͬ��������
		cnsVec:����ֵ�볤���༯��
		adjacentCount:�����Ƶĸ���
		sameCount:��ͬ�Ƶĸ���
		isSplit:�Ƿ���ƽ��в��Ʋ��� true:���Ʋ��� false:�����Ʋ���
		outCardNumVec:�˿�������ֵ���鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindCardNumber(const std::vector<CardNumberSum> cnsVec, const int adjacentCount, const int sameCount, const bool isSplit, std::vector<std::vector<CardNumber>> &outCardNumVec);

		bool FineCardValue(const int *cards, const int len, const vector<vector<CardNumber>> const findCards, const int count, vector<vector<int>> &outCards);

	};
}