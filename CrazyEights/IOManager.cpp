#include "IOManager.h"
#include <iostream>
#include <limits>

IOManager::IOManager()
{
}


IOManager::~IOManager()
{
}

void IOManager::displayCard(const Card& c)
{
	std::cout << c;
}

void IOManager::displayDeck(const Deck& d)
{
	std::cout << d;
}

void IOManager::displayString(std::string message)
{
	std::cout << message;
}

int IOManager::getInt(std::string message)
{
	displayString(message);

	int input;
	std::cin >> input;

	return input;
}

std::string IOManager::getString(std::string message)
{
	displayString(message);

	std::string str;
	std::getline(std::cin, str);

	return str;
}

void IOManager::pause(std::string message)
{
	std::cout << message;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cin.get();
}