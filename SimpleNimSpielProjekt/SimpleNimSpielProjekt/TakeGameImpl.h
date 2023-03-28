#pragma once
#include <iostream>
#include "Game.h"

class TakeGameImpl : public Game
{

public:

	TakeGameImpl() :stones(23), gameover(false) {}

	void play() override
	{
		while (!gameover)
		{
			playRounds();
		}
	}

private:
	int stones;
	bool gameover;

	void playRounds()
	{
		playersTurn();
		computerTurn();
	}
	void playersTurn()
	{
		int zug;
		while(true)
		{
			std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
			std::cin >> zug;
			if (zug >= 1 && zug <= 3) break;
			std::cout << "Ungueltiger Zug" << std::endl;
		}
		stones -= zug;
	}

	void computerTurn()
	{
		const int zuege[] = { 3,1,1,2 };
	
		if(stones < 1)
		{
			std::cout << "Du Loser!" << std::endl;
			gameover = true;
			return;
		}
		if (stones == 1)
		{
			std::cout << "Du hast nur Glueck gehabt" << std::endl;
			gameover = true;
			return;
		}
		int zug = zuege[stones % 4];
		std::cout << "Computer nimmt " << zug << " Steine." << std::endl;
		stones -= zug;
		
	}


};