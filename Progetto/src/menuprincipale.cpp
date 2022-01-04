#include "menuprincipale.h"

MenuPrincipale::MenuPrincipale()
{

  Menus.push_back(new MenuPlay());
  Menus.push_back(new MenuInstructions());
  Menus.push_back(new MenuOptions());
  Menus.push_back(new MenuCredits());
  Menus.push_back(new Menu());
}

MenuPrincipale::~MenuPrincipale()
{
  vector<Menu *>::iterator i;
  for (i = Menus.begin(); i != Menus.end(); i++)
    delete (*i);
}

void MenuPrincipale::Draw() const
{
#ifdef _WIN32
  SelectWindows();
#elif
  SelectOthers();
#endif
}

void MenuPrincipale::PrintVoci(int pos) const
{
  for (int d = 0; d < voci.size(); d++)
  {
    if (d == pos)
    {
      SetConsoleTextAttribute(h, 10);
      cout << "--> " << voci[d];
      SetConsoleTextAttribute(h, 15);
      cout << endl;
    }
    else
      cout << voci[d] << endl;
  }
}

void MenuPrincipale::SelectOthers() const
{
#ifdef __unix
#include <iostream>
#include <termios.h>
#define STDIN_FILENO 0
  using std::cin;
  using std::cout;
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68

  {
    // Black magic to prevent Linux from buffering keystrokes.
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    // Once the buffering is turned off, the rest is simple.
    cout << "Enter a character: ";
    /*char c,d,e;
  cin >> c;
  cin >> d;
  cin >> e;
  cout << "\nYour character was ";*/
    cout << "Enter a character: ";
    char c = cin.get();
    cout << "Your character was " << c << endl;
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
    }
    return 0;
  }
#endif
}

void MenuPrincipale::SelectWindows() const
{

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80

  int c, ex, pos = 0;
  cout << "Selezionare la configurazione usando le frecce" << endl;
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

  PrintVoci(0);
  system("cls");
  do
  {
    PrintVoci(pos)

        do
    {

      c = getch();
      if (c == 0 || c == 224)
      {
        switch (ex = getch())
        {
        case KEY_UP /* H */:
          //cout << endl << "Up" << endl;//key up
          if (pos != 0)
            pos--;
          break;
        case KEY_DOWN /* K */:
          //cout << endl << "Down" << endl;   // key down
          if (pos < voci.size() - 1)
            pos++;
          break;

        default:
          break;
        }
        system("cls");
        if (c != 13)
          PrintVoci(pos);
      }
    }
    while (c != 13)
      ;
      /*HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/

#endif

    do
    {
      Menus[pos]->Draw();
    } while (pos != Menus.size());

    /* switch (pos)
    {
    case 0:
      menuplay.Draw();
      break;
    case 2:

      menuoption.Draw();
      break;
      /*case 0:
                    cout << endl << "Up" << endl;//key up
                		if(pos!=0)
                      	pos--;
                    break;
    case 0:
                    cout << endl << "Up" << endl;//key up
                		if(pos!=0)
                      	pos--;
                    break;

    default:
      break;
    }
  } while (pos != 4);
	*/
  }