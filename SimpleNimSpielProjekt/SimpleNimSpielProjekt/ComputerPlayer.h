#pragma once
#include <iostream>
#include "AbstractTakeGamePlayer.h"

class ComputerPlayer : public AbstractTakeGamePlayer
{
public:
	ComputerPlayer(const std::string& name)
		: AbstractTakeGamePlayer(name)
	{
	}


	int doTurn(const int & stones) override
	{
		const int zuege[] = { 3,1,1,2 };

		int zug = zuege[stones % 4];
		std::cout << "Computer nimmt " << zug << " Steine." << std::endl;
		return zug;
	}
};
