// mainTTT.ccp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include "tictactoe.h"
#include "ConsoleTictactoe.h"
#include "TicTacToeTest.h"

int main()
{
	TestTicTacToe();

	TicTacToeConsole game;
	initialize(&game);
	session(&game);
	clean(&game);

	system("pause");
}
