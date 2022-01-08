#include "Menu.h"

#ifndef MENUDIRAMAZIONE_H
#define MENUDIRAMAZIONE_H


class MenuDiramazione : public Menu
{
    public:
	MenuDiramazione(string, vector<Menu *>);
	~MenuDiramazione();
	virtual void Draw() const;
    void DrawVoci() const;
	virtual void PrintVoci(unsigned int) const;

private:
    string VoceSopra;
	vector<Menu *> Menus;
};

#endif
