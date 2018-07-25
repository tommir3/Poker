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
	class DouDiZhuPlayCardLogic : DouDiZhuLogic
	{
	public:

		__declspec(dllexport) DouDiZhuPlayCardLogic();
		__declspec(dllexport) ~DouDiZhuPlayCardLogic();

		/*
		�ҵ���ͬ���͵��ƣ���ͬ���͵��ƣ�
		cards:������
		len:�����鳤��
		cardType:������
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, 
													const int len, 
													const CardType cardType, 
													vector<vector<int>> &outCards);
		/*
		�ҵ�����ָ���Ƶ��ƣ���ͬ���͵��ƣ�
		cards:������
		len:�����鳤��
		cmpCards:ָ����������
		cmpLen:ָ���������鳤��
		cardType:ָ���Ƶ�����
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindTargetCards(const int *cards, 
													const int len, 
													const int *cmpCards, 
													const int cmpLen, 
													const CardType cardType, 
													vector<vector<int>> &outCards);
		/*
		�ҵ�����ָ���Ƶ��ƣ����������ը����ը�����ҳ�ը����ը��
		cards:������
		len:�����鳤��
		cmpCards:ָ����������
		cmpLen:ָ���������鳤��
		cardType:ָ���Ƶ�����
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		__declspec(dllexport) bool FindGreaterThanCards(const int *cards,
														const int len,
														const int *cmpCards,
														const int cmpLen,
														const CardType cardType,
														vector<vector<int>> &outCards);
		/*----------------------- ���ܲ��� start ----------------------*/

		bool GetSendCards(const int *cards, const int len,
			const int *cmpCards,
			const int cmpLen,
			const CardType cardType,
			const int *deskCards,
			const int deskCardLen,
			const bool pos1_isFriend,
			const int pos1_CardCount,
			const bool pos2_isFriend,
			const int pos2_CardCount,
			vector<vector<int>> &outCards);
		/*
		һ���Լ�����������ȳ�����
		1��ѭ����֣�ȡ�з��������ٵ�
		��1)˫��
		��2������
		��3��4��
		��4��3��
		��5��˫��
		��5��2��
		��6��1��
		�������˳����ƣ����Լ��ܹ��ϵ���

		*/

		/*----------------------- ���ܲ��� end ------------------------*/

	protected:
		/*
		�ҳ������������е����ƣ�����
		cards:������
		len:������ĳ���
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindStraightSingle(const int *cards, const int len, vector<vector<int>> &outCards);
		/*
		�ҳ������������е����ƣ�˫����
		cards:������
		len:������ĳ���
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindStraightPair(const int *cards, const int len, vector<vector<int>> &outCards);
		/*
		�ҳ��������е���ը��˫����
		cards:������
		len:������ĳ���
		outCards:�ҳ����ϵ����������鼯��
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindKingBomb(const int *cards, const int len, vector<vector<int>> &outCards);
		/*
		����
		cards: ������
		len: ������ĳ���
		isCompareMinCard: �Ƿ��бȽ��� ���ҳ��ȴ��ƴ����
		minCard: �Ƚ�����ֵ
		isMainSplit: �������Ƿ���Ҫ���Ʋ��� true:���� false:������
		adjacentCount: �����Ƶĸ���������1Ϊ�����ƣ�
		mainCardSum: ÿ�������Ƶ�����
		subsidiaryCount: �����Ƶĸ���
		subsidiarySum: ÿ�������Ƶ�����
		outCards: �ҵ����Ƶ����飨����������
		return: �ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindCards(const int *cards, const int len, const bool isCompareMinCard,
						const CardNumber minCard, const bool isMainSplit, 
						const int adjacentCount, const int mainCardSum, 
						const int subsidiaryCount, const int subsidiarySum, 
						vector<vector<int>> &outCards);
		/*
		�˿�Ȩ����������ת�˿���ֵ
		sortCards:�˿�Ȩ������ֵ�ļ���
		cards:�˿���ֵ����
		len:�˿���ֵ���鳤��
		outCards: �ҵ����Ƶ����飨����������
		return:�ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/ 
		bool SortArrayCardsToCards(vector<int> sortCards, const int *cards, 
									const int len, vector<int> &outCards);
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
		bool FindMainCards(const int *sortArray, const int sortArrLen, 
							const bool isCompareMinCard, const CardNumber minCard, 
							const int adjacentCount, const int sameCount, 
							const bool isSplit, vector<vector<int>> &outSortArrVec);
		/*
		���Ҹ�����
		sortNoMainArray: �˿�Ȩ����������(ȥ���������Ƶ���������)
		sortArrLen: �˿�Ȩ���������鳤�ȣ��̶�Ϊ14��
		subsidiaryCount: �����Ƶĸ���
		subsidiarySameCount: ÿ�������Ƶ�����
		isSplit: �Ƿ���ƽ��в��Ʋ��� true:���Ʋ��� false:�����Ʋ���
		outSubsidiaryVec: ����Ҫ��ĸ����Ƶ��˿�Ȩ���������鼯�ϣ�����������
		return: �ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool FindSubsidiaryCards(const int *sortNoMainArray, const int sortArrLen, 
								const int subsidiaryCount, const int subsidiarySameCount, 
								const bool isSplit, vector<vector<int>> &outSubsidiaryVec);
		/*
		��������ͺ͸�������
		cards: ������
		len: �����鳤��
		mainCards: �����ͼ��ϣ�ֵΪ���������е�����ֵ��
		mainSum: ������ÿ���Ƶ�����
		subsidiaryCards: ���������鼯�ϣ�ֵΪ���������е�����ֵ��
		subsidiarySum: ��������ÿ���Ƶ�����
		outCards: ��Ϻ�������鼯�ϣ�����������
		return: �ɹ�����true��ʧ�ܷ���false���쳣�׳�
		*/
		bool JoinCards(const int *cards, const int len, const vector<int> const mainCards, 
						const int mainSum, const vector<vector<int>> const subsidiaryCards, 
						const int subsidiarySum, vector<vector<int>> &outCards);
		/*
		����C(M,N)�������  C(len, sub)
		len: �����ܳ��� M
		sub: Ҫ����ϵĳ��� N
		result: C(M,N)�Ľ��
		*/
		bool Cmn(vector<int> cardVec, int len, int sub, vector<vector<int>> &outVec);
		/*
		��������ҳ����������������
		preWei:ǰһλ��ֵ
		wei:��ǰλ��
		r: ������ϵ���ʱ�������
		len:�����ݳ���
		sub:λ������
		result:�������ļ���
		*/
		void Cmn(int preWei, int wei, vector<int> &r, int len, int sub, vector<vector<int>> &outVec);


		/*----------------------- ���ܲ��� start ----------------------*/

		struct SplitInfo
		{
			CardType _cardType;///������
			int _adjacentCount;///�����Ƹ���
			int _mainCardSum;///����������
			vector<CardNumber> _mainCardNums;///����������ֵ����
			int _subsidiaryCount;///����������
			int _subsidiarySum;///�����Ƹ���
			vector<CardNumber> _subsidiaryCardNums;///����������ֵ����
		};

		bool SplitCardArray(const int *cards, const int len, vector<vector<int>> &outCards);
		void LoopSplit(int *sortArray, vector<SplitInfo> &outCards);

		/*----------------------- ���ܲ��� end ------------------------*/
	};
}