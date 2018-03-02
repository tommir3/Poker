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

struct CardNumberSum
{
	CardNumber num;
	int count;
};