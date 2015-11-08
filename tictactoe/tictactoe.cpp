#include "tictactoe.h"
#include <stdlib.h> 

void initialize(TicTacToe* tictactoe,
	int width,
	int height,
	char* name1,
	char mark1,
	bool isComputer1,
	char* name2,
	char mark2,
	bool isComputer2)
{
	if (tictactoe == NULL)
		return; // error

	initialize(&tictactoe->board, width, height);
	initialize(&tictactoe->player[0], name1, mark1, isComputer1);
	initialize(&tictactoe->player[1], name2, mark2, isComputer2);
}

void clean(TicTacToe* tictactoe)
{
	clean(&tictactoe->board);
	clean(&tictactoe->player[0]);
	clean(&tictactoe->player[1]);
}

Board* getBoard(TicTacToe* tictactoe)
{
	if (tictactoe == 0)
		return 0;

	return &(tictactoe->board);
}

Player* getPlayer(TicTacToe* tictactoe, int index)
{
	if (tictactoe == 0)
		return 0;

	return &(tictactoe->player[index]);
}

bool checkWin(TicTacToe* tictactoe)
{
	// horizontal
	for (int y = 1; y <= getBoard(tictactoe)->height; ++y)
	{
		char firstCase = getBoard(tictactoe)->table[xy2i(1, y, getBoard(tictactoe)->width, getBoard(tictactoe)->height)];
		if (firstCase == ' ')
			continue;

		bool win = true;

		for (int x = 2; x <= getBoard(tictactoe)->width; ++x)
		{
			if (getBoard(tictactoe)->table[xy2i(x, y, getBoard(tictactoe)->width, getBoard(tictactoe)->height)] != firstCase)
			{
				win = false;
				break;
			}
		}

		if (win)
			return true;
	}

	// vertical
	for (int x = 1; x <= getBoard(tictactoe)->width; ++x)
	{
		char firstCase = getBoard(tictactoe)->table[xy2i(x, 1, getBoard(tictactoe)->width, getBoard(tictactoe)->height)];
		if (firstCase == ' ')
			continue;

		bool win = true;

		for (int y = 2; y <= getBoard(tictactoe)->width; ++y)
		{
			if (getBoard(tictactoe)->table[xy2i(x, y, getBoard(tictactoe)->width, getBoard(tictactoe)->height)] != firstCase)
			{
				win = false;
				break;
			}
		}

		if (win)
			return true;
	}

	//diagonals
	{
		char firstCase_ul2br = getBoard(tictactoe)->table[xy2i(1, 1, getBoard(tictactoe)->width, getBoard(tictactoe)->height)];
		bool win_ul2br = true;

		char firstCase_ur2bl = getBoard(tictactoe)->table[xy2i(getBoard(tictactoe)->width, 1, getBoard(tictactoe)->width, getBoard(tictactoe)->height)];
		bool win_ur2bl = true;

		for (int y = 2; y <= getBoard(tictactoe)->width; ++y)
		{
			if (firstCase_ul2br == ' ' || getBoard(tictactoe)->table[xy2i(y, y, getBoard(tictactoe)->width, getBoard(tictactoe)->height)] != firstCase_ul2br)
				win_ul2br = false;

			if (firstCase_ur2bl == ' ' || getBoard(tictactoe)->table[xy2i(getBoard(tictactoe)->width + 1 - y, y, getBoard(tictactoe)->width, getBoard(tictactoe)->height)] != firstCase_ur2bl)
				win_ur2bl = false;
		}

		if (win_ul2br || win_ur2bl)
			return true;
	}

	return false;
}

bool checkEnd(TicTacToe* tictactoe)
{
	for (int y = 1; y <= getBoard(tictactoe)->height; ++y)
	{
		for (int x = 1; x <= getBoard(tictactoe)->width; ++x)
		{
			int i = xy2i(x, y, getBoard(tictactoe)->width, getBoard(tictactoe)->height);
			if (getBoard(tictactoe)->table[i] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

void initialize(Board* board, int width, int height)
{
	if (board == NULL)
		return; // error

	board->width = width;
	board->height = height;
	board->table = (char*)malloc(width*height*sizeof(char));
	for (int i = 0; i < (width*height); i++)
	{
		board->table[i] = ' ';
	}
}

void clean(Board* board)
{
	if(board->table != NULL)
		free(board->table);
	board->table = NULL;
}

void initialize(Player* player, char* name, char mark, bool isComputeur)
{
	if (player == NULL)
		return; // error
	player->name = name;
	player->mark = mark;
	player->isComputeur = isComputeur;
}

void clean(Player* player)
{
	// nothing to do
}

void convertChoiceToXY(char* choice, int *x, int *y)
{
	*x = 0;
	*y = 0;

	if (choice[0] == 'A')
		*x = 1;
	else if (choice[0] == 'B')
		*x = 2;
	else if (choice[0] == 'C')
		*x = 3;

	if (choice[1] == '1')
		*y = 1;
	else if (choice[1] == '2')
		*y = 2;
	else if (choice[1] == '3')
		*y = 3;
}

int xy2i(int x, int y, int width, int height) // transformer les coordonnées x y dans le tableau 
{
	return (x - 1)*height + (y - 1);
}

void tick(TicTacToe* tictactoe, Player* player, int x, int y)
{
	int i = xy2i(x, y, getBoard(tictactoe)->width, getBoard(tictactoe)->height);
	getBoard(tictactoe)->table[i] = player->mark;
}

