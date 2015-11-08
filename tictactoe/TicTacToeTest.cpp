#include "tictactoe.h"
#include "unittest.h"
#include <assert.h>

void TestTicTacToe()
{
	printf("========================================\n");
	printf("Unit Tests: \n");
	printf("========================================\n");
	
	TicTacToe tictactoe;
	initialize(&tictactoe, 3, 3, "Joueur 1", 'X', false, "Joueur 2", 'O', false);

	assertFalse(checkEnd(tictactoe.board), "Le jeu n'est pas fini");
	assertFalse(checkWin(tictactoe.board), "Personne n'a gagne");

	printf("========================================\n");
}