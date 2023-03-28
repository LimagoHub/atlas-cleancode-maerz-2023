#pragma once
#include "GamePlayer.h"
template<class BOARD, class TURN>
class AbstractGamePlayer : public GamePlayer<BOARD, TURN>
{
	std::string name;


public:
	AbstractGamePlayer(const std::string& name)
		: name(name)
	{
	}



	std::string getName() override
	{
		return name;
	}

	
};
