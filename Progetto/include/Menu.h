#ifndef MENU_H
#define MENU_H

#ifdef _WIN32
#define CLEAR "cls"
#include <conio.h>
#include <windows.h>
#else
#define CLEAR "clear"
#include <unistd.h>
#include <termios.h>

#endif

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


class Menu
{

public:
	unsigned int Arrows(unsigned int *pos, vector<Menu *>) const;		//permette di muoversi nel menu con le frecce
	unsigned int Arrows(unsigned int *pos, vector<string>) const;		//fa la stessa cosa di quello sopra ma stampa vettori di stringhe anzichè le voci dei menu
	virtual void PrintVoci(unsigned int) const = 0;						//stampa le voci dei menu sottostanti
	virtual void DrawVoci() const {};									//stampa il nome del menu in cui ci troviamo (viene chiamata dal menu sopra)
	virtual void Draw() const = 0;										//Gestisce il menu (scelta dell'utente, muoversi con le frecce e stampa dei menu)
	static void Add(int);												//fa il pushback di un valore a setup
	static void Set(int, int);											//imposta un certo elemento del vettore setup ad un certo valroe

	static vector<int> GetSetup();										//restituisce il setup

#ifndef _WIN32
	string GetColor() const;											//converte il colore impostato in setup in un ANSI escape code per colorare il menu fuori da windows
#endif

private:
	static vector<int> Setup;

};

#endif
