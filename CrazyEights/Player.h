#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "IOManager.h"

class Player
{
public:
	Player(IOManager*, std::string);
	virtual ~Player();

	explicit      Player(const Player&);

	void          addCard(Card*);

	Card*         removeCard(int);

	Card*         getCard(int) const;

	int           getNumCards() const;

	void          addScore(unsigned int);

	int           getScore() const;

	std::string   getName() const;

	bool          validCard(const Card*, const Card*);

	const Deck&   getHand() const;

	virtual Card* playTurn(const Card*) = 0;

protected:
	Deck          mHand;
	IOManager*    mIOManager;
	int           mScore;
	std::string   mName;
};

#endif