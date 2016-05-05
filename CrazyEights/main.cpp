#include <iostream>
#include <ctime>
#include "Game.h"

int main(int argc, char** argv)
{
	srand(static_cast<unsigned>(std::time(nullptr)));

	Game game;
	game.run();
};