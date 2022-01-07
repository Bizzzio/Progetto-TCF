#ifndef MENUTEXT_H
#define MENUTEXT_H

#include <iostream>
#include <vector>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
#include "Play.h"
#include "Menu.h"

class MenuText : public Menu
{
public:
	MenuText(string);
	virtual void Draw() const;
	void PrintVoci(unsigned int) const;
	void DrawVoci() const;
	void SelectWindows() const;
	void SelectOthers() const;
	string GetFileName(string&) const;

private:
	vector<string> Voci;
	vector<string> Description{"Instructions"};
};

#endif