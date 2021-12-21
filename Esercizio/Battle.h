#ifndef Battle__h
#define Battle__h
#include <string>
using std::string;
#include "ArmyFactory.h"

class Battle {

public:
	Battle(ArmyFactory*, ArmyFactory*);
	~Battle();
	void playBattle();

private:
	ArmyFactory* fp;
	ArmyFactory* sp;
	vector<Unit*> fpArmy;
	vector<Unit*> spArmy;

};
#endif

