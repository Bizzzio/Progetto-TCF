#ifndef T34_h
#define T34_h
#include "Tank.h"

class T34 : public Tank {

public:
	T34();
	virtual void move();
	virtual void fight();
	virtual string getName();
private:
	string name;

};
#endif

