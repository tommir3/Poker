// ConsoleTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "D:\learning\C++\Poker_Win32\Poker_Win32\PokerLogic.h"
#include "iostream"


int main(int argc, char *argv[])
{
	PokerLogic pl;
	CardMark mark;
	CardNumber num;
	bool isOK = pl.ValueToCard(0, &mark, &num);
	if (isOK)
	{
		std::cout << "true" << endl;
		std::cout << mark << endl;
		std::cout << num << endl;
	}
	else
	{
		std::cout << "false" << endl;
		std::cout << mark << endl;
		std::cout << num << endl;
	}

    return 0;
}

