#ifndef MENUPLAY_H
#define MENUPLAY_H
#include "Play.h"
#include "Menu.h"
#include "MenuBack.h"

class MenuPlay : public Menu
{
public:
	MenuPlay();
	virtual void DrawVoci() const;
	virtual void Draw() const;
	void PrintVoci(unsigned int) const;

private:
	vector<string> voci;
};

#endif
