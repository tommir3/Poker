#include "PokerLogic.h"

Poker::PokerLogic::PokerLogic()
{

}

Poker::PokerLogic::PokerLogic(int card_a, int card_2, int card_3, int card_4, int card_5,
	int card_6, int card_7, int card_8, int card_9, int card_10,
	int card_j, int card_q, int card_k, int card_bj, int card_rj)
{
	Card_Suits_Weight[0] = card_a;
	Card_Suits_Weight[1] = card_2;
	Card_Suits_Weight[2] = card_3;
	Card_Suits_Weight[3] = card_4;
	Card_Suits_Weight[4] = card_5;
	Card_Suits_Weight[5] = card_6;
	Card_Suits_Weight[6] = card_7;
	Card_Suits_Weight[7] = card_8;
	Card_Suits_Weight[8] = card_9;
	Card_Suits_Weight[9] = card_10;
	Card_Suits_Weight[10] = card_j;
	Card_Suits_Weight[11] = card_q;
	Card_Suits_Weight[12] = card_k;
	Card_Joker_Weight[0] = card_bj;
	Card_Joker_Weight[1] = card_rj;
}

Poker::PokerLogic::~PokerLogic()
{

}


bool Poker::PokerLogic::CreatePoker(int *cards, const int cardsLen)
{
	return CreatePoker(1, cards, cardsLen);
}

bool Poker::PokerLogic::CreatePoker(const int pokerCount, int *cards, const int cardsLen)
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

bool Poker::PokerLogic::CreateCardMarkPoker(const CardMark cardMark, const int pokerIndex, int *cards, const int cardsLen)
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

bool Poker::PokerLogic::ValueToCard(const int cardValue, CardMark& cardMark, CardNumber& cardNum)
{
	bool result = false;
	try
	{
		bool isOK = ValueToMark(cardValue, cardMark);
		if (isOK)
		{
			int cardVal = ValueToWeightValue(cardValue, cardMark);
			result = WeightValueToNumber(cardVal, cardNum);
		}
	}
	catch (exception err)
	{
		result = false;
		throw(err);
	}
	return result;
}

int Poker::PokerLogic::CardToValue(const CardMark cardMark, const CardNumber cardNum)
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

