#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(IOManager*, std::string="Human");
	virtual ~HumanPlayer();

	virtual Card* playTurn(const Card*);

private:
	int           getValidCardIndex(const Card*);
};

#endif