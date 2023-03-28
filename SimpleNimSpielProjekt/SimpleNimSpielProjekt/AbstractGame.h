#pragma once
#include "Game.h"
#include "Writer.h"

template<class BOARD, class TURN>
class AbstractGame: public Game
{
public:


	AbstractGame(Writer& writer)
		: writer(writer)
	{
	}

	void addPlayer(GamePlayer<BOARD, TURN>* player)
	{
		players.emplace_back(player);
	}

	void removePlayer(GamePlayer<BOARD, TURN>* player)
	{
		// Not implemented yet
	}
	
	void play() override
	{
		while (!isGameOver())
		{
			playRounds();
		}
	}

private:

	BOARD board;
	TURN turn;

	std::vector<GamePlayer<BOARD, TURN>*> players;
	GamePlayer<BOARD, TURN>* currentPlayer;
	Writer& writer;
	
	void playRounds()
	{
		for (auto player : players)
		{
			set_current_player(player);
			playSingleTurn();
		}
	}

	void playSingleTurn() // Integration
	{
		if (isGameOver()) return;
		executeTurn();
		terminateTurn();
	}

	void executeTurn()
	{

		do
		{
			turn = currentPlayer->doTurn(board);
		} while (playerTurnIsInvalid());

	}

	bool playerTurnIsInvalid()
	{
		if (isTurnValid()) return false;
		write("Ungueltiger Zug");

		return true;
	}
	void terminateTurn()
	{
		updateBoard();
		printGameoverMessageIfGameIsOver();
	}
	void printGameoverMessageIfGameIsOver()
	{
		if (isGameOver())
		{
			write(currentPlayer->getName() + " hat verloren");
		}
	}



protected:

	virtual bool isTurnValid() = 0;
	virtual void updateBoard() = 0;
	virtual bool isGameOver() = 0;
	
	std::vector<GamePlayer<BOARD, TURN>*> get_players() const
	{
		return players;
	}
	GamePlayer<BOARD, TURN>* get_current_player() const
	{
		return currentPlayer;
	}

	void set_current_player(GamePlayer<BOARD, TURN>* const current_player)
	{
		currentPlayer = current_player;
	}

	void write(std::string message)
	{
		writer.write(message);
	}

	BOARD get_board() const
	{
		return board;
	}

	void set_board(const BOARD& board)
	{
		this->board = board;
	}

	TURN get_turn() const
	{
		return turn;
	}

	void set_turn(const TURN& turn)
	{
		this->turn = turn;
	}
};
