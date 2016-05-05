#include "Game.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"
#include <iostream>
#include <chrono>
#include <thread>

const size_t Game::MAX_CARDS = 52;

Game::Game()
{
}


Game::~Game()
{
	for(size_t i = 0; i < mPlayers.size(); ++i)
	{
		delete mPlayers[i];
	}
}

void Game::run()
{
	init();
	
	int playerIndex = 0;

	while(true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));

		Player* p = mPlayers[playerIndex];
		Card* faceCard = mDiscardPile.getCard(mDiscardPile.getNumCards() - 1);

		mIOManager.displayString("\n\n--" + p->getName() + "'s turn--\n\n");
		mIOManager.displayString("\tFace card: ");
		mIOManager.displayCard(*faceCard);
		mIOManager.displayString("\n");

		Card* playedCard = p->playTurn(faceCard);

		if(!playedCard && mPile.getNumCards() == 0)
		{
			playerIndex = -1;
			break;
		}

		while(!playedCard)
		{
			p->addCard(mPile.removeCard(mPile.getNumCards() - 1));
			playedCard = p->playTurn(faceCard);
		}

		mDiscardPile.addCard(playedCard);

		if(p->getNumCards() == 0)
		{
			break;
		}
		playerIndex = (playerIndex + 1) % 2;

		
	}

	if(playerIndex >= 0)
	{
		mIOManager.displayString("\nGame over - " + mPlayers[playerIndex]->getName() + " won!\n\n");
	}
	else
	{
		mIOManager.displayString("\nDeck ran out of cards!\n\n");
		displayPlayerHands();
	}
	

	mIOManager.pause("Press enter to terminate...\n\n");
}

void Game::init()
{
	mIOManager.displayString("\nCrazy Eights\n");
	mIOManager.displayString("------------\n\n");

	const std::string name = mIOManager.getString("Please enter your name: ");
	const std::string botName = "Bob";

	mPlayers.push_back(new HumanPlayer(&mIOManager, name));
	mPlayers.push_back(new AIPlayer(&mIOManager, botName));

	createMainDeck();

	mPile.shuffleCards();
	
	//Deal eight cards to each player
	for(size_t i = MAX_CARDS; i > MAX_CARDS - (mPlayers.size() * 8); --i)
	{
		mPlayers[i % 2]->addCard(mPile.removeCard(i - 1));
	}
	
	// Turn the top card over to start the game
	mDiscardPile.addCard(mPile.removeCard(mPile.getNumCards() - 1));

}

void Game::createMainDeck()
{
	std::vector<Rank> allRanks = Card::allRanks();
	std::vector<Suit> allSuits = Card::allSuits();

	for(const Rank rank : allRanks)
	{
		for(const Suit suit : allSuits)
		{
			mPile.addCard(new Card(rank, suit));
		}
	}
}

void Game::displayPlayerHands()
{
	for(const Player* p : mPlayers)
	{
		mIOManager.displayString(p->getName() + "'s hand:\n");
		mIOManager.displayDeck(p->getHand());
		mIOManager.displayString("\n\n");
	}
}