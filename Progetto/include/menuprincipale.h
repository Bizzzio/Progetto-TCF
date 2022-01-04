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
<<<<<<< HEAD
	const vector<string> voci{"Play", "Instructions", "Options", "Credits", "Quit"};
	const vector<Menu *> Menus{new MenuPlay, new MenuOption, new MenuOption, new MenuOption};
=======
	// const vector<string> voci{"Play", "Instructions", "Options", "Credits", "Quit"};
	const vector<Menu*> Menus;
>>>>>>> ce6d0ae85f99554cb380896a3dbe6d79033610b3
};

#endif