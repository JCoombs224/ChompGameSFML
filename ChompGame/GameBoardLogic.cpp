#include "GameBoardLogic.h"
#include <iostream>

// Constructor
GameBoardLogic::GameBoardLogic(unsigned int w, unsigned int h)
{
	// Set the private size variables to the info given
	sizeX = w;
	sizeY = h;

	// Create a 2d vector of game squares to create a grid
	for (int i = 0; i < sizeY; i++)
	{
		// Vector to store column game squares
		vector<Square> v1;

		// Fill columns of new game squares
		for (int j = 0; j < sizeX; j++)
		{
			// Add square to column vector
			v1.push_back(Square());
		}
		// Add column to current row
		boardGrid.push_back(v1);
	}
}

	// Execute chomp move on the board
	bool GameBoardLogic::doChomp(unsigned int x, unsigned int y)
	{
		// First check if move is valid, if not return false
		if (x < 0 || y < 0 || ((x == 0 && y == 0) != isGameWon()) || x >= sizeX || y >= sizeY || (!boardGrid[y][x].isPlayable()))
		{
			std::cerr << "That move is not playable, try again...\n";
			return false;
		}

		// Execute move and return true
		for (int i = y; i < sizeY; i++)
		{
			for (int j = x; j < sizeX; j++)
			{
				boardGrid[i][j].chomp();
			}
		}
		return true;
	}

	// Check to see if the game has been won
	bool GameBoardLogic::isGameWon()
	{
		if ((!boardGrid[0][1].isPlayable()) && (!boardGrid[1][0].isPlayable()))
			return true;
		else
			return false;
	}

	// Print the game board with playable squares as 'O' and nonplayable as 'X'
	void GameBoardLogic::printBoardToConsole()
	{
		cout << "   ";
		for (int i = 0; i < sizeX; i++)
		{
			cout << i + 1 << ' ';
		}
		cout << "(m)" << endl;

		for (int i = 0; i < sizeY; i++)
		{
			cout << ' ' << i + 1 << ' ';
			for (int j = 0; j < sizeX; j++)
			{
				if (boardGrid[i][j].isPlayable())
					cout << "O ";
				else
					cout << ". ";
			}
			cout << endl;
		}
		cout << "(n)\n\n";
	}

	void GameBoardLogic::resetBoard()
	{
		boardGrid.clear();
		// Create a 2d vector of game squares to create a grid
		for (int i = 0; i < sizeY; i++)
		{
			// Vector to store column game squares
			vector<Square> v1;

			// Fill columns of new game squares
			for (int j = 0; j < sizeX; j++)
			{
				// Add square to column vector
				v1.push_back(Square());
			}
			// Add column to current row
			boardGrid.push_back(v1);
		}
	}