#include "Menu.h"

vector<int> Menu::Setup{10, 10, 2, 2, 1, 1, 0};

void Menu::Add(int x)
{
  Setup.push_back(x);
}

void Menu::Set(int x, int y)
{
  Setup[x] = y;
}

vector<int> Menu::GetSetup()
{
  return Setup;
}

unsigned int Menu::Arrows(unsigned int *posptr, vector<Menu *> Voci) const
{
#ifdef _WIN32
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
  int c, ex;
  unsigned int pos = (*posptr);
  do
  {
    c = getch();
    if (c == 0 || c == 224)
    {
      switch (ex = getch())
      {
      case KEY_UP :
        //cout << endl << "Up" << endl;//key up
        if (pos != 0)
          pos--;
        break;
      case KEY_DOWN :
        //cout << endl << "Down" << endl;   // key down
        if (pos < Voci.size() - 1)
          pos++;
        break;

      default:
        break;
      }
      system(CLEAR);
      if (c != 13)
        PrintVoci(pos,Voci);
    }
  } while (c != 13);
#else
#include <iostream>
#define KEY_UP 65
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_DOWN 66

  // Black magic to prevent Linux from buffering keystrokes.
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);

  char c, d, e;
  unsigned int pos = (*posptr);
  do
  {

    cin >> c;
    if (c != 'a')
    {
      cin >> d;
      cin >> e;
      if ((c == 27) && (d = 91))
      {
        switch (e)
        {
        case KEY_UP :
          //cout << endl << "Up" << endl;//key up
          if (pos != 0)
            pos--;
          break;
        case KEY_DOWN :
          //cout << endl << "Down" << endl;   // key down
          if (pos < Voci.size() - 1)
            pos++;
          break;

        default:
          break;
        }
      }
      system("clear");
      if (c != 'a')
        PrintVoci(pos, Voci);
    }
  } while (c != 'a');
#endif
  return (pos);
}

/*template <class T>
unsigned int Menu::Arrows(unsigned int *posptr, T Voci) const
{
#ifdef _WIN32
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
  int c, ex;
  unsigned int pos = (*posptr);
  do
  {
    c = getch();
    if (c == 0 || c == 224)
    {
      switch (ex = getch())
      {
      case KEY_UP:
        //cout << endl << "Up" << endl;//key up
        if (pos != 0)
          pos--;
        break;
      case KEY_DOWN :
        //cout << endl << "Down" << endl;   // key down
        if (pos < Voci.size() - 1)
          pos++;
        break;

      default:
        break;
      }
      system(CLEAR);
      if (c != 13)
        PrintVoci(pos, Voci);
    }
  } while (c != 13);
#else
#include <iostream>
#define KEY_UP 65
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_DOWN 66

  // Black magic to prevent Linux from buffering keystrokes.
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);

  char c, d, e;
  unsigned int pos = (*posptr);
  do
  {

    cin >> c;
    if (c != 'a')
    {
      cin >> d;
      cin >> e;
      if ((c == 27) && (d = 91))
      {
        switch (e)
        {
        case KEY_UP :
          //cout << endl << "Up" << endl;//key up
          if (pos != 0)
            pos--;
          break;
        case KEY_DOWN :
          //cout << endl << "Down" << endl;   // key down
          if (pos < T.size() - 1)
            pos++;
          break;

        default:
          break;
        }
      }
      system("clear");
      if (c != 'a')
        PrintVoci(pos, Voci);
    }
  } while (c != 'a');
#endif

  return (pos);
}*/


unsigned int Menu::Arrows(unsigned int *posptr, vector<string> Voci) const
{
#ifdef _WIN32
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
  int c, ex;
  unsigned int pos = (*posptr);
  do
  {
    c = getch();
    if (c == 0 || c == 224)
    {
      switch (ex = getch())
      {
      case KEY_UP :
        //cout << endl << "Up" << endl;//key up
        if (pos != 0)
          pos--;
        break;
      case KEY_DOWN :
        //cout << endl << "Down" << endl;   // key down
        if (pos < Voci.size() - 1)
          pos++;
        break;

      default:
        break;
      }
      system(CLEAR);
      if (c != 13)
        PrintVoci(pos, Voci);
    }
  } while (c != 13);
#else
#include <iostream>
#define KEY_UP 65
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_DOWN 66

  // Black magic to prevent Linux from buffering keystrokes.
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);

  char c, d, e;
  unsigned int pos = (*posptr);
  do
  {

    cin >> c;
    if (c != 'a')
    {
      cin >> d;
      cin >> e;
      if ((c == 27) && (d = 91))
      {
        switch (e)
        {
        case KEY_UP:
          //cout << endl << "Up" << endl;//key up
          if (pos != 0)
            pos--;
          break;
        case KEY_DOWN :
          //cout << endl << "Down" << endl;   // key down
          if (pos < Voci.size() - 1)
            pos++;
          break;

        default:
          break;
        }
      }
      system("clear");
      if (c != 'a')
        PrintVoci(pos, Voci);
    }
  } while (c != 'a');
#endif

  return (pos);
}


#ifndef _WIN32

string Menu::GetColor() const
{
  string Color;
  switch (GetSetup()[0])
  {
  case 9:
    Color = string("\033[34m");
    break;
  case 10:
    Color = string("\033[32m");
    break;
  case 11:
    Color = string("\033[96m");
    break;
  case 12:
    Color = string("\033[31m");
    break;
  case 13:
    Color = string("\033[35m");
    break;
  case 14:
    Color = string("\033[93m");
    break;

  default:
    break;
  }
  return Color;
}
#endif


void Menu::PrintVoci(unsigned int pos, vector<Menu *> Menus) const
{
#ifdef _WIN32
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "Selezionare la configurazione usando le frecce" << endl;
  for (unsigned int d = 0; d < Menus.size(); d++)
  {
    if (d == pos)
    {
      SetConsoleTextAttribute(h, Menu::GetSetup()[0]);
      cout << "--> ";
      Menus[d]->DrawVoci();
      SetConsoleTextAttribute(h, 15);
      cout << endl;
    }
    else
      Menus[d]->DrawVoci();
    cout << endl;
  }
#else
  cout << "Selezionare la configurazione usando le frecce, per selezionare una voce premere 'a'" << endl;
  for (unsigned int d = 0; d < Menus.size(); d++)
  {
    if (d == pos)
    {
      cout << GetColor()              //prende il colore impostato dall'utente
           << "--> ";
      Menus[d]->DrawVoci();
      cout << "\033[0m" << endl;      //fa tornare l'output normale
    }
    else
      Menus[d]->DrawVoci();
    cout << endl;
  }
#endif
}


void Menu::PrintVoci(unsigned int pos, vector<string> voci) const
{
#ifdef _WIN32
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Selezionare la configurazione usando le frecce" << endl;
	for (unsigned int d = 0; d < voci.size(); d++)
	{
		if (d == pos)
		{
			SetConsoleTextAttribute(h, Menu::GetSetup()[0]);
			cout << "--> " << voci[d];
			SetConsoleTextAttribute(h, 15);
			cout << endl;
		}
		else
			cout << voci[d];
		cout << endl;
	}
#else
	cout << "Selezionare la configurazione usando le frecce e premendo il tasto 'a'" << endl;
	for (unsigned int d = 0; d < voci.size(); d++)
	{
		if (d == pos)
		{
			cout << Menu::GetColor()
				 << "--> " << voci[d];
			cout << "\033[0m" << endl;
		}
		else

			cout << voci[d] << endl;
	}
#endif
}