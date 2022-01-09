#ifndef MENUOPZIONI_H
#define MENUOPZIONI_H
#include <iostream>
#include <vector>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
#include "Play.h"
#include "Menu.h"

class MenuOpzioni : public Menu
{
public:
	MenuOpzioni(int,string,string);
	virtual void Draw() const;
	virtual void PrintVoci(unsigned int) const;
	void DrawVoci() const;
    void SetOption(int, unsigned int) const;
    void AddConfig() const;

private:
    
    int NumeroOpzione;
	string Nome,Filename;
	mutable vector<string> Lista{"Torna al menu"};
};

#endif