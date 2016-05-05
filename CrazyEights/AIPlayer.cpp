#include "AIPlayer.h"


AIPlayer::AIPlayer(IOManager* io, std::string name) : Player(io, name)
{
}


AIPlayer::~AIPlayer()
{
}

Card* AIPlayer::playTurn(const Card* faceCard)
{
	for(int i = 0; i < mHand.getNumCards(); ++i)
	{
		if(validCard(mHand.getCard(i), faceCard))
		{
			mIOManager->displayString("\n\t" + getName() + " played a ");
			mIOManager->displayCard(*mHand.getCard(i));
			mIOManager->displayString("\n");
			return mHand.removeCard(i);
		}
	}

	mIOManager->displayString("\t" + getName() + " is drawing a card...\n");
	return nullptr;
}