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

//Menutext si occupa di stampare certe informazioni contenute nei file di testo, come ad esempio le istruzioni e i credits
class MenuText : public Menu
{
public:
	MenuText(string);							//Il costruttore prende in input una stringa, che diventerà il nome del menù e ha lo stesso nome del file di testo da cui prendere i dati
	virtual void Draw() const;					//Si occupa di stampare il menu
	void DrawVoci() const;						//Stampa le voci ai menù sopra

private:
	string Voci;								//Nome del menu che viene stampato dai menù spora (Instructions e Credits)
	vector<string> Description;					//contiene le righe del file di testo da stampare
	string GetFileName(string&) const;			//Restituisce il nome del file aggiungnendo ../src/ e .txt
};

#endif