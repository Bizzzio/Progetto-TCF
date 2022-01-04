#ifndef MENUOPTION_H
#define MENUOPTION_H
#include<iostream>
#include<vector>
#include <fstream>
using std::vector;
using std::cout;
using std::endl;
#include "Play.h"
#include "Menu.h"

class MenuOption : public Menu
{
	public:
    	MenuOption();
    	virtual void Draw() const;
    private:
    	vector<string> voci {"Torna al menu"};
		
};

#endif