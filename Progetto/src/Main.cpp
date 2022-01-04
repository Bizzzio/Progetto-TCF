#include <iostream>
#include <vector>
#include "Factory.h"
#include "Play.h"
#include "MenuPrincipale.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	MenuPrincipale test;
	test.Draw();
#ifdef __unix__
	/*#include <termios.h>
#define STDIN_FILENO 0
#define KEY_UP 65
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_DOWN 66

	struct termios t;
	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);

	// Once the buffering is turned off, the rest is simple.
	cout << "Enter a character: ";
	char c, d, e;
	cin >> c;
	cin >> d;
	cin >> e;
	cout << "\nYour character was ";
	cout << "Enter a character: ";
	//c = cin.get();
	//cout << "Your character was " << c << endl;
	// Using 3 char type, Cause up down right left consist with 3 character
	if ((c == 27) && (d = 91))
	{
		if (e == KEY_UP)
		{
			cout << "UP";
		}
		if (e == KEY_DOWN)
		{
			cout << "DOWN";
		}
		if (e == KEY_RIGHT)
		{
			cout << "RIGHT";
		}
		if (e == KEY_LEFT)
		{
			cout << "LEFT";
		}
	}*/

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
		 << "\033[0m\n";
#endif

	/*Factory* grid1= new Factory(8, 2, 0, 0, 0, 0);
	Factory* grid2= new Factory(8, 2, 0, 0, 0, 0);
	Play game(grid1,grid2);
	game.PlayBattleship();

	delete grid1,grid2;*/
	return 0;
}
