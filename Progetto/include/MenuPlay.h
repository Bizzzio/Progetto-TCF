#ifndef MENUPLAY_H
#define MENUPLAY_H
#include "Play.h"
#include "Menu.h"

class MenuPlay : public Menu
{
public:
	virtual void Draw() const;

private:
	const vector<string> voci{"1 giocatore", "2 giocatori", "Torna al menu"};
};

#endif