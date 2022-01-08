#include "Menu.h"

<<<<<<< HEAD
vector<int> Menu::Setup{};
=======
vector<int> Menu::Setup{10,10,1,0,0,0,0};
>>>>>>> d5e850c1b37fc28c9a70024078d00d709a467ac4

void Menu::Add(int x)
{
    Setup.push_back(x);
}

void Menu::Set(int x, int y)
{
  Setup[x]=y;
}

vector<int> Menu::GetSetup()
{
    return Setup;
}

unsigned int Menu::Arrows(unsigned int *posptr, vector<Menu *> Voci) const{

  
  #define KEY_UP 72
  #define KEY_LEFT 75
  #define KEY_RIGHT 77
  #define KEY_DOWN 80
  int c, ex;
  unsigned int pos=(*posptr);
  do
    {
      c = getch();
      if (c == 0 || c == 224)
      {
        switch (ex = getch())
        {
        case KEY_UP /* H */ :
          //cout << endl << "Up" << endl;//key up
          if (pos != 0)
            pos--;
          break;
        case KEY_DOWN /* K */ :
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
  return (pos);
}

unsigned int Menu::Arrows(unsigned int *posptr, vector<string> Voci) const{

  
  #define KEY_UP 72
  #define KEY_LEFT 75
  #define KEY_RIGHT 77
  #define KEY_DOWN 80
  int c, ex;
  unsigned int pos=(*posptr);
  do
    {
      c = getch();
      if (c == 0 || c == 224)
      {
        switch (ex = getch())
        {
        case KEY_UP /* H */ :
          //cout << endl << "Up" << endl;//key up
          if (pos != 0)
            pos--;
          break;
        case KEY_DOWN /* K */ :
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
  return (pos);
}