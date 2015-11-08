#include "ConsoleTictactoe.h"
#include <stdlib.h> // pour m�moire : malloc, free
#include <stdio.h> // pour console

void initialize(TicTacToeConsole* console)
{
	if (console == NULL)
		return; 

	initialize(&console->tictactoe, 3, 3, "Joueur 1", 'X', false, "Joueur 2", 'O', false);
}

void clean(TicTacToeConsole* console)
{
	clean(&console->tictactoe);
}

void session(TicTacToeConsole* console)
{
	displayBoard(console->tictactoe.board);

	int x = 0;
	int y = 0;

	int currentPlayer = 0;
	while (true)
	{
		getUserNextMove(console->tictactoe.board, console->tictactoe.player[currentPlayer], &x, &y);
		tick(console->tictactoe.board, console->tictactoe.player[currentPlayer], x, y);
		displayBoard(console->tictactoe.board);

		if (checkWin(console->tictactoe.board))
		{
			printf("Vous avez gagne ! ;) ");
			break;
		}

		if (checkEnd(console->tictactoe.board))
		{
			printf("C'est fini , allez dodo! ;) ");
			break;
		}

		currentPlayer = !currentPlayer;
	}
}

void displayBoard(Board b)
{
	printf("  A B C\n");

	for (int y = 1; y <= b.height; ++y) // x width, y height
	{
		printf("%d ", y);
		for (int x = 1; x <= b.width; ++x)
		{
			printf("%c ", b.table[xy2i(x, y, b.width, b.height)]);
		}
		printf("\n");
	}

	printf("\n");
}



void getUserNextMove(Board b, Player p, int *x, int *y)
{
	char choice[3];
	printf("%s : Quelle case voulez-vous jouer ? ", p.name);

	bool valid = false;

	while (valid == false)
	{
		valid = true;

		scanf_s("%2s", choice);
		fseek(stdin, 0, SEEK_END); // vider tout les caracteres pour ne pas les garder pour prochain scanf
		convertChoiceToXY(choice, x, y);

		if (*x == 0 || *y == 0)
		{
			printf("Choix invalide ! Quelle case voulez-vous jouer ? ");
			valid = false;
		}
		else if (b.table[xy2i(*x, *y, b.width, b.height)] != ' ')
		{
			printf("Case occup�e ! Quelle case voulez-vous jouer ? ");
			valid = false;
		}
	}
}