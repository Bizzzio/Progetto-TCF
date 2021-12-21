#include <iostream>
using std::cout;
using std::endl;
#include "Battle.h"
#include "GermanFactory.h"
#include "RussianFactory.h"

int main() {

	string battleName = "Stalingrado";
	string firstPlayer = "German";
	string secondPlayer = "Russian";

	cout << "Battaglia di " << battleName << endl;
	cout << "Primo giocatore: " << firstPlayer << endl;
	cout << "Secondo giocatore: " << secondPlayer << endl;

	ArmyFactory* fp = new GermanFactory;
	ArmyFactory* sp = new RussianFactory;

	Battle b(fp, sp);

	b.playBattle();

	return 0;
}