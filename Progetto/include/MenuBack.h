#ifndef MENUBACK_H
#define MENUBACK_H
#include <iostream>
#include <vector>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
#include "Menu.h"

class MenuBack : public Menu
{
public:
	MenuBack() {}
	virtual void Draw() const;
	void SelectWindows() const;
	//void SelectOthers() const;
	void DrawVoci() const;

private:
	vector<string> Voci{"Torna al menu"};
};

#endif