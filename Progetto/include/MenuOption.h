#ifndef MENUOPTION_H
#define MENUOPTION_H
#include <iostream>
#include <vector>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
#include "Play.h"
#include "Menu.h"

class MenuOption : public Menu
{
public:
	MenuOption();
	virtual void Draw() const;
	void SelectWindows() const;
	//void SelectOthers() const;
	void PrintVoci(int) const;

private:
	vector<string> voci{"Torna al menu"};
};

#endif