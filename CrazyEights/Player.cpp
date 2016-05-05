#include "Player.h"
#include <iostream>

Player::Player(IOManager* io, std::string name) : mIOManager(io), mName(name)
{
}


Player::~Player()
{
}

void Player::addCard(Card* card)
{
	mHand.addCard(card);
}

Card* Player::removeCard(int i)
{
	return mHand.removeCard(i);
}

Card* Player::getCard(int i) const
{
	return mHand.getCard(i);
}

int Player::getNumCards() const
{
	return mHand.getNumCards();
}

void Player::addScore(unsigned int points)
{
	mScore += points;
}

int Player::getScore() const
{
	return mScore;
}

std::string Player::getName() const
{
	return mName;
}

bool Player::validCard(const Card* theCard, const Card* faceCard)
{
	Rank rank = theCard->getRank();
	Suit suit = theCard->getSuit();
	return rank == faceCard->getRank() || suit == faceCard->getSuit() || rank == Rank::EIGHT;
}

const Deck& Player::getHand() const
{
	return mHand;
}