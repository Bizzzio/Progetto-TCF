#include "Menu.h"
#include "MenuOpzioni.h"
#include "MenuBack.h"
#include "MenuPlay.h"
#include "MenuText.h"
#ifndef MENUDIRAMAZIONE_H
#define MENUDIRAMAZIONE_H

//MenuDiramazione permette di creare una voce di menù che rimanda ad altri menu (ad esempio il menu principale è un menu diramazione)

class MenuDiramazione : public Menu
{
    public:
	MenuDiramazione();								//Il costruttore senza argomenti crea il menu principale

	//Il costruttore prende due argomenti: 
	//-	una stringa, che diventerà VoceSopra ed è la voce con cui il menù diramazione viene visto dai menù sopra di lui 
	//	(Il menù principale stampa per il menu opzioni la voce "Options", che è la vocesopra del menu diramazioni delle opzioni);
	//-	Un vettore di Menu*, che rappresenta i vettori contenuti nel menudiramazione
	MenuDiramazione(string, vector<Menu *>);		
	~MenuDiramazione();


	virtual void Draw() const;						//la funzione draw si occupa di gestire la stampa dei menu e la selezione dei menù tramite le frecce
    void DrawVoci() const;							//la funzione draw voci stampa vocesopra

private:
    string VoceSopra;								//la stringa che viene stampata dal menù che sta più in altro per identificare lo specifico menudiramazione
	vector<Menu *> Menus;							//vettore di menu contenuti in menu diramazione
};

#endif
