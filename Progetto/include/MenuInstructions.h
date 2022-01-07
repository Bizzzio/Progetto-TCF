#ifndef MENUINSTRUCTIONS_H
#define MENUINSTRUCTIONS_H
#include "menu.h"
#include <fstream>
using std::cout;
using std::endl;
using std::vector;

class MenuInstructions : public Menu
{
public:
	MenuInstructions(string);
	virtual void Draw() const;
	void PrintVoci(unsigned int) const;
	void DrawVoci() const;
	
private:
	vector<string> Voci;
	vector<string> Description{"Instructions"};
};

#endif
