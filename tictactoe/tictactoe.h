#pragma once
#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__

typedef struct
{
	int width;
	int height;
	char* table;
} Board;

typedef struct
{
	char* name;
	char mark;
	bool isComputeur;
} Player;

typedef struct
{
	Board board; 
	Player player[2];
} TicTacToe;

void initialize(TicTacToe* tictactoe, 
	int width, 
	int height, 
	char* name1, 
	char mark1, 
	bool isComputer1,
	char* name2, 
	char mark2, 
	bool isComputer2);

void clean(TicTacToe* tictactoe);
Board* getBoard(TicTacToe* tictactoe);
Player* getPlayer(TicTacToe* tictactoe, int index);
bool checkWin(TicTacToe* tictactoe);
bool checkEnd(TicTacToe* tictactoe);
void tick(TicTacToe* tictactoe, Player* player, int x, int y);

void initialize(Board* board, int width, int height);
void clean(Board* tictactoe);

void initialize(Player* player, char* name, char mark, bool isComputeur);
void clean(Player* tictactoe);


bool convertChoiceToXY(char* choice, int *x, int *y);
int xy2i(int x, int y, int width, int height);




#endif