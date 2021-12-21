#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include "Battle.h"

Battle::Battle(ArmyFactory* fpA, ArmyFactory* spA) {
	fp = fpA;
	sp = spA;
	fpArmy = fp->getArmy();
	spArmy = sp->getArmy();
}
Battle::~Battle() {

}
void Battle::playBattle() {

	vector<Unit*>::iterator i;
	for (i = fpArmy.begin(); i != fpArmy.end(); i++) {
		cout << (*i)->getName();
		(*i)->move();
		(*i)->fight();
		cout << endl;
	}

	for (i = spArmy.begin(); i != spArmy.end(); i++) {
		cout << (*i)->getName();
		(*i)->move();
		(*i)->fight();
		cout << endl;
	}
}