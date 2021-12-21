#ifndef Tiger_h
#define Tiger_h
#include "Tank.h"

class Tiger : public Tank {

public:
	Tiger();
	virtual void move();
	virtual void fight();
	virtual string getName();
private:
	string name;

};
#endif

