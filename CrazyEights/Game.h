#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "IOManager.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void                 run();

private:
	void                 init();
	void                 createMainDeck();
	void                 displayPlayerHands();

	Deck                 mPile;
	Deck                 mDiscardPile;

	IOManager            mIOManager;

	std::vector<Player*> mPlayers;

	static const size_t  MAX_CARDS;
};

#endif