bool Poker::PokerLogic::ValueToMark(const int value, CardMark &mark)
{
	bool result = false;
	try
	{
		if (value >= 0)
		{
			int pokerNum = value % 100;
			int markVal = pokerNum / 20;
			mark = CardMark(markVal);
			result = true;
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int Poker::PokerLogic::ValueToWeightValue(const int value)
{
	int result = -1;
	try
	{
		CardMark mark;
		bool isOK = ValueToMark(value, mark);
		if (isOK)
		{
			result = ValueToWeightValue(value, mark);
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool Poker::PokerLogic::ValueToWeightValue(const int values[], const int valuesLen, int *cards, const int cardsLen)
{
	bool result = false;
	try
	{
		if (NULL != values && valuesLen == cardsLen)
		{
			for (int i = 0; i < cardsLen; ++i)
			{
				int wVal = ValueToWeightValue(values[i]);
				if (wVal != -1)
				{
					cards[i] = wVal;
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

bool Poker::PokerLogic::ValueToCardNumber(const int value, CardNumber &cardNum)
{
	bool result = false;
	try
	{
		CardMark mark;
		result = ValueToCard(value, mark, cardNum);
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool Poker::PokerLogic::ValueToCardNumber(const int values[], const int valuesLen, CardNumber *cardNums, const int cardNumsLen)
{
	bool result = false;
	try
	{
		if (NULL != values && valuesLen > 0 && NULL != cardNums && valuesLen == cardNumsLen)
		{
			for (int i = 0; i < valuesLen; ++i)
			{
				result = ValueToCardNumber(values[i], cardNums[i]);
				if (!result)
				{
					break;
				}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int Poker::PokerLogic::CardNumberToWeightValue(const CardNumber num)
{
	int result = -1;
	try
	{
		switch (num)
		{
		case CardNumber::C_A:
		case CardNumber::C_2:
		case CardNumber::C_3:
		case CardNumber::C_4:
		case CardNumber::C_5:
		case CardNumber::C_6:
		case CardNumber::C_7:
		case CardNumber::C_8:
		case CardNumber::C_9:
		case CardNumber::C_10:
		case CardNumber::C_J:
		case CardNumber::C_Q:
		case CardNumber::C_K:
			result = Card_Suits_Weight[num];
			break;
		case CardNumber::C_BJ:
			result = Card_Joker_Weight[0];
			break;
		case CardNumber::C_RJ:
			result = Card_Joker_Weight[1];
			break;
		default:
			result = -1;
			break;
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int Poker::PokerLogic::CompareValue(const int value1, const int value2)
{
	int result = 0;
	try
	{
		int val1 = ValueToWeightValue(value1);
		int val2 = ValueToWeightValue(value2);
		result = (val1 > val2) ? 1 : (val1 == val2) ? 0 : -1;
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

int Poker::PokerLogic::CompareCardNumber(const CardNumber num1, const CardNumber num2)
{
	int result = 0;
	try
	{
		int val1 = CardNumberToWeightValue(num1);
		int val2 = CardNumberToWeightValue(num2);
		result = (val1 > val2) ? 1 : (val1 == val2) ? 0 : -1;
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool Poker::PokerLogic::IsCardValue(const int value)
{
	bool result = false;
	try
	{
		CardMark mark;
		CardNumber cardNum;
		result = ValueToCard(value, mark, cardNum);
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool Poker::PokerLogic::IsCardValue(const int *values, const int len)
{
	bool result = false;
	try
	{
		if (NULL != values && len > 0)
		{
			for (int i = 0; i < len; ++i)
			{
				result = IsCardValue(values[i]);
				if (!result)
				{
					break;
				}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool Poker::PokerLogic::Shuffle(int *cards, const int cardsLen)
{
	bool result = false;
	try
	{
		if (NULL != cards && cardsLen > 0)
		{
			srand(time(NULL));
			int *rndArr = new int[cardsLen];
			for (int i = 0; i < cardsLen; ++i)
			{
				int rnd = rand();
				rndArr[i] = rnd;
			}
			SortByArray(rndArr, cardsLen, cards, cardsLen, true);
			delete[] rndArr;
			result = true;
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

void Poker::PokerLogic::Sort(int *cards, const int cardsLen, const bool isAscend)
{
	CardNumber *cardNums = NULL;
	try
	{
		if (NULL != cards && cardsLen > 0)
		{
			CardNumber *cardNums = new CardNumber[cardsLen];
			bool isOK = PokerLogic::ValueToCardNumber(cards, cardsLen, cardNums, cardsLen);
			if (isOK)
			{
				SortByArray((int*)cardNums, cardsLen, cards, cardsLen, isAscend);
			}
		}
		if (NULL != cardNums)
		{
			delete[] cardNums;
		}
	}
	catch (exception err)
	{
		if (NULL != cardNums)
		{
			delete[] cardNums;
		}
		throw(err);
	}
}

int Poker::PokerLogic::FindCount(const CardNumber *cards, const int len, const CardNumber val)
{
	int result = 0;
	try
	{
		if (NULL != cards && len > 0)
		{
			for (int i = 0; i < len; ++i)
			{
				//如果找的是王，则双王表示2个，不单独返回；单王正常返回，返回一个
				if ((cards[i] == CardNumber::C_BJ || cards[i] == CardNumber::C_RJ) && (val == CardNumber::C_BJ || val == CardNumber::C_RJ))
				{
					result++;
				}
				else if (cards[i] == val)
				{
					result++;
				}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

/*以下为私有方法*/
bool Poker::PokerLogic::WeightValueToNumber(const int w_val, CardNumber& outCardNum)
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

int Poker::PokerLogic::ValueToWeightValue(const int value, const CardMark mark)
{
	int result = -1;
	try
	{
		if (mark == CardMark::Joker)
		{
			result = value % 100;
		}
		else
		{
			result = value % 100 % 20;
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}

bool Poker::PokerLogic::SortByArray(int *cards, const int cardsLen, int *outCards, const int outCardsLen, const bool isAscend)
{
	bool result = false;
	try
	{
		if (NULL != cards && NULL != outCards && cardsLen == outCardsLen)
		{
			for (int i = 0; i < cardsLen; ++i)
			{
				for (int j = 0; j < cardsLen - 1; ++j)
				{
					if (isAscend)
					{
						if (cards[j] <= cards[j + 1])
						{
							continue;
						}
					}
					else
					{
						if (cards[j] >= cards[j + 1])
						{
							continue;
						}
					}
					int tmp = cards[j];
					cards[j] = cards[j + 1];
					cards[j + 1] = tmp;
					int tmpCard = outCards[j];
					outCards[j] = outCards[j + 1];
					outCards[j + 1] = tmpCard;
				}
			}
		}
	}
	catch (exception err)
	{
		throw(err);
	}
	return result;
}