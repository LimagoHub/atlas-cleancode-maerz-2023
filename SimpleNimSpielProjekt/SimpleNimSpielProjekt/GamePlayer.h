#pragma once
#include <string>
template<class BOARD, class TURN>
class GamePlayer
{
public:
	virtual std::string getName() = 0;
	virtual TURN doTurn(const  BOARD& board) = 0;
};
