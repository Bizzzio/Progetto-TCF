#ifndef MENUINSTRUCTIONS_H
#define MENUISTRUCTIONS_H
#include "Play.h"
#include "Menu.h"

class MenuInstructions : public Menu
{
public:
	virtual void DrawVoci() const;
	virtual void Draw() const;

private:
	const vector<string> voci{"Istruzioni"};
};

#endif
