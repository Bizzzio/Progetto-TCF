#ifndef MENUPLAY_H
#define MENUPLAY_H
#include "Play.h"
#include "Menu.h"

class MenuPlay : public Menu
{
public:
	MenuPlay();
	virtual void DrawVoci() const;
	virtual void Draw() const;

private:
	vector<string> voci;
};

#endif
