#include "Card.h"

Card::Card(Rank rank, Suit suit) : mRank(rank), mSuit(suit)
{
}

Card::~Card()
{
}

Rank Card::getRank() const
{
	return mRank;
}

Suit Card::getSuit() const
{
	return mSuit;
}

bool Card::operator<(const Card& other) const
{
	if(getSuit() == other.getSuit())
	{
		return getRank() < other.getRank();
	}

	return getSuit() < other.getSuit();
}

bool Card::operator==(const Card& other) const
{
	return getRank() == other.getRank() && getSuit() == other.getSuit();
}

bool Card::operator>(const Card& other) const
{
	return !(*this < other) && !(*this == other);
}

std::vector<Rank> Card::allRanks()
{
	std::vector<Rank> ranks;
	ranks.push_back(Rank::ACE);
	ranks.push_back(Rank::TWO);
	ranks.push_back(Rank::THREE);
	ranks.push_back(Rank::FOUR);
	ranks.push_back(Rank::FIVE);
	ranks.push_back(Rank::SIX);
	ranks.push_back(Rank::SEVEN);
	ranks.push_back(Rank::EIGHT);
	ranks.push_back(Rank::NINE);
	ranks.push_back(Rank::TEN);
	ranks.push_back(Rank::JACK);
	ranks.push_back(Rank::QUEEN);
	ranks.push_back(Rank::KING);

	return ranks;
}

std::vector<Suit> Card::allSuits()
{
	std::vector<Suit> suits;
	suits.push_back(Suit::CLUBS);
	suits.push_back(Suit::DIAMONDS);
	suits.push_back(Suit::HEARTS);
	suits.push_back(Suit::SPADES);

	return suits;
}

std::string Card::rankToString(Rank r)
{
	std::string rankStr;

	switch(r)
	{
	case Rank::ACE:
		rankStr = "A";
		break;
	case Rank::JACK:
		rankStr = "J";
		break;
	case Rank::QUEEN:
		rankStr = "Q";
		break;
	case Rank::KING:
		rankStr = "K";
		break;
	default:
		rankStr = std::to_string(static_cast<int>(r));
	}

	return rankStr;
}

std::string Card::suitToString(Suit s)
{
	std::string suitStr;

	switch(s)
	{
	case Suit::CLUBS:
		suitStr = "C";
		break;
	case Suit::DIAMONDS:
		suitStr = "D";
		break;
	case Suit::HEARTS:
		suitStr = "H";
		break;
	case Suit::SPADES:
		suitStr = "S";
		break;
	}

	return suitStr;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	out << Card::rankToString(card.mRank) << Card::suitToString(card.mSuit);
	return out;
}