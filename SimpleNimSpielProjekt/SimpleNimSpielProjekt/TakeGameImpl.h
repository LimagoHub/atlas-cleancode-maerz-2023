#pragma once
#include <iostream>
#include "Game.h"

class TakeGameImpl : public Game
{

public:

	TakeGameImpl() :stones(23) {}

	void play() override
	{
		while (!isGameOver())
		{
			playRounds();
		}
	}

private:
	int stones;
	int zug;

	void playRounds()
	{
		playersTurn();
		computerTurn();
	}
	
	void playersTurn()
	{
		if (isGameOver()) return;
		
		
		while(true)
		{
			std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
			std::cin >> zug;
			if (zug >= 1 && zug <= 3) break;
			std::cout << "Ungueltiger Zug" << std::endl;
		}
		terminateTurn("Mensch");
	}

	

	void computerTurn()
	{
		if (isGameOver()) return;
		const int zuege[] = { 3,1,1,2 };
		
		zug = zuege[stones % 4];
		std::cout << "Computer nimmt " << zug << " Steine." << std::endl;

		terminateTurn("Computer");
	}


	

	void terminateTurn(std::string playersName)
	{
		updateBoard();
		printGameoverMessageIfGameIsOver(playersName);
	}

	
	void printGameoverMessageIfGameIsOver(std::string playersName)
	{
		if (isGameOver())
		{
			std::cout << playersName << " hat verloren";
		}
	}
	
	void updateBoard()
	{
		stones -= zug;
	}

	bool isGameOver()
	{
		return stones < 1;
	}


};