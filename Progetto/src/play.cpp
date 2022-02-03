#include <iostream>
#include "PlayerFactory.h"
using std::cout;
using std::endl;
#include <vector>
using std::system;
using std::vector;
#include "Play.h"
#ifdef _WIN32
#include <conio.h>
#define CLEAR "cls"
#else
#define CLEAR "clear"
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
#endif

Play::Play(Factory *player1, Factory *player2) : grid1(player1->GetSize()), grid2(player2->GetSize())
{

	grid1 = player1->GetGrid();		// Copiamo in due DM tipo Griglia le griglie costruite nelle 
	grid2 = player2->GetGrid();		// factories sennò non rimarrebbe traccia delle modifiche 
									// durante il gioco
	Player1 = player1;
	Player2 = player2;
}

void Play::PlayBattleship()
{ 
	do
	{
		Player1->Turn(grid2, 1);	// Polimorfismo su Turn
		Player2->Turn(grid1, 2);

	} while (!Player1->EndGame() && !Player2->EndGame());
	if (Player1->EndGame())
	{
		cout << "GIOCATORE 2 HAI VINTOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	}
	if (Player2->EndGame())
	{
		cout << "GIOCATORE 1 HAI VINTOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	}
	#ifdef _WIN32
  getch();
  #else
  getche();
  #endif
}

bool Play::Check(int x, int y, Griglia grid)
{

	// controllo coordinate: per prima cosa verifico che stiano dentro la griglia,
	// poi che non siano già state colpite

	int s = grid.GetSize();
	if (x >= s || y >= s)
	{
		cout << "Coordinate fuori target. Riprovare." << endl;
		return false;
	}

	else
	{
		// Se il puntatore grid[x][y] è nullo vuol dire che punta ad acqua non 
		// colpita e quindi va bene 
		if (!grid[x][y])
		{
			return true;
		}
		else
		{
			// IsHit ritorna vero se la casella è stata colpita
			if (!(grid[x][y]->IsHit(x, y)))
				return true;
			else
			{
				cout << "Coordinate gia colpite. Riprovare." << endl;
				return false;
			}
		}
	}
}