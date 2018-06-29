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
		/*
		�ҵ�����ָ���Ƶ���
		cards:������
		len:�����鳤��
		cmpCards:ָ����������
		cmpLen:ָ���������鳤��
		cardType:ָ���Ƶ�����
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, const int len, const int *cmpCards, const int cmpLen, const CardType cardType, vector<vector<int>> &outCards);

		/*
		�ҳ������������е����ƣ�����
		cards:������
		len:������ĳ���
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindStraightSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindStraightPair(const int *cards, const int len, vector<vector<int>> &outCards);
		__declspec(dllexport) bool FindKingBomb(const int *cards, const int len, vector<vector<int>> &outCards);

	private:

		bool FindCards(const int *cards, const int len, const bool isMainSplit,const int adjacentCount, const int mainCardSum, const int subsidiaryCount,const int subsidiarySum, vector<vector<int>> &outCards);
		bool FindCards(const int *cards, const int len, const bool isCompareMinCard, const CardNumber minCard, const bool isMainSplit, const int adjacentCount, const int mainCardSum, const int subsidiaryCount, const int subsidiarySum, vector<vector<int>> &outCards);
		/*
		�˿���ֵת�˿�Ȩ����������
		cards:�˿���ֵ����
		cardsLen:�˿���ֵ���鳤��
		sortArray:�˿�Ȩ���������飨������,��С����3��4��5��6��7��8��9��10��J��Q��K����
		sortArrLen:�˿�Ȩ���������鳤�ȣ��̶�Ϊ14��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool SortArrayCardsToCards(vector<int> sortCards, const int *cards, const int len, vector<int> &outCards);
		/*
		���������Ƶ�������  ����ɻ���2�����ɻ���Ϊ������
		sortArray:�˿�Ȩ����������
		sortArrLen:�˿�Ȩ���������鳤�ȣ��̶�Ϊ14��
		isCompareMinCard:�Ƿ���ұȽϴ����
		minCard:�Ƚ��Ƶ���ֵ�����isCompareMinCard����ֵ��Ч��
		adjacentCount:�����Ƶĸ���
		sameCount:��ͬ�Ƶĸ���
		isSplit:�Ƿ���ƽ��в��Ʋ��� true:���Ʋ��� false:�����Ʋ���
		outSortArrVec:����Ҫ��������͵��˿�Ȩ���������鼯�ϣ�����������
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindMainCards(const int *sortArray, const int sortArrLen, const bool isCompareMinCard, const CardNumber minCard, const int adjacentCount, const int sameCount, const bool isSplit, vector<vector<int>> &outSortArrVec);

		bool FindSubsidiaryCards(const int *sortNoMainArray, const int sortArrLen, const int subsidiaryCount, const int subsidiarySameCount, const bool isSplit, vector<vector<int>> &outSubsidiaryVec);
		bool JoinCards(const int *cards, const int len, const vector<int> const mainCards, const int mainSum, const vector<vector<int>> const subsidiaryCards, const int subsidiarySum, vector<vector<int>> &outCards);
		/*
		����C(M,N)�������  C(len, sub)
		len: �����ܳ��� M
		sub: Ҫ����ϵĳ��� N
		result: C(M,N)�Ľ��
		*/
		bool Cmn(vector<int> cardVec, int len, int sub, vector<vector<int>> &result);
		/*
		��������ҳ����������������
		preWei:ǰһλ��ֵ
		wei:��ǰλ��
		r: ������ϵ���ʱ�������
		len:�����ݳ���
		sub:λ������
		result:�������ļ���
		*/
		void Cmn(int preWei, int wei, vector<int> &r, int len, int sub, vector<vector<int>> &result);		

	};
}