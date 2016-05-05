#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck
{
	friend std::ostream& operator<<(std::ostream&, const Deck&);

public:
	Deck();
	~Deck();

	explicit Deck(const Deck&);

	void  addCard(Card*);
	Card* removeCard(int);

	Card* getCard(int) const;
	int   getNumCards() const;

	void  shuffleCards();

	void  sortCards();

private:
	std::vector<Card*> mCards;
};

#endif