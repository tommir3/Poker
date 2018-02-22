#include "PokerLogic.h"

PokerLogic::PokerLogic()
{

}

PokerLogic::~PokerLogic()
{

}

bool PokerLogic::ValueToCard(int cardValue, CardMark& cardMark, CardNumber& cardNum)
{
	bool result = false;
	try
	{
		cardMark = CardMark::Heart;
		cardNum = CardNumber::C_A;
		int pokerNum = cardValue % 100;
		int markVal = pokerNum / 20;
		int cardVal = -1;
		cardMark = (CardMark)markVal;
		if (cardMark == CardMark::Joker)
		{
			cardVal = pokerNum;
		}
		else
		{
			cardVal = pokerNum % 20;
		}
		result = WeightValueToNumber(cardVal, cardNum);
	}
	catch (exception err)
	{
		result = false;
		throw(err);
	}
	return result;
}

bool PokerLogic::WeightValueToNumber(int w_val, CardNumber& outCardNum)
{
	try
	{
		int suits_len = sizeof(PokerLogic::Card_Suits_Weight) / sizeof(int);
		CardNumber cardNum = CardNumber::C_A;
		for (int i = 0; i < suits_len; ++i)
		{
			if (Card_Suits_Weight[i] == w_val)
			{
				cardNum = (CardNumber)i;
				outCardNum = cardNum;
				return true;
			}
		}
		int joker_len = sizeof(PokerLogic::Card_Joker_Weight) / sizeof(int);
		for (int i = 0; i < joker_len; ++i)
		{
			if (Card_Joker_Weight[i] == w_val)
			{
				cardNum = (i > 0) ? CardNumber::C_RJ : CardNumber::C_BJ;
				outCardNum = cardNum;
				return true;
			}
		}
	}
	catch (exception err)
	{
		throw (err);
	}
	return false;
}