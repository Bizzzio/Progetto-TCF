#ifndef MENUBACK_H
#define MENUBACK_H
#include <iostream>
#include <vector>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
#include "Menu.h"

//MenuBack è il menu che si occupa di tornare indietro, semplicemente non facendo nulla quando viene chiamato il suo draw
class MenuBack : public Menu
{
public:
	MenuBack();											//Quando viene inizialzzato senza parametri, allora stampa "Back to menu"
	MenuBack(string);									//Quando invece riceve in input una stringa, allora stampa la stringa (ad esempio quit)
	virtual void Draw() const {}
	void DrawVoci() const;								//Stampa voci
	virtual void PrintVoci(unsigned int) const {}

private:
	string Voci;										//è la stringa che stampa per essere selezionato
};

#endif