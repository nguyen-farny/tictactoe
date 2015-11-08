#pragma once
#ifndef __CONSOLETICTACTOE_H__
#define __CONSOLETICTACTOE_H__

#include "tictactoe.h"

typedef struct
{
	TicTacToe tictactoe;
} TicTacToeConsole;

void initialize(TicTacToeConsole* console);
void session(TicTacToeConsole* console);
void clean(TicTacToeConsole* console);

void displayBoard(Board b);
void getUserNextMove(Board b, Player p, int *x, int *y);

#endif