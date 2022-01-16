#ifndef PLAY_H
#define PLAY_H
#include <iostream>
#include <vector>
#include "Factory.h"
#include "PlayerFactory.h"
#include "ComputerFactory.h"
#include <typeinfo> 


class Play
{

public:
	Play(Factory *, Factory *);
	~Play(){};
	bool Check(int, int, Griglia);  // Controlla che la cella individuata dai due interi possa essere colpita per la griglia presa in argomento
	void PlayBattleship();			// Codice cliente per la partita

private:

	/* Ad ogni giocatore associamo una coppia di DM griglia + puntatore 
	alla factory astratta così da poter sfruttare il polimorfismo a 
	seconda del tipo di giocatori*/

	Griglia grid1;
	Griglia grid2;
	Factory *Player1;
	Factory *Player2;
};

#endif