#pragma once
#include <iostream>
#include "AbstractTakeGamePlayer.h"

class HumanPlayer : public AbstractTakeGamePlayer
{
public:
	HumanPlayer(const std::string& name)
		: AbstractTakeGamePlayer(name)
	{
	}


	int doTurn(const int &stones) override
	{
		int zug;
		std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
		std::cin >> zug;
		return zug;
	}
};
