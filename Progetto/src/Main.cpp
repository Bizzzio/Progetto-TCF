#include <iostream>
#include <vector>
#include <conio.h>
#include "Factory.h"
#include "Play.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	#ifdef _WIN32
		cout<<"ciao";
		getch();
		system("cls");
	#endif

	#ifdef __unix__
		cout<<"ciao";
		getch();
		system("cls");
	#endif
	Factory* grid1= new Factory(8, 2, 0, 0, 0, 0);
	Factory* grid2= new Factory(8, 2, 0, 0, 0, 0);
	Play game(grid1,grid2);
	game.PlayBattleship();

	delete grid1,grid2;
	return 0;
}
