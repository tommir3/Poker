#pragma once

/// <summary>
/// 扑克牌花色类型（包括王类型）
/// </summary>
enum CardMark
{
	/// <summary>
	/// 红桃
	/// </summary>
	Heart = 0,
	/// <summary>
	/// 方块
	/// </summary>
	Diamond = 1,
	/// <summary>
	/// 黑桃
	/// </summary>
	Spade = 2,
	/// <summary>
	/// 草花
	/// </summary>
	Club = 3,
	/// <summary>
	/// 王
	/// </summary>
	Joker = 4
};

/// <summary>
/// 扑克牌字面值枚举
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
	C_BJ = 82,  //小王
	C_RJ = 83   //大王
};

struct CardNumberSum
{
	CardNumber num;
	int count;
};