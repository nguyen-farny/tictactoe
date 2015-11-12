#include "unittest.h"
#include <assert.h>

#include "tictactoe.h"
#include "ConsoleTictactoe.h"

void TestTicTacToe()
{
	printf("========================================\n");
	printf("Unit Tests: \n");
	printf("========================================\n");
	
	TicTacToe tictactoe;
	initialize(&tictactoe, 3, 3, "Joueur 1", 'X', false, "Joueur 2", 'O', false);

	assertFalse(checkEnd(&tictactoe), "Le jeu n'est pas fini");
	assertFalse(checkWin(&tictactoe), "Personne n'a gagne");

	tick(&tictactoe, getPlayer(&tictactoe, 0), 1, 1);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 1, 2);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 1, 3);
	assertTrue(checkWin(&tictactoe), "Joueur 1 gagne en horizontal");

	// new game
	clean(&tictactoe);
	initialize(&tictactoe, 3, 3, "Joueur 1", 'X', false, "Joueur 2", 'O', false);
	tick(&tictactoe, getPlayer(&tictactoe, 0), 1, 1);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 2, 1);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 3, 1);
	assertTrue(checkWin(&tictactoe), "Joueur 1 gagne en vertical");

	// new game
	clean(&tictactoe);
	initialize(&tictactoe, 3, 3, "Joueur 1", 'X', false, "Joueur 2", 'O', false);
	tick(&tictactoe, getPlayer(&tictactoe, 0), 1, 1);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 2, 2);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 3, 3);
	assertTrue(checkWin(&tictactoe), "Joueur 1 gagne en diagonale (de haut gauche a bas droit) ");

	// new game
	clean(&tictactoe);
	initialize(&tictactoe, 3, 3, "Joueur 1", 'X', false, "Joueur 2", 'O', false);
	tick(&tictactoe, getPlayer(&tictactoe, 0), 1, 3);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 2, 2);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 3, 1);
	assertTrue(checkWin(&tictactoe), "Joueur 1 gagne en diagonale (de haut droit a bas gauche)");

	// new game
	clean(&tictactoe);
	initialize(&tictactoe, 3, 3, "Joueur 1", 'X', false, "Joueur 2", 'O', false);

	tick(&tictactoe, getPlayer(&tictactoe, 0), 1, 1);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore"); 
	tick(&tictactoe, getPlayer(&tictactoe, 1), 1, 2);
	assertFalse(checkWin(&tictactoe), "Joueur 2 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 2, 1);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 1), 2, 2);
	assertFalse(checkWin(&tictactoe), "Joueur 2 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 3, 2);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 1), 3, 1);
	assertFalse(checkWin(&tictactoe), "Joueur 2 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 3, 3);
	assertFalse(checkWin(&tictactoe), "Joueur 1 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 1), 2, 3);
	assertFalse(checkWin(&tictactoe), "Joueur 2 ne gagne pas encore");
	tick(&tictactoe, getPlayer(&tictactoe, 0), 1, 3);
	assertFalse(checkWin(&tictactoe), "Personne ne gagne");
	assertTrue(checkEnd(&tictactoe), "La partie est finie"); 

	printf("========================================\n");
}