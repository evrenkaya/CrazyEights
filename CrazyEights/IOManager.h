#ifndef IOMANAGER_H
#define IOMANAGER_H


#include "Card.h"
#include "Deck.h"

class IOManager
{
public:
	IOManager();
	~IOManager();

	explicit    IOManager(const IOManager&);

	void        displayCard(const Card&);

	void        displayDeck(const Deck&);

	void        displayString(std::string);

	int         getInt(std::string);

	std::string getString(std::string);

	void        pause(std::string);
};

#endif