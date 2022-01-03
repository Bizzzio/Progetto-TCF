#include <iostream>
#include <vector>
#include "Factory.h"
#include "Play.h"
#include "menu.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	Menu test;
	test.Draw();

	#ifdef __unix__
		cout<<"ciao";
		getch();
		system("clear");
			cout<<"\x1B[31;5m "<<"ciao"<<"\033[0m\n";
	cout<<"\x1B[32m "<<"ciao"<<"\033[0m\n";
	cout<<"\x1B[33m "<<"ciao"<<"\033[0m\n";
	cout<<"\x1B[34m "<<"ciao"<<"\033[0m\n";
	cout<<"\033[3;42;30m"<<"bella"<<"\033[0m\n";
	#endif

	/*Factory* grid1= new Factory(8, 2, 0, 0, 0, 0);
	Factory* grid2= new Factory(8, 2, 0, 0, 0, 0);
	Play game(grid1,grid2);
	game.PlayBattleship();

	delete grid1,grid2;*/
	return 0;
}
