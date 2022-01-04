#ifndef MENUPRINCIPALE_H
#define MENUPRINCIPALE_H

#include "menu.h"
#include "MenuPlay.h"
#include "MenuOption.h"
class MenuPrincipale : public Menu
{
public:
	virtual void Draw() const;

private:
	const vector<string> voci{"Play", "Instructions", "Options", "Credits", "Quit"};
	MenuPlay menuplay;
	MenuOption menuoption;
};

#endif