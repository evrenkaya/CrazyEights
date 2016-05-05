#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player
{
public:
	AIPlayer(IOManager*, std::string="AI");
	~AIPlayer();

	virtual Card* playTurn(const Card*);
};

#endif