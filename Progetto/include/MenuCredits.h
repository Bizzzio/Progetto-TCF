#ifndef MENUCREDITS_H
#define MENUCREDITS_H
#include "Menu.h"

class MenuCredits : public Menu
{
public:
	virtual void DrawVoci() const;
	virtual void Draw() const;

private:
	const vector<string> Voci{"Credits"};
};

#endif