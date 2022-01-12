#ifndef PLAY_H
#define PLAY_H
#include <iostream>
using namespace std;
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
	bool Check(int, int, Griglia);
	void PlayBattleship();

private:
	Griglia grid1;
	Griglia grid2;
	Factory *Player1;
	Factory *Player2;
};

#endif