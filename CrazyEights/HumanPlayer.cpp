#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(IOManager* io, std::string name) : Player(io, name)
{
}


HumanPlayer::~HumanPlayer()
{
}

Card* HumanPlayer::playTurn(const Card* faceCard)
{
	bool drawNeeded = true;
	for(int i = 0; i < mHand.getNumCards(); ++i)
	{
		if(validCard(mHand.getCard(i), faceCard))
		{
			drawNeeded = false;
		}
	}

	if(drawNeeded)
	{
		mIOManager->displayString("\n\tYou have no card to play!\n");
		mIOManager->displayString("\tDrawing a card...\n");
		return nullptr;
	}

	mIOManager->displayString("\n\tYour hand: ");

	mHand.sortCards();

	mIOManager->displayDeck(mHand);
	mIOManager->displayString("\n\n");

	return mHand.removeCard(getValidCardIndex(faceCard));
}

int HumanPlayer::getValidCardIndex(const Card* faceCard)
{
	int index;
	while(true)
	{
		index = mIOManager->getInt("\nChoose a valid card(index 0 to " + std::to_string(mHand.getNumCards() - 1) + "): ");

		if(index >= 0 && index < mHand.getNumCards() && validCard(mHand.getCard(index), faceCard))
		{
			break;
		}
	}

	return index;
}