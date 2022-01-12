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
      case KEY_UP /* H */:
        //cout << endl << "Up" << endl;//key up
        if (pos != 0)
          pos--;
        break;
      case KEY_DOWN /* K */:
        //cout << endl << "Down" << endl;   // key down
        if (pos < Voci.size() - 1)
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
        case KEY_UP /* H */:
          //cout << endl << "Up" << endl;//key up
          if (pos != 0)
            pos--;
          break;
        case KEY_DOWN /* K */:
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
        PrintVoci(pos);
    }
  } while (c != 'a');
#endif
  return (pos);
}

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
      case KEY_UP /* H */:
        //cout << endl << "Up" << endl;//key up
        if (pos != 0)
          pos--;
        break;
      case KEY_DOWN /* K */:
        //cout << endl << "Down" << endl;   // key down
        if (pos < Voci.size() - 1)
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
        case KEY_UP /* H */:
          //cout << endl << "Up" << endl;//key up
          if (pos != 0)
            pos--;
          break;
        case KEY_DOWN /* K */:
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
        PrintVoci(pos);
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