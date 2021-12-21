#ifndef Tank_h
#define Tank_h
#include <string>
using std::string;
#include "Unit.h"

class Tank : public Unit {

public:
	virtual ~Tank() {};
	virtual void move() = 0;
	virtual void fight() = 0;
	virtual string getName() = 0;
};
#endif
