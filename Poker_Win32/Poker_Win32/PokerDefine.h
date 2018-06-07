#pragma once

/// <summary>
/// �˿��ƻ�ɫ���ͣ����������ͣ�
/// </summary>
enum CardMark
{
	/// <summary>
	/// ����
	/// </summary>
	Heart = 0,
	/// <summary>
	/// ����
	/// </summary>
	Diamond = 1,
	/// <summary>
	/// ����
	/// </summary>
	Spade = 2,
	/// <summary>
	/// �ݻ�
	/// </summary>
	Club = 3,
	/// <summary>
	/// ��
	/// </summary>
	Joker = 4
};

/// <summary>
/// �˿�������ֵö��
/// </summary>
enum CardNumber
{
	C_A = 0,    //A
	C_2 = 1,    //2
	C_3 = 2,    //3
	C_4 = 3,    //4
	C_5 = 4,    //5
	C_6 = 5,    //6
	C_7 = 6,    //7
	C_8 = 7,    //8
	C_9 = 8,    //9
	C_10 = 9,   //10
	C_J = 10,   //J
	C_Q = 11,   //Q
	C_K = 12,   //K
	C_BJ = 82,  //С��
	C_RJ = 83   //����
};

/// <summary>
/// �˿��Ƴ�������
/// </summary>
enum CardType
{
	Normal = 0,					//������
	Single = 1,					//��
	Pair = 2,					//��
	Three = 3,					//����
	ThreeSingle = 4,			//����һ
	ThreePair = 5,				//������
	Four = 6,					//�ĸ���ը����
	FourSingle = 7,				//�Ĵ�����
	FourPair = 8,				//�Ĵ�����
	Plane = 9,					//˫�ɻ�
	PlaneSingle = 10,			//˫�ɻ�������
	PlanePair = 11,				//˫�ɻ�������
	ThreePlane = 12,			//���ɻ�
	ThreePlaneSingle = 13,		//���ɻ�������
	ThreePlanePair = 14,		//���ɻ�������
	FourPlane = 15,				//�ķɻ�
	FourPlaneSingle = 16,		//�ķɻ����ĵ�
	FourPlanePair = 17,			//�ķɻ����Ķ�
	FivePlane = 18,				//��ɻ�
	FivePlaneSingle = 19,		//��ɻ����嵥
	SixPlane = 20,				//���ɻ�
	StraightSingle = 21,		//��˳��
	StraightPair = 22,			//˫˳��
	KingBomb = 23				//��ը
};

/*�˿���Ϣ��*/
class CardNumberSum
{
public:
	CardNumber num;		//�˿���ֵ
	int count;			//�˿�������
};