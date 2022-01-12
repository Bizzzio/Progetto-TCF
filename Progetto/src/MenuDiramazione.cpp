#include "MenuDiramazione.h"

#ifndef _WIN32
#define CLEAR "clear"
#endif


//Il Costruttore di menudiramazione senza argomenti costruisce il menu principale
MenuDiramazione::MenuDiramazione()
{
  vector<Menu *> Opzioni;
  Opzioni.push_back(new MenuOpzioni(1, string("Seleziona dimensioni griglia"), string("Dimensioni.txt")));
  Opzioni.push_back(new MenuOpzioni(0, string("Seleziona colore del menu"), string("Colori.txt")));
  Opzioni.push_back(new MenuOpzioni(2, string("Seleziona flotta"), string("Setup.txt")));
  Opzioni.push_back(new MenuBack);
  vector<Menu *> Menu {{new MenuPlay, new MenuDiramazione(string("Options"),Opzioni),new MenuText(string("Instructions")), new MenuText(string("Credits")), new MenuBack("Quit")}};
  Menus=Menu;
 
}


//Gli argomenti del costruttore sono la stringa vocesopra e il vettore di menu che il menudiramazione deve contenere
MenuDiramazione::MenuDiramazione(string vocesopra, vector<Menu *> menu)
{
  VoceSopra = vocesopra;
  Menus = menu;
}

MenuDiramazione::~MenuDiramazione()
{
  vector<Menu *>::const_iterator i;
  for (i = Menus.begin(); i != Menus.end(); i++)
    delete (*i);
}

void MenuDiramazione::DrawVoci() const
{
  cout << VoceSopra;
}

//Draw si occupa di gestire il menù, richiamando le funzioni che stampano le voci dei menu, quelle che permettono di muoversi nel menù attraverso le
//le frecce e gestendo la scelta dell'utente
void MenuDiramazione::Draw() const
{
  unsigned int pos = 0;
  cout << "Selezionare la configurazione usando le frecce" << endl;

  do
  {
    system(CLEAR);
    PrintVoci(pos);
    pos = Arrows(&pos, Menus);          //arrows permette di muoversi dentro il menu

    if (pos != Menus.size() - 1)
      Menus[pos]->Draw();               //chiama il menu selezionato

  } while (pos != Menus.size() - 1);
}

//PrintVoci stampa le voci dei menù sottostanti
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
