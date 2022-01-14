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
    PrintVoci(pos,Menus);
    pos = Arrows(&pos, Menus);          //arrows permette di muoversi dentro il menu

    if (pos != Menus.size() - 1)
      Menus[pos]->Draw();               //chiama il menu selezionato

  } while (pos != Menus.size() - 1);
}


