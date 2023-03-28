#pragma once
#include "AbstractGamePlayer.h"
class AbstractTakeGamePlayer: public AbstractGamePlayer<int,int>
{
	std::string name;


public:


	AbstractTakeGamePlayer(const std::string& name)
		: AbstractGamePlayer<int, int>(name)
	{
	}
};

