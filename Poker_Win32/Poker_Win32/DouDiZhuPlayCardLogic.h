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
		�ҵ���ͬ���͵���
		cards:������
		len:�����鳤��
		cardType:������
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, const int len, const CardType cardType, vector<vector<int>> &outCards);

		__declspec(dllexport) bool FindTargetCards(const int *cards, const int len, const int *cmpCards, const int cmpLen, const CardType cardType, vector<vector<int>> &outCards);

		__declspec(dllexport) bool FindSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		/*
		�ҳ��������е����ж�
		cards:������
		len:������ĳ���
		cmpCards:�Ƚ��ƣ��ұȴ��ƴ���ƣ�
		cmpLen:�Ƚ��Ƶĳ���
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindPair(const int *cards, const int len, const int *cmpCards, const int cmpLen, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindThree(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindThreeSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindThreePair(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindFour(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindFourSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindFourPair(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindPlane(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindPlaneSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindPlanePair(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindThreePlane(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindThreePlaneSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindThreePlanePair(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindFourPlane(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindFourPlaneSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		//bool FindFourPlanePair(const int *cards, const int len, vector<vector<int>> &outCards);//20�� ֻ�е���
		__declspec(dllexport) bool FindFivePlane(const int *cards, const int len, vector<vector<int>> &outCards);
		//bool FindFivePlaneSingle(const int *cards, const int len, vector<vector<int>> &outCards);//20�� ֻ�е���
		//bool FindSixPlane(const int *cards, const int len, vector<vector<int>> &outCards);//18�� ֻ�е���
		__declspec(dllexport) bool FindStraightSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindStraightPair(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindKingBomb(const int *cards, const int len, vector<vector<int>> &outCards);

	private:
		static const int CardSortCount = PokerLogic::SuitsCount + 1;
		/*������������ʱ������ʽ ���Σ�3��4��5��6��7��8��9��10��J��Q��K��A��2����*/
		int SortStyle[CardSortCount] = { 11, 12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13 };

		bool FindCards(const int *cards, const int len, const bool isMainSplit,const int adjacentCount, const int mainCardSum, const int subsidiaryCount,const int subsidiarySum, vector<vector<int>> &outCards);

		int SortStyleValueToCardNumber(const int value);
		
		/*
		�˿���ֵת�˿�Ȩ����������
		cards:�˿���ֵ����
		cardsLen:�˿���ֵ���鳤��
		sortArray:�˿�Ȩ���������飨������,��С����3��4��5��6��7��8��9��10��J��Q��K����
		sortArrLen:�˿�Ȩ���������鳤�ȣ��̶�Ϊ14��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool CardsToSortArray(const int *cards, const int cardsLen, int *sortArray, const int sortArrLen);
		bool SortArrayCardsToCards(const vector<vector<int>> const sortCardsList, const int *cards, const int len, vector<vector<int>> &outCardsList);
		bool SortArrayCardsToCards(vector<int> sortCards, const int *cards, const int len, vector<int> &outCards);
		/*
		���������Ƶ�������  ����ɻ���2�����ɻ���Ϊ������
		sortArray:�˿�Ȩ����������
		sortArrLen:�˿�Ȩ���������鳤�ȣ��̶�Ϊ14��
		adjacentCount:�����Ƶĸ���
		sameCount:��ͬ�Ƶĸ���
		isSplit:�Ƿ���ƽ��в��Ʋ��� true:���Ʋ��� false:�����Ʋ���
		outSortArrVec:����Ҫ��������͵��˿�Ȩ���������鼯�ϣ�����������
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindMainCards(const int *sortArray, const int sortArrLen, const int adjacentCount, const int sameCount, const bool isSplit, vector<vector<int>> &outSortArrVec);
		/*
		������ͬ�Ƶ�������  ����3��1��3��Ϊ������
		sortArray:�˿�Ȩ����������
		sortArrLen:�˿�Ȩ���������鳤�ȣ��̶�Ϊ14��
		sameCount:��ͬ�Ƶĸ���
		isSplit:�Ƿ���ƽ��в��Ʋ��� true:���Ʋ��� false:�����Ʋ���
		outSortArr:����Ҫ��������� �˿�Ȩ���������飨����������
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindMainCards(const int *sortArray, const int sortArrLen, const int sameCount, const bool isSplit, int* outSortArr);
		/*
		���Ҹ�������  ����3��1��1��Ϊ��������
		sortNoMainArray:�ų������͵��˿�Ȩ����������
		sortArrLen:�˿�Ȩ���������鳤�ȣ��̶�Ϊ14��
		sortArrIndex:�˿�Ȩ����������λ�� ���Ӵ�����λ�ÿ�ʼ����
		subsidiaryCount:�����Ƶĸ���
		subsidiarySameCount:ÿ����������ͬ������
		isSplit:�Ƿ���ƽ��в��Ʋ��� true:���Ʋ��� false:�����Ʋ���
		outSubsidiaryVec:����Ҫ��ĸ����� ֵΪ�˿�Ȩ�����������е�����ֵ������������
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindSubsidiaryCards(const int *sortNoMainArray, const int sortArrLen, const int sortArrIndex, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<int> &outSubsidiaryVec);
		bool FindAdjacentIndexCards(const int *sortArray, const int sortArrLen, const vector<int> mainCards, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outCards);
		bool FindSameIndexCards(const int *sortArray, const int sortArrLen, const int cardIndex, const int cardCount, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outCards);
		bool IsSmae(const vector<vector<int>> const hashVec, const vector<int> const subsidiaryCards);

	};
}