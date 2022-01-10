#include <iostream>
#include <vector>
#include "Factory.h"
#include "Play.h"
#include "MenuPrincipale.h"
#include "MenuText.h"
#include "MenuDiramazione.h"
#include "MenuOpzioni.h"
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	/*int a;

	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);
  cin>>a;*/
	/*cout << "Ciao" << endl;

	MenuText menutext("NomeFileMenuText");
	cout << menutext.GetFileName("NomeFileMenuText") << endl;*/

	// MenuPrincipale test;
	// test.Draw();
	/*vector<Menu *> Menus {{new MenuPlay,new MenuDiramazione(string("Options"), 
	vector<Menu* > {new MenuOpzioni(1,string("Seleziona dimensioni griglia"),string("Dimensioni.txt")), 
	new MenuOpzioni(0,string("Seleziona colore del menu"),string("Colori.txt")),
	new MenuOpzioni(2,string("Seleziona flotta"),string("Setup.txt")), 
	new MenuBack}), 
	new MenuText(string("Instructions")), new MenuText(string("Credits")), new MenuBack}};*/
	vector<Menu *> Menus {{new MenuPlay, new MenuDiramazione,new MenuText(string("Instructions")), new MenuText(string("Credits")), new MenuBack("Quit")}};
	MenuDiramazione MenuPrincipale(string("MenuPrincipale"),Menus);
	MenuPrincipale.Draw();
#ifdef __unix__
/*

	cout << "ciao";
	//getch();
	//system("clear");
	cout << "\x1B[31;5m "
		 << "ciao"
		 << "\033[0m\n";
	cout << "\x1B[32m "
		 << "ciao"
		 << "\033[0m\n";
	cout << "\x1B[33m "
		 << "ciao"
		 << "\033[0m\n";
	cout << "\x1B[34m "
		 << "ciao"
		 << "\033[0m\n";
	cout << "\033[3;42;30m"
		 << "bella"
		 << "\033[0m\n";*/
#endif

	/*Factory* grid1= new Factory(8, 2, 0, 0, 0, 0);
	Factory* grid2= new Factory(8, 2, 0, 0, 0, 0);
	Play game(grid1,grid2);
	game.PlayBattleship();

	delete grid1,grid2;*/
	return 0;
}
