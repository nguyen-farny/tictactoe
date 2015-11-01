// mainTTT.ccp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

struct Board
{
	int width;
	int height;
	char* board;
};
typedef struct Board Board; 

Board createBoard(int width, int height)
{
	Board b; 
	b.width = width; 
	b.height = height; 
	b.board = (char*)malloc(width*height*sizeof(char));
	for (int i = 0; i < (width*height); i++)
	{
		b.board[i] = ' ';
	}
	return b;
}

typedef struct
{
	char* name; 
	char mark;
	bool isComputeur; 
} Player;

Player createPlayer(char* name, char mark, bool isComputeur)
{
	Player p; 
	p.name = name;
	p.mark = mark; 
	p.isComputeur = isComputeur;
	return p; 
}

int xy2i(int x, int y, int width, int height);
void displayBoard(Board b);
void convertChoiceToXY(char* choice, int *x, int *y);
void tick(Board b, Player p, int x, int y);
void getUserNextMove(Board b, Player p, int *x, int *y);
bool checkWin(Board b);
bool checkEnd(Board b);

int main()
{
	Board gameboard = createBoard(3, 3);
	Player p1 = createPlayer("Joueur 1",'X', false); 
	Player p2 = createPlayer("Joueur 2", 'O', false);

	displayBoard(gameboard);

	int x = 0;
	int y = 0;

	Player *currentPlayer = &p1;
	while (true)
	{
		getUserNextMove(gameboard, *currentPlayer, &x, &y);
		tick(gameboard, *currentPlayer, x, y);
		displayBoard(gameboard);

		if (checkWin(gameboard))
		{
			printf("Vous avez gagne ! ;) ");
			break;
		}

		if (checkEnd(gameboard))
		{
			printf("C'est fini , allez dodo! ;) "); 
			break;
		}

		if (currentPlayer == &p1)
			currentPlayer = &p2;
		else
			currentPlayer = &p1;
	}

	system("pause");
}

// xy2i (1,1,      3,3) = 0
// xy2i (3,3,      3,3) = 8

int xy2i(int x, int y, int width, int height) // transformer les coordonnées x y dans le tableau 
{
	return (x - 1)*height + (y - 1);
}

void displayBoard(Board b)
{
	printf("  A B C\n");

	for (int y = 1; y <= b.height; ++y) // x width, y height
	{
		printf("%d ", y); 
		for (int x = 1; x <= b.width; ++x)
		{
			printf("%c ", b.board[xy2i(x, y, b.width, b.height)]);
		}
		printf("\n");
	}

	printf("\n");
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

void getUserNextMove(Board b, Player p, int *x, int *y)
{
	char choice[3];
	printf("%s : Quelle case voulez-vous jouer ? ", p.name);
	
	bool valid = false;

	while (valid == false)
	{
		valid = true;

		scanf("%2s", choice);
		fseek(stdin, 0, SEEK_END); // vider tout les caracteres pour ne pas les garder pour prochain scanf
		convertChoiceToXY(choice, x, y);

		if (*x == 0 || *y == 0)
		{
			printf("Choix invalide ! Quelle case voulez-vous jouer ? ");
			valid = false;
		}
		else if (b.board[xy2i(*x, *y, b.width, b.height)] != ' ')
		{
			printf("Case occupée ! Quelle case voulez-vous jouer ? ");
			valid = false;
		}
	}
}

void tick(Board b, Player p, int x, int y)
{
	int i = xy2i(x, y, b.width, b.height);
	b.board[i] = p.mark;
}


bool checkWin(Board b)
{
	// horizontal
	for (int y = 1; y <= b.height; ++y)
	{
		char firstCase = b.board[xy2i(1, y, b.width, b.height)];
		if (firstCase == ' ')
			continue;

		bool win = true;

		for (int x = 2; x <= b.width; ++x)
		{
			if (b.board[xy2i(x, y, b.width, b.height)] != firstCase) 
			{
				win = false;
				break;
			}
		}
		
		if (win)
			return true;
	}

	// vertical
	for (int x = 1; x <= b.width; ++x)
	{
		char firstCase = b.board[xy2i(x, 1, b.width, b.height)];
		if (firstCase == ' ')
			continue;

		bool win = true;

		for (int y = 2; y <= b.width; ++y)
		{
			if (b.board[xy2i(x, y, b.width, b.height)] != firstCase)
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
		char firstCase_ul2br = b.board[xy2i(1, 1, b.width, b.height)];
		bool win_ul2br = true;

		char firstCase_ur2bl = b.board[xy2i(b.width, 1, b.width, b.height)];
		bool win_ur2bl = true;

		for (int y = 2; y <= b.width; ++y)
		{
			if (firstCase_ul2br == ' ' || b.board[xy2i(y, y, b.width, b.height)] != firstCase_ul2br)
				win_ul2br = false;
			
			if (firstCase_ur2bl == ' ' || b.board[xy2i(b.width + 1 - y, y, b.width, b.height)] != firstCase_ur2bl)
				win_ur2bl = false;
		}

		if (win_ul2br || win_ur2bl)
			return true;
	}

	return false; 
}


bool checkEnd(Board b)
{
	for (int y = 1; y <= b.height; ++y)
	{
		for (int x = 1; x <= b.width; ++x)
		{
			int i = xy2i(x, y, b.width, b.height);
			if (b.board[i] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}