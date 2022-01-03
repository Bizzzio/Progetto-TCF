#ifndef MENUOPTION_H
#define MENUOPTION_H
#include "Play.h"
#include "Menu.h"

class MenuOption : public Menu
{
	public:
    	MenuOption();
    	virtual void Draw() const;
    private:
    	const vector<string> voci {"Torna al menu"};
		
};

#endif