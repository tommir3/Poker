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

int PokerLogic::CardToValue(CardMark cardMark, CardNumber cardNum)
{
	int result = -1;
	try
	{
		if (cardMark == CardMark::Joker)
		{
			if (cardNum == CardNumber::C_BJ)
			{
				result = Card_Joker_Weight[0];
			}
			else if (cardNum == CardNumber::C_RJ)
			{
				result = Card_Joker_Weight[1];
			}
		}
		else
		{
			result = (int)cardMark * 20 + Card_Suits_Weight[(int)cardNum];
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool PokerLogic::CreateCardMarkPoker(const CardMark cardMark, const int pokerIndex, int *cards, const int cardsLen)
{
	int result = false;
	try
	{
		int baseCardVal = pokerIndex * 100;
		if (cardMark == CardMark::Joker && cardsLen == JokerCount)
		{
			cards[0] = baseCardVal + CardToValue(CardMark::Joker, CardNumber::C_BJ);
			cards[1] = baseCardVal + CardToValue(CardMark::Joker, CardNumber::C_RJ);
			result = true;
		}
		else
		{
			if (cardsLen == SuitsCount)
			{
				int cardNum = -1;
				for (int i = 0; i < SuitsCount; ++i)
				{
					cardNum = CardToValue(cardMark, (CardNumber)i);
					cards[i] = baseCardVal + cardNum;
				}
				result = true;
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool PokerLogic::CreatePoker(const int pokerCount, int *cards, const int cardsLen)
{
	bool result = false;
	try
	{
		if (pokerCount * PokerCount == cardsLen)
		{
			int heartCards[SuitsCount], diamondCards[SuitsCount],
				spadeCards[SuitsCount], clubCards[SuitsCount], jokerCards[JokerCount];
			int idx = 0;
			for (int i = 0; i < pokerCount; ++i)
			{
				bool isHeart = CreateCardMarkPoker(CardMark::Heart, i, heartCards, SuitsCount);
				bool isDiamond = CreateCardMarkPoker(CardMark::Diamond, i, diamondCards, SuitsCount);
				bool isSpade = CreateCardMarkPoker(CardMark::Spade, i, spadeCards, SuitsCount);
				bool isClub = CreateCardMarkPoker(CardMark::Club, i, clubCards, SuitsCount);
				bool isJoker = CreateCardMarkPoker(CardMark::Joker, i, jokerCards, JokerCount);
				if (isHeart && isDiamond && isSpade	&& isClub && isJoker)
				{
					for (int j = 0; j < SuitsCount; ++j,idx++)
					{
						cards[idx] = heartCards[j];
					}
					for (int j = 0; j < SuitsCount; ++j,idx++)
					{
						cards[idx] = diamondCards[j];
					}
					for (int j = 0; j < SuitsCount; ++j, idx++)
					{
						cards[idx] = spadeCards[j];
					}
					for (int j = 0; j < SuitsCount; ++j, idx++)
					{
						cards[idx] = clubCards[j];
					}
					for (int j = 0; j < JokerCount; ++j, idx++)
					{
						cards[idx] = jokerCards[j];
					}
				}
				else
				{
					return false;
				}
			}
			result = true;
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool PokerLogic::WeightValueToNumber(const int w_val, CardNumber& outCardNum)
{
	bool result = false;
	try
	{
		if (Card_Joker_Weight[0] == w_val)
		{
			outCardNum = CardNumber::C_BJ;
			result = true;
		}
		else if (Card_Joker_Weight[1] == w_val)
		{
			outCardNum = CardNumber::C_RJ;
			result = true;
		}
		else
		{
			for (int i = 0; i < SuitsCount; ++i)
			{
				if (Card_Suits_Weight[i] == w_val)
				{
					outCardNum = (CardNumber)i;
					result = true;
					break;
				}
			}
		}
	}
	catch (exception err)
	{
		throw (err);
	}
	return result;
}