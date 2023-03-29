#pragma once
#include <iostream>
#include <vector>

#include "AbstractGame.h"
#include "GamePlayer.h"
#include "Writer.h"




class TakeGameImpl : public AbstractGame<int,int>
{

public:


	TakeGameImpl(Writer& writer)
		: AbstractGame<int, int>(writer)
	{
		set_board(23);
	}

protected:


	/*void prepare() override
	{
		write(get_current_player()->getName() + " ist am Zug!");
	}*/

	bool isTurnValid() override
	{
		return get_turn() >= 1 && get_turn() <= 3;
	}
	void updateBoard() override
	{
		set_board(get_board() - get_turn());
	}

	bool isGameOver() override
	{
		return get_board() < 1 || get_players().empty();
	}
	

};
