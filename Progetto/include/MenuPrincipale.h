#ifndef MENUPRINCIPALE_H
#define MENUPRINCIPALE_H

#include "menu.h"
#include "MenuPlay.h"
#include "MenuOption.h"
#include "MenuBack.h"
#include "MenuText.h"
#include "MenuDiramazione.h"
#include "MenuOpzioni.h"

class MenuPrincipale : public Menu
{
public:
	MenuPrincipale();
	~MenuPrincipale();
	virtual void Draw() const;
	void SelectWindows() const;
	void SelectOthers() const;
	virtual void PrintVoci(unsigned int) const;

private:
	const vector<Menu *> Menus {{new MenuPlay,new MenuDiramazione(string("Test"), vector<Menu* > {new MenuOpzioni(1,string("Seleziona dimensioni griglia"),string("Dimensioni.txt")), new MenuOpzioni(0,string("Seleziona colore del menu"),string("Colori.txt")),new MenuOpzioni(2,string("Seleziona flotta"),string("Setup.txt")),new MenuText(string("Credits")), new MenuBack}), new MenuOption, new MenuText(string("Instructions")), new MenuText(string("Credits")), new MenuBack}};
};

#endif