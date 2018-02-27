#include "DouDiZhuLogic.h"

DouDiZhu::DouDiZhuLogic::DouDiZhuLogic() : PokerLogic(14,15,3,4,5,6,7,8,9,10,11,12,13,82,83)
{
	
}

DouDiZhu::DouDiZhuLogic::~DouDiZhuLogic()
{

}


bool DouDiZhu::DouDiZhuLogic::Test()
{
	CardMark mark;
	CardNumber num;
	bool isOK = ValueToCard(15, mark, num);
	return true;
}