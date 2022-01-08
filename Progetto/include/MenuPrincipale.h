#ifndef MENUPRINCIPALE_H
#define MENUPRINCIPALE_H

#include "menu.h"
#include "MenuPlay.h"
#include "MenuOption.h"
#include "MenuBack.h"
#include "MenuText.h"

class MenuPrincipale : public Menu
{
public:
	MenuPrincipale();
	~MenuPrincipale();
	unsigned int Arrows(unsigned int *pos, vector<Menu *>) const;
	virtual void Draw() const;
	void SelectWindows() const;
	void SelectOthers() const;
	void PrintVoci(unsigned int) const;

private:
	// const vector<string> voci{"Play", "Instructions", "Options", "Credits", "Quit"}; new MenuInstructions("Credits")
	const vector<Menu *> Menus {{new MenuPlay, new MenuOption, new MenuText(string("Instructions")), new MenuText(string("Credits")), new MenuBack}};
};

#endif