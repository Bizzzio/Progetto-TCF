#include <iostream>
#include <vector>
#ifdef _WIN32
	#include <conio.h>
#else

	#include <unistd.h>
	#include <termios.h>

	char getch() {
		char buf = 0;
		struct termios old = {0};
		if (tcgetattr(0, &old) < 0)
				perror("tcsetattr()");
		old.c_lflag &= ~ICANON;
		old.c_lflag &= ~ECHO;
		old.c_cc[VMIN] = 1;
		old.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSANOW, &old) < 0)
				perror("tcsetattr ICANON");
		if (read(0, &buf, 1) < 0)
				perror ("read()");
		old.c_lflag |= ICANON;
		old.c_lflag |= ECHO;
		if (tcsetattr(0, TCSADRAIN, &old) < 0)
				perror ("tcsetattr ~ICANON");
		return (buf);
}
#endif
#include "Factory.h"
#include "Play.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	#ifdef _WIN32
	#define KEY_UP    72
	#define KEY_LEFT  75
	#define KEY_RIGHT 77
	#define KEY_DOWN  80
		/*cout<<"ciao";
		int ch;
		ch=getch();
		cout<<ch;
		getch();
		//system("cls");*/
		int c, ex;

    //while(1)
    {
        c = getch();

        if (c && c != 224)
        {
            cout << endl << "Not arrow: " << (char) c << endl;
        }
        else
        {
            switch(ex = getch())
            {
                case KEY_UP     /* H */:
                    cout << endl << "Up" << endl;//key up
                    break;
                case KEY_DOWN   /* K */:
                    cout << endl << "Down" << endl;   // key down
                    break;
                case KEY_LEFT   /* M */:
                    cout << endl << "Left" << endl;  // key left
                    break;
                case KEY_RIGHT: /* P */
                    cout << endl << "Right" << endl;  // key right
                    break;
                default:
                    cout << endl << (char) ex << endl;  // not arrow
                    break;
            }
        }
    }
	#endif

	#ifdef __unix__
		cout<<"ciao";
		getch();
		system("clear");
	#endif
	Factory* grid1= new Factory(8, 2, 0, 0, 0, 0);
	Factory* grid2= new Factory(8, 2, 0, 0, 0, 0);
	Play game(grid1,grid2);
	game.PlayBattleship();

	delete grid1,grid2;
	return 0;
}
