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

/// <summary>
/// 扑克牌出牌类型
/// </summary>
enum CardType
{
	Normal = 0,					//无类型
	Single = 1,					//单
	Pair = 2,					//对
	Three = 3,					//三个
	ThreeSingle = 4,			//三带一
	ThreePair = 5,				//三带对
	Four = 6,					//四个（炸弹）
	FourSingle = 7,				//四带二单
	FourPair = 8,				//四带二对
	Plane = 9,					//双飞机
	PlaneSingle = 10,			//双飞机带二单
	PlanePair = 11,				//双飞机带二对
	ThreePlane = 12,			//三飞机
	ThreePlaneSingle = 13,		//三飞机带三单
	ThreePlanePair = 14,		//三飞机带三对
	FourPlane = 15,				//四飞机
	FourPlaneSingle = 16,		//四飞机带四单
	FourPlanePair = 17,			//四飞机带四对
	FivePlane = 18,				//五飞机
	FivePlaneSingle = 19,		//五飞机带五单
	SixPlane = 20,				//六飞机
	StraightSingle = 21,		//单顺子
	StraightPair = 22,			//双顺子
	KingBomb = 23				//王炸
};

/*扑克信息类*/
class CardNumberSum
{
public:
	CardNumber num;		//扑克牌值
	int count;			//扑克牌数量
};