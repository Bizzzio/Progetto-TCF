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
	void DrawVoci() const;
	string GetFileName(string&) const;

private:
	string Voci;
	vector<string> Description;
};

#endif