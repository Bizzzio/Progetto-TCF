#ifndef MENUOPZIONI_H
#define MENUOPZIONI_H
#include <iostream>
#include <vector>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
#include "Menu.h"

//la classe menuopzioni si occupa di gestire le opzioni
class MenuOpzioni : public Menu
{
public:
	//il costruttore prende 3 input: un intero, che rappresenta quale opzione andrà a cambiare,
	//una stringa, che rappresenta il nome dell'opzione che verrà visto dai menu sopra a questo,
	//e una seconda stringa, che contiene il nome del file di testo in cui sono contenute le varie opzioni
	MenuOpzioni(int, string, string);
	virtual void Draw() const;
	void DrawVoci() const;
	void SetOption(int, unsigned int) const; 					//Setoption si occupa di cambiare il valore di Setup (statico) a seconda della scelta dell'utente
	void AddConfig() const;										//Addconfig aggiunge un'opzione al file di testo (ad esempio aggiungere una configurazione di una flotta)

private:
	int NumeroOpzione;											//contiene quale elemento di Setup (statico) il menu deve cambiare
	string Nome, Filename;										//Nome è il nome dell'opzione con cui viene vista dai menu sopra; filename è il nome del file in cui sono contenute le varie opzioni
	mutable vector<string> Lista{"Torna al menu"};				//lista è un vector che contiene le varie opzioni (ad esempio le varie configurazioni delle flotte)	
};

#endif