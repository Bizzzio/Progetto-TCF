#ifndef RussianInfantry_h
#define RussianInfantry_h
#include "Infantry.h"

class RussianInfantry : public Infantry {

public:
	RussianInfantry();
	virtual void move();
	virtual void fight();
	virtual string getName();
private:
	string name;
};
#endif
