#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

enum class Rank
{
	ACE = 1, TWO, THREE, FOUR, FIVE,
	SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING
};

enum class Suit
{
	CLUBS, DIAMONDS, HEARTS, SPADES
};

class Card
{
	friend std::ostream& operator<<(std::ostream&, const Card&);

public:
	Card(Rank, Suit);
	~Card();

	explicit Card(const Card&);

	Rank getRank() const;
	Suit getSuit() const;

	bool operator<(const Card&) const;
	bool operator==(const Card&) const;
	bool operator>(const Card&) const;

	static std::vector<Rank> allRanks();
	static std::vector<Suit> allSuits();

	static std::string rankToString(Rank);
	static std::string suitToString(Suit);

private:
	const Rank mRank;
	const Suit mSuit;
};

#endif