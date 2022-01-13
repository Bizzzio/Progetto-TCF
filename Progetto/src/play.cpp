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

	grid1 = player1->GetGrid();
	grid2 = player2->GetGrid();
	Player1 = player1;
	Player2 = player2;
}

void Play::PlayBattleship()
{ // serve fuzione per cancellare gli output
	/*int x, y;
	do
	{
		cout << typeid(Player1).name() << endl;
		cout << "Premi un tasto per mostrare la griglia";
		getch();
		system(CLEAR);
		cout << "Turno giocatore 1" << endl;
		grid2.DrawEnemy();
		do
		{
			cout << "\nDimmi le coordinate che vuoi colpire " << endl;
			cin >> x >> y;

		} while (!Check(x, y, grid2));
		grid2.Strike(x, y);

		//grid1.DrawAlly();
		grid2.DrawEnemy();
		cout << "Premi un tasto per oscurare" << endl;
		getch();
		system(CLEAR);
		cout << "Premi un tasto per mostrare la griglia" << endl;
		getch();
		system(CLEAR);
		cout << "Turno giocatore 2" << endl;
		grid1.DrawEnemy();
		do
		{
			cout << "\nDimmi le coordinate che vuoi colpire " << endl;
			cin >> x >> y;

		} while (!Check(x, y, grid1));
		grid1.Strike(x, y);

		//grid2.DrawAlly();
		grid1.DrawEnemy();
		cout << "Premi un tasto per oscurare" << endl;
		getch();
		system(CLEAR);

		//system (CLEAR);

	} while (!Player1->EndGame() && !Player2->EndGame());
	if (Player1->EndGame())
	{
		cout << "GIOCATORE 2 HAI VINTOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	}
	if (Player2->EndGame())
	{
		cout << "GIOCATORE 1 HAI VINTOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	}
	getch();*/
	do
	{
		Player1->Turn(grid2, 1);
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

	int s = grid.GetSize();
	if (x >= s || y >= s)
	{
		cout << "Coordinate fuori target. Riprovare." << endl;
		return false;
	}

	else
	{
		if (!grid[x][y])
		{
			return true;
		}
		else
		{
			if (!(grid[x][y]->IsHit(x, y)))
				return true;
			else
			{
				cout << "Coordinate già colpite. Riprovare." << endl;
				return false;
			}
		}
	}
}