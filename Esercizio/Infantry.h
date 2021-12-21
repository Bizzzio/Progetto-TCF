#ifndef Infantry_h
#define Infantry_h
#include <string>
using std::string;
#include "Unit.h"

class Infantry : public Unit {

public:
	virtual ~Infantry() {};
	virtual void move() = 0;
	virtual void fight() = 0;
	virtual string getName() = 0;
};
#endif
