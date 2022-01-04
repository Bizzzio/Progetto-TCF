#include "MenuPrincipale.h"

MenuPrincipale::MenuPrincipale() {}

MenuPrincipale::~MenuPrincipale()
{
  vector<Menu *>::const_iterator i;
  for (i = Menus.begin(); i != Menus.end(); i++)
    delete (*i);
}

void MenuPrincipale::Draw() const
{
#ifdef _WIN32
  SelectWindows();
#else
  SelectOthers();
#endif
}

void MenuPrincipale::PrintVoci(int pos) const
{
#ifdef _WIN32
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "Selezionare la configurazione usando le frecce" << endl;
  for (int d = 0; d < Menus.size(); d++)
  {
    if (d == pos)
    {
      SetConsoleTextAttribute(h, 10);
      cout << "--> ";
      Menus[d]->DrawVoci();
      SetConsoleTextAttribute(h, 15);
      cout << endl;
    }
    else
      Menus[d]->DrawVoci();
    cout << endl;
  }
#endif
}

void MenuPrincipale::SelectOthers() const
{
#ifdef __unix
#include <iostream>
#define KEY_UP 65
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_DOWN 66
  {
    // Black magic to prevent Linux from buffering keystrokes.
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
  }
#endif
}

void MenuPrincipale::SelectWindows() const
{
#ifdef _WIN32
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80

  int c, ex, pos = 0;
  cout << "Selezionare la configurazione usando le frecce" << endl;

  PrintVoci(0);
  system("cls");
  do
  {
    PrintVoci(pos);

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
          if (pos < Menus.size() - 1)
            pos++;
          break;

        default:
          break;
        }
        system("cls");
        if (c != 13)
          PrintVoci(pos);
      }
    } while (c != 13);
    /*HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/

    if (pos != Menus.size() - 1)
      Menus[pos]->Draw();

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
      break;*/
  } while (pos != Menus.size() - 1);
#endif
}