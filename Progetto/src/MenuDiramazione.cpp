#include "MenuDiramazione.h"

#ifndef _WIN32
#define CLEAR "clear"
#endif

MenuDiramazione::MenuDiramazione(string vocesopra, vector<Menu *> menu) 
{
    VoceSopra=vocesopra;
    Menus=menu;
}

MenuDiramazione::~MenuDiramazione()
{
  vector<Menu *>::const_iterator i;
  for (i = Menus.begin(); i != Menus.end(); i++)
    delete (*i);
}

void MenuDiramazione::DrawVoci() const
{
    cout<<VoceSopra;
}


void MenuDiramazione::Draw() const
{
  unsigned int pos=0;
  cout << "Selezionare la configurazione usando le frecce" << endl;

  
  do
  {
    system("cls");
    PrintVoci(pos);
    pos = Arrows(&pos, Menus);


    if (pos != Menus.size() - 1)
      Menus[pos]->Draw();


  } while (pos != Menus.size() - 1);
}

void MenuDiramazione::PrintVoci(unsigned int pos) const
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
  cout << "Selezionare la configurazione usando le frecce" << endl;
  for (unsigned int d = 0; d < Menus.size(); d++)
  {
    if (d == pos)
    {
      cout << "\033[32m"
           << "--> ";
      Menus[d]->DrawVoci();
      cout << "\033[0m" << endl;
    }
    else
      Menus[d]->DrawVoci();
    cout << endl;
  }
#endif
}


