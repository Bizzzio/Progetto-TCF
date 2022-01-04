#ifndef MENUPRINCIPALE_H
#define MENUPRINCIPALE_H

#include "menu.h"
#include "MenuPlay.h"
#include "MenuOption.h"
//#include "MenuInstructions.h"
//#include "MenuCredits.h"

class MenuPrincipale : public Menu
{
public:
	MenuPrincipale();
    ~MenuPrincipale();
	virtual void Draw() const;
    void SelectWindows() const;
    void SelectOthers() const;
    void PrintVoci(int) const;

private:
	// const vector<string> voci{"Play", "Instructions", "Options", "Credits", "Quit"};
	const vector<Menu*> Menus;
};

#endif