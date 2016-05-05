#include "Deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck()
{
}


Deck::~Deck()
{
	for(std::size_t i = 0; i < mCards.size(); ++i)
	{
		delete mCards[i];
	}
}

void Deck::addCard(Card* card)
{
	mCards.push_back(card);
}

Card* Deck::removeCard(int i)
{
	std::swap(mCards[i], mCards.back());
	Card* card = mCards.back();
	mCards.pop_back();

	return card;
}

Card* Deck::getCard(int i) const
{
	return mCards[i];
}

int Deck::getNumCards() const
{
	return mCards.size();
}

void Deck::shuffleCards()
{
	std::random_shuffle(mCards.begin(), mCards.end());
}

void Deck::sortCards()
{
	std::sort(mCards.begin(), mCards.end(), [](const Card* a, const Card* b) -> bool { return (*a) < (*b); });
}

std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
	for(int i = 0; i < deck.getNumCards(); ++i)
	{
		out << *deck.getCard(i) << " ";
	}
	return out;
}